
## 指南
UNIX ® is a registered Trademark of The Open Group.
POSIX ® is a registered Trademark of The IEEE.

[pthreads(7) - Linux man page](https://linux.die.net/man/7/pthreads)  
[System Interfaces: Detailed ToC](http://pubs.opengroup.org/onlinepubs/9699919799/functions/contents.html)  
	2.9 Threads
[IBM e(logo)server iSeries Information Center](http://publib.boulder.ibm.com/iseries/v5r2/ic2924/index_acc.htm)  
	[POSIX thread APIs](http://publib.boulder.ibm.com/iseries/v5r2/ic2924/index.htm?info/apis/rzah4mst.htm)  [Pthread APIs](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_71/apis/rzah4mst.htm)  
[General Programming Concepts: Writing and Debugging Programs](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/mastertoc.htm)  
	[Understanding Threads and Processes](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/understanding_threads.htm)  
	[Multi-Threaded Programming](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/threads_prg.htm)  
[DMOZ - Computers Programming Threads POSIX](http://www.dmoz.org/Computers/Programming/Threads/POSIX/)  
[MTU - Multithreaded Programming with ThreadMentor: A Tutorial](http://www.cs.mtu.edu/~shene/NSF-3/e-Book/index.html)  
[POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/) / [Pthread：POSIX 多线程程序设计](http://www.cnblogs.com/mywolrd/archive/2009/02/05/1930707.html)  

[编程思想之多线程与多进程(1)——以操作系统的角度述说线程与进程](http://blog.csdn.net/luoweifu/article/details/46595285)  
[编程思想之多线程与多进程(4)——C++中的多线程](http://blog.csdn.net/luoweifu/article/details/46835437)

## 基础
[pthread编程基础](http://blog.chinaunix.net/uid-20528014-id-333508.html)  
	mutex 是 MUTual EXclusion 的缩写

[pthreads 的基本用法](https://www.ibm.com/developerworks/cn/linux/l-pthred/)  
[POSIX 线程详解](http://www.ibm.com/developerworks/cn/linux/thread/posix_thread1/index.html)  
Posix线程编程指南([1](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part1/index.html))([2](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part2/index.html))([3](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part3/index.html))([4](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part4/index.html))([5](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part5/index.html))

mybelief321 CSDN 专栏

- [Linux多线程编程(一)---多线程基本编程](http://blog.csdn.net/mybelief321/article/details/9377379)  
- [Linux多线程编程(二)---线程之间的同步与互斥](http://blog.csdn.net/mybelief321/article/details/9390707)  
- [Linux多线程编程(三)---线程之间的同步与互斥进阶实验](http://blog.csdn.net/mybelief321/article/details/9395799)  

Javadino CSDN 专栏

- [[Pthread] Linux上程序调试的基石(一)--ptrace](http://blog.csdn.net/javadino/article/details/2891413)  
- [[Pthread] Linux程序调试的基石(二)--Inside GDB](http://blog.csdn.net/javadino/article/details/2891434)  

- [[Pthread] Linux中的线程同步机制(一) -- Futex](http://blog.csdn.net/javadino/article/details/2891385)  
- [[Pthread] Linux中的线程同步机制(二)--In Glibc](http://blog.csdn.net/javadino/article/details/2891388)  
- [[Pthread] Linux中的线程同步机制(三)--Practice](http://blog.csdn.net/javadino/article/details/2891399)  

## 同步
[Basic Concept of MUTEX](http://www.cs.mtu.edu/~shene/NSF-3/e-Book/MUTEX/locks.html)  

[pthread的各种同步机制](http://casatwy.com/pthreadde-ge-chong-tong-bu-ji-zhi.html)  
[使用 System V Semaphores API 实现 POSIX Semaphore API](http://www.ibm.com/developerworks/cn/linux/l-semaphore/)

## 其他
[[Pthread] Linux上获得线程Id的方法](http://blog.csdn.net/javadino/article/details/2891364)  
[使用 C++11 编写 Linux 多线程程序](http://www.ibm.com/developerworks/cn/linux/1412_zhupx_thread/index.html)  
[C++11 多线程初探](http://www.cnblogs.com/haippy/p/3235560.html)  

## KM
[pthread线程使用小结](http://km.oa.com/articles/show/80841?kmref=search&from_page=1&no=1)

- for 循环参数传递 pthread_create 参数的时延问题。
- pthread_mutex_t / pthread_cond_t初始化/释放。

[pthread线程同步总结](http://km.oa.com/articles/show/211704?kmref=search&from_page=1&no=3)

[pthread_join实现原理](http://km.oa.com/articles/show/206566)  
[错误使用线程函数pthread_join的总结](http://km.oa.com/group/18916/articles/show/145472?kmref=search&from_page=1&no=9)  

[一个所有安卓app都会发生的crash分析](http://km.oa.com/articles/show/287114)  
[拯救安卓枯竭的资源pthread_key_t——正确使用C++运行时库](http://km.oa.com/group/18474/articles/show/290236)  

《[多核编程基础：pthread、原子操作、锁无关数据结构](http://km.oa.com/group/2068/event/10645)》

[类成员函数作为pthread_create函数参数](http://km.oa.com/articles/show/172235?kmref=search&from_page=1&no=10)

[线程中的gettid和pthread_self区别](http://km.oa.com/group/19135/articles/show/157574)

[与windows中的Sleep(0)等价的pthread_yield](http://km.oa.com/articles/show/59102)

[后台Server常见的设计模式 - 兼顾可读性和性能](http://km.oa.com/articles/show/175883)
