## [Pthread 程式撰寫](http://blog.xuite.net/nikoung/wretch/154071878-Pthread+%E7%A8%8B%E5%BC%8F%E6%92%B0%E5%AF%AB)

pthread_create  
pthread_exit  
pthread_cancel  
pthread_join  
pthread_kill  

```

// test target threas is valid or not ?
int kill_rc = pthread_kill(thread_id, 0);

if (kill_rc == ESRCH)
{
    printf("the specified thread did not exists or already quit\n"); 
}
else if (kill_rc == EINVAL)
{
    printf("signal is invalid\n"); 
}
else
{
   printf("the specified thread is alive\n");
}
```

## [pthread_join - pthread_cancel - pthread_exit](http://codego.net/10061499/)
1. pthread_join 不杀线程，它等待线程。  
	如果你想 kill 一个线程 pthread_kill。  
	不过，这之前完成 pthread_join，否则该线程已经退出。   pthread_cancel 要求在接下来的**消除点**线程 teminate，并且可能是更安全的 pthread_kill。  
	pthread_exit 退出当前线程。  

2. 背景将是不错...但如果你只是等待一个线程（可能你只有一个你关心）终止/回报率，然后在pthread_join是不够好。 对在pthread_join（）函数等待由线程指定的线程 终止。如果该线程已经终止，则在pthread_join（）返回。

## [When to use pthread_cancel and not pthread_kill](http://stackoverflow.com/questions/3438536/when-to-use-pthread-cancel-and-not-pthread-kill)

## [pthread_join function kill the thread after execution or we need to call pthread_cancel/pthread_exit?](http://stackoverflow.com/questions/12280216/pthread-join-function-kill-the-thread-after-execution-or-we-need-to-call-pthread)

## [pthread_kill 和 pthread_cancel](http://blog.csdn.net/kaiwii/article/details/7719011)

## [Linux 终止线程 —— pthread_kill & pthread_cancel](http://www.cnblogs.com/biyeymyhjob/archive/2012/10/11/2720377.html)

## [如何正确的终止正在运行的子线程](http://www.cnblogs.com/Creator/archive/2012/03/21/2408413.html)
