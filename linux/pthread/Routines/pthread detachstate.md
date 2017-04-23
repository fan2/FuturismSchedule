[linux 线程之 pthread_join & pthread_cancel](http://www.cnblogs.com/chris-cp/p/3529699.html)

[POSIX 线程状态：Joinable 和 Detached](http://blog.csdn.net/computerhenu/article/details/5860635)

man pthread_create

     Upon thread exit the storage for the thread must be reclaimed by another thread
     via a call to pthread_join().  Alternatively, pthread_detach() may be called on
     the thread to indicate that the system may automatically reclaim the thread stor-
     age upon exit.  The pthread_attr_setdetachstate() function may be used on the
     attr argument passed to pthread_create() in order to achieve the same effect as a
     call to pthread_detach() on the newly created thread.

     The signal state of the new thread is initialized as:
           o   The signal mask is inherited from the creating thread.
           o   The set of signals pending for the new thread is empty.

## 线程的分离状态(detachstate)
线程的**分离状态**决定一个线程以什么样的方式来终止自己。  
非分离的线程终止时，其线程 ID 和退出状态将保留，直到另外一个线程调用  `pthread_join()` 。  
分离的线程在当它终止时，所有的资源将释放，我们不能等待它终止。

设置线程分离状态的函数为 

     int
     pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);

第二个参数可选为：

- `PTHREAD_CREATE_DETACHED`（分离线程）
- `PTHREAD_CREATE_JOINABLE`（非分离线程），**默认属性**。

这里要注意的一点是，如果设置一个线程为分离线程，而这个线程运行又非常快，它很可能在 `pthread_create()` 函数返回之前就终止了，它终止以后就可能将线程号和系统资源移交给其他的线程使用，这样调用 `pthread_create()` 的线程就得到了错误的线程号。

要避免这种情况可以采取一定的同步措施，最简单的方法之一是可以在被创建的线程里调用 `pthread_cond_timewait()` 函数，让这个线程等待一会儿，留出足够的时间让函数 `pthread_create()` 返回。设置一段等待时间，是在多线程编程里常用的方法。

在线程默认或显式设置为 joinable（可汇合态）后，可以调用  **`pthread_detach()`** 使之变为 detached（脱离态）。但是相反的操作则不可以。

还有，如果线程已经调用 `pthread_join()` 后，则再调用 `pthread_detach()` 则不会有任何效果。

## [pthread_join 和 pthread_detach 详解](http://www.2cto.com/kf/201304/199897.html)

如果一个可结合线程结束运行但没有被 join，则它的状态类似于进程中的 Zombie Process，即还有一部分资源没有被回收，所以创建线程者应该调用  `pthread_join()` 来等待线程运行结束，并可得到线程的退出代码，回收其资源。

### [pthread_create 非分离线程会导致内存泄露](http://blog.chinaunix.net/uid-22663647-id-1771775.html)

- 创建之前调用 pthread_attr_setdetachstate 设置线程属性为 PTHREAD_CREATE_DETACHED  
- 调用 pthread_join() 函数回收线程资源  
- 调用 pthread_detach() 函数将线程脱离  

### pthread_join
#### 函数原型

```C
extern int pthread_join __P (pthread_t __th, void **__thread_return);
```

##### 参数

第一个参数为被等待的线程标识符，
第二个参数为一个用户定义的指针，它可以用来存储被等待线程的返回值。

##### 返回值
如果执行成功，将返回0；如果失败，则返回一个错误号。

#### 函数详解
函数 `pthread_join` 用来等待一个线程的结束。

调用 `pthread_join` 函数，等待线程结束再继续往下执行，要不然主进程下面的线程并行执行。

该函数是一个线程阻塞的函数，调用它的函数将**一直等待**到被等待的线程结束为止。当函数返回时，被等待线程的资源被收回。

代码中如果没有调用 `pthread_join()`，主线程 main （不含 runloop）会很快结束，从而使整个进程结束，创建的子线程将没有机会开始执行就结束了。  
调用 `pthread_join()` 后，主线程会同步等待直到被等待的子线程结束，使创建的线程有机会执行。

[linux pthread_join函数详解](http://blog.csdn.net/feiyinziiuxx/article/details/4498135)

最后要说明的是，一个线程不能被多个线程等待，否则第一个接收到信号的线程成功返回，其余调用 `pthread_join()` 的线程则返回错误代码 **ESRCH**。

### pthread_detach
由于调用 `pthread_join()` 后，如果该线程没有运行结束，调用者会被阻塞，在有些情况下我们并不希望如此。例如，在 Web 服务器中当主线程为每个新来的连接请求创建一个子线程进行处理的时候，主线程并不希望因为调用  `pthread_join()` 而阻塞（因为还要继续处理之后到来的连接请求），这时可以在子线程中加入代码

    pthread_detach(pthread_self())

或者父线程调用

    pthread_detach(thread_id) // 非阻塞，可立即返回

这将该子线程的状态设置为分离的（detached），如此一来，该线程运行结束后会**自动释放**所有资源。
