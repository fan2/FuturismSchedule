[overview of signals](http://man7.org/linux/man-pages/man7/signal.7.html)

APUE 第10章 信号

## sigset_t

操作 sigset_t 的相关函数参考 [SIGSETOPS(3)](http://man7.org/linux/man-pages/man3/sigsetops.3.html)。

```c
#include <signal.h>

int sigemptyset(sigset_t *set); // 初始化空集
int sigfillset(sigset_t *set);  // 初始化全集
int sigaddset(sigset_t *set, int signum); // 添加信号到集合
int sigdelset(sigset_t *set, int signum); // 从集合移除信号
int sigismember(const sigset_t *set, int signum); // 判断信号是否在集合中
```

## raise a signal

The following system calls and library functions allow the caller to send a signal:

- [raise(3)](http://man7.org/linux/man-pages/man3/raise.3.html): Sends a signal to the calling thread.  
- [kill(2)](http://man7.org/linux/man-pages/man2/kill.2.html): Sends a signal to a specified process, to all members of a specified process group, or to all processes on the system.  
- [killpg(3)](http://man7.org/linux/man-pages/man3/killpg.3.html): Sends a signal to all of the members of a specified process group.  
- [pthread_kill(3)](http://man7.org/linux/man-pages/man3/pthread_kill.3.html): Sends a signal to a specified POSIX thread in the same process as the caller.  
- [tgkill(2)](http://man7.org/linux/man-pages/man2/tgkill.2.html): Sends a signal to a specified thread within a specific process.  (This is the system call used to implement pthread_kill(3).)  
- [sigqueue(3)](http://man7.org/linux/man-pages/man3/sigqueue.3.html): Sends a real-time signal with accompanying data to a specified process.  

`raise` - send a signal to the caller(process or thread)  
`kill` - send signal to a process  
`pthread_kill` - send a signal to a thread asynchronously  

```c
#include <signal.h>

int raise(int sig);
int kill(pid_t pid, int sig); // #include <sys/types.h> for pid_t
int pthread_kill(pthread_t thread, int sig);
```

1. In a *single-threaded* program it is equivalent to `kill(getpid(), sig)`;  
2. In a *multithreaded* program it is equivalent to `pthread_kill(pthread_self(), sig)`;  

If the signal causes a handler to be called, **raise()** will return *only after* the signal handler has returned.

### empty signal

POSIX.1 编号为0的信号定义为空信号。指定 sig=0 调用 `kill` 或 `pthread_kill`，不会发出任何信号，可用作错误状态检查，常被用来检测一个特定 进程/线程 是否仍然存活。
如果目标 进程/线程已经释放，则检测返回 -1 且 errno=`ESRCH`。

## signal mask

The signal mask is the *set* of signals whose delivery is currently **blocked** for the caller.  
Each thread in a process has an *independent* signal mask, which indicates the set of signals that the thread is currently *blocking*.

> sigmask=signal mask，意即信号掩码。

In a traditional single-threaded application, **sigprocmask(2)** can be used to manipulate the signal mask.   
A thread can manipulate its signal mask using **pthread_sigmask(3)**.  

调用 `sigprocmask`（单线程） 或 `pthread_sigmask`（多线程）可屏蔽掉某些不关心的信号，不做处理。

> It is not possible to block `SIGKILL` or `SIGSTOP`, specifying these signals in mask are silently ignored, and has no effect.

### [sigprocmask(2)](http://man7.org/linux/man-pages/man2/sigprocmask.2.html)

`sigprocmask`, `rt_sigprocmask` - examine and change blocked signals

**sigprocmask()** is used to fetch and/or change the signal mask of the calling thread.  

`sigprocmask` 接口用于检测获取或设置更改当前信号屏蔽字。

#### SYNOPSIS

```c
#include <signal.h>

/* Prototype for the glibc wrapper function */
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```

> If `oldset` is non-NULL, the previous value of the signal mask is **stored** in oldset.

#### how

- `SIG_BLOCK`: The set of blocked signals is the **union**（添加） of the current set and the set argument.  
- `SIG_UNBLOCK`: The signals in set are **removed**（移除） from the current set of blocked signals. It is permissible to attempt to unblock a signal which is not blocked.  
- `SIG_SETMASK`: The set of blocked signals is **set**（替换） to the argument set.  

调用 `sigprocmask(0, NULL, &sigset)` 可以获取当前的信号掩码集 sigset_t。

### [pthread_sigmask(3)](http://man7.org/linux/man-pages/man3/pthread_sigmask.3.html)

`pthread_sigmask` - examine and change mask of blocked signals

调用 `pthread_sigmask(0, NULL, &sigset)` 也可以获取当前的信号掩码集 sigset_t。

#### SYNOPSIS

```c
 #include <signal.h>

 int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);
```

#### DESCRIPTION

The `pthread_sigmask()` function is just like `sigprocmask(2)`, with the difference that its use in **multithreaded** programs is explicitly specified by POSIX.1.

### blocked pending

A signal may be blocked, which means that it will *not* be delivered *until* it is later unblocked.  
Between the time when it is *generated* and when it is *delivered* a signal is said to be **pending**.  

> 从信号产生（generation），被阻塞（blocked），直到解除阻塞（unblocked）被投递（delivered）这段时间为挂起状态。

A thread can obtain the set of signals that it currently has pending using [sigpending(2)](http://man7.org/linux/man-pages/man2/sigpending.2.html).

```c
#include <signal.h>

int sigpending(sigset_t *set);
```

This set will consist of the **union** of the set of pending process-directed signals and the **set** of signals pending for the calling thread.  

## suspend for signal

The following system calls **suspend** execution of the calling process or thread ***until*** a signal is caught (or an unhandled signal terminates the process):

- [pause(2)](http://man7.org/linux/man-pages/man2/pause.2.html): Suspends execution until *any* signal is caught.  
- [sigsuspend(2)](http://man7.org/linux/man-pages/man2/sigsuspend.2.html): Temporarily changes the signal mask (see below) and suspends execution until one of the *unmasked* signals is caught.  

### pause for any signal

**pause()** causes the calling process (or thread) to sleep until a signal is delivered that either terminates the process or causes the invocation of a signal-catching function.  
**pause()** returns only when a signal was caught and the signal-catching function returned. In this case, **pause()** returns -1, and *errno* is set to `EINTR`.

`pause` 会挂起当前进程（线程），直到收到任意（非屏蔽？）信号且被处理后才返回。

> 为了避免一个 C 程序执行完自动终止一闪而过，可以 pause 等待用户按键再退出，以便在控制台看到输出结果。

### sigsuspend for unmasked signal

**sigsuspend()** temporarily replaces the signal mask of the calling process with the mask given by `mask` and then suspends the process *until* delivery of a signal whose action is to invoke a signal handler or to terminate a process.  

- If the signal terminates the process, then `sigsuspend()` does not return.  
- If the signal is caught, then `sigsuspend()` returns after the signal handler *returns*, and the signal mask is *restored* to the state before the call to sigsuspend().  

`sigsuspend` 临时改变 sigmask，挂起当前进程（线程），直到收到一个非屏蔽（unmasked）信号。信号被处理后，sigsuspend 返回，restore 之前的 sigmask。  

> 挂起等待接受到指定信号才唤醒。

```c
#include <signal.h>

int sigsuspend(const sigset_t *mask);
```

### sigwait for sigset

Rather than *asynchronously* catching a signal via a signal handler, it is possible to **synchronously** accept the signal, that is, to ***block*** execution *until* the signal is delivered, at which point the kernel returns information about the signal to the caller.  

There are two general ways to do this:

* [sigwaitinfo(2)](http://man7.org/linux/man-pages/man2/sigwaitinfo.2.html), [sigtimedwait(2)](http://man7.org/linux/man-pages/man2/sigtimedwait.2.html), and [sigwait(3)](http://man7.org/linux/man-pages/man3/sigwait.3.html) suspend execution until one of the signals in a specified set is delivered. Each of these calls returns information about the delivered signal.

* [signalfd(2)](http://man7.org/linux/man-pages/man2/signalfd.2.html) returns a file descriptor that can be used to read information about signals that are delivered to the caller. Each [read(2)](http://man7.org/linux/man-pages/man2/read.2.html) from this file descriptor blocks until one of the signals in the set specified in the signalfd(2) call is delivered to the caller. The buffer returned by read(2) contains a structure describing the signal.

除了可以通过 signal、sigaction 预先安装信号处理器等待异步捕获处理信号外，还可以调用 `sigwait` 同步阻塞等待指定信号的到来。

```c
#include <signal.h>
int sigwait(const sigset_t *set, int *sig);
```

The **sigwait()** function suspends execution of the calling thread *until* one of the signals specified in the signal set set becomes pending. The function accepts the signal (removes it from the pending list of signals), and returns the signal number in `sig`.

`sigwait()` is implemented using [sigtimedwait(2)](http://man7.org/linux/man-pages/man2/sigtimedwait.2.html).

### signalfd

`signalfd` - create a file descriptor for accepting signals

```c
 #include <sys/signalfd.h>

 int signalfd(int fd, const sigset_t *mask, int flags);
```

**signalfd()** creates a file descriptor that can be used to accept signals targeted at the caller.  
This provides an *alternative* to the use of a signal handler or `sigwaitinfo(2)`, and has the **advantage** that the file descriptor may be monitored by `select(2)`, `poll(2)`, and `epoll(7)`.

如此一来，信号就能和其他I/O事件一样被 I/O 复用器一并等待，即统一事件源。

## signal dispositions

Each signal has a current disposition, which determines how the process **behaves** when it is delivered the signal.

The entries in the "Action" column of the tables below specify the default disposition for each signal, as follows:

| action                                                        | desc                                                          |
| ------------------------------------------------------------- | ------------------------------------------------------------- |
| Term                                                          | Default action is to terminate the process.                   |
| Ign                                                           | Default action is to ignore the signal.                       |
| Core                                                          | Default action is to terminate the process and dump core (see [core(5)](http://man7.org/linux/man-pages/man5/core.5.html)). |
| Stop                                                          | Default action is to stop the process.                        |
| Cont                                                          | Default action is to continue the process if it is currently stopped. |

A process can change the disposition of a signal using `sigaction(2)` or `signal(2)`.(The latter is less portable when establishing a signal handler; see `signal(2)` for details.)  
Using these system calls, a process can elect one of the following behaviors to occur on **delivery** of the signal: 

1. perform the default action;  
2. ignore the signal;  
3. or catch the signal with a **signal handler**, a programmer defined function that is automatically invoked when the signal is delivered.  

The signal disposition is a ***per-process*** attribute: in a multithreaded application, the disposition of a particular signal is the same for all threads.

### signal handler

信号是异步事件的经典实例，产生信号的事件对进程而言是随机出现的。
进程不能简单地测试一个变量（如 errno）来判断是否发生了一个信号，而应该告诉内核在此信号发生时应该如何处理。

在某个信号出现时，可以告诉内核按以下3种方式之一进行处理，我们称之为信号的处理或与信号相关的动作。

1. 忽略该信号，但是不能忽略 `SIGKILL`，`SIGSTOP` 和一些由硬件异常产生的信号；  
2. 捕捉信号，通过系统接口安装用户预定义的信号处理函数，系统内核在收到某种信号时回调绑定函数；  
3. 系统默认动作。注意，对于大多信号的系统默认动作是终止该进程。

调用 `signal()` 和 `sigaction()` 函数可以为指定信号安装对应的信号处理器。

进程捕捉到信号时，会临时中断正在执行的正常指令序列，转而执行预先绑定的异步回调函数。
信号处理程序返回后，继续执行之前被中断的正常指令序列，这类似硬件中断处理后的恢复现场。

#### [signal](http://man7.org/linux/man-pages/man2/signal.2.html)

`signal` - ANSI C signal handling

```c
#include <signal.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```

The behavior of `signal()` varies across UNIX versions, and has also varied historically across different versions of Linux.  
Avoid its use: use `sigaction(2)` *instead*.

#### [sigaction](http://man7.org/linux/man-pages/man2/sigaction.2.html)

`sigaction`, `rt_sigaction` - examine and change a signal action

```c
#include <signal.h>

struct sigaction {
   void     (*sa_handler)(int);
   void     (*sa_sigaction)(int, siginfo_t *, void *);
   sigset_t   sa_mask; // should be blocked during execution
   int        sa_flags;
   void     (*sa_restorer)(void);
};

int sigaction(int signum, const struct sigaction *act,
             struct sigaction *oldact);
```

The `sigaction()` system call is used to change the action taken by a process on receipt of a **specific** signal.

- *signum* specifies the signal and can be any valid signal except `SIGKILL` and `SIGSTOP`.  
- If *act* is non-NULL, the new action for signal signum is **installed** from act.  
    - If *oldact* is non-NULL, the previous action is **saved** in oldact.  

#### sa_mask

可以配置 sigaction.sa_mask，以便在处理某个信号期间，阻塞某些信号。  
如果正在处理某个信号，没有在 sigaction.sa_flags 中配置 `SA_NODEFER`，则默认会阻塞掉再次到来的同一信号。  

`sa_mask` specifies a mask of signals which should be blocked (i.e., added to the signal mask of the thread in which the signal handler is invoked) during execution of the signal handler.  
In addition, the signal which triggered the handler will be blocked, unless the `SA_NODEFER` flag is used.

## Interruption by signal handler

Interruption of system calls and library functions by signal handlers

If a signal handler is invoked while a system call or library function call is *blocked*, then either:

- the call is automatically **restarted** after the signal handler returns; or  
- the call fails with the error `EINTR`.

### restartable

如果安装信号处理器时，sigaction.sa_flags 设置了 `SA_RESTART` 标记（making system calls restartable across signals），则被中断的系统调用在 sa_sigaction 处理完毕后可自动重入。

支持 restart 的典型系统调用如下：

- 诸如外设读写（read(2)/write(2)）；  
- 套接字连接（connect(2)/accept(2)）及读写（recv(2)/send(2)）；  
- 同步设施（sem、mutex、cond）等待（lock 或 wait）；  
- etc.  

### EINTR

还有一些系统调用或在某些场景下，无论是否设置了 `SA_RESTART` 标记，被信号中断后都不会自动重入，而是返回错误（errno=`EINTR`）。

- 等待信号接口：pause(2), sigsuspend(2), sigtimedwait(2), and sigwaitinfo(2)；  
- 已被设置 `SO_RCVTIMEO` 套接字的可读调用（accept,recv）和可写调用（connect,send）；  
- I/O 多路复用器：epoll_wait(2), epoll_pwait(2), poll(2), ppoll(2), select(2), and pselect(2)；  
- 睡眠接口：clock_nanosleep(2), nanosleep(2), and usleep(3).
- etc.  

> 需要注意的是，`sleep(3)` 函数也不会重启，但是不会返回错误，返回剩余时间。

被 sigaction.sa_handler 中断的系统调用必须显式地捕获 `errno=EINTR` 错误，并按需进行手动重入处理。

假定低速设备进行读操作被中断，我们希望重启它。典型的代码序列如下：

```c
again:
  if ((n = read(fd, buf, BUFFSIZE)) < 0) {
    if (errno == EINTR)
      goto again;
    /*handle other errors*/
  }
```

#### libuv

libuv 中的 select 和 poll 检测到 `EINTR` 会执行重试：

```c
// https://github.com/libuv/libuv/blob/v1.x/src/unix/posix-poll.c
/* Check whether the given fd is supported by poll().  */
int uv__io_check_fd(uv_loop_t* loop, int fd) {
  //...

  do
    rv = poll(p, 1, 0);
  while (rv == -1 && (errno == EINTR || errno == EAGAIN));

  // ...
}

// https://github.com/libuv/libuv/blob/v1.x/src/unix/stream.c
#if defined(__APPLE__)
static void uv__stream_osx_select(void* arg) {
{

  while (1) {

    /* Wait indefinitely for fd events */
    r = select(max_fd + 1, s->sread, s->swrite, NULL, NULL);
    if (r == -1) {
      if (errno == EINTR)
        continue;

      /* XXX: Possible?! */
      abort();
    }

}
#endif
```

#### mars

mars 中执行 `pthread_mutex_lock` 和 `connect` 检测到 `EINTR` 会执行重试：

```cpp
// https://github.com/Tencent/mars/blob/master/mars/boost/thread/pthread/mutex.hpp
namespace mars_boost {} namespace boost = mars_boost; namespace mars_boost
{
  namespace posix {

    BOOST_FORCEINLINE int pthread_mutex_lock(pthread_mutex_t* m)
    {
      int ret;
      do
      {
          ret = ::pthread_mutex_lock(m);
      } while (ret == EINTR);
      return ret;
    }

  }

}

// https://github.com/Tencent/mars/blob/master/mars/comm/socket/local_ipstack.cc
static const unsigned int kMaxLoopCount = 10;
static int
_test_connect(int pf, struct sockaddr *addr, size_t addrlen, struct sockaddr* local_addr, socklen_t local_addr_len) {
    int s = socket(pf, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0) return 0;
    int ret;
    unsigned int loop_count = 0;
    do {
        ret = connect(s, addr, addrlen);
    } while (ret < 0 && errno == EINTR && loop_count++<kMaxLoopCount);

}
```

## [demo](http://man7.org/linux/man-pages/man3/pthread_sigmask.3.html)

The program below blocks some signals in the main thread, and then creates a dedicated thread to fetch those signals via `sigwait(3)`.

示例代码中，主线程通过设置 sigmask 屏蔽掉（不处理）`SIGQUIT` 和 `SIGUSR1` 信号，由子线程 `sigwait()` 接收处理。  
同时，主线程调用 `pause()` 等待信号，当收到 `SIGTERM` 信号时，主线程（进程）退出。  
