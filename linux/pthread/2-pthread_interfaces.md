[从pthread 到QThread](http://www.cnblogs.com/lfsblack/p/4614541.html)

[tomohikoseven/pthread_join](https://github.com/tomohikoseven/pthread_join)

[pthread_create & pthread_join 示例1](http://blog.csdn.net/youbang321/article/details/7815707)

[pthread_create & pthread_join 示例2](http://www.cnblogs.com/maliqian/archive/2011/12/16/2290815.html)

[pthread_create & pthread_join & pthread_exit 示例](http://blog.csdn.net/feiyinziiuxx/article/details/4498135)

[pthread_create & pthread_join & pthread_cancel 示例](http://blog.csdn.net/jxxfqyy/article/details/4084193)

![pthread_create & pthread_join sequence](http://g.hiphotos.baidu.com/baike/c0%3Dbaike80%2C5%2C5%2C80%2C26/sign=63a8b923e7dde711f3df4ba4c686a57e/a50f4bfbfbedab64b58544e6f536afc379311e24.jpg)

## [POSIX 线程接口——pthread](http://blog.csdn.net/tommy_wxie/article/details/8545253)

### 创建线程

POSIX 通过 `pthread_create()` 函数创建线程，API 定义如下：

     int
     pthread_create(pthread_t *thread, const pthread_attr_t *attr,
         void *(*start_routine)(void *), void *arg);

与 `fork()` 调用创建一个进程的方法不同，`pthread_create()` 创建的线程并不具备与主线程（即调用 `pthread_create()` 的线程）同样的执行序列，而是使其运行 `start_routine(arg)` 函数。thread 返回创建的线程 ID，而 attr 是创建线程时设置的线程属性（见下）。`pthread_create()` 的返回值表示线程创建是否成功。

尽管 arg 是 void* 类型的变量，但它同样可以作为任意类型的参数传给 `start_routine()` 函数；同时，`start_routine()` 可以返回一个 void* 类型的返回值，而这个返回值也可以是其他类型，并由 `pthread_join()` 获取。

### 线程创建属性

    The pthread_create() function is used to create a new thread, with attributes specified by attr, within a process.  
    If attr is NULL, the default attributes are used.  
    If the attributes specified by attr are modified later, the thread's attributes are not affected.

`pthread_create()` 中的 attr 参数是一个结构指针，结构中的元素分别对应着新线程的运行属性，主要包括以下几项：

#### __detachstate

表示新线程是否与进程中其他线程脱离同步，如果置位则新线程不能用 `pthread_join()` 来同步，且在退出时自行释放所占用的资源。缺省为 **`PTHREAD_CREATE_JOINABLE`** 状态。

这个属性也可以在线程创建并运行以后用 **`pthread_detach()`** 来设置，而一旦设置为 `PTHREAD_CREATE_DETACH` 状态（不论是创建时设置还是运行时设置）则不能再恢复到 `PTHREAD_CREATE_JOINABLE` 状态。

#### __schedpolicy

表示新线程的调度策略，主要包括 `SCHED_OTHER`（正常、非实时）、`SCHED_RR`（实时、轮转法）和 `SCHED_FIFO`（实时、先入先出）三种，缺省为`SCHED_OTHER`，后两种调度策略仅对超级用户有效。运行时可以用过 **`pthread_setschedparam()`** 来改变。

__schedparam，一个 struct sched_param 结构，目前仅有一个 sched_priority 整型变量表示线程的运行优先级。这个参数仅当调度策略为实时（即 `SCHED_RR` 或 `SCHED_FIFO`）时才有效，并可以在运行时通过  **`pthread_setschedparam()`** 函数来改变，缺省为 0。

#### __inheritsched

有两种值可供选择：`PTHREAD_EXPLICIT_SCHED` 和  `PTHREAD_INHERIT_SCHED`，前者表示新线程使用显式指定调度策略和调度参数（即 attr 中的值），而后者表示继承调用者线程的值。缺省为 **`PTHREAD_EXPLICIT_SCHED`**。

#### __scope

表示线程间竞争 CPU 的范围，也就是说线程优先级的有效范围。POSIX的标准中定义了两个值：`PTHREAD_SCOPE_SYSTEM` 和 `PTHREAD_SCOPE_PROCESS`，前者表示与系统中所有线程一起竞争 CPU 时间，后者表示仅与同进程中的线程竞争CPU。目前 Linux Threads 仅实现了 `PTHREAD_SCOPE_SYSTEM` 一值。

`pthread_attr_t` 结构中还有一些值，但不使用 `pthread_create()` 来设置。

为了设置这些属性，POSIX 定义了一系列属性设置函数，包括  pthread_attr_init()/pthread_attr_destroy() 和与各个属性相关的 pthread_attr_get---/pthread_attr_set--- 函数。

> [pthread 的属性和TLS](http://www.cnblogs.com/lidabo/p/5009249.html)

### 线程创建的Linux实现

Linux 线程在核内是以_轻量级_进程的形式存在的，拥有独立的进程表项，而所有的创建、同步、删除等操作都在核外 pthread 库中进行。

pthread 库使用一个管理线程（__pthread_manager()，每个进程独立且唯一）来管理线程的创建和终止，为线程分配线程ID，发送线程相关的信号（比如Cancel），而主线程（`pthread_create()`）的调用者则通过管道将请求信息传给管理线程。
