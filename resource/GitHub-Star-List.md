## 开源库
[自己项目中常用开源库](http://blog.csdn.net/gyz413977349/article/details/44832739)

[推荐的c/c++开源库](http://blog.csdn.net/v2x222/article/details/42496803)  
[值得推荐的开源C/C++框架和库](http://www.cnblogs.com/lidabo/p/5514155.html)

[Objective-C 常用开发库索引](http://www.cnblogs.com/lingzhao/p/3477641.html)

[Github-iOS备忘](http://github.ibireme.com/github/list/ios/)

[GitHub上最火的40个iOS开源项目（一）](http://www.open-open.com/lib/view/open1388317004500.html)

### [iOS-Runtime-Headers](https://github.com/nst/iOS-Runtime-Headers)
Dynamically Generated iOS Headers（运行时导出的所有的 Objective-C 的头文件）

iOS8.4 及之前的头文件 私有及共有API

## ToolKits
### [Underscore](https://github.com/EkoCommunications/Underscore)
a functional toolbelt for Objective-C

### [FormatterKit](https://github.com/mattt/FormatterKit)
`FormatterKit` is a collection of well-crafted `NSFormatter` subclasses for things like units of information, distance, and relative time intervals.

### [EKAlgorithms](https://github.com/EvgenyKarkan/EKAlgorithms)
EKAlgorithms contains some well known CS algorithms & data structures.

### [KVOController](https://github.com/facebook/KVOController)

### [OmniGroup](https://github.com/omnigroup/OmniGroup)

## Reachability
### [Reachability]([Reachability](https://github.com/tonymillion/Reachability))

### [SDReachability](https://github.com/rs/SDReachability)

## Networking
### [CocoaAsyncSocket](https://github.com/robbiehanson/CocoaAsyncSocket)
CocoaAsyncSocket provides easy-to-use and powerful asynchronous socket libraries for Mac and iOS. The classes are described below.

#### TCP
**`GCDAsyncSocket`** is a TCP/IP socket networking library built atop _Grand Central Dispatch_. Here are the key features available:

#### UDP
**`GCDAsyncUdpSocket`** is a UDP/IP socket networking library built atop _Grand Central Dispatch_. Here are the key features available:

### [CocoaHTTPServer](https://github.com/robbiehanson/CocoaHTTPServer)
A small, lightweight, embeddable HTTP server for Mac OS X or iOS applications

#### [RoutingHTTPServer](https://github.com/mattstevens/RoutingHTTPServer)
Adds a Sinatra-inspired routing API on top of CocoaHTTPServer.

### [STHTTPRequest](https://github.com/nst/STHTTPRequest)
A NSURLSession wrapper for humans

### [asi-http-request](https://github.com/pokeb/asi-http-request)
ASIHTTPRequest is an easy to use wrapper around the **CFNetwork API** that makes some of the more tedious aspects of communicating with web servers easier. It is written in Objective-C and works in both Mac OS X and iPhone applications.

It is suitable performing basic HTTP requests and interacting with REST-based services (GET / POST / PUT / DELETE). The included ASIFormDataRequest subclass makes it easy to submit POST data and files using multipart/form-data.

最近一次更新是在 3 years ago。

`-[URLDownRequst downloadFilePart]` 原来基于 ASIHTTPRequest，现改造基于 QQHttpClient 和 QQHttpClientSession 实现。

```obj-c
@interface QQHttpClientSession : AFHTTPRequestOperation
```

### [AFNetworking](https://github.com/AFNetworking/AFNetworking)
A delightful networking framework for iOS, OS X, watchOS, and tvOS.

AFNetworking is a delightful networking library for iOS and Mac OS X. It's built on top of the [**Foundation URL Loading System**](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/URLLoadingSystem.html), extending the powerful high-level networking abstractions built into Cocoa. It has a modular architecture with well-designed, feature-rich APIs that are a joy to use.

#### [RestKit](https://github.com/RestKit/RestKit)
RestKit is a modern Objective-C framework for implementing RESTful web services clients on iOS and Mac OS X. It provides a powerful object mapping engine that seamlessly integrates with Core Data and a simple set of networking primitives for mapping HTTP requests and responses built on top of [_**AFNetworking**_](https://github.com/AFNetworking/AFNetworking). It has an elegant, carefully designed set of APIs that make accessing and modeling RESTful resources feel almost magical. 

#### References
[AFNetWorking的实现分析以及简单使用](http://www.cnblogs.com/xukunhenchouchang/p/4593586.html)  
[AFNetWorking的实现原理](http://blog.csdn.net/lcg910978041/article/details/51485062)  
[AFNetworking源码分析](http://www.jianshu.com/p/8eac5b1975de)  

[较老版本 AFNetworking 使用心得](http://www.cnblogs.com/YouXianMing/p/3568947.html)  
[AFNetworking3.0版本之前和之后的一些变化](http://blog.csdn.net/hannibal_zj/article/details/52216213)  
[AFNetworking 新版本3.0的迁移](http://www.cnblogs.com/fengmin/p/5507692.html)  
[AFNetworking 3.0迁移指南](http://www.jianshu.com/p/047463a7ce9b)  

#### AFNetworking vs ASIHTTPRequest
[对比iOS网络组件：AFNetworking VS ASIHTTPRequest](http://www.infoq.com/cn/articles/afn_vs_asi)  
[iOS开发:AFNetworking和ASIHTTPRequest的比较](http://www.cocoachina.com/bbs/read.php?tid-293699-page-e-fpage-583.html)  

同样是发起一个最普通的异步请求，使用AFN只需要调用一个静态方法，但代码可读性较差；而ASI的示例看起来更清晰，但需要调用多个实例方法才能完成一次请求。  
AFN的设计更加**工程化**，或者说对使用者更友好；而ASI的设计更经典，典型的OOP（Object Oriented Programming）。  

ASI是基于CFHTTP开发的一个组件；而AFN的基础——**NSURL**，也是基于  **CFNetwork** 开发的。
也就是说ASI相比AFN更加底层，这就从一定程度上造成二者的性能差距。

@img ![AFN&ASI](http://cdn3.infoqstatic.com/statics_s2_20170530-0600u1/resource/articles/afn_vs_asi/zh/resources/image018.gif)

ASI 的直接操作对象 ASIHTTPRequest 是 NSOperation 的子类，实现了 NSCopying 协议。  
在异步请求的处理上，ASIHTTPRequest 对象初始化结束后，在  startAsynchronous 方法中把对象加入共享操作队列。  

AFN 的直接操作对象 AFHTTPClient 不同于 ASI，是一个实现了 NSCoding 和 NSCopying 协议的 NSObject 子类。  
AFHTTPClient 是一个封装了一系列操作方法的“工具类”，处理请求的操作类是一系列单独的，基于 NSOperation 封装的，AFURLConnectionOperation 的子类。

从实现方式可以看出，ASI 显得更加底层，并没有过多使用 Cocoa 框架中已经封装的 API；而 AFN 则更加实用主义，逻辑简单清晰，大量使用了框架API。

[AFNetworking、MKNetworkKit和ASIHTTPRequest对比](http://www.cocoachina.com/bbs/read.php?tid=145456)

### [MKNetworkKit](https://github.com/MugunthKumar/MKNetworkKit)
Modern NSURLSession based Networking Framework with built in authentication and HTTP 1.1 caching standards support for iOS 8+ devices

支持 ARC，有 ASIHTTPRequest 的功能，AFNetWorking 的轻便。

这里给个解决用 MKNetworkKit 断点续传和 progress 问题地址：  
https://github.com/iiiyu/SIDownloader

### [peertalk](https://github.com/rsms/peertalk)
[PeerTalk, BeagleBone, and Raspberry Pi](http://www.eeboard.com/bbs/thread-13114-1-1.html)  
[Peertalk - 通过USB和TCP进行通信的iOS与OS X Cocoa库](http://www.open-open.com/lib/view/open1344867648631.html)  

### [socket.IO-objc](https://github.com/pkyeck/socket.IO-objc)
Interface to communicate between Objective C and Socket.IO with the help of websockets or [Long-Polling](http://en.wikipedia.org/wiki/Push_technology#Long_polling). Originally based on fpotter's [socketio-cocoa]([socketio-cocoa](https://github.com/fpotter/socketio-cocoa)) it uses other libraries/classes like

## RequestQueue
### [RequestQueue](https://github.com/nicklockwood/RequestQueue)

### [JJAFAcceleratedDownloadRequestOperation](https://github.com/jnjosh/JJAFAcceleratedDownloadRequestOperation)
