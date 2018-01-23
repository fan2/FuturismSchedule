
# Shells
终端执行 `cat /etc/shells` 查看支持的 shell：

```Shell
# macOS
faner@THOMASFAN-MB0:~|⇒  cat /etc/shells
# List of acceptable shells for chpass(1).
# Ftpd will not allow users to connect who are not using
# one of these shells.

/bin/bash
/bin/csh
/bin/ksh
/bin/sh
/bin/tcsh
/bin/zsh

# raspbian
pi@raspberrypi:~$ cat /etc/shells
cat /etc/shells
# /etc/shells: valid login shells
/bin/sh
/bin/dash
/bin/bash
/bin/rbash
/usr/bin/screen
```

终端执行 `env | grep 'SHELL'` 或 `echo $SHELL` 可查看当前账户正在使用的 shell：

```Shell
pi@raspberrypi:~$ env | grep 'SHELL'
SHELL=/bin/bash

faner@THOMASFAN-MB0:~|⇒  echo $SHELL
/bin/bash
```

## bash
macOS（BSD）、raspbian（Debian） 系统默认 Shell 均为 `/bin/bash`。

> [Bash Keyboard Shortcuts](https://ss64.com/osx/syntax-bashkeyboard.html) @ss64  
> [20 Terminal shortcuts developers need to know](http://www.techrepublic.com/article/20-terminal-shortcuts-developers-need-to-know/)  
> [Using the Terminal keybindings with bash on macOS](https://superuser.com/questions/124336/using-the-terminal-keybindings-with-bash-on-macos)  
> [Shortcuts to move faster in Bash command line](http://teohm.com/blog/shortcuts-to-move-faster-in-bash-command-line/)  
> [The Best Keyboard Shortcuts for Bash (aka the Linux and macOS Terminal)](https://www.howtogeek.com/howto/ubuntu/keyboard-shortcuts-for-bash-command-shell-for-ubuntu-debian-suse-redhat-linux-etc/)  
> [List of default Mac OS X command-line editing bash keyboard shortcuts](https://maymay.net/blog/2007/07/18/list-of-default-mac-os-x-command-line-editing-bash-keyboard-shortcuts/)  

输入 `bash --version` 查看 bash 版本信息：

```Shell
# macOS
faner@THOMASFAN-MB0:~|⇒  bash --version
bash --version
GNU bash, version 3.2.57(1)-release (x86_64-apple-darwin16)
Copyright (C) 2007 Free Software Foundation, Inc.

# raspbian
pi@raspberrypi:~$ bash --version
bash --version
GNU bash, version 4.4.12(1)-release (arm-unknown-linux-gnueabihf)
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>

This is free software; you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

输入执行 `man bash` 或 `man 1 bash` 可以查看 bash 的说明文档——[GNU Bash manual](https://www.gnu.org/software/bash/manual/) | [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html)。

### PROMPTING
When executing interactively, **bash** *displays* the <u>primary</u> prompt **PS1** when it is ready to read a command,  

> PS1 stands for "Prompt String One" or "Prompt Statement One", the first prompt string (that you see at a command line).  
> The default value is `'\s-\v\$'`, such as `bash-3.2$`.  

and the <u>secondary</u> prompt **PS2** when it needs more *input* to complete a command.  

> PS2 The secondary prompt string. ie for continued commands (those taking more than one line).  
> The default value is `'>'`.  

**Bash** displays **PS0** *after it reads* a command but *before executing* it.  

> [Why is bash's prompt variable called PS1?](https://unix.stackexchange.com/questions/32096/why-is-bashs-prompt-variable-called-ps1)  
> [Bash Shell: Take Control of PS1, PS2, PS3, PS4 and PROMPT_COMMAND](http://www.thegeekstuff.com/2008/09/bash-shell-take-control-of-ps1-ps2-ps3-ps4-and-prompt_command/)  
> [Echo expanded PS1](https://stackoverflow.com/questions/3451993/echo-expanded-ps1)  
> [Bash prompt basics](https://linuxconfig.org/bash-prompt-basics)  
> [Linux用户命令行字符环境变量](http://blog.csdn.net/cheungjustin/article/details/5825213)  
> [shell PS1 PS2 PS3 PS4界面提示符](http://blog.csdn.net/misskissc/article/details/8144283)  
> [Linux下PS1、PS2、PS3、PS4使用详解](http://os.51cto.com/art/201205/334954.htm)  

### command type
bash 内置的 **type** 命令可以查看某个命令是否为 bash 的内置命令。

例如 cd、ECHO(1) 命令为 bash 内置：

```Shell
pi@raspberrypi:~$ type -t cd
builtin

pi@raspberrypi:~$ type -a cd
cd is a shell builtin

pi@raspberrypi:~$ type -t echo
builtin

pi@raspberrypi:~$ type -a echo
echo is a shell builtin
echo is /bin/echo
```

type（和 cd）命令的说明内含在 bash 的 man page 中（`type [-aftpP] name [name ...]`），没有对应的 manual page entry。

```Shell
pi@raspberrypi:~$ man type
No manual entry for type

pi@raspberrypi:~$ man cd
No manual entry for cd
```

ECHO(1) 命令有 manual page，可执行 `man echo` 或  `man 1 echo` 查看。

SU(1)、SUDO(8)、NANO(1)、VIM(1)、SSH(1)、rsync(1)、SFTP(1)、IFCONFIG(8) 为外部命令：

```Shell
pi@raspberrypi:~$ type -t sudo
file
pi@raspberrypi:~$ type -p sudo
/usr/bin/sudo
pi@raspberrypi:~$ type -a sudo
sudo is /usr/bin/sudo

pi@raspberrypi:~$ type -t vim
file
pi@raspberrypi:~$ type -p vim
/usr/bin/vim
pi@raspberrypi:~$ type -a vim
vim is /usr/bin/vim

pi@raspberrypi:~$ type -t ifconfig
file
pi@raspberrypi:~$ type -p ifconfig
/sbin/ifconfig
pi@raspberrypi:~$ type -a ifconfig
ifconfig is /sbin/ifconfig
```

### Special keys

- `C-i` = Tab  
- `C-g` = Abort，放弃当前行，新起一行  
- `C-j` = Newline，运行当前行，新起一行  
- `C-[` = Escape  
- `C-m` = Enter  
- `C-_` / `<C-x>u` = Undo  

### Special characters
#### single quotes
bash shell 中可通过等号（equality sign）赋值定义变量，但是等号前后左侧变量名和右值只能为单符号，不能含有空格。

```shell
pi@raspberrypi:~ $ testString=define string in shell command line
-bash: string: command not found
```

以上第一个空格将截出 `testString=define` 命令1，string 为命令2，由于找不到 `string` 命令而报错。

当然，我们可以用反斜杠 `\` 转义显式定义空格。

```shell
pi@raspberrypi:~ $ testString=define\ string\ in\ shell\ command\ line
pi@raspberrypi:~ $ echo $testString 
define string in shell command line
```

另外一种编程语言中常见的定义字符串的方式是通过单引号或双引号来封闭定义。

```shell
# 单引号定义字符串
pi@raspberrypi:~ $ testString='define string in shell command line'
pi@raspberrypi:~ $ echo $testString 
define string in shell command line

# 双引号重定义字符串
pi@raspberrypi:~ $ testString="define string in shell command line"
pi@raspberrypi:~ $ echo $testString 
define string in shell command line
```

#### double quotes
单引号将 `$` 视作普通字符，不会替代解引用变量值：

```shell
pi@raspberrypi:~ $ varLANG='env LANG=$LANG'
pi@raspberrypi:~ $ echo $varLANG 
env LANG=$LANG
```

双引号可识别 shell 的特殊字符 `$`，解引用变量值并替换。

```shell
pi@raspberrypi:~ $ varLC_CTYPE="LC_CTYPE = $LC_CTYPE"
pi@raspberrypi:~ $ echo ${varLC_CTYPE}
LC_CTYPE = UTF-8
```

双引号中若要打印普通的 `$` 符号，可使用反斜杠 `\$` 转义为普通字符。

```shell
pi@raspberrypi:~ $ varLC_CTYPE="LC_CTYPE = \$LC_CTYPE"
pi@raspberrypi:~ $ echo ${varLC_CTYPE}
LC_CTYPE = $LC_CTYPE
```

以下右值引用中的 `$testPATH` 和 `${testPATH}` 可加双引号。

```shell
# testPATH 初始值
pi@raspberrypi:~ $ testPATH=/usr/bin:/bin:/usr/sbin:/sbin

# 头部插入
pi@raspberrypi:~ $ testPATH=/usr/local/bin:$testPATH

# 尾部追加
pi@raspberrypi:~ $ testPATH=${testPATH}:/usr/local/sbin
```

以下 [brew 的官网首页](http://brew.sh/index.html) 给出的 Homebrew 安装命令：

```shell
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

1. 调用 **curl** 下载 Homebrew 的 安装脚本 [install.rb](https://github.com/Homebrew/install/blob/master/install)  

	> `-f`, --fail: (HTTP)  Fail  silently (no output at all) on server errors.  
	> `-s`, --silent: Silent or quiet mode. Don't show progress meter or  error  messages. Makes  Curl mute.  
	> `-S`, --show-error: When used with -s, --silent, it makes curl show an error message if it fails.  
	> `-L`, --location: (HTTP)  If  the  server  reports  that the requested page has moved to a different location (indicated with a Location: header and a 3XX response code), this  option will  make  curl  redo  the  request  on  the new place.  

2. 调用 **ruby** 执行下载的安装脚本（install.rb）。

	> `-e` 'command': one line of script.  

以下选自 [清华大学开源软件镜像站](https://mirror.tuna.tsinghua.edu.cn/) 的 [Homebrew 镜像使用帮助](https://mirror.tuna.tsinghua.edu.cn/help/homebrew/)：

```shell
# $(brew --repo) 可加双引号
faner@THOMASFAN-MB0:~|⇒  cd $(brew --repo)
faner@THOMASFAN-MB0:/usr/local/Homebrew|stable

# $(brew --repo) 可加双引号
⇒  cd $(brew --repo)/Library/Taps/homebrew/homebrew-core
faner@THOMASFAN-MB0:/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core|master
⇒  
```

#### backtick quotes
在 shell 命令中，往往需要将其他命令执行结果作为输入信息，此时可使用 “\`command\`” 或 “$(command)” 引用 command 执行结果。

Linux Distributions 都可能拥有多个内核版本，且几乎 distribution 的所有内核版本都不相同。  
若想进入当前内核的模块目录，可以先执行 `uname -r` 获取发行版本信息（-r, --kernel-release），然后 cd 进入目前内核的驱动程序所放位置。

```shell
pi@raspberrypi:~ $ uname -r
4.9.59-v7+
pi@raspberrypi:~ $ cd /lib/modules/`uname -r`/kernel
pi@raspberrypi:/lib/modules/4.9.59-v7+/kernel $ ls
arch  crypto  drivers  fs  kernel  lib  mm  net  sound
pi@raspberrypi:/lib/modules/4.9.59-v7+/kernel $ ls | wc -l
9
```

以上 \`uname -r\` 可替换为 `$(uname -r)` 或 `"$(uname -r)"`。

1. 先执行反单引号内的命令 `uname -r` 获取内核版本为 `4.9.59-v7+`；  
2. 将上述结果代入 cd 命令的目录中，得到实际命令 `/lib/modules/4.9.59-v7+/kernel`。  

鉴于反单引号容易打错或弄错，建议使用 **`$(uname -r)`** 这种解引用格式。

#### && / ||
使用空格或分号（`;`）可执行无相关性的连续命令：

```
faner@THOMASFAN-MB0:~|⇒  test1='test 1' test2='test 2'
faner@THOMASFAN-MB0:~|⇒  echo $test1
test 1
faner@THOMASFAN-MB0:~|⇒  echo $test2
test 2
faner@THOMASFAN-MB0:~|⇒  echo $test1;echo $test2
test 1
test 2
```

`&&` 和 `||` 则可连续执行相关性的命令。

`command1 || command2`：在逻辑上只要有第一条命令执行成功就不会执行第二条命令，只有第一条命令执行失败才会启动执行第二条命令。

`command1 && command2`：只有在第一条命令执行成功时才会启动执行第二条命令。

```shell
mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master
```

> 若 `mkdir homebrew` 执行完毕且正确执行（成功创建目录 `homebrew`），则启动执行后面的 `curl -L` 命令。  

## zsh
终端执行以下命令可通过 curl 从 github 下载安装流行的 Zsh（兼容 bash） 配置 [oh-my-zsh](http://ohmyz.sh/)：

```Shell
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

输入 `zsh --version` 查看 zsh 版本信息：

```Shell
faner@THOMASFAN-MB0:~|⇒  zsh --version
zsh --version
zsh 5.2 (x86_64-apple-darwin16.0)
```

执行 `chsh -s /bin/zsh` 命令（重启生效）可切换为更注重用户体验和交互的 zsh。

> [使用 Zsh 的九个理由](http://blog.jobbole.com/28829/)  
> [Linux终极shell-Z Shell](http://blog.csdn.net/gatieme/article/details/52741221)  
> [为什么说 zsh 是 shell 中的极品？](https://www.zhihu.com/question/21418449)  
> [Mac下采用zsh代替bash](http://www.jianshu.com/p/ae378aa725cf)  
> [oh my zsh 相比 bash 的优势](https://www.zhihu.com/question/29977255)  

### zsh 下切回 bash
如果在 zsh 下执行 sh 脚本（例如 `./startup.sh`）报错，可以按照以下任何一种方式解决：

1. 指定在 bash 下执行脚本：`bash ./startup.sh`。  
2. 输入 bash 进入 bash 命令环境，然后再执行命令或脚本：`bash-3.2$ ./startup.sh`；通过快捷键 <C-d> 或输入 exit 退回默认 Shell（zsh）。  
3. Shell | New Command（<kbd>⇧</kbd><kbd>⌘</kbd><kbd>N</kbd>）输入 `/bin/bash`，新建 bash shell 临时窗口。  
4. 在终端执行 `chsh -s /bin/bash` 命令（重启生效）将 Shell 切回默认的 bash。  
