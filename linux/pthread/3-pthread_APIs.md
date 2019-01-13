## DESCRIPTION

POSIX threads are a set of functions that support applications with requirements for multiple flows of control, called `threads`, within a process.  
Multithreading is used to improve the performance of a program.

### APIs

The POSIX thread functions are summarized in this section in the following groups:

- Thread Routines  
- Attribute Object Routines  
- Mutex Routines  
- Condition Variable Routines  
- Read/Write Lock Routines  
- Per-Thread Context Routines  
- Cleanup Routines  

#### pthread_attr_*

pthread_attr_*(init, destroy, set, get)

#### pthread_mutex_*

pthread_mutex_*(init, destroy, )

#### pthread_cond_*

pthread_cond_*(init, destroy, broadcast, signal, timewait, wait)  
pthread_condattr_*(init, destroy, getpshared, setpshared)

#### cancel & exit

pthread_cancel(3),  
pthread_exit(3),  
pthread_kill(3),  

#### cleanup

pthread_join(3)  

pthread_cleanup_push  
pthread_cleanup_pop  

## pthread_create 函数

### RETURN VALUES

If successful, the `pthread_create()` function will return zero.  
Otherwise an error number(`EPERM`,`EAGAIN`,`EINVAL`) will be returned to indicate the error.

## pthread_exit 函数

If the `start_routine` returns, the effect is as if there was an implicit call to `pthread_exit()` using the return value of `start_routine` as the exit status.  
Note that the thread in which `main()` was originally invoked differs from this. When it returns from `main()`, the effect is as if there was an implicit call to `exit()` using the return value of `main()` as the exit status.

- 线程函数自然返回（return），自动终止  
- 自己调用 pthread_cancel/pthread_exit，主动终止  
- 外部调用 pthread_cancel/pthread_kill，强制终止  
- 进程（主线程 main）返回（return or exit）

## pthread_cleanup_push/pop

[线程清理函数 pthread_cleanup_push / pthread_cleanup_pop](http://blog.csdn.net/b_h_l/article/details/40183731)

[pthread_clean_push与pthread_cleanup_pop函数详解](http://blog.chinaunix.net/uid-26772137-id-3369725.html)

[pthread_cleanup_push()/pthread_cleanup_pop()的详解](http://blog.csdn.net/caianye/article/details/5912172)

[pthread_cleanup_push/pop成对出现的意义](http://blog.csdn.net/yangyiwei524386/article/details/21821095)
