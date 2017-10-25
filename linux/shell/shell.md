
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

## zsh
终端执行以下命令可通过 curl 从 github 下载安装流行的 Zsh（兼容 bash） 配置 [oh-my-zsh](http://ohmyz.sh/)：

```
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

输入 `zsh --version` 查看 zsh 版本信息：

```Shell
faner@THOMASFAN-MB0:~|⇒  zsh --version
zsh --version
zsh 5.2 (x86_64-apple-darwin16.0)
```

执行 `chsh -s /bin/zsh` 命令（重启生效）可切换为更注重用户体验和交互的 。

> [使用 Zsh 的九个理由](http://blog.jobbole.com/28829/)  
> [Linux终极shell-Z Shell](http://blog.csdn.net/gatieme/article/details/52741221)  
> [为什么说 zsh 是 shell 中的极品？](https://www.zhihu.com/question/21418449)  
> [Mac下采用zsh代替bash](http://www.jianshu.com/p/ae378aa725cf)  
> [oh my zsh 相比 bash 的优势](https://www.zhihu.com/question/29977255)  

### zsh 下切回 bash
如果在 zsh 下执行 sh 脚本（例如 `./startup.sh`）报错，可以按照以下任何一种方式解决：

1. 指定在 bash 下执行脚本：`bash  ./startup.sh`。  
2. 输入 bash 进入 bash 命令环境，然后再执行命令或脚本：`bash-3.2$ ./startup.sh`；通过快捷键 <C-d> 或输入 exit 退回默认 Shell（zsh）。  
3. Shell | New Command（<kbd>⇧</kbd><kbd>⌘</kbd><kbd>N</kbd>）输入 `/bin/bash`，新建 bash shell 临时窗口。  
4. 在终端执行 `chsh -s /bin/bash` 命令（重启生效）将 Shell 切回默认的 bash。  

# Command Line
> [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>> [8 Command Line Editing](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  

## readline
The GNU Readline Library: [Library for command-line editing](https://tiswww.case.edu/php/chet/readline/rltop.html)

在 BASH(1) 的 man page 输入 `/^READLINE`，可搜索 READLINE 相关的说明（the READLINE section of the bash(1) man page）。

> [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>> [8 Command Line Editing](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>>> [8.2 Readline Interaction](https://www.gnu.org/software/bash/manual/bashref.html#Readline-Interaction)  

## Moving
BASH(1) 的 man page 中的 `Commands for Moving`。

[emacs-compatible keybindings](https://stackoverflow.com/questions/81272/is-there-any-way-in-the-os-x-terminal-to-move-the-cursor-word-by-word)

```Shell
beginning-of-line (C-a)
      Move to the start of the current line.
end-of-line (C-e)
      Move to the end of the line.
forward-char (C-f)
      Move forward a character.
backward-char (C-b)
      Move back a character.
forward-word (M-f)
      Move forward to the end  of  the  next  word.   Words  are  composed  of
      alphanumeric characters (letters and digits).
backward-word (M-b)
      Move  back to the start of the current or previous word.  Words are com-
      posed of alphanumeric characters (letters and digits).
clear-screen (C-l)
      Clear the screen leaving the current line at  the  top  of  the  screen.
      With  an argument, refresh the current line without clearing the screen.
redraw-current-line
      Refresh the current line.
```

## Editing
BASH(1) 的 man page 中的 `Commands for Changing Text`。

## Killing and Yanking
BASH(1) 的 man page 中的 `Killing and Yanking`。

## Keyboard Macros
BASH(1) 的 man page 中的 `Keyboard Macros`。

# history
BASH(1) 的 man page 中的议题：

- Searching  
- Commands for Manipulating the History   

## list
输入 `history` 可以查看输入的历史命令。

`!!`：执行上一条命令。

## Search
Readline  provides commands for searching through the command history

- Search as you type. `Ctrl + r` and type the search term; Repeat `Ctrl + r` to loop through results.  
- Search the last remembered search term. `Ctrl + r` twice.  
- End the search at current history entry. `Ctrl + j`.  
- Cancel the search and restore original line. `Ctrl + g`.  