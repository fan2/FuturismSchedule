## [POSIX 线程接口——pthread](http://blog.csdn.net/tommy_wxie/article/details/8545253)

### 线程取消
#### 线程取消的定义
一般情况下，线程在其主体函数退出（自然返回 return）的时候会**自动终止**，但同时也可以因为接收到另一个线程发来的终止（取消）请求而**强制终止**。

#### 线程取消的语义
线程取消的方法是向目标线程发 CANCEL 信号，但如何处理 CANCEL 信号则由目标线程自己决定，或者忽略、或者立即终止、或者继续运行至 Cancelation-point（取消点），由不同的 Cancelation 状态决定。

线程接收到 CANCEL 信号的缺省处理（即 `pthread_create()` 创建线程时使用默认缺省属性）是_继续运行至取消点_，也就是说设置一个 CANCELED 状态，线程继续运行，只有运行至 Cancelation-point 的时候才会退出。

#### 取消点
根据 POSIX 标准，`pthread_join()`、`pthread_testcancel()`、`pthread_cond_wait()`、`pthread_cond_timedwait()`、`sem_wait()`、`sigwait()` 等函数以及 `read()`、`write()` 等会**引起阻塞**的系统调用都是 Cancelation-point，而其他 pthread 函数都不会引起 Cancelation 动作。

但是 pthread_cancel 的手册页声称，由于 Linux Thread 库与 C 库结合得不好，因而目前 C 库函数都不是 Cancelation-point；但 **_CANCEL 信号会使线程从阻塞的系统调用中退出_**，并置 `EINTR` 错误码，因此可以在需要作为 Cancelation-point 的系统调用**前后**调用 `pthread_testcancel()`，从而达到 POSIX 标准所要求的目标，即如下代码段：

```C
	pthread_testcancel();
    retcode = read(fd, buffer, length);
    pthread_testcancel();
```

> 按照 POSIX 标准，阻塞调用 read() 进入应检测 pthread_self 是否处于 CANCELED 状态。若检测到处于 CANCELED 状态，则立即调用 `pthread_exit()` 退出。

#### 程序设计方面的考虑
如果线程处于无限循环中，且循环体内没有执行至取消点的必然路径，则线程无法由外部其他线程的取消请求而终止。因此在这样的循环体的必经路径上应该加入 pthread_testcancel() 调用。

#### 线程取消相关的函数
##### pthread_cancel
```C
int pthread_cancel(pthread_t thread)
```

发送终止信号给 thread 线程，如果成功则返回0，否则为非0值。  
发送成功并不意味着 thread 会终止。

##### pthread_setcancelstate
```C
int pthread_setcancelstate(int state, int *oldstate)
```

设置本线程对 Cancel 信号的**反应**，state 有两种值：

1. PTHREAD_CANCEL_ENABLE（缺省）  
2. PTHREAD_CANCEL_DISABLE  

分别表示收到信号后设为 CANCLED 状态和忽略 CANCEL 信号继续运行；
old_state 如果不为 NULL 则存入原来的 Cancel 状态以便恢复。

##### pthread_setcanceltype
```C
int pthread_setcanceltype(int type, int *oldtype)
```

设置本线程取消动作的**执行时机**，type 由两种取值：

1. PTHREAD_CANCEL_DEFFERED  
2. PTHREAD_CANCEL_ASYCHRONOUS  

仅当 Cancel 状态为 Enable 时有效，分别表示收到信号后继续运行至下一个取消点再退出和立即执行取消动作（退出）。

oldtype 如果不为NULL则存入运来的取消动作类型值。

##### [pthread_testcancel](http://blog.csdn.net/huangshanchun/article/details/47420961)
```C
void pthread_testcancel(void)
```

检查本线程是否处于 Canceld 状态，如果是，则进行取消动作，否则直接返回。

### 参考
[POSIX 线程取消点的 Linux 实现](http://www.cnblogs.com/bigben0123/p/3227255.html)

[一个pthread_cancel 引起的线程死锁](http://blog.sae.sina.com.cn/archives/884)

[防止死锁:采用linux多线程的pthread_cancel终止线程](http://www.cnblogs.com/linuxsuperstart/archive/2013/03/28/2987830.html)

