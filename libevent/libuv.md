## [异步事件循环](http://www.cnblogs.com/lidabo/p/5514155.html)

[Asio](http://think-async.com/)：用于网络和底层I/O编程的跨平台的C++库。  
[libevent](http://libevent.org/) ：事件通知库  
[libev](http://libev.schmorp.de/) ：功能齐全，高性能的时间循环，轻微地仿效libevent，但是不再像libevent一样有局限性，也修复了它的一些bug。  
[libuv](https://github.com/libuv/libuv) ：[Cross-platform asynchronous I/O](http://libuv.org/)（跨平台异步I/O）。  

## [libuv中文教程](http://luohaha.github.io/Chinese-uvbook/source/introduction.html)
Background

node.js最初开始于2009年，是一个可以让Javascript代码离开浏览器的执行环境也可以执行的项目。

node.js使用了Google的V8解析引擎和Marc Lehmann的libev。Node.js将事件驱动的I/O模型与适合该模型的编程语言(Javascript)融合在了一起。随着node.js的日益流行，node.js需要同时支持windows, 但是libev只能在Unix环境下运行。Windows 平台上与kqueue(FreeBSD)或者(e)poll(Linux)等内核事件通知相应的机制是IOCP。

libuv提供了一个跨平台的抽象，由平台决定使用libev或IOCP。在node-v0.9.0版本中，libuv移除了libev的内容。

随着libuv的日益成熟，它成为了拥有卓越性能的系统编程库。除了node.js以外，包括Mozilla的Rust编程语言，和许多的语言都开始使用libuv。

## [libuv 初窥](http://blog.codingnow.com/2012/01/libuv.html)
[libuv API documentation](http://docs.libuv.org/en/v1.x/)

[libuv的源码分析(1)](http://www.cnblogs.com/watercoldyi/p/5675180.html)

[libuv库学习笔记（1）](http://blog.csdn.net/paohui0134/article/details/51636618)

[利用libuv编写异步多线程的addon实例](https://cnodejs.org/topic/519ceb5263e9f8a542c19764)

[libuv移植到ios](http://www.aichengxu.com/ios/5415195.htm)  [iOS 编译 libuv 资料](http://www.jianshu.com/p/dfce640e4d1c)  

[征服优雅、高效的Libuv库之初识篇](http://www.jianshu.com/p/98eb18ed6149)

**Nodejs事件引擎libuv源码剖析**：

	[高效队列（queue）的实现](http://www.cnblogs.com/chenyangyao/p/libuv.html)  
	[高效线程池(threadpool)的实现](http://www.cnblogs.com/chenyangyao/p/libuv_threadpool.html)  
	[句柄(handle)结构的设计剖析](http://www.cnblogs.com/chenyangyao/p/libuv_handle.html)  
	[请求(request)结构的设计剖析](http://www.cnblogs.com/chenyangyao/p/libuv_req.html)  

[使用 libevent 和 libev 提高网络应用性能——I/O模型演进变化史](http://blog.csdn.net/hguisu/article/details/38638183)
