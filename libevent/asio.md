## [Asio](http://think-async.com/)

https://github.com/chriskohlhoff/asio

Asio C++ Library：用于网络和底层I/O编程的跨平台的C++库。

Asio is a cross-platform C++ library for network and low-level I/O programming that provides developers with a consistent asynchronous model using a modern C++ approach.

**Supported Platforms**

The following platform and compiler combinations are regularly tested:

- Linux using g++ 4.1 or later  
- Linux using clang 3.2 or later  
- FreeBSD using g++ 4.1 or later  
- macOS using Xcode 8 or later  
- Win32 using Visual C++ 9.0 or later  
- Win32 using g++ 4.1 or later (MinGW)  
- Win64 using Visual C++ 9.0 or later  

![Asio-Framework](https://think-async.com/Asio/overview.gif)

> Asio 被放入 Boost 锻炼了十余年后，终于在 2017 年进入了 C++ 标准。

## docs

[asio C++ library](http://think-async.com/Asio/asio-1.12.2/doc/) - [Using Asio](http://think-async.com/Asio/asio-1.12.2/doc/asio/using.html)  
[Boost.Asio](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html) - [Using Boost.Asio](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/using.html)  

[Using Asio with C++11](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3388.pdf)  
[boost-asio-cpp-network-programming-in-chinese](https://github.com/mmoaay/boost-asio-cpp-network-programming-in-chinese)  
w3cschool - [Boost.Asio 网络编程](https://m.w3cschool.cn/nlzbw/nlzbw-mr5h25y6.html)  

所有的 asio 类都只要包含头文件：`asio.hpp`

## refs

Proactor 模式需要一个 loop，asio 将其封装为 `io_service`。它不仅是 asio 的核心，更是一切基于 asio 设计的程序的核心。

### [avplayer.org](https://bbs.avplayer.org/)

[Asio 讲座](https://bbs.avplayer.org/t/asio/245)  
[Boost.Asio 作为线程池库](https://bbs.avplayer.org/t/topic/492)  
[asio 协程的思维转变](https://bbs.avplayer.org/t/asio/499) & [asio 与协程](https://microcai.org/2013/04/22/asio-statemachine.html) & [asio 协程详解](https://bbs.avplayer.org/t/asio/771)  
[请问 asio 怎么样正确关闭 socket连接?](https://bbs.avplayer.org/t/asio-socket/754)  

### [microcai.org](https://microcai.org/)

那些年我们追过的网络库：

- [Part I - ACE to libuv](https://microcai.org/2015/09/14/history-of-network-libraries-part-one.html)  
- [PartII - ASIO 腾空出世](https://microcai.org/2015/09/18/history-of-network-libraries-part-two.html)  

### analysis

[ASIO攻破](http://www.cppblog.com/shanoa/archive/2009/06/26/88606.html)  
[Asio实现浅析](https://zhuanlan.zhihu.com/p/55503053)  
[boost.asio 学习笔记](https://www.zybuluo.com/khan-lau/note/307144)  

[boost asio 应用方法学](https://blog.csdn.net/luansxx/article/category/1209890) 系列  
[【boost学习】之 boost::asio](https://blog.csdn.net/yockie/article/category/1405118) 系列  
[ Boost.Asio C++ 网络编程](https://blog.csdn.net/caoshangpa/article/category/7438478) 系列  

### alternative

[Is there efficient alternative to ASIO?](https://www.reddit.com/r/cpp/comments/5s8s2f/is_there_efficient_alternative_to_asio/) - [ZeroMQ](http://zeromq.org/)  & [Nanomsg](https://nanomsg.org/index.html)？

## libs

[beast](https://github.com/boostorg/beast)：HTTP and WebSocket built on Boost.Asio in C++11  

[networking-ts-impl](https://github.com/chriskohlhoff/networking-ts-impl)  

> [如何评价 Christopher Kohlhoff 实验性的 C++ Network 标准库 ？](https://www.zhihu.com/question/57773932)

[avhttp](https://github.com/avplayer/avhttp): concurrent http downloader based on Boost.Asio  

> avhttp - [支持异步、并发、续传的 HTTP 下载器](https://blog.csdn.net/liuhhaiffeng/article/details/52366143)  

## demos

[Socket Programming in C++ using boost.asio: TCP Server and Client](https://www.codeproject.com/Articles/1264257/Socket-Programming-in-Cplusplus-using-boost-asio-T)  
