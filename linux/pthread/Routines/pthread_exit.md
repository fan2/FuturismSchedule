## stackoverflow - [main thread exit, does other exit too?](http://stackoverflow.com/questions/11875956/main-thread-exit-does-other-exit-too)

> When the main thread returns, it terminates the entire process. This includes all other threads. The same thing happens when you call exit.
> The purpose of `pthread_detach` is to make it so you don't need to join with other threads in order to release their resources. Detaching a thread does not make it exist past process termination, it will still be destroyed along with all the other threads.

## [why new threads exit when main thread exit.](http://developerweb.net/viewtopic.php?id=6763)

> There are two system calls to exit in Linux: _exit and exit_group. The first just exits the process, and in case of a thread only the thread. The second exits all threads within the thread group. 

> According to POSIX an exit(3) should exit all the threads, so that's why glibc calls exit_group then. The same is true for when main returns. If you don't want that you have to call pthread_exit to exit the main thread (and probably make the other threads detachable).

## stackoverflow - [Do child threads exit when the parent thread terminates](http://stackoverflow.com/questions/4666628/do-child-threads-exit-when-the-parent-thread-terminates)

> There is no parent/child relationship between threads. If thread A creates thread B and then thread A terminates, then thread B will continue to execute.
> The exception to this is when the main thread (that is, the thread that runs the main() function) terminates. When this happens, the process terminates and all other threads stop.

> Two exceptions. If any thread calls exit, then all threads terminate. 


> Since C and C++ [mandate that returning from the main function kills all running threads](http://blogs.msdn.com/b/oldnewthing/archive/2010/08/27/10054832.aspx), yes, the process should be gone. And since that behavior is done by the runtime the situation should be the same on Linux.

## [If you return from the main thread, does the process exit?](https://blogs.msdn.microsoft.com/oldnewthing/20100827-00/?p=13023)

> I also was aware that the standards say nothing about threads.  That's why when I saw this, I read that part as, "the standards require that returning from main() have the same behavior as calling exit()".  Nothing about threads in that statement either.
> But in Windows, the C runtime's exit() calls Win32 ExitProcess(), which has this behavior re: threads.  So for returning from main to have the same behavior as calling exit(), they have to either (1) make exit() not terminate all threads, or (2) terminate all threads.
> Raymond provides citations for which part of the standard he's talking about, so maybe that would clarify this point.  (Personally I don't have much interest in looking it up, but it sounds like you might.)

> C++ ISO/IEC 14882:2003, 3.6.1 main function, para 4
>
>   Calling the function void exit(int) .. terminates the program …
>
> This certainly sounds like a requirement to terminate other threads, even though the language has no concept of threads.  It is difficult to imagine how you could satisfy 'terminate the program' otherwise.

> Para 5 says that returning from main() is equivalent to a call to exit().
