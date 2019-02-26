
linux - [EPOLL(7)](http://man7.org/linux/man-pages/man7/epoll.7.html)  
debian/Ubuntu - [EPOLL(7)](https://manpages.debian.org/stretch/manpages/epoll.7.en.html)  

## SYNOPSIS

**API**:

`epoll_create`, `epoll_create1` - open an epoll file descriptor  
`epoll_ctl` - control interface for an epoll file descriptor  
`epoll_wait`, `epoll_pwait` - wait for an I/O event on an epoll file descriptor  

**SYNOPSIS**:

```c
#include <sys/epoll.h>

int epoll_create(int size);
int epoll_create1(int flags);

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

int epoll_wait(int epfd, struct epoll_event *events,
              int maxevents, int timeout);
int epoll_pwait(int epfd, struct epoll_event *events,
              int maxevents, int timeout,
              const sigset_t *sigmask);
```

## refs

[epoll 或者 kqueue 的原理是什么？](https://www.zhihu.com/question/20122137/answer/14049112)  

[epoll 前戏](http://www.cnblogs.com/zhanzhao/p/5481169.html) / [epoll 笔记](https://my.oschina.net/pthread/blog/37711)  

[epoll 模型详解](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4232252)  
[linux 中的 epoll 机制](https://blog.csdn.net/zhaozhanyong/article/details/5410887)  
[epoll 的理解和深入分析](https://blog.csdn.net/apacat/article/details/51375950)  
[高并发网络编程之 epoll 详解](https://blog.csdn.net/shenya1314/article/details/73691088)  

[Linux epoll 实现机制源码剖析](https://blog.csdn.net/tgxallen/article/details/78086360)  
[Linux 内核 EPOLL 实现原理分析](http://www.valleytalk.org/2012/08/05/epoll-linux%E5%86%85%E6%A0%B8%E6%BA%90%E4%BB%A3%E7%A0%81%E5%AE%9E%E7%8E%B0%E5%8E%9F%E7%90%86%E5%88%86%E6%9E%90/)  
[linux 下 epoll 如何实现高效处理](http://www.cnblogs.com/debian/archive/2012/02/16/2354469.html)  

[epoll 使用详解](http://www.cnblogs.com/haippy/archive/2012/01/09/2317269.html)  
[epoll 机制用法详解](https://blog.csdn.net/rock_joker/article/details/76735333)  
彻底学会使用epoll [一](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4273856)  [二](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4285054)  [三](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4288802) [四](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4296180) [五](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4308612) [六](http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=28541347&id=4324338)  

## libraries

### libevent

[epoll.c](https://github.com/libevent/libevent/blob/master/epoll.c)  
[epoll_sub.c](https://github.com/libevent/libevent/blob/master/epoll_sub.c)  
[epolltable-internal.h](https://github.com/libevent/libevent/blob/master/epolltable-internal.h)  

### libuv

[unix/linux-core.c](https://github.com/libuv/libuv/blob/v1.x/src/unix/linux-core.c)  
[test/test-poll.c](https://github.com/libuv/libuv/blob/v1.x/test/test-poll.c)  
[test/test-embed.c](https://github.com/libuv/libuv/blob/v1.x/test/test-embed.c)  

### nginx

nginx/src/event/

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h) - NGX_HAVE_EPOLL  
[ngx_epoll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_epoll_module.c)  

### [muduo](https://github.com/chenshuo/muduo)

[EPollPoller.cc](https://github.com/chenshuo/muduo/blob/master/muduo/net/poller/EPollPoller.cc)  
