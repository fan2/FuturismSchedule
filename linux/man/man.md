
# man
[The Linux *man-pages* project](https://www.kernel.org/doc/man-pages/) documents the [Linux](http://en.wikipedia.org/wiki/Linux) [kernel](http://www.kernel.org/pub/linux/kernel) and C library interfaces that are employed by user-space programs.  
With respect to the C library, the primary focus is the [GNU](http://www.gnu.org/) C library (glibc), although, where known, documentation of *variations* on other C libraries available for Linux is also included.

- [CGit](http://git.kernel.org/?p=docs/man-pages/man-pages.git)  
- [Online man pages](http://man7.org/linux/man-pages/index.html) @man7.org  
- [Changelog](http://man7.org/linux/man-pages/changelog.html)  

## man location
```Shell
faner@THOMASFAN-MB0:~|⇒  cd /usr/share/man/
faner@THOMASFAN-MB0:/usr/share/man|⇒  ls
man1   man4   man5   man6   man7   man8   man9   mann   whatis
```

```Shell
faner@THOMASFAN-MB0:/usr/share/man|⇒  ls man1 | grep bash
bash.1
bashbug.1
```

## manual page types

```Shell
       The table below shows the section numbers of the manual followed by the
       types of pages they contain.

       1   Executable programs or shell commands
       2   System calls (functions provided by the kernel)
       3   Library calls (functions within program libraries)
       4   Special files (usually found in /dev)
       5   File formats and conventions eg /etc/passwd
       6   Games
       7   Miscellaneous  (including  macro  packages  and  conventions), e.g.
           man(7), groff(7)
       8   System administration commands (usually only for root)
       9   Kernel routines [Non standard]
```

[Online man pages](http://man7.org/linux/man-pages/index.html):   [**by section**](http://man7.org/linux/man-pages/dir_all_by_section.html)  |  [alphabetically](http://man7.org/linux/man-pages/dir_all_alphabetic.html)  |  [by project](http://man7.org/linux/man-pages/dir_by_project.html)

- [1: *User commands*](http://man7.org/linux/man-pages/dir_section_1.html); man-pages includes a very few Section 1 pages that document programs supplied by the <u>GNU C library</u>.  
- [2: *System calls*](http://man7.org/linux/man-pages/dir_section_2.html) documents the [system calls](http://man7.org/linux/man-pages/man2/syscalls.2.html) provided by the Linux kernel.  
- [3: *Library functions*](http://man7.org/linux/man-pages/dir_section_3.html) documents the functions provided by the <u>standard C library</u>.  
- [4: *Devices*](http://man7.org/linux/man-pages/dir_section_4.html) documents details of various devices, most of which reside in `/dev`.  
- [5: *Files*](http://man7.org/linux/man-pages/dir_section_5.html) describes various file formats, and includes [proc(5)](http://man7.org/linux/man-pages/man5/proc.5.html), which documents the `/proc` file system.  
- [7: *Overviews, conventions, and miscellaneous*](http://man7.org/linux/man-pages/dir_section_7.html).  
- [*8: Superuser and system administration commands*](http://man7.org/linux/man-pages/dir_section_8.html); man-pages includes a very few Section 8 pages, mainly documenting programs supplied by the <u>GNU C library</u>.  

### 1.General Commands
man bash：MAN(1), BASH(1)；  
脚本类型及命令文件：WHICH(1) （相当于 `type -p`）；  
系统信息：UNAME(1), ARCH(1), HOSTNAME(1)；  
用户权限管理：SU(1), CHGRP(1), CHOWN(1), CHMOD(1), ID(1), WHO(1)；  
环境变量：ENV(1), DATE(1),  CAL(1)；  
列举、打印、输出：ECHO(1), PRINTF(1), LS(1), TREE(1)；  
目录管理：PWD(1), MKDIR(1), RMDIR(1)；  
文件管理：CP(1), RM(1), MV(1)；  
磁盘管理：DF(1), DU(1)；  
模式匹配及格式化提取：GREP(1), SED(1), MAWK(1), XARGS(1)；  
文本编辑器：NANO(1), VIM(1)；  
文件信息：TOUCH(1), FILE(1)；  
文件内容查阅：CAT(1), TAC(1), NL(1), MORE(1), LESS(1), HEAD(1), TAIL;  
SCM 版本控制管理工具：GIT(1), svn(1)；  
比较补丁工具：DIFF(1), CMP(1), PATCH(1)；  
网络诊断命令：TRACEROUTE(1)；  
网络传输相关：curl(1), WGET(1), SSH(1), SCP(1) , SFTP(1), rsync(1)；  
编程工具链：MAKE(1), STRACE(1)；gcc 和 gdb 没有 manual entry；  
软件包管理工具：dpkg(1)；  
查找文件：WHEREIS(1), FIND(1)；  

### 1m. System Admin；
raspbian 下默认只安装了 git，macOS 下安装的 svn(subversion) 有 man page。

### 2.System Calls
系统调用：SYSCALL(2), _EXIT(2), IOCTL(2);  
权限操作接口：CHMOD(2), CHOWN(2), CHDIR(2);  
文件操作接口：FCNTL(2), DUP(2), READ(2), WRITE(2), CLOSE(2);  
C库函数：SIGNAL(2);  
socket 编程接口：BIND(2), LISTEN(2), CONNECT(2), ACCEPT(2), SEND(2), RECV(2), SHUTDOWN(2);  
epoll 编程接口：EVENTFD(2), EPOLL_CREATE(2), EPOLL_CTL(2), EPOLL_WAIT(2);  

1. `man write` 默认查看的是 WRITE(1) - send a message to another user；`man 2 write` 才能明确查看 socket 编程接口 WRITE(2)。  
2. `man accept` 默认查看的是 cupsaccept(8)；`man 2 accept` 才能明确查看 socket 编程接口 ACCEPT(2)。  
3. `man shutdown` 默认查看的是关机命令 SHUTDOWN(8)；`man 2 shutdown` 才能明确查看 socket 编程接口 SHUTDOWN(2)。  
4. macOS(BSD) 下有 KQUEUE(2) 的 man page，raspbian(Debian) 下没有该接口。  

### 3.Subroutines
READLINE(3), HISTORY(3);  
stdio 接口：PRINTF(3);  
Pthreads 相关接口：PTHREAD_ATTR_INIT(3), PTHREAD_SELF(3), PTHREAD_EQUAL(3), PTHREAD_JOIN(3), PTHREAD_CANCEL(3), PTHREAD_DETACH(3), PTHREAD_EXIT(3);  
EXIT(3);  

1. `PRINTF(1)` 为 Linux 内核向 bash shell 提供的格式化输出支持；而这里的 `PRINTF(3)` 为 Linux Programmer's Manual，为标准C库（libstdcxx）头文件 <stdio.h> 提供的控制台格式化打印接口函数。  
2. macOS(BSD) 下有 `PTHREAD(3)` 的 man page，raspbian(Debian) 下没有，只有 PTHREADS(7) 以及 。  

### 4.Special Files

### 5.File Formats
网络接口控制管理：INTERFACES(5), DHCPCD.CONF(5)

INTERFACES(5) 对应 `/etc/network/interfaces`；  
DHCPCD.CONF(5) 对应 `/etc/dhcpcd.conf`;  

### 6.Games

### 7.Macros and Conventions
MAN(7);  
HIER(7);  
PTHREADS(7);  

### 8.Maintenance Commands
系统管理：SUDO(8), SHUTDOWN(8), HALT(8)；  
网络接口管理：IFCONFIG(8), IFUP(8), ；  
网络诊断工具：ARP(8),  RARP(8), PING(8), ROUTE(8), NETSTAT(8),   IPTABLES(8)。  
软件包管理工具：APT(8)  

### 9.Kernel Interface

### N. New Commands  

## Conventional  section

```Shell
       A manual page consists of several sections.

       Conventional  section  names  include  NAME,  SYNOPSIS,  CONFIGURATION,
       DESCRIPTION,  OPTIONS,  EXIT STATUS, RETURN VALUE, ERRORS, ENVIRONMENT,
       FILES, VERSIONS, CONFORMING TO,  NOTES,  BUGS,  EXAMPLE,  AUTHORS,  and
       SEE ALSO.

```

### man man
[Linux 2.6 - man page for man (linux section 1)](https://www.unix.com/man-page/linux/1/man/)

```Shell
MAN(1)					Manual pager utils				   MAN(1)
NAME
       man - an interface to the on-line reference manuals

SYNOPSIS

DESCRIPTION

EXAMPLES

OVERVIEW

DEFAULTS

OPTIONS

EXIT STATUS

ENVIRONMENT

FILES

SEE ALSO

HISTORY

2.6.0.2 				    2011-04-13					   MAN(1)

```

Raspbian GNU/Linux 9.1 (stretch) 下的 man(1) 版本为最新的：

```Shell
2.7.6.1                           2016-12-12                            MAN(1)
```

macOS 下的 man(1) 版本为比较陈旧的：

```Shell
                                  September 19, 2005                            man(1)
```