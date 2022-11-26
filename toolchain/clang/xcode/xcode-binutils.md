
执行 xcode-select 的 `-p`(`--print-path`) 选项打印开发配置目录：

```
-p, --print-path            print the path of the active developer directory
```

```
-> % xcdevpath=`xcode-select -p`
-> % echo $xcdevpath
/Applications/Xcode.app/Contents/Developer
```

## toolchain binUtils

参考 [GNU Binutils](https://www.gnu.org/software/binutils/)  

> $xcdevpath/Toolchains/XcodeDefault.xctoolchain/usr/bin

### C/C++

- c89 -- standard C language compiler  
- c99 -- standard C language compiler  

执行 `man c89` 和 `man c99` 查看帮助手册。

### preprocessor

- gm4(m4)：M4 - macro processor  
- unifdef, unifdefall -- remove preprocessor conditionals from code  

### cl(Compiler/Assembler/Linker)

#### clang

- clang - the Clang C, C++, and Objective-C compiler - c++/cc/clang++/cpp  

cc 和 c++ 为 clang 的软链：

```
⇒  readlink $xcdevpath/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
clang
readlink $xcdevpath/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
clang
```

```
-> % which gcc
/usr/bin/gcc
-> % type -a gcc
gcc is /usr/bin/gcc

-> % which g++
/usr/bin/g++
-> % type -a g++
g++ is /usr/bin/g++
```

`gcc -v` 或 `g++ -v` 输出如下：

```
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 11.0.0 (clang-1100.0.33.16)
Target: x86_64-apple-darwin19.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

#### as

- as - Mac OS X Mach-O GNU-based assemblers  

```Shell
faner@FAN-MB0:
⇒  tree $xcdevpath/Toolchains/XcodeDefault.xctoolchain/usr/libexec/as
.
├── arm
│   └── as
├── i386
│   └── as
└── x86_64
    └── as

3 directories, 3 files
```

#### ld

- ld -- linker  

```
     The ld command combines several object files and libraries, resolves references, and produces an ouput
     file.  ld can produce a final linked image (executable, dylib, or bundle), or with the -r option, pro-
     duce another object file.  If the -o option is not used, the output file produced is named "a.out".
```

#### ar

- ar -- create and maintain library archives  

```
     The ar utility creates and maintains groups of files combined into an archive.  Once an archive has
     been created, new files can be added and existing files can be extracted, deleted, or replaced.
```

### utility

- indent -- indent and format C program source  
- lorder -- list dependencies for object files  
- strings - find the printable strings in a object, or other binary, file  
- size(llvm-size) - print the size of the sections in an object file  

### libtool

- lipo - create or operate on universal files  
- libtool - create libraries  
- ranlib(libtool) - add or update the table of contents of archive libraries  

### bison(yacc)

- bison - GNU Project parser generator (yacc replacement)  
- flex(lex) - the fast lexical analyser generator  

### otool(objdump)

- nm(llvm-nm) - display name list (symbol table)  
- otool(llvm-otool) - object file displaying tool  
- objdump(llvm-objdump): llvm object file dumper  

### edit

- strip - remove symbols  
- rebase -- Changes base address of dylibs and bundles  

- segedit - extract and replace sections from object files  
- bitcode_strip - remove or leave the bitcode segment in a Mach-O file  

### dwarfdump

- dwarfdump -- dump DWARF debug information.  
- dsymutil -- manipulate archived DWARF debug symbol files.  

## Developer binUtils

> $xcdevpath/usr/bin

### cl(Compiler and Linker)

- nasm - the Netwide Assembler, a portable 80x86 assembler  
- make - GNU make utility to maintain groups of programs  
- gcc/g++ - clang LLVM compiler  
- ld -- linker  

- bitcode-build-tool  
- symbols -- display symbol information about a file or process  
- lldb -- The debugger  

### SCM

- svn  
- git  
