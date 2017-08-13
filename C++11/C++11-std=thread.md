
## [C++ 11 STL | functional 标准库](http://www.sczyh30.com/posts/C-C/cpp-stl-functional/)
### Callable type
Callable type 指可以像调用函数一样被调用的对象或函数，包括：

- [std::function](http://www.jellythink.com/archives/771)  
- std::bind  
- std::result_of  
- std::thread  
- [std::call_once](http://blog.csdn.net/cywosp/article/details/8968655)  
- std::async  
- std::packaged_task  
- std::reference_wrapper  

### call_once & singleton
[面试中的Singleton](http://www.cnblogs.com/loveis715/archive/2012/07/18/2598409.html)  
[C++中单例模式到底该怎么写？](https://segmentfault.com/q/1010000000593968)  
[C++11及BOOST特性之一nocopyable，pthread_once和call_once](http://fpcfjf.blog.163.com/blog/static/5546979320131149331846/)  
[C++11中once_flag，call_once实现分析](http://blog.csdn.net/hengyunabc/article/details/33031465)  

### [C++11改进我们的程序之简化我们的程序](http://www.cnblogs.com/qicosmos/category/490693.html)

- （[五](http://www.cnblogs.com/qicosmos/p/3302144.html)）：bind 和 function  
- （[六](http://www.cnblogs.com/qicosmos/p/3304471.html)）：lamda  
- （[七](http://www.cnblogs.com/qicosmos/p/3318070.html)）：tuple  

## future & promise & async
[c++11新特性之 future](http://www.cnblogs.com/taiyang-li/p/5914167.html)  
[C++11新特性之 std::future and std::async](http://blog.csdn.net/wangshubo1989/article/details/49872199)  
[C++11多线程——<future>之std::promise学习](http://blog.csdn.net/u013507368/article/details/45112071)  
[C++11之std--future和std--promise](http://blog.csdn.net/aiwuzhi12/article/details/63685019)  

[Why using std::async from C++11?](http://stackoverflow.com/questions/17963172/why-using-stdasync-from-c11)  
[C++ async task](http://www.cnblogs.com/zhuyp1015/p/4020971.html)  
[用C++11的std::async代替线程的创建](http://www.cnblogs.com/qicosmos/p/3534211.html)  

future/promise 和 coroutine 简化异步编程。

## C++11 multithreading
[Start thread with member function](http://stackoverflow.com/questions/10673585/start-thread-with-member-function)  
[C++11 multithreading tutorial](https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/)  
[使用 C++11 编写 Linux 多线程程序](http://www.ibm.com/developerworks/cn/linux/1412_zhupx_thread/index.html)  
[C++ 11是如何封装Thread库的？](https://www.zhihu.com/question/30553807)  

## [C++11 并发指南系列](http://www.cnblogs.com/haippy/p/3284540.html)

- [C++11 并发指南一(C++11 多线程初探)](http://www.cnblogs.com/haippy/p/3235560.html)  
- [C++11 并发指南二(std::thread 详解)](http://www.cnblogs.com/haippy/p/3236136.html)  
- C++11 并发指南三：[std::mutex 详解](http://www.cnblogs.com/haippy/p/3237213.html)   [Lock 详解](http://www.cnblogs.com/haippy/p/3346477.html)  
- C++11 并发指南四(future)  
	- [详解一 std::promise 介绍](http://www.cnblogs.com/haippy/p/3239248.html)   
	- [详解二 std::packaged_task 介绍)](http://www.cnblogs.com/haippy/p/3279565.html)  
	- [详解三 std::future & std::shared_future](http://www.cnblogs.com/haippy/p/3280643.html)  
- [C++11 并发指南五(std::condition_variable 详解)](http://www.cnblogs.com/haippy/p/3252041.html)  
- C++11 并发指南六(atomic)  
	- [类型详解一 atomic_flag 介绍](http://www.cnblogs.com/haippy/p/3252056.html)  
	- [类型详解二 std::atomic](http://www.cnblogs.com/haippy/p/3301408.html) [(续)](http://www.cnblogs.com/haippy/p/3304556.html)  
	- [类型详解四 C 风格原子操作介绍](http://www.cnblogs.com/haippy/p/3306625.html)  
- [C++11 并发指南七(C++11 内存模型一：介绍)](http://www.cnblogs.com/haippy/p/3412858.html)  
- [C++11 并发指南九(综合运用: C++11 多线程下生产者消费者模型详解)](http://www.cnblogs.com/haippy/p/3252092.html)  

## [C++并发实战](http://blog.csdn.net/liuxuejiang158/article/category/1774739)
[C++并发实战1：thread object](http://blog.csdn.net/liuxuejiang158blog/article/details/17025577)  
[C++并发实战2：thread::join和thread::detach](http://blog.csdn.net/liuxuejiang158blog/article/details/17068723)  
[C++并发实战3：向thread传递参数](http://blog.csdn.net/liuxuejiang158blog/article/details/17090971)  
[C++并发实战4：thread object is movable,not copyable](http://blog.csdn.net/liuxuejiang158blog/article/details/17096261)  
[C++并发实战5：并行化的std::accumulate](http://blog.csdn.net/liuxuejiang158blog/article/details/17118649)  
[C++并发实战6：thread::id](http://blog.csdn.net/liuxuejiang158blog/article/details/17121253)  
[C++并发实战7：thread::mutex](http://blog.csdn.net/liuxuejiang158blog/article/details/17144485)  
[C++并发实战8：deadlock](http://blog.csdn.net/liuxuejiang158blog/article/details/17241387)  
[C++并发实战11：条件变量](http://blog.csdn.net/liuxuejiang158blog/article/details/17297135)  
[C++并发实战12：线程安全的queue](http://blog.csdn.net/liuxuejiang158blog/article/details/17301739)  
[C++并发实战13：std::future、std::async、std::promise、std::packaged_task](http://blog.csdn.net/liuxuejiang158blog/article/details/17354115)  
[C++并发实战16：std::atomic原子操作](http://blog.csdn.net/liuxuejiang158blog/article/details/17413149)  
[C++并发实战17：线程安全的stack和queue](http://blog.csdn.net/liuxuejiang158blog/article/details/17523477)  