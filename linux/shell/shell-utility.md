## cd
cd（change directory）：切换文件目录。

- `cd` / `cd ~`：进入当前用户的家目录（$HOME）；  
- `cd ..`：返回上级目录；  
- `cd -`：返回上次访问目录。  

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

## ls
只列举文件夹：

- `ls -d */`  
- `ls -al | grep '^d'`：过滤出以 d 开头的（文件夹）  

其他命令：

- `find . -maxdepth 1 -type d`  
- `tree -d -L 1`  

> [Listing only directories in UNIX](https://stackoverflow.com/questions/3667329/listing-only-directories-in-unix)  
> [ls to view directories only](https://www.linuxquestions.org/questions/linux-newbie-8/ls-to-view-directories-only-156254/)  
> [List Directories in Unix and Linux Systems](https://www.cyberciti.biz/faq/linux-list-just-directories-or-directory-names/list-dirs-in-unix-linux/)  

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

> select output format or formats（定制 dump 输出格式：`[d|o|u|x][C|S|I|L|n]`）

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
Linux/Unix（macOS）下的命令行工具 `od` 可按指定进制格式查看文档：

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
