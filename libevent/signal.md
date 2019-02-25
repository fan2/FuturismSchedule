[overview of signals](http://man7.org/linux/man-pages/man7/signal.7.html)

## Sending a signal

The following system calls and library functions allow the caller to send a signal:

- [raise(3)](http://man7.org/linux/man-pages/man3/raise.3.html): Sends a signal to the calling thread.  
- [kill(2)](http://man7.org/linux/man-pages/man2/kill.2.html): Sends a signal to a specified process, to all members of a specified process group, or to all processes on the system.  
- [killpg(3)](http://man7.org/linux/man-pages/man3/killpg.3.html): Sends a signal to all of the members of a specified process group.  
- [pthread_kill(3)](http://man7.org/linux/man-pages/man3/pthread_kill.3.html): Sends a signal to a specified POSIX thread in the same process as the caller.  
- [tgkill(2)](http://man7.org/linux/man-pages/man2/tgkill.2.html): Sends a signal to a specified thread within a specific process.  (This is the system call used to implement pthread_kill(3).)  
- [sigqueue(3)](http://man7.org/linux/man-pages/man3/sigqueue.3.html): Sends a real-time signal with accompanying data to a specified process.  

`raise` - send a signal to the caller(process or thread)  
`kill` - send signal to a process  
`pthread_kill` - send a signal to a thread asynchronously  

In a *single-threaded* program it is equivalent to `kill(getpid(), sig);`  
In a *multithreaded* program it is equivalent to `pthread_kill(pthread_self(), sig);`  

If the signal causes a handler to be called, `raise()` will return **only** after the signal handler has returned.

## signal mask

The signal mask is the set of signals whose delivery is currently **blocked** for the caller.  
Each thread in a process has an *independent* signal mask, which indicates the set of signals that the thread is currently *blocking*.

> sigmask=signal mask，意即信号掩码。

A thread can manipulate its signal mask using `pthread_sigmask(3)`.  
In a traditional single-threaded application, `sigprocmask(2)` can be used to manipulate the signal mask.

调用 `sigprocmask`（单线程） 或 `pthread_sigmask`（多线程）可屏蔽掉某些不关心的信号，不做处理。

> It is not possible to block `SIGKILL` or `SIGSTOP`, specifying these signals in mask are silently ignored, and has no effect.

### [sigprocmask(2)](http://man7.org/linux/man-pages/man2/sigprocmask.2.html)

`sigprocmask`, `rt_sigprocmask` - examine and change blocked signals

**sigprocmask()** is used to fetch and/or change the signal mask of the calling thread.  

#### SYNOPSIS

```c
#include <signal.h>

/* Prototype for the glibc wrapper function */
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```

> If `oldset` is non-NULL, the previous value of the signal mask is **stored** in oldset.

#### how

- `SIG_BLOCK`: The set of blocked signals is the **union** of the current set and the set argument.  
- `SIG_UNBLOCK`: The signals in set are **removed** from the current set of blocked signals. It is permissible to attempt to unblock a signal which is not blocked.  
- `SIG_SETMASK`: The set of blocked signals is **set** to the argument set.  

### [pthread_sigmask(3)](http://man7.org/linux/man-pages/man3/pthread_sigmask.3.html)

`pthread_sigmask` - examine and change mask of blocked signals

#### SYNOPSIS

```c
 #include <signal.h>

 int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);
```

#### DESCRIPTION

The `pthread_sigmask()` function is just like `sigprocmask(2)`, with the difference that its use in **multithreaded** programs is explicitly specified by POSIX.1.

## Waiting for a signal to be caught

The following system calls suspend execution of the calling process or thread until a signal is caught (or an unhandled signal terminates the process):

- [pause(2)](http://man7.org/linux/man-pages/man2/pause.2.html): Suspends execution until any signal is caught.  
- [sigsuspend(2)](http://man7.org/linux/man-pages/man2/sigsuspend.2.html): Temporarily changes the signal mask (see below) and suspends execution until one of the unmasked signals is caught.  

只接受处理当前线程 unmask 的信号。

## Asynchronously signal handler

`signal()` 函数和 `sigaction()` 函数为指定信号量安装信号处理器。

### [signal](http://man7.org/linux/man-pages/man2/signal.2.html)

`signal` - ANSI C signal handling

```c
#include <signal.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```

The behavior of signal() varies across UNIX versions, and has also varied historically across different versions of Linux.  
Avoid its use: use sigaction(2) instead.

### [sigaction](http://man7.org/linux/man-pages/man2/sigaction.2.html)

`sigaction`, `rt_sigaction` - examine and change a signal action

```c
#include <signal.h>

struct sigaction {
   void     (*sa_handler)(int);
   void     (*sa_sigaction)(int, siginfo_t *, void *);
   sigset_t   sa_mask; // should be blocked during execution
   int        sa_flags;
   void     (*sa_restorer)(void);
};

int sigaction(int signum, const struct sigaction *act,
             struct sigaction *oldact);
```

The `sigaction()` system call is used to change the action taken by a process on receipt of a **specific** signal.

- *signum* specifies the signal and can be any valid signal except `SIGKILL` and `SIGSTOP`.  
- If *act* is non-NULL, the new action for signal signum is **installed** from act.  
    - If *oldact* is non-NULL, the previous action is **saved** in oldact.  

#### sa_mask

可以配置 sigaction.sa_mask，以便在处理某个信号期间，阻塞某些信号。  
如果正在处理某个信号，没有在 sigaction.sa_flags 中配置 `SA_NODEFER`，则默认会阻塞掉再次到来的同一信号。  

`sa_mask` specifies a mask of signals which should be blocked (i.e., added to the signal mask of the thread in which the signal handler is invoked) during execution of the signal handler.  
In addition, the signal which triggered the handler will be blocked, unless the `SA_NODEFER` flag is used.

## Synchronously accepting a signal

Rather than **asynchronously** catching a signal via a signal handler, it is possible to **synchronously** accept the signal, that is, to ***block*** execution *until* the signal is delivered, at which point the kernel returns information about the signal to the caller.  

There are two general ways to do this:

* [sigwaitinfo(2)](http://man7.org/linux/man-pages/man2/sigwaitinfo.2.html), [sigtimedwait(2)](http://man7.org/linux/man-pages/man2/sigtimedwait.2.html), and [sigwait(3)](http://man7.org/linux/man-pages/man3/sigwait.3.html) suspend execution until one of the signals in a specified set is delivered. Each of these calls returns information about the delivered signal.

* [signalfd(2)](http://man7.org/linux/man-pages/man2/signalfd.2.html) returns a file descriptor that can be used to read information about signals that are delivered to the caller. Each [read(2)](http://man7.org/linux/man-pages/man2/read.2.html) from this file descriptor blocks until one of the signals in the set specified in the signalfd(2) call is delivered to the caller. The buffer returned by read(2) contains a structure describing the signal.

### signalfd

signalfd - create a file descriptor for accepting signals

```c
 #include <sys/signalfd.h>

 int signalfd(int fd, const sigset_t *mask, int flags);
```

`signalfd()` creates a file descriptor that can be used to accept signals targeted at the caller.  
This provides an *alternative* to the use of a signal handler or `sigwaitinfo(2)`, and has the **advantage** that the file descriptor may be monitored by `select(2)`, `poll(2)`, and `epoll(7)`.

如此一来，信号事件就能和其他I/O事件一样被 I/O 复用器一并处理，即统一事件源。

## pending signals

A signal may be blocked, which means that it will **not** be delivered until it is later unblocked.  
Between the time when it is generated and when it is delivered a signal is said to be **pending**.

A thread can obtain the set of signals that it currently has pending using [sigpending(2)](http://man7.org/linux/man-pages/man2/sigpending.2.html).  
This set will consist of the **union** of the set of pending process-directed signals and the set of signals pending for the calling thread.  

## Interruption by signal handler

Interruption of system calls and library functions by signal handlers

If a signal handler is invoked while a system call or library function call is *blocked*, then either:

- the call is automatically restarted after the signal handler returns; or  
- the call fails with the error `EINTR`.

### restartable

如果安装信号处理器时，sigaction.sa_flags 设置了 `SA_RESTART` 标记（making system calls restartable across signals），则被中断的系统调用在 sa_sigaction 处理完毕后可自动重入。

支持 restart 的典型系统调用如下：

- 诸如外设读写（read(2)/write(2)）；  
- 套接字连接（connect(2)/accept(2)）及读写（recv(2)/send(2)）；  
- 同步设施（sem、mutex、cond）等待（lock 或 wait）；  
- etc.  

否则，系统调用将会返回错误（errno=`EINTR`）。

### EINTR

还有一些系统调用或在某些场景下，无论是否设置了 `SA_RESTART` 标记，被信号中断后不会自动重入，直接返回错误。

- 等待信号接口：pause(2), sigsuspend(2), sigtimedwait(2), and sigwaitinfo(2)；  
- 已被设置 `SO_RCVTIMEO` 套接字的可读调用（accept,recv）和可写调用（connect,send）；  
- I/O 多路复用器：epoll_wait(2), epoll_pwait(2), poll(2), ppoll(2), select(2), and pselect(2)；  
- 睡眠接口：clock_nanosleep(2), nanosleep(2), and usleep(3).
- etc.  

> 需要注意的是，`sleep(3)` 函数也不会重启，但是不会返回错误，返回剩余时间。

应按需对某些系统调用捕获 `errno=EINTR` 错误，并进行手动重入处理。

#### libuv

libuv 中的 select 和 poll 检测到 `EINTR` 会执行重试：

```c
// https://github.com/libuv/libuv/blob/v1.x/src/unix/posix-poll.c
/* Check whether the given fd is supported by poll().  */
int uv__io_check_fd(uv_loop_t* loop, int fd) {
  //...

  do
    rv = poll(p, 1, 0);
  while (rv == -1 && (errno == EINTR || errno == EAGAIN));

  // ...
}

// https://github.com/libuv/libuv/blob/v1.x/src/unix/stream.c
#if defined(__APPLE__)
static void uv__stream_osx_select(void* arg) {
{

  while (1) {

    /* Wait indefinitely for fd events */
    r = select(max_fd + 1, s->sread, s->swrite, NULL, NULL);
    if (r == -1) {
      if (errno == EINTR)
        continue;

      /* XXX: Possible?! */
      abort();
    }

}
#endif
```

#### mars

mars 中执行 `pthread_mutex_lock` 和 `connect` 检测到 `EINTR` 会执行重试：

```cpp
// https://github.com/Tencent/mars/blob/master/mars/boost/thread/pthread/mutex.hpp
namespace mars_boost {} namespace boost = mars_boost; namespace mars_boost
{
  namespace posix {

    BOOST_FORCEINLINE int pthread_mutex_lock(pthread_mutex_t* m)
    {
      int ret;
      do
      {
          ret = ::pthread_mutex_lock(m);
      } while (ret == EINTR);
      return ret;
    }

  }

}

// https://github.com/Tencent/mars/blob/master/mars/comm/socket/local_ipstack.cc
static const unsigned int kMaxLoopCount = 10;
static int
_test_connect(int pf, struct sockaddr *addr, size_t addrlen, struct sockaddr* local_addr, socklen_t local_addr_len) {
    int s = socket(pf, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0) return 0;
    int ret;
    unsigned int loop_count = 0;
    do {
        ret = connect(s, addr, addrlen);
    } while (ret < 0 && errno == EINTR && loop_count++<kMaxLoopCount);

}
```

## [demo](http://man7.org/linux/man-pages/man3/pthread_sigmask.3.html)

The program below blocks some signals in the main thread, and then creates a dedicated thread to fetch those signals via `sigwait(3)`.

示例代码中，主线程通过设置 sigmask 屏蔽掉（不处理）`SIGQUIT` 和 `SIGUSR1` 信号，由子线程 `sigwait()` 接收处理。  
同时，主线程调用 `pause()` 等待信号，当收到 `SIGTERM` 信号时，主线程（进程）退出。  
