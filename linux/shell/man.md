
# man

[Linux Man Pages](https://www.linux.org/docs/)  
[善用 man 指令查詢 Linux 線上手冊（Man Page）](https://blog.gtwang.org/linux/linux-man-page-command-examples/)  

[The Linux *man-pages* project](https://www.kernel.org/doc/man-pages/) documents the [Linux](http://en.wikipedia.org/wiki/Linux) [kernel](http://www.kernel.org/pub/linux/kernel) and C library interfaces that are employed by user-space programs.  
With respect to the C library, the primary focus is the [GNU](http://www.gnu.org/) C library (glibc), although, where known, documentation of *variations* on other C libraries available for Linux is also included.

- [CGit](http://git.kernel.org/?p=docs/man-pages/man-pages.git)  
- [Online man pages](http://man7.org/linux/man-pages/index.html) @man7.org  
- [Changelog](http://man7.org/linux/man-pages/changelog.html)  

## manpath

macOS 下的 manpath：

```shell
# 等效 man -w
faner@MBP-FAN:~|⇒  manpath
/usr/local/share/man:/usr/share/man:/opt/X11/share/man:/Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/share/man:/Applications/Xcode-beta.app/Contents/Developer/usr/share/man:/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/share/man
```

raspbian 下的 manpath：

```shell
# 等效 man -w
pi@raspberrypi:~$ manpath
/usr/local/man:/usr/local/share/man:/usr/share/man:/usr/man
```

CentOS 下的 manpath：

```shell
# 等效 man -w
[root@vcentos ~]# manpath
/usr/local/share/man:/usr/share/man
```

### /usr/share/man/

以下为 `/usr/share/man/` 下的详细列表：

```shell
# macOS
faner@MBP-FAN:~|⇒  cd /usr/share/man/
faner@MBP-FAN:/usr/share/man|⇒  ls
man1   man4   man5   man6   man7   man8   man9   mann   whatis

# raspbian
pi@raspberrypi:/usr/share/man$ ls
cs  es  fr.ISO8859-1  hu  ja    man2  man5  man8  pt     sl  zh_CN
da  fi  fr.UTF-8      id  ko    man3  man6  nl    pt_BR  sv  zh_TW
de  fr  gl            it  man1  man4  man7  pl    ru     tr

pi@raspberrypi:/usr/share/man$ ls zh_CN
man1  man5  man8
```

### bash.1

man子目录后面的数字为 man 手册章节序号。

```shell
# macOS
faner@MBP-FAN:/usr/share/man|⇒  ls man1 | grep bash
bash.1
bashbug.1

# raspbian
pi@raspberrypi:/usr/share/man$ ls man1 | grep bash
bash.1.gz
bashbug.1.gz
dh_bash-completion.1.gz
rbash.1.gz
```

### man -w
`man -w` 命令可以查看 man 手册的 nroff 源文件；加上 `-a`(--all) 选项，则显示所有 section 匹配到的命令说明文档路径。

```shell
# macOS
faner@MBP-FAN:~|⇒  man -w bash
/usr/share/man/man1/bash.1

faner@MBP-FAN:~|⇒  man -aw shutdown
/usr/share/man/man8/shutdown.8
/Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/share/man/man8/shutdown.8
/Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/share/man/man2/shutdown.2

# raspbian
pi@raspberrypi:~$ man -w bash
/usr/share/man/man1/bash.1.gz

pi@raspberrypi:/usr/share/man$ man -aw shutdown
/usr/share/man/man8/shutdown.8.gz
/usr/share/man/man2/shutdown.2.gz
```

### man -L

-L 选项可指定帮助文档的语系。

> -L locale, --locale=locale

执行 `ls /usr/share/man/zh_CN` 可知 man 1、5、8 三章节中含有部分中文翻译文档。具体可进一步深入查看 `/zh_CN/man1/` 子目录。

```shell
pi@raspberrypi:~$ man -L zh_CN man
MAN(1)                         手册分页显示工具                         MAN(1)

名称
       man - 在线参考手册的接口
```

## man pager

man 默认使用可翻页查看的 **less** 作为分页器，可指定 `-P pager`（`--pager=pager`） 选项来修改输出分页器程序。

> This option overrides the `$MANPAGER` environment variable, which in turn overrides the `$PAGER` environment variable.

- **linux**: By default, man uses `less`.  
- **raspbian**: By default, man uses `pager`.  
- **macOS**: By default, man uses `/usr/bin/less -is`.  

```shell
pi@raspberrypi:~ $ whatis pager
pager (1)            - opposite of more

pi@raspberrypi:~ $ echo $PAGER
less

# man less
pi@raspberrypi:~ $ whatis less
less (1)             - opposite of more
```

man pager 打开的也是 LESS(1) 的帮助手册。

```shell
faner@MBP-FAN:~|⇒  echo $PAGER
less

# man less
faner@MBP-FAN:~ $ whatis less
less(1)                  - opposite of more
```

可见 man pager 默认是基于 less 的，而 less 基于 more，more 则是基于 vi 的。  

- Interactive commands for ***more*** are based on **vi**(1).  
- Commands of ***less*** are based on both **more** and **vi**.  

也即 man 是基于 **vi-style** 的。  

### help

在查看 man page 时，输入 `:h` 可打开查看 man-page viewer 的操作帮助说明（SUMMARY OF **LESS** COMMANDS）。

- **MOVING**  
- **SEARCHING**  
- **JUMPING**  
- CHANGING FILES  
- MISCELLANEOUS COMMANDS  
- OPTIONS  
- LINE EDITING  

### status line

`man/less/vi` 中输入 **`=`** 可以调出 [bottom status / prompt line](https://askubuntu.com/questions/905322/man-pages-how-to-always-show-total-lines-and-percentage-in-the-bottom-status) 查看阅读进度：

```shell
# raspbian
Downloads/NSURLSession.h lines 3-63/1002 byte 1933/47129 4%  (press RETURN)
```

关于 less 底栏状态行的配置，可参考 [constantly display status line in less](https://unix.stackexchange.com/questions/298329/constantly-display-status-line-in-less)：

可在 `~/.zshrc` 或 `~/.bash_profile`(`~/bashrc`) 中配置 LESS，source 重启生效：

```shell
# less to prompt even more verbosely than more
LESS='-Pslines %lt-%lb (%Pt-%Pb \%) bytes %bt-%bb file %f'; export LESS
```

**说明**：`%l`, `%P`, `%b` for **lines**, **percentage** and **bytes**, trailing `t` and `b` for "**top**" and "**bottom**" of screen.  

`less $ZSH_CUSTOM/scripts/vimman/vimman.zsh` 底栏状态：

```shell
lines 39-95 (20-49 %) bytes 959-2253 file /Users/faner/.oh-my-zsh/custom/scripts/vimman/vimman.zsh
```

可以改良为 `LESS='-Pslines %lt-%lb bytes %bt-%bb %Pb\% of file %f';`

**注意**：man 查看手册，底部 `%f` 为空。

> [Make the less Command More Powerful](https://www.topbug.net/blog/2016/09/27/make-gnu-less-more-powerful/)

## manual page types

```shell
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

[Online man pages](http://man7.org/linux/man-pages/index.html): [by section](http://man7.org/linux/man-pages/dir_all_by_section.html)  |  [alphabetically](http://man7.org/linux/man-pages/dir_all_alphabetic.html)  |  [by project](http://man7.org/linux/man-pages/dir_by_project.html)

- [1: *User commands*](http://man7.org/linux/man-pages/dir_section_1.html); man-pages includes a very few Section 1 pages that document programs supplied by the <u>GNU C library</u>.  
- [2: *System calls*](http://man7.org/linux/man-pages/dir_section_2.html) documents the [system calls](http://man7.org/linux/man-pages/man2/syscalls.2.html) provided by the Linux kernel.  
- [3: *Library functions*](http://man7.org/linux/man-pages/dir_section_3.html) documents the functions provided by the <u>standard C library</u>.  
- [4: *Devices*](http://man7.org/linux/man-pages/dir_section_4.html) documents details of various devices, most of which reside in `/dev`.  
- [5: *Files*](http://man7.org/linux/man-pages/dir_section_5.html) describes various file formats, and includes [proc(5)](http://man7.org/linux/man-pages/man5/proc.5.html), which documents the `/proc` file system.  
- [7: *Overviews, conventions, and miscellaneous*](http://man7.org/linux/man-pages/dir_section_7.html).  
- [*8: Superuser and system administration commands*](http://man7.org/linux/man-pages/dir_section_8.html); man-pages includes a very few Section 8 pages, mainly documenting programs supplied by the <u>GNU C library</u>.  

如果一个关键字（item keyword）出现在多个 man 手册中，则按照手册中的章节号顺序进行搜索。man 预定义的搜索章节号顺序（search available sections following a pre-defined order by default）为 `1 n l 8 3 2 5 4 9 6 7`。  
可在 man 后面接 section 段号，指定从哪本 man 手册中搜索帮助，如 `man 1 kill`（User commands）,`man 2 kill`（System calls）；`man 2 shutdown`（System calls）,`man shutdown 8`（Admin commands）。  

`man -f` 命令可查看命令简介，默认显示第一个搜索到的；加上 `-a`(--all) 选项，则显示所有 section 匹配到的命令。

```shell
# macOS
faner@MBP-FAN:~|⇒  man -af shutdown
servertool(1)            - The Java(TM) IDL Server Tool servertool provides an ease-of-use interface for application programmers to register, unregister, startup and shutdown a server
shutdown(8)              - close down the system at a given time
upsshutdown(8)           - UPS emergency low power shutdown script

# raspbian
pi@raspberrypi:/usr/share/man$ man -af shutdown
shutdown (2)         - shut down part of a full-duplex connection
shutdown (8)         - Halt, power-off or reboot the machine
```

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

```shell
       A manual page consists of several sections.

       Conventional  section  names  include  NAME,  SYNOPSIS,  CONFIGURATION,
       DESCRIPTION,  OPTIONS,  EXIT STATUS, RETURN VALUE, ERRORS, ENVIRONMENT,
       FILES, VERSIONS, CONFORMING TO,  NOTES,  BUGS,  EXAMPLE,  AUTHORS,  and
       SEE ALSO.

```

### man man
[Linux 2.6 - man page for man (linux section 1)](https://www.unix.com/man-page/linux/1/man/)

```shell
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

```shell
2.7.6.1                           2016-12-12                            MAN(1)
```

macOS 下的 man(1) 版本为比较陈旧的：

```shell
                                  September 19, 2005                            man(1)
```

## [man.vim](http://www.vim.org/scripts/script.php?script_id=5615)

[vim-man](https://github.com/vim-utils/vim-man)：View man pages in vim

## [On Viewing `man` Pages](https://scriptingosx.com/2017/04/on-viewing-man-pages/)

[Open man Page in Preview and Save as PDF](http://osxdaily.com/2010/09/27/open-any-man-page-in-preview-and-save-as-pdf/)  
[View Terminal ‘man’ Pages In Preview / PDF](http://www.mactricksandtips.com/2012/01/view-terminal-man-pages-in-preview-pdf.html)  
[Use Preview to view formatted man pages ](http://hints.macworld.com/article.php?story=20051225101106519)  
[Can man pages be converted to html and/or pdf format?](https://apple.stackexchange.com/questions/315272/can-man-pages-be-converted-to-html-and-or-pdf-format)  

### X-man

```shell
faner@MBP-FAN:~|⇒  open x-man-page://sed
```

### man -t

```shell
# man man
       -t     Use  /usr/bin/groff  -Tps  -mandoc -c to format the manual page, passing
              the output to stdout.  The default output format of /usr/bin/groff  -Tps
              -mandoc  -c  is  Postscript,  refer to the manual page of /usr/bin/groff
              -Tps -mandoc -c for ways to pick an alternate format.
```

`man -t` 选项利用 groff 工具将 man page 转换为 PostScript 格式。

#### Preview

`man -t` 结果重定向到 open 使用 Preview.app 打开。

```shell
faner@MBP-FAN:~|⇒  man -t sed | open -fa "Preview"
faner@MBP-FAN:~|⇒  man -t sed | open -f -a /Applications/Preview.app
```

open 的 `-fa` 选项表示 piping output to open(`-f`) and specifies the application(`-a`)，可参考 man open。

zsh 中启用 `osx` 插件，支持 **`man-preview`** 命令调用预览打开 man page（Open a specified man page in Preview app）。例如 `man-preivew sed`。

#### pstopdf

**pstopdf** -- convert PostScript input into a PDF document.

```shell
# 调用 pstopdf 将 man -t 的 PostScript 转换为 PDF 
faner@MBP-FAN:~|⇒  man -t sed | pstopdf -i -o man_sed.pdf
```

### Bwana

A man page reader for your browser

The following are the three main commands you need to know to work with Bwana:

- `man:command` -- used as URL in the browser to call man page.  
- `man:` -- bring up index  
- `man:index_refresh` -- reload index from source pages  
