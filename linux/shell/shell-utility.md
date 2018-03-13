## cd
cd（change directory）：切换文件目录。

- `cd` / `cd ~`：进入当前用户的家目录（$HOME）；  
- `cd ..`：返回上级目录；  
- `cd -`：返回上次访问目录（相当于 `cd $OLDPWD`），再次执行在近两次目录之间切换。  

切换到带有空格的路径，需要加转义字符（反斜杠<kbd>\\</kbd>）来标识空格。

以下示例从 `~/` 目录切换到 `/Library/Application Support/Sublime Text 3/Packages/User`：

```Shell
faner@THOMASFAN-MB0:~|⇒  cd /Users/faner/Library/Application\ Support/Sublime\ Text\ 3/Packages/User/
faner@THOMASFAN-MB0:~/Library/Application Support/Sublime Text 3/Packages/User|
⇒  
```

另外一种做法是定义 shell 字符串变量，然后使用 <kbd>$</kbd> 符号解引用变量作为 cd 的参数：

```Shell
faner@THOMASFAN-MB0:~|⇒  dir="/Users/faner/Library/Application Support/Sublime Text 3/Packages/User/"                    
faner@THOMASFAN-MB0:~|⇒  cd $dir
faner@THOMASFAN-MB0:~/Library/Application Support/Sublime Text 3/Packages/User|
```

### pushd & popd
`cd -` 可在近两次目录之间切换，当涉及3个以上的工作目录需要切换时，可以使用 pushd 和 popd 命令。

macOS 的 zsh 命令行输入 push 然后 tab 可以查看所有 push 相关命令：

```shell
faner@MBP-FAN:~|⇒  push
pushd   pushdf  pushln
```

- 其中 **pushdf** 表示切换到当前 Finder 目录（`pushd` to the current Finder directory）。  
- 关于 **pushln** 可参考 zsh-manual [Shell Builtin Commands](http://bolyai.cs.elte.hu/zsh-manual/zsh_toc.html#TOC65) 中的说明。  

> 在 macOS 终端中执行 `man pushd` 或 `man popd` 可知，他们为 BASH 内置命令（Shell builtin commands）。

**`pushd`** 和 **`popd`** 可以用于在多个目录（directory）之间进行切换（push/pop）而无需复制并粘贴目录路径。 

`pushd` 和 `popd` 以栈的方式来运作，后进先出（Last In First Out, LIFO）。目录路径被存储在栈中，然后用 push 和 pop 操作在目录之间进行切换。

```shell

# 执行 dirs -c 清理栈之后，只剩当前目录
faner@MBP-FAN:~|⇒  dirs
~

# 将 ~/Downloads 目录压栈
faner@MBP-FAN:~|⇒  pushd Downloads 
~/Downloads ~

# 将 ~/Documents 目录压栈
faner@MBP-FAN:~/Downloads|⇒  pushd ../Documents 
~/Documents ~/Downloads ~

# 依次执行 pushd ../Movies、pushd ../Pictures、pushd ../AppData、pushd ../Applications、pushd ../Desktop

# 将 ~/Music 目录压栈
faner@MBP-FAN:~/Desktop|⇒  pushd ../Music 
~/Music ~/Desktop ~/Applications ~/AppData ~/Pictures ~/Movies ~/Documents ~/Downloads ~
```

**`dirs`**：查看当前 Shell 窗口操作过的目录栈记录，索引0表示栈顶。

 选项 | 含义
-----|------
-p  | 每行显示一条记录
-v  | 每行显示一条记录，同时展示该记录在栈中的index
-c  | 清空目录栈

```shell
# 查看当前栈，0为栈顶，8为栈底
faner@MBP-FAN:~/Music|⇒  dirs -v
0   ~/Music
1   ~/Desktop
2   ~/Applications
3   ~/AppData
4   ~/Pictures
5   ~/Movies
6   ~/Documents
7   ~/Downloads
8   ~
```

- 不带参数输入 **pushd** 会将栈顶目录和下一目录对调，相当于 `cd -` 的效果。  

	> pushd 还可以带索引选项 +n，**切换**到当前栈中从栈底开始计数的某个目录。

- 不带参数输入 **popd** 会移除栈顶（当前）目录，切换到上一次访问的目录。  

	> popd 还可以带索引选项 +n，移除当前栈中从栈底开始计数的某个目录。

对于 `pushd +n` 和 `popd +n`，索引顺序与 `dirs -v` 相反，从栈底开始计数；  
反过来 `pushd -n` 和 `popd -n` 索引顺序与 `dirs -v` 相同，从栈顶开始计数。

```shell
# 从栈底（索引为0）右往左数第3个目录 ~/Movies 重新压入栈顶，相当于切换到该目录
faner@MBP-FAN:~/Music|⇒  pushd +3
~/Movies ~/Documents ~/Downloads ~ ~/Music ~/Desktop ~/Applications ~/AppData ~/Pictures

# 从栈顶（索引为-0）左往右数第3个目录 ~ 移除出栈
faner@MBP-FAN:~/Movies|⇒  popd -3
~/Movies ~/Documents ~/Downloads ~/Music ~/Desktop ~/Applications ~/AppData ~/Pictures

# 从栈顶（索引为-0）左往右数第3个目录 ~/Music 重新压入栈顶，相当于切换到该目录
faner@MBP-FAN:~/Movies|⇒  pushd -3
~/Music ~/Desktop ~/Applications ~/AppData ~/Pictures ~/Movies ~/Documents ~/Downloads

# 从栈底（索引为0）右往左数第3个目录 ~/Pictures 移除出栈
faner@MBP-FAN:~/Music|⇒  popd +3
~/Music ~/Desktop ~/Applications ~/AppData ~/Movies ~/Documents ~/Downloads
```

[Linux中的pushd和popd](https://www.jianshu.com/p/53cccae3c443)  
[在命令行中使用pushd和popd进行快速定位](http://blog.sina.com.cn/s/blog_b6b704ef0102wjdk.html)  

## ls
`ls -ld`: 显示当前文件夹(`.`)信息。  

`ls -lS`：按大小（**降序**）列出文件和文件夹详细信息。  
`ls -lSr`：按大小**升序**列出文件和文件夹详细信息。  

`ls -lt`：按修改时间（**降序**）列出文件和文件夹详细信息。  
`ls -ltr`：按修改时间**升序**列出文件和文件夹详细信息。  

`ls -lR`：递归列举当前及所有子文件夹。

### ls only file/dir

- `ls -d */`：通配符语法  
- `ls -l | grep '^d'`：grep 正则表达式，过滤出以 d 开头的**文件夹**  
- `ls -al | grep '^[^d]'`：grep 正则表达式，过滤出非 d 开头的**文件**  

其他命令：

- `find . -maxdepth 1 -type d`  
- `tree -d -L 1`  

> [Listing only directories in UNIX](https://stackoverflow.com/questions/3667329/listing-only-directories-in-unix)  
> [ls to view directories only](https://www.linuxquestions.org/questions/linux-newbie-8/ls-to-view-directories-only-156254/)  
> [List Directories in Unix and Linux Systems](https://www.cyberciti.biz/faq/linux-list-just-directories-or-directory-names/list-dirs-in-unix-linux/)  
> [first two results from ls command](https://stackoverflow.com/questions/10520120/first-two-results-from-ls-command)  

### file count
[Counting files in a directory from the terminal](http://hints.macworld.com/article.php?story=20010508182132282)  

```shell
# （递归）统计当前目录下(.)文件夹数量
## 比 ls -lR | grep '^d' 多1个
faner@MBP-FAN:~/Downloads/src|⇒  find . -type d -print | wc -l
       7

# （递归）统计当前目录下(.)文件数量
## 等效于 ls -lR | grep -c '^-'
faner@MBP-FAN:~/Downloads/src|⇒  find . -type f -print | wc -l
       93
```

### file size
[How to Get the Size of a Directory from Command Line](http://osxdaily.com/2017/03/09/get-size-directory-command-line/)  

进入指定文件夹执行 `du -sh`

## [bc](https://en.wikipedia.org/wiki/Bc_(programming_language))
[bc](https://www.gnu.org/software/bc/manual/html_mono/bc.html)(basic calculator) - An arbitrary precision calculator language  

bc is typically used as either a `mathematical scripting language` or as an `interactive mathematical shell`.  

There are four special variables, `scale`, `ibase`, `obase`, and `last`.  

支持输入数学表达式的解释型计算语言  

在终端输入 `bc` 即可进入 bc 命令行解释器；输入 `quit` 或者 `<C-d>` 发送 EOF 结束退出 bc。

> [COMMAND LINE CALCULATOR, BC](http://linux.byexamples.com/archives/42/command-line-calculator-bc/)  
> [How to Use the "bc" Calculator in Scripts](https://www.lifewire.com/use-the-bc-calculator-in-scripts-2200588)  
> [Linux下的计算器(bc、expr、dc、echo、awk)知多少？](http://blog.csdn.net/linco_gp/article/details/4517945)  
> [Linux中的super pi(bc 命令总结)](http://www.linuxidc.com/Linux/2012-06/63684.htm)  
> [我使用过的Linux命令之bc - 浮点计算器、进制转换](http://codingstandards.iteye.com/blog/793734)  

### basic
1. 在 bash shell 终端输入 `bc` 即可启动 bc 计算器。

输入表达式 `56.8 + 77.7`，再按回车键即可在新行得到计算结果：

```Shell
pi@raspberrypi:~ $ bc
bc 1.06.95
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'. 

56.8 + 77.7
134.5
```

也可书写代数表达式，用变量承载计算结果，作为进一步计算的操作数：

```Shell
a=2+3;
a
5
b=a*4;
b
20
```

2. 在 bash shell 终端可基于[数据流重定向或管道](https://www.cnblogs.com/mingcaoyouxin/p/4077264.html)作为 `bc` 的输入表达式：

```Shell
pi@raspberrypi:~ $ bc <<< "56.8 + 77.7"
134.5

pi@raspberrypi:~ $ echo "56.8 + 77.7" | bc
134.5
```

3. bc 内置的 **`scale`** 变量可指定浮点数计算输出精度：

```Shell
scale=2; 5 * 7 /3
11.66
```

4. 以下为在 shell scripts 调用 bc 做计算的示例:

```Shell
pi@raspberrypi:~ $ result=$(echo "scale=2; 5 * 7 /3;" | bc)
pi@raspberrypi:~ $ echo $result
11.66
```

### last
**`last`**  (an  extension)  is a variable that has the value of the *last* printed number.

bc 内置的 **`last`** 变量代表上个表达式的计算结果，可将 last 变量作为后续表达式的操作数，进行二次计算：

```
2+3
5
last*4
20
```

### ibase/obase
默认输入和输出都是基于十进制：

```Shell
ibase
10
obase
10
```

在 bc 命令解释器中输入 `ibase=10;obase=16;2017`，转换输出2017（十进制）的十六进制：

```Shell
ibase=10;obase=16;2017
7E1
```

或者 echo 分号相隔的表达式重定向作为 bc 的输入进行解释运行：

```Shell
pi@raspberrypi:~ $ echo "ibase=10;obase=16;2017" | bc
7E1
```

## Checksum
### cksum
cksum, sum -- display file checksums and block counts

### CRC32
crc32 - Perform a 32bit Cyclic Redundancy Check

计算从 [crx4chrome](https://www.crx4chrome.com/) 离线下载的 [Vimium CRX 1.60.3 for Chrome](https://www.crx4chrome.com/crx/731/)  插件的 crc32 校验和：

```Shell
faner@THOMASFAN-MB0:~/Downloads/crx|
⇒  crc32 dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx 
db950177
```

与官网给出的 CRC32 Checksum 值一致，则说明未被篡改，可放心安装。

### MD5 
md5 -- calculate a message-digest fingerprint (checksum) for a file

md5 命令后的默认输入参数为文件名，也可通过 `-s` 选项指定计算字符串参数的MD5。

```Shell
     -s string
             Print a checksum of the given string.
```

计算从 [crx4chrome](https://www.crx4chrome.com/) 离线下载的 [Vimium CRX 1.60.3 for Chrome](https://www.crx4chrome.com/crx/731/)  插件的 MD5：

```Shell
faner@THOMASFAN-MB0:~/Downloads/crx|
⇒  md5 dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx 
MD5 (dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx) = c98057821ee3cede87d911ead832dcc1
```

与官网给出的 MD5 Checksum 值一致，则说明未被篡改，可放心安装。

---

计算下载到本地的 Vimium CRX 1.60.3 for Chrome 插件所在路径字符串的 MD5 值：

```Shell
faner@THOMASFAN-MB0:~/Downloads/crx|
⇒  md5 -s "/Users/faner/Downloads/crx/dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx" 
MD5 ("/Users/faner/Downloads/crx/dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx") = 2f6f9a98b561f995564793765c205a66
```

### SHA1
shasum - Print or Check SHA Checksums

```Shell
SYNOPSIS
        Usage: shasum [OPTION]... [FILE]...
        Print or check SHA checksums.
        With no FILE, or when FILE is -, read standard input.

          -a, --algorithm   1 (default), 224, 256, 384, 512, 512224, 512256
          -b, --binary      read in binary mode
          -c, --check       read SHA sums from the FILEs and check them
          -t, --text        read in text mode (default)
```

When verifying SHA-512/224 or SHA-512/256 checksums, indicate the **algorithm** explicitly using the `-a` option, e.g.

`shasum -a 512224 -c checksumfile`

---

计算从 [crx4chrome](https://www.crx4chrome.com/) 离线下载的 [Vimium CRX 1.60.3 for Chrome](https://www.crx4chrome.com/crx/731/)  插件的 SHA：

```
faner@THOMASFAN-MB0:~/Downloads/crx|
⇒  shasum dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx 
476c61437d3c34e38ed1ee15950d202ded0902c8  dbepggeogbaibhgnhhndojpepiihcmeb-1.60.3-Crx4Chrome.com.crx
```

与官网给出的 SHA1 Checksum 值一致，则说明未被篡改，可放心安装。

## hexdump
### od
Linux/Unix（macOS）下的命令行工具 `od` 可按指定进制格式查看文档：

```shell
pi@raspberrypi:~ $ od --version
od (GNU coreutils) 8.26
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Jim Meyering.
```

```shell
pi@raspberrypi:~ $ man od

NAME
       od - dump files in octal and other formats

SYNOPSIS
       od [OPTION]... [FILE]...
       od [-abcdfilosx]... [FILE] [[+]OFFSET[.][b]]
       od --traditional [OPTION]... [FILE] [[+]OFFSET[.][b] [+][LABEL][.][b]]
```

**`-A`**, --address-radix=RADIX

> output format for file offsets; RADIX is one of [doxn], for Decimal, Octal, Hex or None  
>> 输出左侧的地址格式，默认为 o（八进制），可指定为 x（十六进制）。   

**`-j`**, --skip-bytes=BYTES

> skip BYTES input bytes first（跳过开头指定长度的字节）

**`-N`**, --read-bytes=BYTES

> limit dump to BYTES input bytes（只 dump 转译指定长度的内容）

**`-t`**, --format=TYPE

> select output format or formats（dump 输出的级联复合格式：`[d|o|u|x][C|S|I|L|n]`）

- `[doux]` 可指定有符号十、八、无符号十、十六进制；  
- `[CSIL]` 可指定 sizeof(char)=1, sizeof(short)=2, sizeof(int)=4, sizeof(long)=8 作为 group_bytes_by_bits；或直接输入数字[1,2,4,8]。

- `a`：Named characters (ASCII)，打印可见 ASCII 字符。

***`-x`***: same as `-t x2`, select hexadecimal 2-byte units

>  默认 group_bytes_by_bits = 16，两个字节（shorts）为一组。  

---

以下示例 hex dump `tuple.h` 文件开头的64字节：

```shell
# 等效 od -N 64 -A x -t xCa tuple.h
faner@MBP-FAN:~/Downloads|⇒  od -N 64 -A x -t x1a tuple.h
0000000    ef  bb  bf  0d  0a  23  70  72  61  67  6d  61  20  6f  6e  63
           ?   ?   ?  cr  nl   #   p   r   a   g   m   a  sp   o   n   c
0000010    65  0d  0a  0d  0a  6e  61  6d  65  73  70  61  63  65  20  41
           e  cr  nl  cr  nl   n   a   m   e   s   p   a   c   e  sp   A
0000020    73  79  6e  63  54  61  73  6b  0d  0a  7b  0d  0a  0d  0a  2f
           s   y   n   c   T   a   s   k  cr  nl   {  cr  nl  cr  nl   /
0000030    2f  20  e5  85  83  e7  bb  84  28  54  75  70  6c  65  29  e6
           /  sp   ?  85  83   ?   ?  84   (   T   u   p   l   e   )   ?
0000040
```

### hexdump
Linux/Unix（macOS）下的命令行工具 `hexdump` 可按指定进制格式查看文档：

```shell
pi@raspberrypi:~ $ man hexdump

NAME
     hexdump, hd — ASCII, decimal, hexadecimal, octal dump

SYNOPSIS
     hexdump [-bcCdovx] [-e format_string] [-f format_file] [-n length] [-s skip] file ...
     hd [-bcdovx] [-e format_string] [-f format_file] [-n length] [-s skip] file ...
```

**`-b`**      One-byte octal display.  
**`-c`**      One-byte character display.  
**`-C`**      Canonical hex+ASCII display.  
**`-d`**      Two-byte decimal display.  
**`-o`**      Two-byte octal display.  
**`-x`**      Two-byte hexadecimal display.  

**`-s`** offset: Skip offset bytes from the beginning of the input（跳过开头指定长度的字节）  
**`-n`** length: Interpret only length bytes of input（ 只 dump 转译指定长度的内容）  

---

可以 hexdump 出 UTF-8 编码的文本文件，通过开头3个字节来判断是否带BOM：

> 如果开头3个字节为 `ef bb bf`，则为带 BOM 编码；否则为不带 BOM 编码。

```shell
# 等效 hexdump -C litetransfer.cpp | head -n 4
faner@MBP-FAN:~/Downloads|⇒  hexdump -n 64 -C tuple.h
00000000  ef bb bf 0d 0a 23 70 72  61 67 6d 61 20 6f 6e 63  |.....#pragma onc|
00000010  65 0d 0a 0d 0a 6e 61 6d  65 73 70 61 63 65 20 41  |e....namespace A|
00000020  73 79 6e 63 54 61 73 6b  0d 0a 7b 0d 0a 0d 0a 2f  |syncTask..{..../|
00000030  2f 20 e5 85 83 e7 bb 84  28 54 75 70 6c 65 29 e6  |/ ......(Tuple).|
00000040
```

### strings

```shell
pi@raspberrypi:~ $ man strings

STRINGS(1)                          GNU Development Tools                          STRINGS(1)

NAME
       strings - print the strings of printable characters in files.

SYNOPSIS
       strings [-afovV] [-min-len]
               [-n min-len] [--bytes=min-len]
               [-t radix] [--radix=radix]
               [-e encoding] [--encoding=encoding]
               [-] [--all] [--print-file-name]
               [-T bfdname] [--target=bfdname]
               [-w] [--include-all-whitespace]
               [-s] [--output-separatorsep_string]
               [--help] [--version] file...

```
