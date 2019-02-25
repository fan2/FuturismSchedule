## [异步事件循环](http://www.cnblogs.com/lidabo/p/5514155.html)

异步事件通知机制（Asynchronous Event Notification，AEN）就是根据发生的事件，调用相应的回调函数进行处理。

- 事件（Event）：事件是异步事件通知机制的核心，比如fd事件、超时事件、信号事件、定时器事件。

	> 有时候也称事件为事件处理器（EventHandler），这个名称更形象，因为 Handler 本身表示了包含处理所需数据（或数据的地址）和处理的方法（回调函数），更像是面向对象思想中的称谓。  

- 事件循环（EventLoop）：用于管理事件，包括添加/移除事件、等待和分发事件。  

异步事件库本质上是提供异步事件通知机制的实现。

- `libevent`：名气最大，应用最广泛，历史悠久的跨平台事件库；  
- `libev`：较 libevent 而言，设计更简练，性能更好，但对 Windows 支持不够好；  
- `libuv`：开发 node 的过程中需要一个跨平台的事件库，他们首选了 libev；但又要支持 Windows，故重新封装了一套：linux 下用 libev 实现，Windows 下用 IOCP 实现；  

## [libevent](http://libevent.org/)

libevent – an event notification library

https://github.com/libevent/libevent

The *libevent* API provides a mechanism to execute a callback function when a specific event occurs on a file descriptor or after a timeout has been reached. Furthermore, *libevent* also support callbacks due to **signals** or regular **timeouts**.  
*libevent* is meant to replace the event loop found in event driven network servers. An application just needs to call `event_dispatch()` and then *add* or *remove* events dynamically without having to change the event loop.  

Currently, libevent supports `/dev/poll`, `kqueue(2)`, `event ports`, `POSIX select(2)`, `Windows select()`, `poll(2)`, and `epoll(4)`.

The internal event mechanism is completely independent of the exposed event API, and a simple update of libevent can provide new functionality without having to redesign the applications.

documentation: [Programming with Libevent](http://www.wangafu.net/~nickm/libevent-book/)

### libeventInterface

[**libeventInterface**](https://github.com/xuwening/libeventInterface)：C++实现，对libevent库二次开发，解决libevent和自有服务融合问题。

### gevent

[gevent](http://gevent.org) is a coroutine-based Python networking library that uses [greenlet](https://greenlet.readthedocs.io/) to provide a high-level synchronous API on top of the libev or libuv event loop.

[Event Loop Implementations: libuv and libev](http://www.gevent.org/loop_impls.html#event-loop-implementations-libuv-and-libev)  

### refs

caoshangpa - [libevent 学习笔记](https://blog.csdn.net/caoshangpa/article/category/6460835)  

[libevent 源码深度剖析](https://blog.csdn.net/sparkliang/article/category/660506) - [PDF](https://blog.csdn.net/sparkliang/article/details/5202394) @[腾讯云](https://cloud.tencent.com/developer/article/1165034)  

## [libev](http://libev.schmorp.de/)

libev - a high performance full-featured event loop written in C, loosely modelled after libevent

[libev-4.22](https://github.com/enki/libev) & [latest-sync](https://github.com/kindy/libev)

功能齐全，高性能的时间循环，轻微地仿效libevent，但是不再像libevent一样有局限性，也修复了它的一些bug。  

只是封装了 Event Library，需自行进行 I/O 读写和回调。

documentation: [metacpan](https://metacpan.org/pod/distribution/EV/libev/ev.pod)

### design philosophy

Marc Lehmann: [What's the difference between libev and libevent?](https://stackoverflow.com/questions/9433864/whats-the-difference-between-libev-and-libevent)  

So in short, libev tries to do one thing **only** (POSIX event library), and this in the most efficient way possible. Libevent tries to give you the **full** solution (event lib, non-blocking I/O library, http server, DNS client).

Or, even shorter, libev tries to follow the UNIX toolbox philosophy of doing one thing only, as good as possible.

Libev can be small and efficient, but you also need to look elsewhere for an http library, because libev simply doesn't have one.
There is a very related library called `libeio` that does asynchronous I/O, which can be used independently or together with libev, so you can mix and match.

### [libeio](http://software.schmorp.de/pkg/libeio.html)

AIO library

https://github.com/kindy/libeio

### refs

[网络服务器事件循环框架 libev](https://blog.csdn.net/tgxallen/article/details/79575227)

## [libuv](http://libuv.org/)

libuv - a multi-platform support library with a focus on asynchronous I/O.

https://github.com/libuv/libuv

跨平台异步I/O库（Cross-platform asynchronous I/O]）。

libuv API documentation: http://docs.libuv.org/

* [LXJS 2012 talk](http://www.youtube.com/watch?v=nGn60vDSxQ4) — High-level introductory talk about libuv.  
* [libuv-dox](https://github.com/thlorenz/libuv-dox) — Documenting types and methods of libuv, mostly by reading `uv.h`.  
* [learnuv](https://github.com/thlorenz/learnuv) — Learn uv for fun and profit, a self guided workshop to libuv.  

### 发展历史

滥觞于 2009 年的 Node.js 是一个可以让 Javascript 代码离开浏览器的执行环境也可以执行的项目。  
Node.js 基于 Google 的 V8 解析引擎和 Marc Lehmann 的 libev 实现，将事件驱动的 I/O 模型与适合该模型的编程语言(Javascript)融合在了一起。  
随着 Node.js 的日益流行，它需要同时支持 Windows，但是 libev 只能在 Unix 环境下运行。Windows 平台上与 kqueue(FreeBSD) 或者 (e)poll(Linux) 等内核事件通知相应的机制是 IOCP，因此 libuv 提供了一个跨平台的抽象，由平台决定使用 libev 或 IOCP。  

在 Node-v0.9.0版本中，libuv 移除了 libev 的内容。随着 libuv 的日益成熟，它成为了拥有卓越性能的系统编程库。除了 Node.js 以外，包括 Mozilla 的 Rust 编程语言和许多其他语言都开始使用 libuv。

### [中文教程](http://luohaha.github.io/Chinese-uvbook/source/introduction.html)

[libuv 初窥](http://blog.codingnow.com/2012/01/libuv.html)

[libuv的源码分析(1)](http://www.cnblogs.com/watercoldyi/p/5675180.html)

[libuv库学习笔记（1）](http://blog.csdn.net/paohui0134/article/details/51636618)

[libuv移植到ios](http://www.aichengxu.com/ios/5415195.htm)  [iOS 编译 libuv 资料](http://www.jianshu.com/p/dfce640e4d1c)  

[征服优雅、高效的Libuv库之初识篇](http://www.jianshu.com/p/98eb18ed6149)

**Nodejs事件引擎libuv源码剖析**：

- [高效队列（queue）的实现](http://www.cnblogs.com/chenyangyao/p/libuv.html)  
- [高效线程池(threadpool)的实现](http://www.cnblogs.com/chenyangyao/p/libuv_threadpool.html)  
- [句柄(handle)结构的设计剖析](http://www.cnblogs.com/chenyangyao/p/libuv_handle.html)  
- [请求(request)结构的设计剖析](http://www.cnblogs.com/chenyangyao/p/libuv_req.html)  

### 应用示例

[利用libuv编写异步多线程的addon实例](https://cnodejs.org/topic/519ceb5263e9f8a542c19764)  

[libuv 高并发异步使用](https://blog.csdn.net/xcw_1987/article/details/79977726)  

基于libuv的TCP设计：[（一）](https://www.cnblogs.com/wqvbjhc/p/3757582.html)、[（二）](https://www.cnblogs.com/wqvbjhc/p/3758141.html)、[（三）](https://www.cnblogs.com/wqvbjhc/p/4175469.html)  
