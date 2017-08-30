- C(++) Standard Library  
- toolchain：GNU(GCC) / LLVM(CLANG) / Visual Studio(VC)  
- SDK  

## Fundamental types
[C type](http://en.cppreference.com/w/c/language/type) / [C++ Type](http://en.cppreference.com/w/cpp/language/type) / [C++ Fundamental types](http://en.cppreference.com/w/cpp/language/types)  

> The signedness of char depends on the compiler and the target platform: the defaults for ARM and PowerPC are typically **unsigned**, the defaults for x86 and x64 are typically **signed**.

[Variables. Data Types.](http://www.cplusplus.com/doc/oldtutorial/variables/)

MSDN 的 [C++ Type System (Modern C++)](https://msdn.microsoft.com/en-us/library/hh279663.aspx) & [Fundamental Types (C++)](https://msdn.microsoft.com/en-us/library/cc953fe1.aspx)

GNU 的 [The GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html) / [Primitive-Types](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Primitive-Types)、[GCC C++: Primitive Data Types, Variables and Constants Introduction](http://helpcentreonline.com/article/primitiv_console_gcc_framhtml.html)  

ARM/Keil 的 [Basic data types in ARM C and C++](http://www.keil.com/support/man/docs/armcc/armcc_chr1359125009502.htm)  

### limits(range)

MSDN 的 [Data Type Ranges](https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.140).aspx) 和 GNU 的 [Data Type Measurements](http://www.gnu.org/software/libc/manual/html_node/Data-Type-Measurements.html#Data-Type-Measurements) & [Layout of Source Language Data Types](https://gcc.gnu.org/onlinedocs/gccint/Type-Layout.html)  

## Data Models(数据模型)
[数据模型（LP32 ILP32 LP64 LLP64 ILP64 ）](http://blog.csdn.net/wyywatdl/article/details/4683762)  
[資料模型(Data Model LP32 ILP32 LP64 ILP64 LLP64)](http://ryan0988.pixnet.net/blog/post/194111613)  
[ILP32 and LP64 data models and data type sizes](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbcpx01/datatypesize64.htm)  

TYPE      | LP32 | ILP32 | LP64 | ILP64 | LLP64
----------|------|-------|------|-------|--------
CHAR      | 8    | 8     | 8    | 8     | 8
SHORT     | 16   | 16    | 16   | 16    | 16
INT       | 16   | 32    | 32   | 64    | 32
LONG      | 32   | 32    | 64   | 64    | 32
LONG LONG | 64   | 64    | 64   | 64    | 64
POINTER   | 32   | 32    | 64   | 64    | 64

1. `LP32` 和 `ILP32` 是32位平台上的字长模型

LP32：long，pointer 是 32-bit；  
ILP32：int，long 和 pointer 是 32-bit；  
LLP（or P32）：long long 和 pointer 是 32-bit。  

2. LP64，ILP64，LLP64是64位平台上的字长模型

LP64：long 和 pointer 是 64-bit；  
ILP64：int，long，pointer 是 64-bit；  
LLP64（(or P64)）：long long，pointer 是 64-bit；  

## win64
[What is the bit size of long on 64-bit Windows?](https://stackoverflow.com/questions/384502/what-is-the-bit-size-of-long-on-64-bit-windows)  

> All modern 64-bit Unix systems use **LP64**. MacOS X and Linux are both modern 64-bit systems.  
> Microsoft uses a different scheme for transitioning to 64-bit: LLP64 ('long long, pointers are 64-bit').   
> This has the merit of meaning that 32-bit software can be recompiled without change.  

[Programming Guide for 64-bit Windows](https://msdn.microsoft.com/en-us/library/windows/desktop/bb427430(v=vs.85).aspx) - [Getting Ready for 64-bit Windows](https://msdn.microsoft.com/en-us/library/windows/desktop/aa384083(v=vs.85).aspx#)  - **Abstract Data Models**  

> In the **LLP64** data model, only pointers expand to 64 bits; all other basic data types (integer and long) remain 32 bits in length.

[Why did the Win64 team choose the LLP64 model?](https://blogs.msdn.microsoft.com/oldnewthing/20050131-00/?p=36563)  
[64-Bit Programming Models: Why LP64?](http://www.unix.org/version2/whatsnew/lp64_wp.html)  

wireshark [Development/Win64](https://wiki.wireshark.org/Development/Win64)  

> 32-bit UN*X platforms, and 32-bit Windows, use the **ILP32** data model.  
> 64-bit UN*X platform use the **LP64** data model; however, 64-bit Windows uses the **LLP64** data model.  

[Installing Visual Studio 64-bit Components](https://msdn.microsoft.com/en-us/library/ms246588(v=vs.100).aspx)  
[How to make Visual Studio use the native amd64 toolchain](https://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain)  

## Predefined-Macros
MSDN 的 [Keywords (C++)](https://msdn.microsoft.com/en-us/library/2e6a4at9.aspx)

> In Microsoft C++, identifiers with two leading underscores are reserved for compiler implementations.

MSDN 的 [Data Type Ranges](https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.140).aspx)

> If its name begins with two underscores (__), a data type is non-standard.

GNU 的 [Common Predefined Macros](https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html)

> The common predefined macros are GNU C extensions. 
> Their names all start with double underscores.

Visual Studio 2015 [预定义的宏](https://msdn.microsoft.com/zh-cn/library/b0084kay.aspx)

### __int n
MSDN 的 [Data Type Ranges](https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.140).aspx)

> C/C++ in Visual Studio also supports sized integer types. For more information, see __int8, __int16, __int32, __int64 and Integer Limits. 

[MS-DTYP](https://msdn.microsoft.com/en-us/library/cc230273.aspx) [Integer Types](https://msdn.microsoft.com/en-us/library/cc230339.aspx)

> Microsoft C/C++ supports different sizes of integer types. An 8-bit, 16-bit, 32-bit, or 64-bit integer variable can be declared by using the __intn type specifier, where n is 8, 16, 32, or 64.
The types __int8, __int16, and __int32 are synonyms for the ANSI/ISO C types (as specified in [ISO/IEC-9899]) that have the same size. They are useful for writing portable code that behaves identically across multiple platforms.

## cross platform
[Linux64位程序移植](http://www.cnblogs.com/linuxbug/p/4887715.html)  

[针对 64 位平台配置 Visual C++ 项目](https://msdn.microsoft.com/zh-cn/library/9yb4317s.aspx)  
[Windows上64位编程](http://www.cnblogs.com/shiney/archive/2011/06/23/2088103.html)  
[从 Windows 移植到 UNIX，第 1 部分: 移植 C/C++ 源代码](https://www.ibm.com/developerworks/cn/aix/library/au-porting/index.html)  

[Differences in Primitive Data Types between OS X and Windows](http://thecoatlessprofessor.com/programming/differences-in-primitive-data-types-between-os-x-and-windows/)
