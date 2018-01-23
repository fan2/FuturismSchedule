
# pipe(管道)

参考 BASH(1) manual page 的 `SHELL GRAMMAR > Pipelines` 部分。

11.6 管道命令（pipe）

- 11.6.1 选取命令：cut,grep  
- 11.6.2 排序命令：sort,wc,uniq  
- 11.6.3 双向重定向：tee  
- 11.6.4 字符转换命令：tr,col,join,paste,expand  
- 11.6.5 切割命令：split  
- 11.6.6 参数代换：xargs  
- 11.6.7 关于减号-的用途  

## 管道分隔界定符(|)
A `pipeline` is a sequence of one or more commands separated by one of the control operators `|` or `|&`. The format for a pipeline is:

```shell
[time [-p]] [ ! ] command [ [|⎪|&] command2 ... ]
```

The standard output of *`command`* is connected via a pipe to the standard input of *`command2`*.  
If **`|&`** is used, *`command`*'s standard error, in addition to its standard output, is connected to *`command2`*'s standard input through the pipe; it is shorthand for `2>&1 |`.  

## grep
执行 `grep -V` 查看版本信息：

```shell
pi@raspberrypi:~ $ grep -V
grep (GNU grep) 2.27
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

```shell

执行 `grep --help` 可查看简要帮助。

执行 `man grep` 可查看详细帮助手册：

```shell
pi@raspberrypi:~ $ man grep

GREP(1)                            General Commands Manual                            GREP(1)

NAME
       grep, egrep, fgrep, rgrep - print lines matching a pattern

SYNOPSIS
       grep [OPTIONS] PATTERN [FILE...]
       grep [OPTIONS] [-e PATTERN]...  [-f FILE]...  [FILE...]

DESCRIPTION
       grep searches the named input FILEs for lines containing a match to the given PATTERN.
       If no files are specified, or if the file “-” is given, grep searches standard  input.
       By default, grep prints the matching lines.
```

`svn log --search fan -l 100`（`svn log -l 100 | grep fan`）：从最近100条日志中查找 fan 提交的记录。  

## sed
执行 `sed --version` 查看版本信息：

```shell
pi@raspberrypi:~ $ sed --version
sed (GNU sed) 4.4
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Jay Fenlason, Tom Lord, Ken Pizzini,
and Paolo Bonzini.
GNU sed home page: <http://www.gnu.org/software/sed/>.
General help using GNU software: <http://www.gnu.org/gethelp/>.
E-mail bug reports to: <bug-sed@gnu.org>.
```

执行 `sed --help` 可查看简要帮助。

执行 `man sed` 可查看详细帮助手册：

```shell
pi@raspberrypi:~ $ man sed

SED(1)                                  User Commands                                  SED(1)

NAME
       sed - stream editor for filtering and transforming text

SYNOPSIS
       sed [OPTION]... {script-only-if-no-other-script} [input-file]...

DESCRIPTION
       Sed is a stream editor.  A stream editor is used to perform basic text transformations
       on an input stream (a file or input from a pipeline).  While in some ways  similar  to
       an editor which permits scripted edits (such as ed), sed works by making only one pass
       over the input(s), and is consequently more efficient.  But it  is  sed's  ability  to
       filter text in a pipeline which particularly distinguishes it from other types of edi‐
       tors.

```

`svn log -v | sed -n '/fan/,/-----$/ p'` 

## cut
执行 `cut --version` 查看版本信息：

```shell
pi@raspberrypi:~ $ cut --version
cut (GNU coreutils) 8.26
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by David M. Ihnat, David MacKenzie, and Jim Meyering.
```

执行 `cut --help` 可查看简要帮助。

执行 `man cut` 可查看详细帮助手册：

```shell
pi@raspberrypi:~ $ man cut

CUT(1)                                  User Commands                                  CUT(1)

NAME
       cut - remove sections from each line of files

SYNOPSIS
       cut OPTION... [FILE]...

DESCRIPTION
       Print selected parts of lines from each FILE to standard output.

       With no FILE, or when FILE is -, read standard input.

       Mandatory arguments to long options are mandatory for short options too.
```

## xargs
执行 `xargs --version` 查看版本信息：

```shell
pi@raspberrypi:~ $ xargs --version
xargs (GNU findutils) 4.7.0-git
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Eric B. Decker, James Youngman, and Kevin Dalley.
```

执行 `xargs --help` 可查看简要帮助。

执行 `man xargs` 可查看详细帮助手册：

```shell
pi@raspberrypi:~ $ man xargs

XARGS(1)                           General Commands Manual                           XARGS(1)

NAME
       xargs - build and execute command lines from standard input



DESCRIPTION
       This manual page documents the GNU version of xargs.  xargs reads items from the stan‐
       dard input, delimited by blanks (which can be protected with double or  single  quotes
       or  a  backslash)  or newlines, and executes the command (default is /bin/echo) one or
       more times with any initial-arguments followed by  items  read  from  standard  input.
       Blank lines on the standard input are ignored.
```

## demos
### demo 1
[Homebrew](https://docs.brew.sh/) [Installation](https://docs.brew.sh/Installation.html) 脚本，基于 `&&` 递进执行相关命令：创建目录，下载并解压。

```shell
mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew
```

### demo 2

```shell
pi@raspberrypi:~ $ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games
pi@raspberrypi:~ $ PATH=$PATH:/usr/local/sbin
pi@raspberrypi:~ $ echo $PATH 
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games:/usr/local/sbin
```

如何删除刚才追加重复的 `/usr/local/sbin`？

直接 `PATH=` 赋值修改前的值 `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games`。

执行 `PATH=$(echo $PATH | cut -d : -f 1,3-)` 可移除第2项；

### demo 3
查找当前目录下的 `.svn` 目录，然后通过管道 xargs 作为参数传递给 `rm -rf` 执行删除。

```shell
find . -type d -name ".svn"|xargs rm -rf
```

### demo 4

how count all lines in all files in current dir and omit empty lines with wc, grep, cut and bc commands

```Shell
echo `wc -l * | grep total | cut -f2 -d’ ‘` – `grep -in “^$” * | wc -l ` | bc
```

