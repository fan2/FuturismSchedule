# [Toolchain](https://en.wikipedia.org/wiki/Toolchain)
A simple software development toolchain may consist of a [compiler](https://en.wikipedia.org/wiki/Compiler) and [linker](https://en.wikipedia.org/wiki/Linker_(computing)) (which transform the source code into an [executable program](https://en.wikipedia.org/wiki/Executable_program)), [libraries](https://en.wikipedia.org/wiki/Software_library) (which provide interfaces to the [operating system](https://en.wikipedia.org/wiki/Operating_system)), and a [debugger](https://en.wikipedia.org/wiki/Debugger) (which is used to [test](https://en.wikipedia.org/wiki/Software_testing) and debug [debug](https://en.wikipedia.org/wiki/Debugging) programs).

## [compiler tool chain](https://www.quora.com/What-exactly-is-a-compiler-tool-chain) 
answered by Ajinkya RC：

Every program of any language is written in a high level language. This must be converted to machine understandable language. So, ‘Compiler’ is the predefined set of program that does this activity. Also, there are number of different components that play important role. This whole set of components is nothing but the ‘Compiler tool chain’.

Lets consider the simple C program:

When we write a normal program ‘hello.c’ and compile it, compiler converts it into a machine code. It creates a ‘hello.obj’ file but its not executable at this stage.

After this ‘Linker’ comes into the picture. It links some additional code with that .obj file. Linker also gives a magic number with this code and this process is called as ‘Primary Header’. It also links static and dynamic library functions to this code. This additional code helps the .obj file to be executable.

Now, Loader does the further work. Loader splits the code in S, T & D sections. These sections are present on the RAM. Stack contains all the functions in the code. Text section contains the information of the functions and others texts present in the program and Data section contains all the data.

Thus the execution of the code takes place when the program goes from Hard Disk to RAM.

Here the compiler tool chain contains three basic elements, first compiler itself, second Linker and third Loader.

## [Cross compiler](https://en.wikipedia.org/wiki/Cross_compiler)
[What is cross compile and toolchain?](http://www.xuebuyuan.com/508805.html)  

A cross compiler is a compiler capable of creating executable code for a platform other than the one on which the compiler is running.

A cross compiler is necessary to compile for multiple platforms from one machine. A platform could be infeasible for a compiler to run on, such as for the microcontroller of an embedded system because those systems contain no operating system.

The fundamental use of a cross compiler is to separate the build environment from target environment.

### elinux [Toolchains](http://www.elinux.org/Toolchains) 
A toolchain is a set of distinct software development tools that are linked (or chained) together by specific stages such as GCC, binutils and glibc (a portion of the GNU Toolchain). Optionally, a toolchain may contain other tools such as a Debugger or a Compiler for a specific programming language, such as ,C++. Quite often, the toolchain used for embedded development is a cross toolchain, or more commonly known as a cross compiler. All the programs (like GCC) run on a host system of a specific architecture (such as x86) but produce binary code (executables) to run on a different architecture (e.g. ARM). This is called cross compilation and is the typical way of building embedded software.

When talking about toolchains, one must distinguish ***three different machines*** :

- the build machine, on which the toolchain is built  
- the host machine, on which the toolchain is executed  
- the target machine, for which the toolchain generates code  

From these three different machines, we distinguish ***four different types*** of toolchain building processes :

- A native toolchain, as can be found in normal Linux distributions, has usually been compiled on x86, runs on x86 and generates - code for x86.  
- A cross-compilation toolchain, which is the most interesting toolchain type for embedded development, is typically compiled on - x86, runs on x86 and generates code for the target architecture (be it ARM, MIPS, PowerPC or any other architecture supported - by the different toolchain components)  
- A cross-native toolchain, is a toolchain that has been built on x86, but runs on your target architecture and generates code  for your target architecture. It's typically needed when you want a native gcc on your target platform, without building it on  your target platform.  
- A canadian build is the process of building a toolchain on machine A, so that it runs on machine B and generates code for machine C. It's usually not really necessary.  

### [What is a toolchain and a cross compiler?](https://stackoverflow.com/questions/22756199/what-is-a-toolchain-and-a-cross-compiler)
If we define the word "*`host`*" to mean a computer on which you are compiling, and "*`target`*" as the computer on which you want to run the code, then a ***native compiler*** is one where the target and the host are the same (kind). A ***cross-compiler*** is a compiler where the target is <u>different</u> from the host.

A toolchain is the set of `compiler + linker + librarian + any other tools` you need to produce the executable (+ shared libraries, etc) for the target. A debugger and/or IDE may also count as part of a toolchain.

### [What exactly is a compiler tool chain?](https://www.quora.com/What-exactly-is-a-compiler-tool-chain)
answered by Greg Kemnitz：

The notion of a [Toolchain](https://en.wikipedia.org/wiki/Toolchain) is usually used in the embedded world.  It is the **package** of software needed to compile, link, and deploy software from a *`development host`* to the *`target device`*.  (In most embedded devices, the device itself doesn't have enough capability to support development directly on the device.)

A toolchain will have some sort of [Cross compiler](https://en.wikipedia.org/wiki/Cross_compiler) and linker for the target, possibly a [Debugger](https://en.wikipedia.org/wiki/Debugger) (which may allow on-device debugging), occasionally some sort of [simulator](https://en.wikipedia.org/wiki/Computer_architecture_simulator) that allows testing and debugging on the development host, a mechanism for deploying to the device, etc.

Sometimes the toolchain may involve a full IDE (like Microsoft VC++ Embedded or Hitachi's IDEs), often it is a **collection** of *command-line tools*, especially if the toolchain is hosted on Unix/Linux.

## [MSVC](https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B)
Microsoft Visual C++ (often abbreviated to MSVC) is an [integrated development environment](https://en.wikipedia.org/wiki/Integrated_development_environment) (IDE) product from Microsoft for the C, C++, and [C++/CLI](https://en.wikipedia.org/wiki/C%2B%2B/CLI) [programming languages](https://en.wikipedia.org/wiki/Programming_language).

> [**Visual Studio 2015 中的 Visual C++**](https://msdn.microsoft.com/zh-cn/library/60k1461a.aspx)  
>> [**C++ 语言和标准库**](https://msdn.microsoft.com/zh-cn/library/hh875057.aspx)：[C/C++ 预处理器参考](https://msdn.microsoft.com/zh-cn/library/y4skk93w.aspx)  
>> [**用于 Visual C++ 开发的 IDE 和工具**](https://msdn.microsoft.com/zh-cn/library/hh967574.aspx)  
>>> [生成 C/C++ 程序](https://msdn.microsoft.com/zh-cn/library/z7kx322x.aspx)  
>>>> [在命令行上生成](https://msdn.microsoft.com/zh-cn/library/f35ctcxw.aspx)：[C 程序](https://msdn.microsoft.com/zh-cn/library/bb384838.aspx) / [C++ 程序](https://msdn.microsoft.com/zh-cn/library/ms235639.aspx) / [NMAKE 参考](https://msdn.microsoft.com/zh-cn/library/dd9y37ha.aspx)  
>>>> [C/C++ 生成参考](https://msdn.microsoft.com/zh-CN/library/91621w01.aspx)  
>>>>> [编译 C/C++ 程序](https://msdn.microsoft.com/zh-cn/library/wk21sfcf.aspx)  
>>>>>> [编译器选项](https://msdn.microsoft.com/zh-cn/library/9s7c9wdw.aspx)：[/D（预处理器定义）](https://msdn.microsoft.com/zh-cn/library/hhzbb5c8.aspx)、[/U、/u（未定义符号）](https://msdn.microsoft.com/zh-cn/library/c3h46dfd.aspx)、[/P（预处理到文件）](https://msdn.microsoft.com/zh-cn/library/8z9z0bx6.aspx)、[/link（将选项传递到链接器）](https://msdn.microsoft.com/zh-cn/library/5y4fae15.aspx)  
>>>>>> [设置编译器选项](https://msdn.microsoft.com/zh-CN/library/3600tzxa.aspx)：[编译器命令行语法](https://msdn.microsoft.com/zh-cn/library/610ecb4h.aspx)、[CL 调用链接器](https://msdn.microsoft.com/zh-cn/library/btw8x58e.aspx)  

## [GNU toolchain](https://en.wikipedia.org/wiki/GNU_toolchain)
official site: [What is GNU?](https://www.gnu.org/home.en.html)

The GNU toolchain is a broad collection of [programming tools](https://en.wikipedia.org/wiki/Programming_tool) produced by the [GNU Project](https://en.wikipedia.org/wiki/GNU_Project). These tools form a [toolchain](https://en.wikipedia.org/wiki/Toolchain) (a suite of tools used in a serial manner) used for developing software [applications](https://en.wikipedia.org/wiki/Application_software) and [operating systems](https://en.wikipedia.org/wiki/Operating_system).

The GNU toolchain plays a vital role in development of [Linux](https://en.wikipedia.org/wiki/Linux), some [BSD](https://en.wikipedia.org/wiki/Berkeley_Software_Distribution) systems, and software for [embedded systems](https://en.wikipedia.org/wiki/Embedded_system). Parts of the GNU toolchain are also directly used with or ported to other platforms such as [Solaris](https://en.wikipedia.org/wiki/Solaris_(operating_system)), [macOS](https://en.wikipedia.org/wiki/MacOS), [Microsoft Windows](https://en.wikipedia.org/wiki/Microsoft_Windows) (via [Cygwin](https://en.wikipedia.org/wiki/Cygwin) and [MinGW/MSYS](https://en.wikipedia.org/wiki/MinGW)) and [Sony PlayStation 3](https://en.wikipedia.org/wiki/PlayStation_3).

***Components***

Projects included in the GNU toolchain are:

- [GNU make](https://en.wikipedia.org/wiki/Make_(software)): an automation tool for compilation and build  
- [GNU Compiler Collection](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) (GCC): a suite of compilers for several programming languages  
- [GNU Binutils](https://en.wikipedia.org/wiki/GNU_Binutils): a suite of tools including linker, assembler and other tools  
- [GNU Bison](https://en.wikipedia.org/wiki/GNU_Bison): a [parser generator](https://en.wikipedia.org/wiki/Parser_generator), often used with the [Flex lexical analyser](https://en.wikipedia.org/wiki/Flex_lexical_analyser)  
- [GNU m4](https://en.wikipedia.org/wiki/GNU_m4): an [m4](https://en.wikipedia.org/wiki/M4_(computer_language)) macro processor  
- [GNU Debugger](https://en.wikipedia.org/wiki/GNU_Debugger) (GDB): a code debugging tool  
- [GNU build system](https://en.wikipedia.org/wiki/GNU_build_system) (autotools): [Autoconf](https://en.wikipedia.org/wiki/Autoconf), [Automake](https://en.wikipedia.org/wiki/Automake) and [Libtool](https://en.wikipedia.org/wiki/Libtool)  

### GCC
official site: [GCC, the GNU Compiler Collection](https://gcc.gnu.org/)  
[Using the GNU Compiler Collection (GCC)](https://gcc.gnu.org/onlinedocs/gcc-7.2.0/gcc/)

### [GNU Binutils Commands](https://en.wikipedia.org/wiki/GNU_Binutils)
<table class="wikitable">
<tr>
<td><code><a href="/wiki/GNU_Assembler" title="GNU Assembler">as</a></code></td>
<td><a href="/wiki/Assembly_language#Assembler" title="Assembly language">assembler</a> popularly known as GAS (GNU Assembler)</td>
</tr>
<tr>
<td><code><a href="/wiki/GNU_linker" title="GNU linker">ld</a></code></td>
<td><a href="/wiki/Linker_(computing)" title="Linker (computing)">linker</a></td>
</tr>
<tr>
<td><code><a href="/wiki/Gprof" title="Gprof">gprof</a></code></td>
<td><a href="/wiki/Profiling_(computer_programming)" title="Profiling (computer programming)">profiler</a></td>
</tr>
<tr>
<td><code><a href="/w/index.php?title=Addr2line&amp;action=edit&amp;redlink=1" class="new" title="Addr2line (page does not exist)">addr2line</a></code></td>
<td>convert address to file and line</td>
</tr>
<tr>
<td><code><a href="/wiki/Ar_(Unix)" title="Ar (Unix)">ar</a></code></td>
<td>create, modify, and extract from <a href="/wiki/Archive_file" title="Archive file">archives</a></td>
</tr>
<tr>
<td><code>c++filt</code></td>
<td><a href="/wiki/Name_mangling#Name_mangling_in_C.2B.2B" title="Name mangling">demangling</a> filter for <a href="/wiki/C%2B%2B" title="C++">C++</a> symbols</td>
</tr>
<tr>
<td><code>dlltool</code></td>
<td>creation of Windows <a href="/wiki/Dynamic-link_library" title="Dynamic-link library">dynamic-link libraries</a></td>
</tr>
<tr>
<td><code><a href="/wiki/Gold_(linker)" title="Gold (linker)">gold</a></code></td>
<td>alternative linker</td>
</tr>
<tr>
<td><code>nlmconv</code></td>
<td>object file conversion to a <a href="/wiki/NetWare_Loadable_Module" title="NetWare Loadable Module">NetWare Loadable Module</a></td>
</tr>
<tr>
<td><code><a href="/wiki/Nm_(Unix)" title="Nm (Unix)">nm</a></code></td>
<td>list symbols in object files</td>
</tr>
<tr>
<td><code><a href="/w/index.php?title=Objcopy&amp;action=edit&amp;redlink=1" class="new" title="Objcopy (page does not exist)">objcopy</a></code></td>
<td>copy object files, possibly making changes</td>
</tr>
<tr>
<td><code><a href="/wiki/Objdump" title="Objdump">objdump</a></code></td>
<td>dump information about object files</td>
</tr>
<tr>
<td><code><a href="/w/index.php?title=Ranlib&amp;action=edit&amp;redlink=1" class="new" title="Ranlib (page does not exist)">ranlib</a></code></td>
<td>generate indices for archives</td>
</tr>
<tr>
<td><code><a href="/wiki/Readelf" class="mw-redirect" title="Readelf">readelf</a></code></td>
<td>display content of <a href="/wiki/Executable_and_Linkable_Format" title="Executable and Linkable Format">ELF</a> files</td>
</tr>
<tr>
<td><code><a href="/w/index.php?title=Size_(Unix)&amp;action=edit&amp;redlink=1" class="new" title="Size (Unix) (page does not exist)">size</a></code></td>
<td>list total and section sizes</td>
</tr>
<tr>
<td><code><a href="/wiki/Strings_(Unix)" title="Strings (Unix)">strings</a></code></td>
<td>list printable strings</td>
</tr>
<tr>
<td><code><a href="/wiki/Strip_(Unix)" title="Strip (Unix)">strip</a></code></td>
<td>remove symbols from an object file</td>
</tr>
<tr>
<td><code>windmc</code></td>
<td>generates Windows message resources</td>
</tr>
<tr>
<td><code>windres</code></td>
<td>compiler for Windows <a href="/wiki/Resource_(Windows)" title="Resource (Windows)">resource</a> files</td>
</tr>
</table>

### [GDB](https://en.wikipedia.org/wiki/GNU_Debugger)
The debugger is also usually part of the toolchain, as a cross-debugger is needed to debug applications running on your target machine. In the embedded Linux world, the typical debugger is [GDB](http://elinux.org/GDB).

### references
[Linux GCC编译器和GDB调试器](http://www.jianshu.com/p/ffbc358150b9)  
[预处理-编译-汇编-链接过程分析](http://blog.h5min.cn/radianceblau/article/details/73606101)  
[gcc编译出的elf文件分析](http://blog.h5min.cn/radianceblau/article/details/73649350)  

[GCC 编译的背后](https://www.kancloud.cn/kancloud/cbook/68997) / [GCC 编译详解](http://www.cnblogs.com/azraelly/archive/2012/07/07/2580839.html) / [GCC编译器总结](http://www.jianshu.com/p/b8ddb4cee7af)  

[Compiling GCC 7 on macOS](https://solarianprogrammer.com/2017/05/21/compiling-gcc-macos/)

## [LLVM](https://en.wikipedia.org/wiki/LLVM)
official site: [The LLVM Compiler Infrastructure](http://llvm.org/)  
[Assembling a Complete Toolchain](https://clang.llvm.org/docs/Toolchain.html)  

[LLVM零基础学习](http://blog.csdn.net/column/details/llvm.html)  
LLVM每日谈：@[csdn](http://blog.csdn.net/column/details/llvm-study.html)/@[zhihu](https://zhuanlan.zhihu.com/llvm-clang)  

LLVM was originally developed as a research infrastructure to investigate [dynamic compilation](https://en.wikipedia.org/wiki/Dynamic_compilation) techniques for static and dynamic programming languages.  
LLVM was originally written to be a replacement for the existing code generator in the GCC stack.  

The **LLVM** compiler infrastructure project (formerly **Low Level Virtual Machine**) is a "collection of modular and reusable compiler and toolchain technologies" used to develop compiler [front ends](https://en.wikipedia.org/wiki/Compiler#Front_end) and [back ends](https://en.wikipedia.org/wiki/Compiler#Back_end).

> **前端**是语言相关的，输出为抽象语法树；  
> **后端**是机器相关的，输出为机器代码。  
> 有些优化是机器无关的，这一部分可能被单列出来称为**中端**。  
> 
> 以gcc为例，前端生成的中间语言为GENERIC，之后转化为gimple做机器无关的优化，最后转化为RTL做机器相关优化并生成机器代码。
这三个部分就可以分别称为前端、中端、后端。

LLVM is written in C++ and is designed for [compile-time](https://en.wikipedia.org/wiki/Compile-time), [link-time](https://en.wikipedia.org/wiki/Link-time), [run-time](https://en.wikipedia.org/wiki/Run_time_(program_lifecycle_phase)), and "idle-time" optimization of programs written in arbitrary programming languages. Originally implemented for C and C++.

In 2005, Apple Inc. hired Lattner and formed a team to work on the LLVM system for various uses within Apple's development systems. LLVM is an integral part of Apple's latest development tools for macOS and iOS. Since 2013, Sony has been using LLVM's primary front end Clang compiler in the software development kit (SDK) of its PS4 console.

The name LLVM was originally an [initialism](https://en.wikipedia.org/wiki/Initialism) for *Low Level Virtual Machine*, but this became increasingly less apt as LLVM became an "umbrella project" that included a variety of other compiler and low-level tool technologies, so the project abandoned the initialism. Now, LLVM is a brand that applies to the LLVM umbrella project, the LLVM [intermediate representation](https://en.wikipedia.org/wiki/Intermediate_representation) (IR), the LLVM [debugger](https://en.wikipedia.org/wiki/Debugger), the LLVM [C++ Standard Library](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library) (with full support of C++11 and C++14), etc. LLVM is administered by the LLVM Foundation. Its president is compiler engineer Tanya Lattner.

***Components***:

- Front ends  
- Intermediate representation  
- Back ends  
- Linker  
- C++ Standard Library  
- Debugger  

***Features***:

LLVM can provide the middle layers of a complete compiler system, taking intermediate representation (IR) code from a compiler and emitting an optimized IR. This new IR can then be converted and linked into machine-dependent [assembly language](https://en.wikipedia.org/wiki/Assembly_language) code for a target platform. LLVM can accept the IR from the GNU Compiler Collection (GCC) toolchain, allowing it to be used with a wide array of extant compilers written for that project.

LLVM can also generate [relocatable machine code](https://en.wikipedia.org/wiki/Relocation_(computing)) at compile-time or link-time or even binary machine code at run-time.

LLVM supports a language-independent [instruction set](https://en.wikipedia.org/wiki/Instruction_set) and [type system](https://en.wikipedia.org/wiki/Type_system). Each instruction is in [static single assignment form](https://en.wikipedia.org/wiki/Static_single_assignment_form) (SSA), meaning that each [variable](https://en.wikipedia.org/wiki/Variable_(programming)) (called a typed register) is assigned once and then frozen. This helps simplify the analysis of dependencies among variables. LLVM allows code to be compiled statically, as it is **under** the traditional GCC system, or left for late-compiling from the IR to machine code via [just-in-time compilation](https://en.wikipedia.org/wiki/Just-in-time_compilation) (JIT), similar to Java.

### [Clang](https://en.wikipedia.org/wiki/Clang)
[clang: a C language family frontend for LLVM](http://clang.llvm.org/)  
[Clang Language Extensions](http://clang.llvm.org/docs/LanguageExtensions.html)  
[Clang vs Other Open Source Compilers](https://clang.llvm.org/comparison.html)  

[Clang “man” pages](http://clang.llvm.org/docs/CommandGuide/index.html)  
[Clang Compiler User’s Manual](http://clang.llvm.org/docs/UsersManual.html)  
[Frequently Asked Questions (FAQ)](http://clang.llvm.org/docs/FAQ.html)  

Widespread interest in LLVM has led to several efforts to develop new front ends for a variety of languages. The one that has received the most attention is Clang, a new compiler supporting C, C++, and Objective-C.

[LLVM 与 Clang 介绍](https://linuxtoy.org/archives/llvm-and-clang.html)  
[结构化编译器前端 Clang 介绍](https://www.ibm.com/developerworks/cn/opensource/os-cn-clang/index.html)  
[深入研究Clang](http://blog.csdn.net/column/details/hacking-clang.html)：[Clang和LLVM的关系及整体架构](http://blog.csdn.net/snsn1984/article/details/17716261)  

[iOS编译过程的原理和应用](http://blog.csdn.net/hello_hwc/article/details/53557308)  
[深入剖析 iOS 编译 Clang / LLVM](https://segmentfault.com/l/1500000008514518)  
[一篇文章走进mac逆向的世界](http://www.alonemonkey.com/2017/05/31/get-start-with-mac-reverse/)  

### [LLDB](https://en.wikipedia.org/wiki/LLDB_(debugger))
[LLDB to GDB Command Map](https://lldb.llvm.org/lldb-gdb.html)  
[LLDB Quick Start Guide](https://developer.apple.com/library/content/documentation/IDEs/Conceptual/gdb_to_lldb_transition_guide/document/lldb-basics.html): [GDB and LLDB Command Examples](https://developer.apple.com/library/content/documentation/IDEs/Conceptual/gdb_to_lldb_transition_guide/document/lldb-command-examples.html)  

[LLDB基础知识](http://www.jianshu.com/p/e89af3e9a8d7) / [LLDB调试命令初探](http://www.starfelix.com/blog/2014/03/17/lldbdiao-shi-ming-ling-chu-tan/)  
[Dancing in the Debugger — A Waltz with LLDB](https://www.objc.io/issues/19-debugging/lldb-debugging/) / [与调试器共舞 - LLDB 的华尔兹](https://objccn.io/issue-19-2/) @[segmentfault](https://segmentfault.com/a/1190000002413758)

## references
[编译器(GNU & GCC & LLVM & clang)](http://blog.csdn.net/itianyi/article/details/43057279)  
[通过编译 eddic 来比较 GCC 4.7 和 Clang 3.1 的性能](https://www.oschina.net/question/12_78997)  

[Clang 比 GCC 好在哪里？](https://www.zhihu.com/question/20235742)  
[C/C++: clang 代替 gcc](http://fzheng.me/2016/03/15/clang-gcc/)  

[mac 使用gcc 为什么编译错误是clang 提示？](https://segmentfault.com/q/1010000000515389)

