
## GB2312,GBK & GB18030

[关于GBK、GB2312、UTF8](http://csumissu.iteye.com/blog/1090053)  
[GB2312、GBK、GB18030 这几种字符集的主要区别是什么？](https://www.zhihu.com/question/19677619)  

> GB2312是GBK的子集，GBK是GB18030的子集。

## UTF-8 BOM

BOM（Byte Order Mark），意为字节序标记。

BOM 在 UTF-16 中用来表示高低字节序列。在字节流之前有 BOM 表示采用低字节序列（低字节在前面）。

在 [UCS](https://en.wikipedia.org/wiki/Universal_Coded_Character_Set) 编码中有一个叫做 "ZERO WIDTH NO-BREAK SPACE" 的字符，它的编码是 **`FE FF`**。而 `FF FE` 在 UCS 中是不存在的字符，所以不应该出现在实际传输中。

UCS 规范建议我们在传输字节流前，先传输字符 "ZERO WIDTH NO-BREAK SPACE"。

- 如果收到 `FE FF`，就表明这个字节流是 `Big-Endian` 的； 
- 如果收到 `FF FE`，就表明这个字节流是 `Little-Endian` 的。

因此，字符 "ZERO WIDTH NO-BREAK SPACE" 又被称作 **BOM**。

---

UTF-8 以字节为编码单元，没有字节序的问题，故 UTF-8 有无 BOM 都可以。UTF-8 不需要 BOM 来表明字节顺序，但可以用 BOM 来表明编码方式。

字符 "ZERO WIDTH NO-BREAK SPACE" 的 UTF-8 编码是 **`EF BB BF`**，所以如果接收者收到以 `EF BB BF` 开头的字节流，就知道这是 UTF-8 编码了。

Windows 就是使用 BOM 来标记文本文件的编码方式的。

使用 Sublime Text 3 打开文件，通过菜单 `File | Save with Encoding` 可以选择设置保存编码为 [`UTF8 with BOM`](https://stackoverflow.com/questions/21289157/set-encoding-of-file-to-utf8-with-bom-in-sublime-text-3)。

[THE UNIVERSAL CHARACTER SET](http://www.open-std.org/CEN/TC304/guidecharactersets/guideannexb.html)  
[UCS-2 and UTF-8](https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.nlsgdrf/ucs-2_utf-8.htm)  
[**UTF8 带BOM 和不带BOM**](http://www.cnblogs.com/yongssu/p/4926506.html)  
[UTF8 with BOM 与 UTF8 without BOM](http://www.cnblogs.com/zhongru_tu/archive/2008/04/11/1147792.html)  
[UTF-8 and UTF-8 without BOM](http://blog.csdn.net/LJL1603/article/details/4303971)  
[⎡带 BOM 的 UTF-8⎦ 和 ⎡无 BOM 的 UTF-8⎦](http://www.zhihu.com/question/20167122)  

## 查看文件编码

[How do I determine file encoding in OSX?](https://stackoverflow.com/questions/539294/how-do-i-determine-file-encoding-in-osx)  
[How to Determine File Type & Encoding from Command Line in Mac OS X](http://osxdaily.com/2015/08/11/determine-file-type-encoding-command-line-mac-os-x/)  
[linux下查看文件编码及修改编码](http://blog.csdn.net/jnbbwyth/article/details/6991425)  

### file 命令

```shell
pi@raspberrypi:~ $ man file

FILE(1)                                         BSD General Commands Manual                                        FILE(1)

NAME
     file — determine file type

SYNOPSIS
     file [-bcdEhiklLNnprsvzZ0] [--apple] [--extension] [--mime-encoding] [--mime-type] [-e testname] [-F separator]
          [-f namefile] [-m magicfiles] [-P name=value] file ...
     file -C [-m magicfiles]
     file [--help]

DESCRIPTION
     This manual page documents version 5.30 of the file command.

     file tests each argument in an attempt to classify it.  There are three sets of tests, performed in this order:
     filesystem tests, magic tests, and language tests.  The first test that succeeds causes the file type to be printed.
```

直接执行 file 命令，查看当前目录下所有文件的信息：

```shell
⇒  file *
UtilcFunctions.h: c program text, ASCII text
WifiPhotoIf.h:    c program text, UTF-8 Unicode text
liteif.h:         c program text, ISO-8859 text
litelog.h:        c program text, UTF-8 Unicode (with BOM) text
litenet.h:        c program text, ASCII text, with CRLF, LF line terminators
litestd.h:        c program text, UTF-8 Unicode text, with CRLF line terminators
litetime.h:       c program text, ASCII text, with CRLF line terminators
```

> 包括 UTF8 编码的 with BOM 信息。

带 `-I` 选项执行 `file -I filename` 将输出 MIME 类型信息：

```shell
⇒  file -I *
UtilcFunctions.h: text/x-c; charset=us-ascii
WifiPhotoIf.h:    text/x-c; charset=utf-8
liteif.h:         text/x-c; charset=iso-8859-1
litelog.h:        text/x-c; charset=utf-8
litenet.h:        text/x-c; charset=us-ascii
litestd.h:        text/x-c; charset=utf-8
litetime.h:       text/x-c; charset=us-ascii
```

过滤出当前目录下文件编码为 `ISO-8859` 的文件信息：

```shell
⇒  file * | grep 'ISO-8859'
./litetransfer.cpp: c program text, ISO-8859 text, with CRLF line terminators
./tuple.h: C++ source text, ISO-8859 text, with CRLF line terminators
```

除了 file 本身是作用于当前目录，也可以指定 maxdepth 为 1  执行 find 查找当前目录下的文件（`-type` 为 f），然后再执行 grep 过滤：

```
find . -maxdepth 1 -type f -exec file {} \; | grep 'ISO-8859'
find . -maxdepth 1 -type f | xargs file | grep 'ISO-8859'
```

若 find 不指定 maxdepth，则会递归查找当前目录及其子目录下的所有文件：

`find . -type f | xargs file | grep 'ISO-8859'`

---

以下为某个特殊编码的文件：

```shell
faner@MBP-FAN:~/Classes/module/liteTransfer/src/http|
⇒  file lthttpchannel.cpp 
lthttpchannel.cpp: c program text, Non-ISO extended-ASCII text, with CRLF line terminators

faner@MBP-FAN:~/Classes/module/liteTransfer/src/http|
⇒  enca lthttpchannel.cpp
Unrecognized encoding
```

Sublime Text 打开提示

```
Errors occurred while converting lthttpchannel.cpp with GB18030 encoding.

WARNING: Continue to load this file using GB18030, malformed data will be ignored.

Press "Cancel" to choose another encoding manually.
```

底部状态栏编码显示为 `Western(Windows 1252)`

### enca 命令

`enca` 命令可查看、转换文件的编码。

#### 安装 enca

macOS 通过包管理器 brew 可搜索安装 enca 工具包：

```shell
# 查找 enca
ifan@FAN-MC1:~|⇒  brew search enca
==> Searching local taps...
enca
==> Searching taps on GitHub...
==> Searching blacklisted, migrated and deleted formulae...

# enca 概述
ifan@FAN-MC1:~|⇒  brew desc enca
enca: Charset analyzer and converter

# enca 信息
ifan@FAN-MC1:~|⇒  brew info enca
enca: stable 1.19 (bottled), HEAD
Charset analyzer and converter
https://cihar.com/software/enca/
Not installed
From: http://android.oa.com/homebrew-core/Formula/enca.rb

# 安装 enca
ifan@FAN-MC1:~|⇒  brew install enca

# 查看 enca 版本信息
faner@MBP-FAN:~|⇒  enca -v
enca 1.19

Features: -librecode-interface +iconv-interface +external-converter +language-detection +locale-alias +target-charset-auto +ENCAOPT 

Copyright (C) 2000-2005 David Necas (Yeti) (<yeti@physics.muni.cz>),
              2005 Zuxy Meng (<zuxy.meng@gmail.com>).

Enca is free software; it can be copied and/or modified under the terms of
version 2 of GNU General Public License, run `enca --license' to see the full
license text.  There is NO WARRANTY; not even for MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.
```

raspbian 通过包管理器 apt 可搜索安装 enca 工具包：

```shell
# 查找 enca
pi@raspberrypi:~ $ apt-cache search enca --names-only 
enca - Extremely Naive Charset Analyser - binaries

# 查看 enca 安装包信息
pi@raspberrypi:~ $ apt-cache show enca

Description: Extremely Naive Charset Analyser - binaries
 Enca is an Extremely Naive Charset Analyser. It detects the character set and
 the encoding of text files and can also convert them to other encodings using
 either a built-in converter or external libraries and tools like libiconv,
 librecode, or cstocs.

# 安装 enca
pi@raspberrypi:~ $ sudo apt-get install enca

# 查看 enca 版本信息
pi@raspberrypi:~ $ enca -v

```

用 enca 命令检测文件编码信息：

```shell
# -f, --human-readable
faner@MBP-FAN:~|⇒  enca -L zh_CN *
./UtilcFunctions.h: 7bit ASCII characters
./WifiPhotoIf.h: Universal transformation format 8 bits; UTF-8
./liteif.h: Simplified Chinese National Standard; GB2312
./litelog.h: Universal transformation format 8 bits; UTF-8
./litenet.h: 7bit ASCII characters
  Mixed line terminators
./litestd.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
./litetime.h: 7bit ASCII characters
  CRLF line terminators

# -m, --mime-name，同 file -I
faner@MBP-FAN:~|⇒  enca -m *
UtilcFunctions.h: US-ASCII
WifiPhotoIf.h: UTF-8
liteif.h: UTF-8
litelog.h: UTF-8
litenet.h: US-ASCII
litestd.h: UTF-8
litetime.h: US-ASCII

# -i, --iconv-name
faner@MBP-FAN:~|⇒  enca -i *
UtilcFunctions.h: ASCII
WifiPhotoIf.h: UTF-8
liteif.h: UTF-8
litelog.h: UTF-8
litenet.h: ASCII
litestd.h: UTF-8
litetime.h: ASCII
```

> 无法检测 BOM 信息？

### Editor File Inspector

用 Vim 打开文件，执行底行命令 `:set fileencoding ?` 可查看当前文件编码，貌似检测不准确？

> 具体编码格式可查询关键字 encoding-names 和 encoding-values。

Sublime Text 3 默认不在状态栏显示编码格式，`~/Library/Application Support/Sublime Text 3/Packages/Default/Preferences.sublime-settings` 中默认配置如下：

```json
    // Display file encoding in the status bar
    "show_encoding": false,
```

`Preferences > Settings - Users` 打开 `~/Library/Application Support/Sublime Text 3/Packages/User/Preferences.sublime-settings`，在其中设置 

```json
    "show_encoding": true,
```

则在状态栏中将有一格显示当前文件编码格式：

![sublime_text_3](https://i.stack.imgur.com/FNvMj.jpg) 

## 中文显示乱码问题

Xcode 代码文档的默认编码通常是中英文混排的 `No Explicit Encoding`。  
但老版本的 Xcode 对带 BOM 头的 UTF8 文件编码无法识别，使用了 GBK 编码的文件在 Xcode 下也无法识别的，从而导致 [Xcode 下的中文显示可能乱码](http://linyehui.me/2014/07/09/convert-gbk-to-utf8-on-mac/)。

VS2015 只支持带 BOM 的 UTF-8，否则无法识别其中的中文部分；XCode 能够直接打开和编辑 `UTF-8 with BOM` 编码的文件。因此，**[`UTF-8 with BOM`](http://zplutor.github.io/2017/04/02/the-most-compatible-text-encoding-between-visual-studio-and-xcode/)** 是目前跨平台开发兼容性最好的编码选择。

遗憾的是，两款 IDE 都不能直接创建这种编码的文件，只能在创建之后再手工或借助第三方编辑工具转换。  

> [解决Visual Studio 2005显示中文乱码](http://blog.csdn.net/kevinojt/article/details/2009619)  
> [解决VS2008生成的文件在XCode下中文乱码](http://blog.csdn.net/ani_di/article/details/6657341)  
> [使用Xcode打开Winnows下C文件中文乱码问题解决](https://www.jianshu.com/p/b5441c8f1847)  
> [Visual Studio 2015 中如何使文件默认保存为 UTF - 8 编码格式？](https://www.zhihu.com/question/37252051)  

## 文件编码格式转换

[Visual Studio C/C++](http://zcodes.net/2016/09/29/visual-studio-cpp-encoding.html) 可以 [将新建的源码文件的编码格式自动设置成UTF8](http://blog.csdn.net/maxwoods/article/details/44828295)，或从其他格式 [更改编码格式为 UTF-8](http://blog.csdn.net/caroline_wendy/article/details/13169837)。

对于某些在 Xcode 中文乱码问题，通过右侧栏的 Text Settings | Text Encoding 选择 `Simplified Chinese(Mac OS)` 可正确显示。

当然，也可借助 Sublime Text 等第三方可视化编辑器，打开文件后对已有编码执行转换。

另外一种思路是借助  iconv 或 enca  等命令行工具实现转码。

### iconv 命令转码

> [Linux下GBK->UTF-8文件编码批量转换命令](http://blog.csdn.net/a280606790/article/details/8504133)  
> [linux 批量转换GBK到UTF-8编码的方法](http://blog.csdn.net/qq_14821541/article/details/78860018)  
> [用iconv实现的gb18030到utf-8的编码转换](http://blog.csdn.net/zhaoweikid/article/details/308676)  
> [macOS 使用 iconv 命令将 gb18030 编码转换为 utf-8 格式](http://blog.csdn.net/ft2028739/article/details/15809019)  

iconv 命令默认将转码结果输出到控制台（stdout）上。

- 新版 iconv（raspbian 下的 2.24）可通过 `-o` 选项指定输出文件（outputfile）；  
- 旧版 iconv（macOS 下的 1.11）命令不支持 `-o` 选项，则可使用 `>` 将转码结果重定向到指定文件。  

```shell
iconv -f GB2312 -t UTF-8 file1 > file2
iconv -f GBK -t UTF-8 file1 -o file2
iconv -f GB18030 -t UTF-8 file1 -o file2
```

转换前 `include/` 目录下的文件编码信息如下：

```shell
# 转换前
⇒  file *
UtilcFunctions.h: c program text, ASCII text # 纯英文
WifiPhotoIf.h:    c program text, UTF-8 Unicode text # 中英文
liteif.h:         c program text, ISO-8859 text, with CRLF line terminators # 中英文
litelog.h:        c program text, UTF-8 Unicode (with BOM) text # 纯英文
litenet.h:        c program text, ASCII text, with CRLF, LF line terminators # 纯英文
litestd.h:        c program text, UTF-8 Unicode text, with CRLF line terminators # 中英文
litetime.h:       c program text, ASCII text, with CRLF line terminators # 纯英文

# 转换前
⇒  enca *
UtilcFunctions.h: 7bit ASCII characters
WifiPhotoIf.h: Universal transformation format 8 bits; UTF-8
liteif.h: Simplified Chinese National Standard; GB2312
  CRLF line terminators
litelog.h: Universal transformation format 8 bits; UTF-8
litenet.h: 7bit ASCII characters
  Mixed line terminators
litestd.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
litetime.h: 7bit ASCII characters
  CRLF line terminators
```

执行 iconv 转换编码：

```shell
# 转换
ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 UtilcFunctions.h > UtilcFunctions2.h

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 WifiPhotoIf.h > WifiPhotoIf2.h

iconv: WifiPhotoIf.h:5:24: cannot convert

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 liteif.h > liteif2.h    

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 litelog.h > litelog2.h    

iconv: litelog.h:1:2: cannot convert

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 litenet.h > litenet2.h

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 litestd.h > litestd2.h

iconv: litestd.h:48:31: cannot convert

ifan@FAN-MC1:~/liteTransfer/include|
⇒  iconv -f GB18030 -t UTF-8 litetime.h > litetime2.h
```

转换成功后，重新执行 `file` 和 `enca` 命令：

```shell
# 转换后
⇒  file *
UtilcFunctions.h: c program text, ASCII text
WifiPhotoIf.h:    c program text, UTF-8 Unicode text
liteif.h:         c program text, UTF-8 Unicode text
litelog.h:        c program text, UTF-8 Unicode (with BOM) text
litenet.h:        c program text, ASCII text, with CRLF, LF line terminators
litestd.h:        c program text, UTF-8 Unicode text, with CRLF line terminators
litetime.h:       c program text, ASCII text, with CRLF line terminators

# 转换后
⇒  enca *
UtilcFunctions.h: 7bit ASCII characters
WifiPhotoIf.h: Universal transformation format 8 bits; UTF-8
liteif.h: Universal transformation format 8 bits; UTF-8
litelog.h: Universal transformation format 8 bits; UTF-8
litenet.h: 7bit ASCII characters
  Mixed line terminators
litestd.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
litetime.h: 7bit ASCII characters
  CRLF line terminators
```

`ASCII text`：表示纯 ASCII 编码，只有英文字符，没有中文等其他语言字符。  
当输入中文等其他语言字符后，则编码将显示为 `UTF-8 Unicode text`。  

#### [iconv 批量更改文件编码](http://blog.csdn.net/longxibendi/article/details/5889110)  

将当前执行目录下所有的 php 文件 `$file` 从 GB18030 转码为 utf8 文件 `$file.new`，然后将 `$file.new` 重命名为 `$file`，即覆盖源文件。

```shell
#!/bin/bash
for file in *.php
do
    iconv -f GB18030 -t utf8 -o "$file.new" "$file" &&
    mv -f "$file.new" "$file"
done
```

在当前目录查找后缀为 php 的文件，每个 find 结果行（文件）读取到变量 file 中，然后 echo 打印出文件名，紧接着将 `$file` 从 GB18030 转码为 UTF-8 文件 `$file.utf8`。  
第一个 mv 命令将源文件重命名为 *.18030 备份；第二个 mv 将转码文件（`*.utf8`）重名为源文件。

```shell
#!/bin/bash
find . -type f -name "*.php" | while read file;
do
   echo $file
   iconv -f GB18030 -t UTF-8 $file > ${file}.utf8
   mv $file ${file}.18030
   mv ${file}.utf8 $file
done
```

[format_converter.sh](https://gist.github.com/dedeexe/b222b932539ea373fb0c)

> iconv 命令不能直接转码覆盖源文件，只能通过 `mv -f` 强制覆盖。

[How can I make iconv replace the input file with the converted output?](https://unix.stackexchange.com/questions/10241/how-can-i-make-iconv-replace-the-input-file-with-the-converted-output)  

### enca 命令转换

`enca -L zh_CN -x utf-8 *` 将当前目录下的所有文件转码为 UTF-8。  

如果不想覆盖，则可以执行 `enca -L zh_CN -x UTF-8 < file1 > file2`，将 file1 转换成 file2。

首先利用管道批量查找过滤出混合中文编码的文件：

```shell
find . -type f | xargs file | grep 'ISO-8859' | cut -d ':' -f 1
find . -type f | xargs file -I | grep 'iso-8859' | cut -d ':' -f 1
find . -type f | xargs enca -L zh_CN -m | grep 'GB2312' | cut -d ':' -f 1
find . -type f | xargs enca -L zh_CN -i | grep 'GBK' | cut -d ':' -f 1
```

> 1. 利用 `find` 命令查找当前文件夹及其子目录下的所有文件；  
> 2. 针对查找结果集，利用 **xargs** 重定向执行 `file` 或 `enca` 命令查看编码信息；  
> 3. 利用 `grep` 命令过滤出编码为 ISO-8859(iso-8859)/GBK(GB2312) 的文件信息；  
> 4. 分析文件信息行组织规律，利用 `cut` 命令对文件信息行以 `:`  切割提取出第一列相对文件名；  
> 5. 对相对文件名结果集执行 `enca -L zh_CN -x utf-8` 命令 将其转码为 UTF-8。  

```shell
faner@MBP-FAN:~/Classes/module/liteTransfer/src2|
⇒  find . -type f | xargs file | grep 'ISO-8859' | cut -d ':' -f 1 | xargs enca -L zh_CN -x utf-8
```

#### GB18030_2_UTF-8.sh

鉴于以上一句复合命令没有中间结果输出，可采用 Shell 脚本实现批处理筛检转码并输出有效信息。

```
#!/bin/bash
fileCount=$(find . -type f | xargs file | grep 'ISO-8859' | wc -l)
if [ $fileCount -gt 0 ]
then
    echo "########################################"
    echo "find/grep $fileCount files encoding with ISO-8859 before convert"
    echo "########################################"

    read -p "Are you sure you want to convert the $fileCount files' encoding to UTF-8? <y/N> " prompt
    if [[ $prompt == "y" || $prompt == "Y" || $prompt == "yes" || $prompt == "Yes" ]]
    then
        find . -type f | xargs file | grep 'ISO-8859' | while read fileInfoLine;
        do
            echo $fileInfoLine              # 打印符号条件的行信息
            fileName=${fileInfoLine%%:*}    # 取相对文件名（路径）
            #echo $fileName

            # 方案1：先备份再转码覆盖
            iconv -f GB18030 -t UTF-8 $fileName > ${fileName}.utf8
            #mv $fileName ${fileName}.18030 # 可选备份。如不执行，等效于方案2。
            mv ${fileName}.utf8 $fileName

            # 方案2：直接转码覆盖
            # enca -L zh_CN -x utf-8 $fileName
        done
        # 方案1
        #echo "########################################"
        #echo "被转码的源文件备份如下："
        #echo "########################################"
        #find . -type f -name "*.18030"
        # 方案2
        echo "########################################"
        find . -type f | xargs file | grep 'ISO-8859' | echo "find/grep $(wc -l) files encoding with ISO-8859 after convert."
        echo "########################################"
    else
        exit 0
    fi
else
    echo "find/grep no files encoding with ISO-8859!"
fi
```

## UTF8 with BOM

[Set Encoding of File to UTF8 With BOM in Sublime Text 3](https://stackoverflow.com/questions/21289157/set-encoding-of-file-to-utf8-with-bom-in-sublime-text-3)  

使用 iconv 命令将所有 GB18030 字符都转换为 UTF8 后，再使用 Sublime Text 3 打开文件，通过菜单 File | Save with Encoding 选择 `UTF8 with BOM`：

```shell
⇒  file *
UtilcFunctions.h: c program text, UTF-8 Unicode (with BOM) text
WifiPhotoIf.h:    c program text, UTF-8 Unicode (with BOM) text
liteif.h:         c program text, UTF-8 Unicode (with BOM) text
litelog.h:        c program text, UTF-8 Unicode (with BOM) text
litenet.h:        c program text, UTF-8 Unicode (with BOM) text, with CRLF line terminators
litestd.h:        c program text, UTF-8 Unicode (with BOM) text, with CRLF line terminators
litetime.h:       c program text, UTF-8 Unicode (with BOM) text, with CRLF line terminators

⇒  enca *
UtilcFunctions.h: Universal transformation format 8 bits; UTF-8
WifiPhotoIf.h: Universal transformation format 8 bits; UTF-8
liteif.h: Universal transformation format 8 bits; UTF-8
litelog.h: Universal transformation format 8 bits; UTF-8
litenet.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
litestd.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
litetime.h: Universal transformation format 8 bits; UTF-8
  CRLF line terminators
```

## Line Endings
### 回车换行

以下摘自《[我的电脑生涯（2）：ASCII码](http://blog.sina.com.cn/s/blog_4a20485e0102dr82.html)》：

> 使用过机械式英文打字机的人都知道，当一行字符快打完的时候，打字机会发出“叮”的一声铃响，提醒打字员别再不停地击键了，否则字符就打到纸外面去了。此时，打字员要用手把打字机的滑车推到最左边，这个动作称为“[**回车**](https://zh.wikipedia.org/wiki/%E5%9B%9E%E8%BD%A6%E7%AC%A6)”。  

>> **`\r`**（ASCII 码为 0x0d）：本义是光标重新回到本行开头，r 即 **r**eturn，控制字符可以写成 CR（[Carriage Return](https://en.wikipedia.org/wiki/Carriage_return)）；  

> 仅仅回车是不够的，如果此时打字员继续打字，字符就会重叠在刚才已经打过字的这一行上面，所以打字员还要用手把纸卷滚筒向前转一下，这个动作叫“[**换行**](https://zh.wikipedia.org/wiki/%E6%8F%9B%E8%A1%8C)”。  

>> **`\n`**（ASCII 码为 0x0a）：本义是光标往下一行（不一定到下一行行首），n 及 **n**ewline，控制字符可以写成 LF（[Line Feed](https://en.wikipedia.org/wiki/Newline)）。  

在计算机上编辑文本，每当按下 enter(return) 键，系统会在行末（EOL）插入不可见的结束符（invisible **Line Ending**）标记换行，同时光标自动移动到下一行首。

在非英语系国家的键盘上，回车键会用 <kbd>↵</kbd>（U+21B5、`&crarr;`）符号表示，形象直观地说明了该键的功能。

尽管回车换行这两个概念也被挪到了计算机上，但是早期存储器较贵，一些科学家认为在每行结尾加两个额外的字符来标识行末太浪费存储，加一个即可。

具体到文本编码中，不同的操作系统在敲下 enter 键时插入的不可见行末结束符有所不同。具体分为[三大流派](https://zhuanlan.zhihu.com/p/25503610)：

- 在 Windows 系统下，`\r\n` 这两个字符连在一起标识行末，本义表示回车换行；  
- 在 UNIX 类系统（包括最新的 macOS）中，换行符 `\n` 标识行末，表示光标移到下一行并回到行首；  
- 在已经退出历史舞台的 Mac OS  9 及更古，`\r` 标识行末，表示回到本行开头并往下一行。  

两大主流操作系统阵营采用不同的 Line Endings，造成的后果是：

- Unix/macOS 系统下的文件在 Windows 中打开，所有文字都会变成一行；  
- 而 Windows 下的文件在 Unix/macOS 下打开的话，在每行的结尾可能会多出一个 `^M` 符号。  

---

1. Xcode 右侧的 Line Endings：

	- macOS/Unix(LF)  
	- Classic Mac OS(CR)  
	- Windows(CRLF)  

2. 在 vim 下底行模式输入命令 `:set fileformat ?` 可查询当前文档的 EOL 格式；问号可换为 unix/dos 设置具体格式。  
3. 在终端命令行中使用 `od -A x -t xCa tuple.h` 或 `hexdump -C tuple.h`，或在 Sublime Text 下使用 hexviewer 可查看 tuple.h 文件的十六进制码，以查验行末结束符。  
4. 在 python 中（sublime text 控制台）执行 `import os;os.linesep` 可以查看行分隔符（`line separator in text files`）。  

### vim 编辑替换

在 vim 下执行 `:%s/\r//g` 可将DOS文件中的回车符 `^M` 替换为空（即删除）。  
dos2unix 批量替换方案：`find ./ -type f print0 | xargs -0 sed -i 's/^M$//'`。  

> [Vim 中如何去掉 ^M 字符？](https://www.zhihu.com/question/22130727)  
> [vim linux下查找显示^M并且删除](http://www.cnblogs.com/juandx/p/5663064.html)  

### Sublime Text 3 编辑替换

Sublime Text 的 `~/Library/Application Support/Sublime Text 3/Packages/Default/Preferences.sublime-settings`

```json
    // Determines what character(s) are used to terminate each line in new files.
    // Valid values are 'system' (whatever the OS uses), 'windows' (CRLF) and
    // 'unix' (LF only).
    "default_line_ending": "system",
    
    // Display line endings in the status bar
    "show_line_endings": false,
```

`default_line_ending`: 默认 line ending 跟随系统，macOS 下是 LF。  
`show_line_endings`: 默认不在状态栏显示当前 Line Ending，可以 `Preferences > Settings - Users` 打开 `~/Library/Application Support/Sublime Text 3/Packages/User/Preferences.sublime-settings`，在其中设置：

```json
    "show_line_endings": true,
```

底部状态栏将显示当前 Line Ending：

- Windows：Windows Line Endings(CRLF)  
- Unix：Unix Line Endings(LF)  
- CR：Mac OS 9 Line Endings(CR)  

可以点击选择切换，将 `litenet.h`,`litestd.h`,`litetime.h` 这3个文件的 Line Ending 都切换为 Unix(LF)。

[Difference between CR LF, LF and CR line break types?](https://stackoverflow.com/questions/1552749/difference-between-cr-lf-lf-and-cr-line-break-types)  

[Dealing with line endings](https://help.github.com/articles/dealing-with-line-endings/)  
[git replacing LF with CRLF](https://stackoverflow.com/questions/1967370/git-replacing-lf-with-crlf)  

[crlf.py](https://gist.github.com/jonlabelle/dd8c3caa7808cbe4cfe0a47ee4881059): Replace CRLF (windows) line endings with LF (unix) line endings in files.  

[How to Ensure Always LF not CRLF on Windows](https://intellij-support.jetbrains.com/hc/en-us/community/posts/205969644-How-to-Ensure-Always-LF-not-CRLF-on-Windows)  

---

```
# 查找当前目录下（不递归子目录）的所有文件，并针对每个文件执行 file 命令

⇒  find . -maxdepth 1 -type f -exec file {} \; 
./.DS_Store: Apple Desktop Services Store
./liteafx.h: C++ source text, ASCII text
./liteconststr.cpp: c program text, ASCII text, with CRLF line terminators
./liteconststr.h: ASCII text, with CRLF line terminators
./litetransfer.cpp: c program text, ISO-8859 text
./litetransfer.h: C++ source text, ASCII text, with CRLF, LF line terminators
./sink.h: C++ source text, ASCII text, with CRLF, LF line terminators
./tuple.h: C++ source text, ISO-8859 text, with CRLF line terminators
```

`find . -type f -exec file {} \;` 则不限制查找深度，查找所有子目录。