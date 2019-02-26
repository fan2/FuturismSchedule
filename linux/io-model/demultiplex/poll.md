
unix/POSIX - [poll](http://pubs.opengroup.org/onlinepubs/9699919799/functions/poll.html)  
FreeBSD/Darwin - [poll](https://www.freebsd.org/cgi/man.cgi?query=poll)  

linux - [POLL(2)](http://man7.org/linux/man-pages/man2/poll.2.html)  
debian/Ubuntu - [poll](https://manpages.debian.org/stretch/manpages-dev/poll.2.en.html)  

## SYNOPSIS

**API**:

`poll`, `ppoll` - input/output multiplexing, wait for some event on a file descriptor

**SYNOPSIS**:

```c
#include <poll.h>

struct pollfd {
    int   fd;         /* file descriptor */
    short events;     /* requested events */
    short revents;    /* returned events */
};

int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```

### ppoll

Feature Test Macro Requirements for glibc (see [feature_test_macros(7)](http://man7.org/linux/man-pages/man7/feature_test_macros.7.html)):

```c
#define _GNU_SOURCE

#include <signal.h>
#include <poll.h>

int ppoll(struct pollfd *fds, nfds_t nfds,
        const struct timespec *tmo_p, const sigset_t *sigmask);
```

## DESCRIPTION

`poll()` performs a similar task to `select(2)`: it waits for one of a set of file descriptors to become ready to perform I/O.

### ppoll

The relationship between `poll()` and `ppoll()` is analogous to the relationship between `select(2)` and `pselect(2)`: like pselect(2), ppoll() allows an application to **safely** wait until *either* a file descriptor becomes ready *or* until a signal is caught.

### vs. select

[Linux select() vs pselect() vs ppoll()](https://stackoverflow.com/questions/9774986/linux-select-vs-ppoll-vs-pselect)  
[What are the differences between poll and select?](https://stackoverflow.com/questions/970979/what-are-the-differences-between-poll-and-select)  
[Caveats of select/poll vs. epoll reactors in Twisted](https://stackoverflow.com/questions/2032598/caveats-of-select-poll-vs-epoll-reactors-in-twisted)  

`select()` can monitor only file descriptors numbers that are less than *FD_SETSIZE*; `poll(2)` does **not** have this limitation.  

相比 select 需要用户按关注事件类型组装三个 FD_SET，`pollfd` 结构直接将 fd 及其关注的事件封装在一起，调用参数及回调管理更直观简洁。
此外，select 每次都要重新初始化各个 FD_SET，且 select 返回后需要对前后 FD_SET 进行二次分拣。poll 则直接在 pollfd.revents 中返回发生的事件。

## refs

## libraries

### libevent

[poll.c](https://github.com/libevent/libevent/blob/master/poll.c)  

### libuv

[unix/fs.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/fs.c)  
[unix/posix-poll.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/posix-poll.c)  

### nginx

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h) -NGX_HAVE_POLL,NGX_HAVE_DEVPOLL  
[ngx_poll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_poll_module.c)  
[ngx_win32_poll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_win32_poll_module.c)  
[ngx_devpoll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_devpoll_module.c)  

### mars

微信终端跨平台组件 Mars 针对 unix 平台采用 poll 作为 I/O 多路复用器，SocketBreaker 基于管道（pipe）对轮询进行唤醒（Break）。  

[socketpoll.cc](https://github.com/Tencent/mars/blob/master/mars/comm/unix/socket/socketpoll.cc)

### [muduo](https://github.com/chenshuo/muduo)

[PollPoller.cc](https://github.com/chenshuo/muduo/blob/master/muduo/net/poller/PollPoller.cc)  
