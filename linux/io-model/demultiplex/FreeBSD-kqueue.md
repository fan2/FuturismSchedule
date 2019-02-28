
FreeBSD/Darwin - [KQUEUE(2)](https://www.freebsd.org/cgi/man.cgi?query=kqueue&apropos=0&sektion=0&format=html)  

Ubuntu - [bionic (2) kqueue.2](http://manpages.ubuntu.com/manpages/bionic/man2/kqueue.2.html)

## [wiki](https://en.wikipedia.org/wiki/Kqueue)

Kqueue provides efficient input and output event pipelines between the kernel and userland.

**Kqueue** is a scalable event notification interface introduced in FreeBSD 4.1 on July 2000, also supported in NetBSD, OpenBSD, DragonflyBSD, and macOS.

> iOS 不支持？

Kqueue equivalent for other platforms:

- on Solaris, Windows and AIX: [I/O completion ports](https://en.wikipedia.org/wiki/Input/output_completion_port)  
- on Linux:

    - **epoll** system call has similar but not identical semantics. `epoll` notifies when a file descriptor is ready to perform an I/O operation, whereas kqueue & IOCP notify when a requested operation has completed.  
    - **inotify** is a Linux kernel subsystem that notices changes to the filesystem and reports those to applications.

## SYNOPSIS

**API**:

`kqueue`, `kevent` -- kernel event notification mechanism

**SYNOPSIS**:

```c
#include <sys/event.h>

int
kqueue(void);

int
kevent(int kq, const struct kevent *changelist, int nchanges,
        struct kevent *eventlist, int nevents,
        const struct timespec *timeout);

struct kevent {
    uintptr_t   ident;      /* identifier for this event */
    short       filter;     /* filter for event */
    u_short     flags;      /* action flags for kqueue */
    u_int       fflags;     /* filter flag value */
    int64_t     data;       /* filter data value */
    void        *udata;     /* opaque user data identifier */
    uint64_t    ext[4];     /* extensions */
};

EV_SET(kev, ident, filter, flags, fflags, data, udata);
```

## DESCRIPTION

The `kqueue()` system call provides a generic method of notifying the user when an event happens or a condition holds, based on the results of small pieces of kernel code termed filters.  
A kevent is identified by the (ident, filter) pair; there may only be one unique kevent per kqueue.

The `kqueue()` system call creates a new kernel event queue and returns a descriptor.  
The queue is not inherited by a child created with `fork(2)`. However, if `rfork(2)` is called without the RFFDG flag, then the descriptor table is shared, which will allow sharing of the kqueue between two processes.  
 The `kevent()` system call is used to register events with the queue, and return any pending events to the user.

The `EV_SET()` macro is provided for ease of initializing a `kevent` structure.

## libraries

OS-independent libraries with support for kqueue:

- libevent  
- libuv  
- libbrb_core  

### [libbrb_core](https://github.com/BrByte/brb_framework)

contains an abstraction for an event-oriented base, using kqueue on FreeBSD system.

On Linux you can use `libkqueue`.

### [libkqueue](https://github.com/mheily/libkqueue)

kqueue(2) compatibility library

A user space implementation of the kqueue(2) kernel event notification mechanism libkqueue acts as a translator between the kevent structure and the native kernel facilities on Linux, Android, Solaris, and Windows.

## demos

iOS: [A wrapper around kqueue to monitor changes to files](https://gist.github.com/nielsbot/5155671)  

[apple-ios-samples](https://github.com/robovm/apple-ios-samples) - [DirectoryWatcher.m](https://github.com/robovm/apple-ios-samples/blob/master/DocInteraction/Classes/DirectoryWatcher.m)  

macOS/iOS: [LightWeightRunLoop](https://github.com/wuyunfeng/LightWeightRunLoop-A-Reactor-Style-NSRunLoop)：A-Reactor-Style-NSRunLoop  

[CFFileDescriptor](https://developer.apple.com/documentation/corefoundation/cffiledescriptor?language=objc)  

> provides an opaque type to monitor file descriptors for read and write activity via CFRunLoop.  
> monitor kqueue file descriptors for read activity to find out when an event the kqueue is filtering for has occurred.  

### libevent

[kqueue-internal.h](https://github.com/libevent/libevent/blob/master/kqueue-internal.h)  
[kqueue.c](https://github.com/libevent/libevent/blob/master/kqueue.c)  

### libuv

[unix/kqueue.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/kqueue.c)  
[unix/stream.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/stream.c)  
[test/test-poll.c](https://github.com/libuv/libuv/blob/v1.x/test/test-poll.c)  

### nginx

nginx/src/event/

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h) - NGX_HAVE_KQUEUE  
[ngx_kqueue_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_kqueue_module.c)  

### mars

微信终端跨平台组件 Mars 早期针对 TARGET_OS_MAC 平台采用 kqueue/kevent 作为 I/O 多路复用器。

[socketselect.cc](https://github.com/Tencent/mars/blob/master/mars/comm/unix/socket/socketselect.cc)

## refs

[macOS 上的 epoll —— kqueue](https://zhuanlan.zhihu.com/p/21375144)  
[FreeBSD Kqueue 的实现原理](http://wangxuemin.github.io/2015/07/30/FreeBSD%20Kqueue%E7%9A%84%E5%AE%9E%E7%8E%B0%E5%8E%9F%E7%90%86/)  

[kqueue tutorial](https://wiki.netbsd.org/tutorials/kqueue_tutorial/)  
[How to write a TCP server with the kqueue API](https://jameshfisher.com/2016/12/18/tcp-server-kqueue.html)  
[Kernel Queues: An Alternative to File System Events](https://developer.apple.com/library/archive/documentation/Darwin/Conceptual/FSEvents_ProgGuide/KernelQueues/KernelQueues.html)  

[kqueue network & file example](https://gist.github.com/josephg/6c078a241b0e9e538ac04ef28be6e787)  
[Handling TCP Connections with Kqueue Event Notification](http://eradman.com/posts//kqueue-tcp.html)  

[Scalable Event Multiplexing: epoll vs. kqueue](http://people.eecs.berkeley.edu/~sangjin/2012/12/21/epoll-vs-kqueue.html)  
