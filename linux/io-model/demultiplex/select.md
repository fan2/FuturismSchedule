
unix/POSIX - [select](http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html)  
FreeBSD/Darwin - [SELECT(2)](https://www.freebsd.org/cgi/man.cgi?query=select)  

linux - [SELECT(2)](http://man7.org/linux/man-pages/man2/select.2.html)  
debian/Ubuntu - [SELECT(2)](https://manpages.debian.org/stretch/manpages-dev/_newselect.2.en.html)  

Windows - [select()](https://docs.microsoft.com/zh-cn/windows/desktop/api/winsock2/nf-winsock2-select)

## SYNOPSIS

**API**:

`select`, `pselect` - synchronous I/O multiplexing.  
`FD_ZERO`, `FD_SET`, `FD_ISSET`, `FD_CLR` - macros to manipulate the sets  

**SYNOPSIS**:

```c
/* According to POSIX.1-2001, POSIX.1-2008 */
#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int nfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, struct timeval *timeout);

void FD_CLR(int fd, fd_set *set);
int  FD_ISSET(int fd, fd_set *set);
void FD_SET(int fd, fd_set *set);
void FD_ZERO(fd_set *set);
```

### pselect

`pselect()` was added to Linux in kernel 2.6.16. Prior to this, `pselect()` was emulated in glibc (but see BUGS).  
Feature Test Macro Requirements for glibc (see [feature_test_macros(7)](http://man7.org/linux/man-pages/man7/feature_test_macros.7.html)):

> pselect(): _POSIX_C_SOURCE >= 200112L

```c
#include <sys/select.h>

int pselect(int nfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, const struct timespec *timeout,
            const sigset_t *sigmask);
```

## DESCRIPTION

### function

`select()` and `pselect()` allow a program to **monitor** multiple file descriptors, **waiting** until one or more of the file descriptors become "ready" for some class of I/O operation (e.g., input possible).  
A file descriptor is considered ***ready*** if it is possible to *perform* a corresponding I/O operation (e.g., read(2) without blocking, or a sufficiently small write(2)).  

### return

On exit, each of the file descriptor sets is **modified** in place to indicate which file descriptors actually changed status. (Thus, if using `select()` within a loop, the sets must be **reinitialized** before each call.)

> `EINTR`:  A signal occurred before any requested event;

### timeout

If both fields of the timeval structure are *zero*, then `select()` returns immediately. (This is useful for **polling**.)  
If timeout is *NULL* (no timeout), `select()` can block indefinitely.  

### pselect

1. **select()** has no sigmask argument, and behaves as **pselect()** called with *NULL* `sigmask`.  
2. **select()** uses a timeout that is a `struct timeval` (with seconds and *microseconds*), while **pselect()** uses a `struct timespec` (with seconds and *nanoseconds*).  

#### preface

关于 pselect 的产生背景和必要性，可参考 UNP 相关章节以及 [select](https://www.cnblogs.com/diegodu/p/3988103.html) vs. [pselect()](https://stackoverflow.com/questions/9774986/linux-select-vs-ppoll-vs-pselect)。

下面我们来看一段代码：

```c
int sig_int();      /*my signal handling function*/
int sig_int_flag;   /*set nonzero when signal occurs*/

int main(int argc, char* argv[]) {
    signal(SIGINT, sig_int);    /*establish handler*/
    /*...*/
    while (sig_int_flag == 0)
        pause();                /*go to sleep, waiting for signal*/
    /*...*/
}

sig_int() {
    signal(SIGINT, sig_int);    /*reestablish handler for next time*/
    sig_int_flag = 1;           /*set flag for main loop to examine*/
}
```

上述代码的本意是想让 pause 等待 SIGINT 信号唤醒。然而，由于 while 循环和 pause 之间非原子执行，如果测试满足 sig_int_flag==0 后，发生处理了 SIGINT 信号，
假设后续不再产生 SIGINT 信号，则 pause 将错失中断唤醒而永久休眠！

将 pause 换成 select，来看下面这段代码：

```c
if (intr_flag)
    handle_intr();       /*handle the signal*/

if ( (nready = select(...)) < 0 ) { /*go to sleep, waiting for I/O and signal*/
    if (errno == EINTR) {
        if (intr_flag)
            handle_intr();
    }
    /*...*/
}
```

需要明确的是，select 不仅要同步阻塞等待 I/O 事件，还要接受 `EINTR` 软中断。

假设信号处理函数 handle_intr 设置全局标记位 *intr_flag* 然后返回，在第一个 intr_flag 测试和 select 等待之间可能有 `SIGINT` 信号发生，若 select 一直阻塞等待 I/O，又错失 `SIGINT` 信号，则永远无法执行到第二个 intr_flag 测试。

究其原因在于存在竞态（race condition），test 和 wait 之间是非原子的，wait 之前收到 `SIGINT` 信号而错失唤醒。  

`pselect()` allows one to first **block** signals, **handle** the signals that have come in, then call `pselect()` with the *desired* sigmask, ***avoiding*** the race.

#### sigmask

If *sigmask* is not a null pointer, then the `pselect()` function shall **replace** the signal mask of the caller by the set of signals pointed to by *sigmask* before examining the descriptors, and shall **restore** the signal mask of the calling thread before returning.

1. first **replaces** the current signal mask by the one pointed to by sigmask,   
2. then does the "**select**" function,  
3. and then **restores** the original signal mask.  

- sigmask 可以临时屏蔽掉某些信号，这样 (p)select 调用期间不会被这些信号打断。  
- 也可以传入 empty sigmask，这样 (p)select 调用期间不会屏蔽任何信号。  

the following `pselect()` call:

```c
ready = pselect(nfds, &readfds, &writefds, &exceptfds,
               timeout, &sigmask);
```

is *equivalent* to atomically executing the following calls:

```c
sigset_t origmask;

pthread_sigmask(SIG_SETMASK, &sigmask, &origmask);  // atomically
ready = select(nfds, &readfds, &writefds, &exceptfds, timeout);
pthread_sigmask(SIG_SETMASK, &origmask, NULL);      // atomically
```

---

基于 pselect，可按以下方式可靠地修改上述示例代码：

```c
sigset_t newmask, oldmask, zeromask;

sigemptyset(&zeromask);
sigemptyset(&newmask);
sigaddset(&newmask, SIGINT);

sigprocmask(SIG_BLOCK, &newmask, &oldmask); // add new block - SIGINT
if (intr_flag)
    handle_intr();

if ( (nready = pselect(...,&zeromask)) < 0 ) {
    if (errno == EINTR) {
       if (intr_flag)
           handle_intr();
    }
    /*...*/
}
```

1. 在执行第一个 intr_flag 检测之前，先阻塞掉 SIGINT 信号；  
2. 在 pselect 中先原子设置空集掩码（取消阻塞）再真正执行 select；  
3. 在 pselect 返回之前恢复旧的信号掩码（阻塞 SIGINT 信号）。  

在 sigprocmask 之前投递的 SIGINT 信号将立即被处理；在 sigprocmask 和 pselect 之间投递的 SIGINT 信号被阻塞挂起；直到 pselect 解除阻塞执行 select 捕获到 SIGINT 信号。pselect 返回又恢复之前 sigprocmask 设置的 sigmask。

这样，在 pselect 前后阻塞掉 SIGINT，pselect-select 可准确捕获到 SIGINT 信号返回 EINTR 错误。

#### self-pipe trick

On systems that *lack* pselect(), reliable (and more portable) signal trapping can be achieved using the **self-pipe trick**.  
In this technique, a signal handler writes a dummy byte to a pipe(nonblocking) whose other end is monitored by `select()` in the main program.

Mars Unix 下的 `SocketBreaker` 基于管道（pipe）对 SocketPoll 提供轮询唤醒（Break）机制。还可调用 [socketpair](http://pubs.opengroup.org/onlinepubs/9699919799/functions/socketpair.html) 函数创建一对 UNIX 域（AF_UNIX, AF_LOCAL）套接字用于本地进程之间的通信。相比因特网域套接字，UNIX 域套接字仅复制数据，不执行协议、报头和校验相关的处理，因此效率更高。

Mars Windows 下的 `SocketSelectBreaker` 则创建一对 AF_INET 域的 UDP 套接字，绑定本地回环地址（INADDR_LOOPBACK:0），模拟全双工管道（pipe），对 SocketSelect 提供轮询唤醒（Break）机制。

## libraries

### libevent

[select.c](https://github.com/libevent/libevent/blob/master/select.c)  
[win32select.c](https://github.com/libevent/libevent/blob/master/win32select.c)  

### libuv

[win/poll.c](https://github.com/libuv/libuv/blob/v1.x/src/win/poll.c)  
[unix/stream.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/stream.c)  
[runner-unix.c](https://github.com/libuv/libuv/blob/v1.x/test/runner-unix.c)  

### nginx

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h)  
[ngx_select_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_select_module.c)  
[ngx_win32_select_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_win32_select_module.c)  

### mars

微信终端跨平台组件 Mars 中采用 select 等待 DNS 查询结果（[dnsquery.cc](https://github.com/Tencent/mars/blob/master/mars/sdt/src/checkimpl/dnsquery.cc)）。

Windows 平台采用 select 作为 I/O 多路复用器或查询接口：

- [SocketSelect.cpp](https://github.com/Tencent/mars/blob/master/mars/comm/windows/SocketSelect/SocketSelect.cpp)：采用 select 查询 I/O 事件，SocketSelectBreaker 基于本地 UDP 套接字对模拟管道（pipe），提供轮询唤醒（Break）机制。  
- [socketselect2.cc](https://github.com/Tencent/mars/blob/master/mars/comm/windows/SocketSelect/socketselect2.cc)：采用 select(to=0) 即时查询 + WSAEventSelect 等待 I/O 事件。SocketBreaker 基于 WSAEVENT 提供唤醒机制。  

## refs

[WinSock三种选择I/O模型](https://blog.csdn.net/phunxm/article/details/5085898)  

select 模式、WSAAsyncSelect 以及 WSAEventSelect 都是通过批量轮询 socket 集合来确定哪些 socket 是当前有效的（即存在待决 I/O 需要处理），好处是防止在在阻塞模式的套接字里被锁死，避免在非阻塞套接字里重复检查 `WSAEWOULDBLOCK` 错误。
