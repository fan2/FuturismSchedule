## win64
[What is the bit size of long on 64-bit Windows?](https://stackoverflow.com/questions/384502/what-is-the-bit-size-of-long-on-64-bit-windows)  

> All modern 64-bit Unix systems use **LP64**. MacOS X and Linux are both modern 64-bit systems.  
> Microsoft uses a different scheme for transitioning to 64-bit: LLP64 ('long long, pointers are 64-bit').   
> This has the merit of meaning that 32-bit software can be recompiled without change.  

[Programming Guide for 64-bit Windows](https://msdn.microsoft.com/en-us/library/windows/desktop/bb427430(v=vs.85).aspx) - [Getting Ready for 64-bit Windows](https://msdn.microsoft.com/en-us/library/windows/desktop/aa384083(v=vs.85).aspx#)  - **Abstract Data Models**  

> In the **LLP64** data model, only pointers expand to 64 bits; all other basic data types (integer and long) remain 32 bits in length.

[Why did the Win64 team choose the LLP64 model?](https://blogs.msdn.microsoft.com/oldnewthing/20050131-00/?p=36563)  
UNIX [64-Bit Programming Models: Why LP64?](http://www.unix.org/version2/whatsnew/lp64_wp.html)  

wireshark [Development/Win64](https://wiki.wireshark.org/Development/Win64)  

> 32-bit UN*X platforms, and 32-bit Windows, use the **ILP32** data model.  
> 64-bit UN*X platform use the **LP64** data model; however, 64-bit Windows uses the **LLP64** data model.  

[Installing Visual Studio 64-bit Components](https://msdn.microsoft.com/en-us/library/ms246588(v=vs.100).aspx)  
[How to make Visual Studio use the native amd64 toolchain](https://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain)  

### __int n
MSDN 的 [Data Type Ranges](https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.140).aspx)

> C/C++ in Visual Studio also supports sized integer types. For more information, see __int8, __int16, __int32, __int64 and Integer Limits. 

[MS-DTYP](https://msdn.microsoft.com/en-us/library/cc230273.aspx) [Integer Types](https://msdn.microsoft.com/en-us/library/cc230339.aspx)

> Microsoft C/C++ supports different sizes of integer types. An 8-bit, 16-bit, 32-bit, or 64-bit integer variable can be declared by using the __intn type specifier, where n is 8, 16, 32, or 64.
The types __int8, __int16, and __int32 are synonyms for the ANSI/ISO C types (as specified in [ISO/IEC-9899]) that have the same size. They are useful for writing portable code that behaves identically across multiple platforms.

[__int64 与 long long 的区别](http://blog.csdn.net/shiwei408/article/details/7463476)  
[C++ 中的 long long 和 __int64 类型](http://blog.csdn.net/ithomer/article/details/5913669)  

### porting
[Windows上64位编程](http://www.cnblogs.com/shiney/archive/2011/06/23/2088103.html)  
[用Visual Studio 编译64位程序](http://blog.csdn.net/jiangxinyu/article/details/6205710)  
[Programming Guide for 64-bit Windows](https://msdn.microsoft.com/en-us/library/windows/desktop/bb427430(v=vs.85).aspx)  
[针对 64 位平台配置 Visual C++ 项目](https://msdn.microsoft.com/zh-cn/library/9yb4317s.aspx)  

## cross platform
[Linux64位程序移植](http://www.cnblogs.com/linuxbug/p/4887715.html)  
[从 Windows 移植到 UNIX，第 1 部分: 移植 C/C++ 源代码](https://www.ibm.com/developerworks/cn/aix/library/au-porting/index.html)  
[Differences in Primitive Data Types between OS X and Windows](http://thecoatlessprofessor.com/programming/differences-in-primitive-data-types-between-os-x-and-windows/)  
