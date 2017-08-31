## binutils

```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>dir *.exe
 驱动器 C 中的卷是 System
 卷的序列号是 0004-9485

 C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin 的目录

2016/06/09  22:46            92,320 bscmake.exe
2016/08/25  23:13           190,600 cl.exe
2016/06/09  22:46            48,288 cvtres.exe
2016/06/09  22:46            27,296 dumpbin.exe
2016/06/09  22:46            27,296 editbin.exe
2016/06/09  22:46           166,544 ifc.exe
2016/06/09  22:46            27,280 lib.exe
2016/08/25  23:13           994,448 link.exe
2016/06/09  22:46           448,144 ml.exe
2016/06/09  22:46           987,304 mspdbcmf.exe
2016/06/09  22:46           137,896 mspdbsrv.exe
2016/06/09  22:46           105,624 nmake.exe
2016/06/09  22:46            62,624 pgocvt.exe
2016/06/09  22:46            92,320 pgomgr.exe
2016/06/09  22:46            67,752 pgosweep.exe
2016/06/09  22:46            29,856 undname.exe
2016/06/09  22:46           899,736 vctip.exe
2016/06/09  22:46            48,288 xdcmake.exe
              18 个文件      4,453,616 字节
               0 个目录 41,085,566,976 可用字节
```

amd64/x86_amd64 下有 64 位版本的 `ml64.exe`。

---

[生成 C/C++ 程序](https://msdn.microsoft.com/zh-cn/library/z7kx322x.aspx)：[在命令行上生成](https://msdn.microsoft.com/zh-cn/library/f35ctcxw.aspx) & [C/C++ 生成参考](https://msdn.microsoft.com/zh-CN/library/91621w01.aspx) 

/? Display brief usage message

## ml(Macro Assembler)
```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>ml
Microsoft (R) Macro Assembler Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: ML [ options ] filelist [ /link linkoptions]
Run "ML /help" or "ML /?" for more info
```

[在Visual Studio中编译程序集](https://gxnotes.com/article/132239.html)  
[windows 上使用汇编](http://www.mouseos.com/assembly/nasm.html)  
[如何用VC编绎ASM](http://www.aogosoft.com/bbs/mixpage.asp?mode=viewoktext&fileid=69173) - MASM6.14从傻瓜到入门

## nmake
```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>nmake

Microsoft (R) Program Maintenance Utility Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.

```

[NMAKE 参考](https://msdn.microsoft.com/zh-cn/library/dd9y37ha.aspx)

[[Windows]使用nmake命令](http://www.cnblogs.com/russellluo/archive/2011/10/15/2212787.html)  
[nmake命令（windows下的makefile）](http://www.cnblogs.com/kekec/archive/2013/04/21/3007277.html)  

## cl(Compiler)
```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

[VC 命令行 CL](http://blog.csdn.net/yeweiouyang/article/details/8642770)  

[编译器选项](https://msdn.microsoft.com/zh-cn/library/9s7c9wdw.aspx)：[/link（将选项传递到链接器）](https://msdn.microsoft.com/zh-cn/library/5y4fae15.aspx)  

[编译器命令行语法](https://msdn.microsoft.com/zh-cn/library/610ecb4h.aspx)  - [CL 调用链接器](https://msdn.microsoft.com/zh-cn/library/btw8x58e.aspx)  
[演练：在命令行上编译 C 程序](https://msdn.microsoft.com/zh-cn/library/bb384838.aspx)  
[演练：在命令行上编译本机 C++ 程序](https://msdn.microsoft.com/zh-cn/library/ms235639.aspx)  

## link(Linker)
```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>link
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

 usage: LINK [options] [files] [@commandfile]
```

[链接器选项](https://msdn.microsoft.com/zh-cn/library/y0zzbyt4.aspx)  
[LINK 输入文件](https://msdn.microsoft.com/zh-cn/library/hcce369f.aspx)  

## objdump
```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>lib
Microsoft (R) Library Manager Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: LIB [options] [files]
```

```Shell
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>dumpbin
Microsoft (R) COFF/PE Dumper Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: DUMPBIN [options] [files]
```