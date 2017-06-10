## 官方指南
[Multithreading and Grand Central Dispatch on iOS for Beginners Tutorial](https://www.raywenderlich.com/4295/multithreading-and-grand-central-dispatch-on-ios-for-beginners-tutorial)  
[Guides and Sample Code](https://developer.apple.com/library/content/navigation/):  [Threading Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Multithreading/Introduction/Introduction.html#//apple_ref/doc/uid/10000057i-CH1-SW1)  

You set up your code so that a particular data structure is **only** accessed by code running within a particular dispatch queue. Then since dispatch queues run blocks **serially**, you’re guaranteed that only one will access the data structure *at a time*.

**NSOperations** are simply an API *built on top of* **Grand Central Dispatch**. So when you’re using NSOperations, you’re really still using Grand Central Dispatch.

It’s just that NSOperations give you some fancy features that you might like. You can make some operations **dependent** on other operations, **reorder** queues after you sumbit items, and other things like that.

## NSThread
[iOS多线程编程之NSThread的使用](http://blog.csdn.net/totogo2010/article/details/8010231)  
[iOS 多线程编程之锁](https://tech.45eggs.com/ios/2013/ios-multithread-locker.html)  

## 参考
我是一个线程：[jianshu](http://www.jianshu.com/p/c1be86e4cbe5)  [cnblogs](http://kb.cnblogs.com/page/542462/)
[iOS 并发编程指南](http://www.cocoachina.com/bbs/read.php?tid=86050)  

[并发编程：API 及挑战](http://objccn.io/issue-2-1/)  
[OS X 和 iOS 中的多线程技术](http://www.infoq.com/cn/articles/os-x-ios-multithread-technology)  

[关于iOS多线程，你看我就够了](http://www.jianshu.com/p/0b0d9b1f1f19)

[GCD使用经验与技巧浅谈](http://tutuge.me/2015/04/03/something-about-gcd/)  
[NSOperation v.s GCD](http://zhangbuhuai.com/nsoperation-vs-gcd/)  
[IOS应用架构思考一（网络层）](https://blog.cnbluebox.com/blog/2015/05/07/architecture-ios-1/)  
[深度优化iOS网络模块](http://mrpeak.cn/blog/ios-network/)  

[iOS 并发编程之 Operation Queues](http://blog.leichunfeng.com/blog/2015/07/29/ios-concurrency-programming-operation-queues/)  
[并发编程之Operation Queue和GCD](http://www.cocoachina.com/industry/20131210/7506.html)  
[iOS并发编程中Operation与Dispatch Queues实践](http://geek.csdn.net/news/detail/63001)  
