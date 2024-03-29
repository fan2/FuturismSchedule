[Machine_code](https://en.wikipedia.org/wiki/Machine_code)  
[Assembly_language](https://en.wikipedia.org/wiki/Assembly_language)  

[OS X Assembler Reference](https://developer.apple.com/library/content/documentation/DeveloperTools/Reference/Assembler/000-Introduction/introduction.html)  
[23. Whirlwind Tour of ARM Assembly](https://www.coranac.com/tonc/text/asm.htm)  

## quora
[as -arch armv6 main.s](https://stackoverflow.com/questions/15982720/armv6-assembler-for-mac)  
[Where should I start learning Assembly?](https://news.ycombinator.com/item?id=7143186) Hacker News  
[How do I run ARM Assembly language on a Mac?](https://www.quora.com/How-do-I-run-ARM-Assembly-language-on-a-Mac)  quora  
[How can I use my MacBook Pro for learning assembly language?](https://www.quora.com/How-can-I-use-my-MacBook-Pro-for-learning-assembly-language) quora  
[Writing and learning assembly on a Mac](https://stackoverflow.com/questions/7315595/writing-and-learning-assembly-on-a-mac) stackoverflow  

[ARM Assembler for iOS: Part 1 – Environment Setup](https://38leinad.wordpress.com/2011/04/06/arm-assembler-for-ios-part-1-environment-setup/) 2011  

## NASM
[NASM](http://www.nasm.us/): [Netwide Assembler](https://en.wikipedia.org/wiki/Netwide_Assembler) wiki  
[NASM Hello World](https://gist.github.com/FiloSottile/7125822)  

[nasm 与 masm语法区别](http://www.cnblogs.com/jiu0821/p/4422464.html)  
[Linux 汇编器：对比 GAS 和 NASM](https://www.ibm.com/developerworks/cn/linux/l-gas-nasm.html)  

## [iOS Assembly Tutorial: Understanding ARM](https://www.raywenderlich.com/37181/ios-assembly-tutorial)
翻译：[iOS汇编教程：理解ARM](http://www.jianshu.com/p/544464a5e630)  

In ARM assembly, the destination comes first, so the above instruction moves the value 42 into register r0. 

```nasm
mov r0, #42
```

- **registers** are like variables that can hold a single value.  
- **registers** are bits of memory very close to the CPU that are used to hold the data currently being acted upon.  

[Mac OS X ABI Mach-O File Format](http://blog.csdn.net/demondev/article/details/7366314) 参考

## practice
[**IA-32 ASSEMBLY ON MAC OS X**](http://fabiensanglard.net/macosxassembly/index.php)  
[***Running Assembly on OS X with nasm***](https://lord.io/blog/2014/assembly-on-osx/)  
[Writing 64 Bit Assembly on Mac OS X](http://www.idryman.org/blog/2014/12/02/writing-64-bit-assembly-on-mac-os-x/)  

[**armAssembly**](http://shervinemami.info/armAssembly.html)：

- [How to write ARM Assembly code for Android or iPhone or Raspberry Pi:](http://shervinemami.info/armAssembly.html#howto)  
- [Combining Assembly code with Objective-C in XCode for iPhone:](http://shervinemami.info/armAssembly.html#combining)  

## misc.etc
[iOS 开发者应该知道的 ARM 结构](http://apple4us.com/2010/07/a-few-things-ios-developer-ought-to-know/)  
[**iOS 逆向之ARM汇编**](http://www.cnblogs.com/csutanyu/p/3575297.html)  

### LDR
[ARM 软件开发工具](http://infocenter.arm.com/help/topic/com.arm.doc.set.swdev/index.html) | [Legacy Tools](http://infocenter.arm.com/help/topic/com.arm.doc.set.swdev/index.html) | [RealView Development Suite](http://infocenter.arm.com/help/topic/com.arm.doc.subset.swdev.rvds/index.html)  
- [Version 4.0 中文用户手册](http://infocenter.arm.com/help/topic/com.arm.doc.subset.swdev.rvds/index.html#rvdscn40)/[RealView 编译工具 《汇编器指南》](http://infocenter.arm.com/help/topic/com.arm.doc.dui0204ic/index.html)/[LDR 伪指令](http://infocenter.arm.com/help/topic/com.arm.doc.dui0204ic/Babbfdih.html)  

[说说ARM汇编的LDR伪指令](http://blog.chinaunix.net/uid-26765074-id-3498038.html)  
[ARM汇编中LDR伪指令和LDR指令](http://blog.csdn.net/ce123_zhouwei/article/details/7182756)  
[ARM汇编中的ldr和adr的区别及其在uboot中相关源码的分析](http://blog.csdn.net/ce123_zhouwei/article/details/7277114)  
