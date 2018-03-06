
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

`ls -al /etc | less`：列举 `/etc` 目录，然后导向 less 使可翻页查看。

## grep
grep 过滤筛选出符合条件的行。

执行 `grep -V` 查看版本信息：

```shell
pi@raspberrypi:~ $ grep -V
grep (GNU grep) 2.27
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

执行 `grep --help` 可查看简要帮助（Usage）。

```shell

Regexp selection and interpretation:
# 忽略大小写敏感
  -i, --ignore-case         ignore case distinctions
  -w, --word-regexp         force PATTERN to match only whole words
  -x, --line-regexp         force PATTERN to match only whole lines

Miscellaneous:
# 匹配补集，过滤出不包含 '查找字符串' 的行
  -v, --invert-match        select non-matching lines

Output control:
# 最多查找条目，相当于 grep | head -n NUM
  -m, --max-count=NUM       stop after NUM matches
  -b, --byte-offset         print the byte offset with output lines

# 顺便打印行号
  -n, --line-number         print line number with output lines
      --line-buffered       flush output on every line

  -a, --text                equivalent to --binary-files=text

# 只列举（不）符合条件的文件名
  -L, --files-without-match  print only names of FILEs containing no match
  -l, --files-with-matches  print only names of FILEs containing matches

# 仅仅打印匹配的行数
  -c, --count               print only a count of matching lines per FILE

# 查找结果上下文
Context control:
# 顺便打印查找结果上面 NUM 行
  -B, --before-context=NUM  print NUM lines of leading context
# 顺便打印查找结果下面 NUM 行
  -A, --after-context=NUM   print NUM lines of trailing context
# 顺便打印查找结果上面和下面各 NUM 行
  -C, --context=NUM         print NUM lines of output context
  -NUM                      same as --context=NUM

```

执行 `man grep` 可查看详细帮助手册（Manual Page）：

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

       In  addition,  the  variant  programs  egrep, fgrep and rgrep are the same as grep -E,
       grep -F, and grep -r, respectively.  These variants are deprecated, but  are  provided
       for backward compatibility.

OPTIONS
   Generic Program Information
       --help Output a usage message and exit.

       -V, --version
              Output the version number of grep and exit.

   Matcher Selection
       -E, --extended-regexp
              Interpret PATTERN as an extended regular expression (ERE, see below).

       -F, --fixed-strings
              Interpret  PATTERN as a list of fixed strings (instead of regular expressions),
              separated by newlines, any of which is to be matched.

       -G, --basic-regexp
              Interpret PATTERN as a basic regular expression (BRE, see below).  This is  the
              default.

       -P, --perl-regexp
              Interpret  the pattern as a Perl-compatible regular expression (PCRE).  This is
              highly experimental and grep -P may warn of unimplemented features.
```

### ls
`ls -al | grep '^d'`：过滤出 ls 结果中以 d 开头的（即文件夹）。  

### svn log
`svn log -l 100 | grep fan`（`svn log --search fan -l 100`）：从最近100条日志中查找 fan 提交的记录。

### file

```shell
# 查找 src/ 下所有文件编码为 ISO-8859 的文件个数
faner@MBP-FAN:~/Downloads/src|⇒  find . -type f -exec file {} \; | grep -c 'ISO-8859'
15
```

## cut
cut 可以基于分隔符（separator/delimiter）将行内数据进行切割，分解出所需的信息列。

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

执行 `cut --help` 可查看简要帮助（Usage）。

```shell
-c, --characters=LIST   select only these characters
-d, --delimiter=DELIM   use DELIM instead of TAB for field delimiter
-f, --fields=LIST       select only these fields;
```

执行 `man cut` 可查看详细帮助手册（Manual Page）：

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

### PATH
PATH 环境变量是以 `:` 分隔多个路径，可以使用 cut 命令提取其中部分路径。

```shell
faner@MBP-FAN:~|⇒  echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin
faner@MBP-FAN:~|⇒  echo $PATH | cut -d ':' -f 3  
/bin
faner@MBP-FAN:~|⇒  echo $PATH | cut -d ':' -f 5
/sbin
faner@MBP-FAN:~|⇒  echo $PATH | cut -d ':' -f 3,5
/bin:/sbin
```

### enca

enca 执行结果输出行格式为 `file: iconv charset`：

```shell
faner@MBP-FAN:~/Downloads/include|⇒  enca -L zh_CN -i *
UtilcFunctions.h: ASCII
WifiPhotoIf.h: UTF-8
liteif.h: GBK
litelog.h: UTF-8
litenet.h: ASCII
litestd.h: UTF-8
litetime.h: ASCII

# 提取第1列：文件名称
faner@MBP-FAN:~/Downloads/include|⇒  enca -L zh_CN -i * | cut -d ':' -f 1
UtilcFunctions.h
WifiPhotoIf.h
liteif.h
litelog.h
litenet.h
litestd.h
litetime.h

# 提取第2列：字符编码(注意行首有空格)
faner@MBP-FAN:~/Downloads/include|⇒  enca -L zh_CN -i * | cut -d ':' -f 2
 ASCII
 UTF-8
 GBK
 UTF-8
 ASCII
 UTF-8
 ASCII
```

### file
file 执行结果输出行格式为 `file: description & charset`：

```shell
faner@MBP-FAN:~/Downloads/include|⇒  file *
UtilcFunctions.h: c program text, ASCII text
WifiPhotoIf.h:    c program text, UTF-8 Unicode text
liteif.h:         c program text, ISO-8859 text, with CRLF line terminators
litelog.h:        c program text, UTF-8 Unicode (with BOM) text
litenet.h:        c program text, ASCII text, with CRLF, LF line terminators
litestd.h:        c program text, UTF-8 Unicode text, with CRLF line terminators
litetime.h:       c program text, ASCII text, with CRLF line terminators

# 先以 : 分割第1列，再以 , 分割第2列，获取编码部分
faner@MBP-FAN:~/Downloads/include|⇒  file * | cut -d ':' -f 2 | cut -d ',' -f 2
 ASCII text
 UTF-8 Unicode text
 ISO-8859 text
 UTF-8 Unicode (with BOM) text
 ASCII text
 UTF-8 Unicode text
 ASCII text
```

### export
export 声明变量排列整齐，可据此以字符为单位提取固定字符位置区间：

```shell
# 获取 export 前4条
pi@raspberrypi:~ $ export | head -n 4
declare -x DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/1000/bus"
declare -x HOME="/home/pi"
declare -x INFINALITY_FT_AUTOHINT_HORIZONTAL_STEM_DARKEN_STRENGTH="10"
declare -x INFINALITY_FT_AUTOHINT_INCREASE_GLYPH_HEIGHTS="true"

# 提取12个字符及其后的部分（移除行首的11个字符(declare -x )）
## 12为起始位置，-后面未指定结束位置，表示至行尾
pi@raspberrypi:~ $ export | head -n 4 | cut -c 12-
DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/1000/bus"
HOME="/home/pi"
INFINALITY_FT_AUTOHINT_HORIZONTAL_STEM_DARKEN_STRENGTH="10"
INFINALITY_FT_AUTOHINT_INCREASE_GLYPH_HEIGHTS="true"
```

其他像 ps、last 等命令输出都由空白（空格或tab 制表符）控制排版格式，连续空白较难合适分割。

### grep & cut
grep 和 cut  综合示例：

```shell
faner@MBP-FAN:~/Downloads/include|⇒  file *
UtilcFunctions.h: c program text, ASCII text
WifiPhotoIf.h:    c program text, UTF-8 Unicode text
liteif.h:         c program text, ISO-8859 text, with CRLF line terminators
litelog.h:        c program text, UTF-8 Unicode (with BOM) text
litenet.h:        c program text, ASCII text, with CRLF, LF line terminators
litestd.h:        c program text, UTF-8 Unicode text, with CRLF line terminators
litetime.h:       c program text, ASCII text, with CRLF line terminators

# 过滤出编码为 ISO-8859 的文件
faner@MBP-FAN:~/Downloads/include|⇒  file * | grep ISO-8859 | cut -d ':' -f 1
liteif.h
```

## wc,sort,uniq
### wc
**wc** - print newline, word, and byte counts for each file

```shell
-c, --bytes
      print the byte counts

-m, --chars
      print the character counts

-w, --words
      print the word counts

-l, --lines
      print the newline counts
```

### sort
**sort** - sort lines of text files

### uniq
**uniq** - report or omit repeated lines

统计 `mars/mars/stn/src` 目录下类数（同名的 h/cc）

```shell
faner@MBP-FAN:~/Projects/git/framework/mars/mars/stn/src|master⚡ 
⇒  ls | cut -d '.' -f 1 | uniq -c
   2 anti_avalanche
   2 dynamic_timeout
   2 flow_limit
   2 frequency_limit
   2 longlink
   2 longlink_connect_monitor
   2 longlink_identify_checker
   2 longlink_speed_test
   2 longlink_task_manager
   2 net_channel_factory
   2 net_check_logic
   2 net_core
   2 net_source
   2 netsource_timercheck
   2 proxy_test
   2 shortlink
   1 shortlink_interface
   2 shortlink_task_manager
   2 signalling_keeper
   2 simple_ipport_sort
   2 smart_heartbeat
   1 special_ini
   1 task_profile
   2 timing_sync
   2 zombie_task_manager
```

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

执行 `sed --help` 可查看简要帮助（Usage）。

执行 `man sed` 可查看详细帮助手册（Manual Page）：

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

执行 `xargs --help` 可查看简要帮助（Usage）。

执行 `man xargs` 可查看详细帮助手册（Manual Page）：

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
  
- [Homebrew](https://docs.brew.sh/) [Installation](https://docs.brew.sh/Installation.html) 脚本，基于 `&&` 递进执行相关命令：创建目录，下载并解压。

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
查找当前目录及其子目录下所有的 `.o` 文件，然后通过管道 xargs 作为参数传递给 `rm -rf`  [递归删除子目录下所有.o后缀文件](http://blog.163.com/sweet_hard/blog/static/66656838201162294812840/)：

```shell
find . -name "*.o"  | xargs rm -f
```

查找当前目录下的 `.svn` 目录，然后通过管道 xargs 作为参数传递给 `rm -rf` 执行删除。

```shell
find . -type d -name ".svn" | xargs rm -rf
```

### demo 4

how count all lines in all files in current dir and omit empty lines with wc, grep, cut and bc commands

```Shell
echo `wc -l * | grep total | cut -f2 -d’ ‘` – `grep -in “^$” * | wc -l ` | bc
```

### demo.todo
- 针对当前（指定）目录下的文件执行 **`file`** 命令，过滤出编码为 ASCII,UTF-8 之外的所有文件。  
	> grep -v；正则或；  
- 针对当前（指定）目录下的文件执行 **`file`** 命令，过滤出编码为 *`ISO-8859`* 的文件，执行 **`iconv`** 或 **`enca`** 将以上文件都转码为 *`UTF-8`*。  
	> cut grep 结果集切出符合条件的文件集；针对文件集进行批量转码。  
