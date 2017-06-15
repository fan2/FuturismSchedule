《UNIX 网络编程》卷1：套接字联网API》  
[UNIX Network Programming, Volume 1](http://www.unpbook.com/)  

UNIX Network Programming, Volume 1, [Third Edition Source Code](http://www.unpbook.com/src.html)

Here you can download the source code for all the examples in the book. Sorry, we have not spent time making sure the source unpacks and builds cleanly on various systems, but since we compiled these examples and ran them on the target systems used while writing the book, chances are this source will provide you a good starting point for something that works on your machine.

## 电子书
[linuxidc](http://www.linuxidc.com/Linux/2014-04/100222.htm)  
[vdisk](http://vdisk.weibo.com/s/zp3-W49kwbIBd)  
[CSDN](http://download.csdn.net/download/chn475111/7379853#)  

## 1.4 错误处理：包裹函数
任何现实世界的程序都必须检查*每个函数*调用是否返回错误。
在图1-5所示的程序 `intro/daytimetcpcli.c` 中，我们检查 `socket`、`inet_pton`、`connect`、`read` 和 `fputs` 函数是否返回错误。当发生错误时，就调用 `unp.h` 中声明、`error.c` 中定义的 `err_quit` 或 `err_sys` 函数**输出**一个出错消息（fputs error message to stderr）并**终止**程序的运行（exit(EXIT_FAILURE)）。

```
static void	err_doit(int, int, const char *, va_list);


/* Print message and return to caller
 * Caller specifies "errnoflag" and "level" */

static void
err_doit(int errnoflag, int level, const char *fmt, va_list ap)
{
    // ...
	if (daemon_proc) {
		syslog(level, buf);
	} else {
		fflush(stdout);		/* in case stdout and stderr are the same */
		fputs(buf, stderr);
		fflush(stderr);
	}
    // ...
}

/* Fatal error related to system call
 * Print message and terminate */
void
err_sys(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(1);
}

/* Fatal error unrelated to system call
 * Print message and terminate */

void
err_quit(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(0, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(1);
}

```

我们发现绝大多数情况下这正是我们要做的事情。既然发生错误时终止程序的运行时普遍的情况，我们对本书中要调用的大多数系统调用函数（原始API）简单封装了各自的 ***包裹函数*** 。包裹函数内部调用API完成实际的系统调用，当检查到API返回值为负值时，通常意味着出错，将**输出**适当的消息并**终止**程序的运行。

我们约定包裹函数名是实际函数名的首字母大写形式，例如 `wrapsock.c` 中定义的 `Socket` 封装了 `socket` 调用，`wrapunix.c` 中定义的  `Close` 封装了 `close` 调用。

```C
// unpv13e/lib/wrapsock.c
/* include Socket */
int
Socket(int family, int type, int protocol)
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0)
		err_sys("socket error");
	return(n);
}
/* end Socket */

// unpv13e/lib/wrapunix.c
void
Close(int fd)
{
	if (close(fd) == -1)
		err_sys("close error");
}
```

为了简化代码缩短程序，**多数情况下**我们改为调用封装了通用错误检查处理的包裹函数而非原始API。

**个别情况下**，当这些函数返回错误时，我们想做的事情并非简单地终止程序的运行，此时不能调用包裹函数执行常规错误检查，而应该改为调用原始API。如图5-12所示的程序 `tcpclisvr/tcpserv04.c`，我们必须检查 `accept` 系统调用是否被中断了。

```
	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		if ( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
			if (errno == EINTR)
				continue;		/* back to for() */
			else
				err_sys("accept error");
		}

		if ( (childpid = Fork()) == 0) {	/* child process */
			Close(listenfd);	/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		Close(connfd);			/* parent closes connected socket */
	}
```

## unpv13e 源码编译
[《UNP》中源代码的编译和使用 转载](http://blog.chinaunix.net/uid-10780339-id-189358.html)  
[《UNP》中源代码的编译和使用](http://www.cnblogs.com/liulipeng/archive/2013/03/23/2977227.html)  
[UNP编程环境配置](http://blog.chinaunix.net/uid-29586004-id-4211268.html)  
[Unix网络编程第三版源码编译](http://blog.csdn.net/hantangsongming/article/details/20453349)  

```markdown
QUICK AND DIRTY
===============

Execute the following from the src/ directory:

    ./configure    # try to figure out all implementation differences

    cd lib         # build the basic library that all programs need
    make           # use "gmake" everywhere on BSD/OS systems

    cd ../libfree  # continue building the basic library
    make

    cd ../libroute # only if your system supports 4.4BSD style routing sockets
    make           # only if your system supports 4.4BSD style routing sockets

    cd ../libxti   # only if your system supports XTI
    make           # only if your system supports XTI

    cd ../intro    # build and test a basic client program
    make daytimetcpcli
    ./daytimetcpcli 127.0.0.1

If all that works, you're all set to start compiling individual programs.

Notice that all the source code assumes tabs every 4 columns, not 8.

5.  If you need to make any changes to the "unp.h" header, notice that it
    is a hard link in each directory, so you only need to change it once.

6.  Go into the "lib/" directory and type "make".  This builds the library
    "libunp.a" that is required by almost all of the programs.  There may
    be compiler warnings (see NOTES below).  This step is where you'll find
    all of your system's dependencies, and you must just update your cf/
    files from step 1, rerun "config" and do this step again.

6.  Go into the "libfree/" directory and type "make".  This adds to the
    "libunp.a" library.  The files in this directory do not #include
    the "unp.h" header, as people may want to use these functions
    independent of the book's examples.

8.  Once the library is made from steps 5 and 6, you can then go into any
    of the source code directories and make whatever program you are
    interested in.  Note that the horizontal rules at the beginning and
    end of each program listing in the book contain the directory name and
    filename.
```
