
UNIX ® is a registered Trademark of The Open Group.  
POSIX ® is a registered Trademark of The IEEE.  

## manuals

Linux man pages: [man7](http://man7.org/linux/man-pages/index.html), [die.net](https://linux.die.net/man/)  

Linux Programmer's Manual - [PTHREADS(7)](http://man7.org/linux/man-pages/man7/pthreads.7.html)  
iOS Manual Pages - [PTHREAD(3)](https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/pthread.3.html)  

## documents

The GNU C Library - [Threads](https://www.gnu.org/software/libc/manual/html_node/Threads.html#Threads), [POSIX Threads](http://elias.rhi.hi.is/libc/POSIX-Threads.html#POSIX%20Threads)  

IBM z/OS XL C/C++ - [Runtime Library Reference](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/toc.htm), [Using threads in z/OS UNIX applications](https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.cbcpx01/uthrds.htm)  
IBM i 7.1 - [Pthread APIs](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_71/apis/rzah4mst.htm)  

[opengroup](http://pubs.opengroup.org/onlinepubs/9699919799/) - [pthread.h](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html)

## source

`pthread.c`: [apple-Libc](https://opensource.apple.com/source/Libc/Libc-498/pthreads/pthread.c), [darwin-libpthread](https://github.com/apple/darwin-libpthread/blob/master/src/pthread.c)  
`pthread_join.c`: [glibc/nptl](https://github.com/lattera/glibc/blob/master/nptl/pthread_join.c)

## [tutorials](https://www.dmoztools.net/Computers/Programming/Threads/POSIX/)

[General Programming Concepts: Writing and Debugging Programs](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/mastertoc.htm)  
	> [Understanding Threads and Processes](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/understanding_threads.htm)  
	> [Multi-Threaded Programming](http://publib16.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/threads_prg.htm)  

### groups

**LLNL**（Lawrence Livermore National Laboratory） - [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/) / [Pthread：POSIX 多线程程序设计](http://www.cnblogs.com/mywolrd/archive/2009/02/05/1930707.html)  

opengroup - [System Interfaces: Detailed ToC](http://pubs.opengroup.org/onlinepubs/9699919799/functions/contents.html) - [Threads](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_09)  

POSIX Threads Tutorial: [laptev](http://www.laptev.org/doc/pthreads.html),[randu](https://randu.org/tutorials/threads/)  

### edu

mit - [Introduction to Programming Threads](http://www.mit.edu/people/proven/IAP_2000/index.html) - PPT  
**mtu** - [Multithreaded Programming with ThreadMentor](http://pages.mtu.edu/~shene/NSF-3/e-Book/index.html)  
cmu - [POSIX thread (pthread) libraries](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)  
fsu - [POSIX Threads API](http://www.cs.fsu.edu/~baker/realtime/restricted/notes/pthreads.html)  
kent - [Multi-Threaded Programming With POSIX Threads](http://www.cs.kent.edu/~ruttan/sysprog/lectures/multi-thread/multi-thread.html)  

## guidelines

### IBM

[Basic use of pthreads](https://www.ibm.com/developerworks/library/l-pthred/index.html) / [pthreads 的基本用法](https://www.ibm.com/developerworks/cn/linux/l-pthred/)  
Posix线程编程指南([1](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part1/index.html))([2](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part2/index.html))([3](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part3/index.html))([4](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part4/index.html))([5](http://www.ibm.com/developerworks/cn/linux/thread/posix_threadapi/part5/index.html))  
POSIX threads explained: ([1](https://www.ibm.com/developerworks/library/l-posix1/index.html))([2](https://www.ibm.com/developerworks/library/l-posix2/))([3](https://www.ibm.com/developerworks/library/l-posix3/)) / POSIX 线程详解 ([1](http://www.ibm.com/developerworks/cn/linux/thread/posix_thread1/index.html))([2](https://www.ibm.com/developerworks/cn/linux/thread/posix_thread2/index.html))([3](https://www.ibm.com/developerworks/cn/linux/thread/posix_thread3/index.html))  

### articles

luoweifu - CSDN

- [编程思想之多线程与多进程(1)——以操作系统的角度述说线程与进程](http://blog.csdn.net/luoweifu/article/details/46595285)  
- [编程思想之多线程与多进程(2)——线程优先级与线程安全](https://blog.csdn.net/luoweifu/article/details/46701167)  
- [编程思想之多线程与多进程(3)——Java中的多线程](https://blog.csdn.net/luoweifu/article/details/46673975)  
- [编程思想之多线程与多进程(4)——C++中的多线程](http://blog.csdn.net/luoweifu/article/details/46835437)  

mybelief321 - CSDN

- [Linux多线程编程(一)---多线程基本编程](http://blog.csdn.net/mybelief321/article/details/9377379)  
- [Linux多线程编程(二)---线程之间的同步与互斥](http://blog.csdn.net/mybelief321/article/details/9390707)  
- [Linux多线程编程(三)---线程之间的同步与互斥进阶实验](http://blog.csdn.net/mybelief321/article/details/9395799)  

Javadino CSDN 专栏

- [[Pthread] Linux上程序调试的基石(一)--ptrace](http://blog.csdn.net/javadino/article/details/2891413)  
- [[Pthread] Linux上程序调试的基石(二)--Inside GDB](http://blog.csdn.net/javadino/article/details/2891434)  

- [[Pthread] Linux中的线程同步机制(一)--Futex](http://blog.csdn.net/javadino/article/details/2891385)  
- [[Pthread] Linux中的线程同步机制(二)--In Glibc](http://blog.csdn.net/javadino/article/details/2891388)  
- [[Pthread] Linux中的线程同步机制(三)--Practice](http://blog.csdn.net/javadino/article/details/2891399)  

### iOS

Apple Developer - [Threading Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Multithreading/CreatingThreads/CreatingThreads.html)

[iOS 多线程 Pthreads 篇](https://juejin.im/post/5a3887dbf265da432e5c1f2f)  
[iOS 使用 Pthread 库开辟子线程](https://www.jianshu.com/p/5f592aab388c)  
[iOS 多线程：pthread、NSThread 详尽总结](https://cloud.tencent.com/developer/article/1139794)  

### std::thread

[C++11 多线程初探](http://www.cnblogs.com/haippy/p/3235560.html)  
[使用 C++11 编写 Linux 多线程程序](http://www.ibm.com/developerworks/cn/linux/1412_zhupx_thread/index.html)  

## 其他

[pthread编程基础](http://blog.chinaunix.net/uid-20528014-id-333508.html)  
[[Pthread] Linux上获得线程Id的方法](http://blog.csdn.net/javadino/article/details/2891364)  
