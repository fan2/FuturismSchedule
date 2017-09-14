
## Architecture profiles
《Architectures, Processors, and Devices Development Article》:

ARMv7 introduces the concept of Architecture ***profiles***, defining versions of the architecture aimed at different types of processors for different market segments. The defined profiles are:

- ***A***: The *Application* profile defines a VMSA(*Virtual Memory System Architecture*) based microprocessor architecture. It is targeted at **high performance** processors, capable of running **full feature** operating systems. It supports the ARM and Thumb instruction sets.  
- ***R***: The *Real-time* profile defines a PMSA(*Protected Memory System Architecture*) based microprocessor architecture. It is targeted at systems that require **deterministic timing** and **low interrupt latency**. It supports the ARM and Thumb instruction sets.  
- ***M***: The *Microcontroller* profile provides **low-latency interrupt** processing accessible directly from high-level programming languages. It has a **different exception handling model** to the other profiles, implements a variant of the PMSA, and supports a variant of the Thumb instruction set only.  

参考 [Cores](https://en.wikipedia.org/wiki/ARM_architecture#Cores) 和 [List of ARM cores](https://en.wikipedia.org/wiki/List_of_ARM_cores) 表格。

## [ARM infocenter](http://infocenter.arm.com/help/index.jsp)
ARM 信息中心，包含所有 ARM 非机密† 技术出版物。

- [ARM 体系结构](http://infocenter.arm.com/help/topic/com.arm.doc.set.architecture/index.html)  
	- [**Reference Manuals**](http://infocenter.arm.com/help/topic/com.arm.doc.subset.architecture.reference/index.html#reference)  
	- [Instruction Set Quick Reference Cards](http://infocenter.arm.com/help/topic/com.arm.doc.set.architecture/index.html#qrcs)  
- [ARM 软件开发工具](http://infocenter.arm.com/help/topic/com.arm.doc.set.swdev/index.html)  
- [Keil 嵌入式开发](http://infocenter.arm.com/help/topic/com.arm.doc.set.keil/index.html)  
- [开发人员指南和文章](http://infocenter.arm.com/help/topic/com.arm.doc.set.devlib/index.html)  
	- [Software Development](http://infocenter.arm.com/help/topic/com.arm.doc.set.devlib/index.html#swdev)  
		- [Cortex-A Series Programmer's Guide for ARMv7-A](http://infocenter.arm.com/help/topic/com.arm.doc.den0013d/index.html)  
		- [Cortex-A Series Programmer's Guide for ARMv8-A](http://infocenter.arm.com/help/topic/com.arm.doc.den0024a/index.html)  
- [Cortex-A 系列处理器](http://infocenter.arm.com/help/topic/com.arm.doc.set.cortexa/index.html)  

### past
1994 - ARMv3-ARM7 Data Sheet - [ARM DDI 0020C](http://robo.fe.uni-lj.si/~marko/ur/literature%20from%20www/ARM7vC.pdf) - P106  
1995 - ARMv4T-ARM 7TDMI Data Sheet - ARM DDI 0029E - [pt1](http://bear.ces.cwru.edu/eecs_382/ARM7-TDMI-manual-pt1.pdf) / [pt2](http://bear.ces.cwru.edu/eecs_382/ARM7-TDMI-manual-pt2.pdf)  
[ARM Instruction Set - ARM DDI 0084D](http://vision.gel.ulaval.ca/~jflalonde/cours/1001/h17/docs/arm-instructionset.pdf) - P60  
2000 - ARMv5TE-ARM Architecture Reference Manual - [ARM DDI 0100E](https://www.altera.com/en_US/pdfs/literature/third-party/archives/ddi0100e_arm_arm.pdf) - P811  
2005 - ARMv6-ARM Architecture Reference Manual - [ARM DDI 0100I](https://www.scss.tcd.ie/~waldroj/3d1/arm_arm.pdf) - P1138  

### latest
2008 - [The ARM Instruction Set Architecture.ppt](http://users.ece.utexas.edu/~valvano/EE345M/Arm_EE382N_4.pdf) - P85

**2011 - ARMv7-A and ARMv7-R - ARM® Architecture Reference Manual**

- [DDI 0406B](https://www.cs.utexas.edu/~simon/378/resources/ARMv7-AR_TRM.pdf) - P2158  
- [DDI 0406C.b](http://liris.cnrs.fr/~mmrissa/lib/exe/fetch.php?media=armv7-a-r-manual.pdf) - P2734  
- DDI0406C.c - P2736(官方最新)  

2011 - ARMv8 Instruction Set Overview - [PRD03-GENC-010197](https://www.element14.com/community/servlet/JiveServlet/previewBody/41836-102-1-229511/ARM.Reference_Manual.pdf) - P112  

[ARM Architecture Reference Manual for ARMv8-A (64-bit) publicly released](https://community.arm.com/processors/b/blog/posts/arm-architecture-reference-manual-for-armv8-a-64-bit-publicly-released)  
2017 - [**ARM Architecture Reference Manual ARMv8, for ARMv8-A architecture profile**](https://developer.arm.com/docs/ddi0487/latest/arm-architecture-reference-manual-armv8-for-armv8-a-architecture-profile)  

- [ARM DDI 0487A.a (ID090413)](https://yurichev.com/mirrors/ARMv8-A_Architecture_Reference_Manual_(Issue_A.a).pdf) - P5158 beta  
- [ARM DDI 0487B.a (ID033117)](https://static.docs.arm.com/ddi0487/b/DDI0487B_a_armv8_arm.pdf) - P6354(同官方最新)  

## [ARM7的体系结构](http://blog.csdn.net/tigerjibo/article/details/6127026) / [arm架构与体系结构](http://www.cnblogs.com/PengfeiSong/p/6295151.html)  
- ARM 是 RISC 架构  
- ARM 是统一编址的  
- ARM 是哈佛结构的  

### [Computer architecture](https://en.wikipedia.org/wiki/Computer_architecture)
From [ARM9T](https://en.wikipedia.org/wiki/ARM9T)/ARMv4T, with this design generation, ARM moved from a [von Neumann architecture](https://en.wikipedia.org/wiki/Von_Neumann_architecture) (Princeton architecture) to a (modified; meaning split cache) [Harvard architecture](https://en.wikipedia.org/wiki/Harvard_architecture) with separate instruction and data buses (and caches), significantly increasing its potential speed. Most silicon chips integrating these cores will package them as [modified Harvard architecture](https://en.wikipedia.org/wiki/Modified_Harvard_architecture) chips, combining the two address buses on the other side of separated [CPU caches](https://en.wikipedia.org/wiki/CPU_caches) and tightly coupled memories.

@img ![Von Neumann architecture scheme](https://upload.wikimedia.org/wikipedia/commons/e/e5/Von_Neumann_Architecture.svg)

@img ![Block diagram of Harvard computer architecture](https://upload.wikimedia.org/wikipedia/commons/3/3f/Harvard_architecture.svg)

[Difference Between Harvard Architecture And Von Neumann Architecture](http://wikidifferences.com/Difference_Between_Harvard_Architecture_And_Von_Neumann_Architecture)  
[What is the difference between a von Neumann architecture and a Harvard architecture?](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka3839.html)  
[What are the advantages and disadvantages of von Neumann architecture vs Harvard architecture?](https://www.quora.com/Computer-Science-What-are-the-advantages-and-disadvantages-of-von-Neumann-architecture-vs-Harvard-architecture)  

### pipeline stage
参考 [List of ARM microarchitectures](https://en.wikipedia.org/wiki/List_of_ARM_microarchitectures)：

ARM7T/ARMv4T/ARM7TDMI(-S)：3-stage pipeline  
ARM7EJ/ARMv5TEJ/ARM7EJ-S：5-stage pipeline  
ARM10E/ARMv5TE/ARM1020E：6-stage pipeline  
ARM11/ARMv6/ARM1136J(F)-S：8-stage pipeline  
ARM11/ARMv6T2/ARM1156T2(F)-S：9-stage pipeline  
Cortex-R/ARMv7-R/Cortex-R7：9-stage pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A7：8–10 stage pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A8：13-stage superscalar pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A15：15–24 stage pipeline  
Cortex-A(32-bit)/ARMv8-A/Cortex-A32：dual issue, in-order pipeline  
Cortex-A(64-bit)/ARMv8-A/Cortex-A57：3-way superscalar, deeply out-of-order pipeline  

`ARM7TDMI` - architecture v4T. **Von Neuman** core with 3 stage pipeline  
`ARM920T` - architecture v4T. **Harvard** core with 5 stage pipeline and MMU  

博客：《[指令集及流水线](http://blog.csdn.net/phunxm/article/details/8980808)》  

## instruction set
`ARM_Architecture_Overview.pdf`

- All instructions are 32 bits long  
- many execute in a single cycle  
- Instructions are conditionally executed  
- A load / store architecture  

`The ARM Instruction Set Architecture.ppt.pdf`

Main features of the ARM Instruction Set：

-  All instructions are 32 bits long.  
-  Most instructions execute in a single cycle.  
-  Most instructions can be conditionally executed.   
- A load/store architecture  

 When the processor is executing in ARM state:

- All instructions are 32 bits in length  
- All instructions **must be** word aligned  
- Therefore the PC value is stored in bits [31:2] with bits [1:0] equal to zero (as instruction cannot be halfword or byte aligned).  

## MSDN
Understanding ARM Assembly：[Part 1](https://blogs.msdn.microsoft.com/ntdebugging/2013/11/22/understanding-arm-assembly-part-1/) / [Part 2](https://blogs.msdn.microsoft.com/ntdebugging/2014/05/15/understanding-arm-assembly-part-2/) / [Part 3](https://blogs.msdn.microsoft.com/ntdebugging/2014/05/29/understanding-arm-assembly-part-3/)  

## [davespace](http://www.davespace.co.uk/)
http://www.davespace.co.uk/arm/

- [ARM: Introduction to ARM](http://www.davespace.co.uk/arm/introduction-to-arm/)  
- [ARM: Efficient C for ARM](http://www.davespace.co.uk/arm/efficient-c-for-arm/)  

## azeria-labs

- [ARM Assembly Basics](https://azeria-labs.com/writing-arm-assembly-part-1/)  
- [ARM Exploit Development](https://azeria-labs.com/writing-arm-shellcode/)  

## arm keil
[Assembler User Guide](http://www.keil.com/support/man/docs/armasm/armasm_deb1353593789871.htm)  

ARM® Compiler for µVision® armasm User Guide

1. [Chapter 1 Overview of the Assembler](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731119400.htm)  
2. [Chapter 2 Overview of the ARM Architecture](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731124840.htm)  
3. [Chapter 3 Structure of Assembly Language Modules](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731140888.htm)  
4. [Chapter 4 Writing ARM Assembly Language](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731144635.htm)  
5. [Chapter 5 Condition Codes](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731158738.htm)  
6. [Chapter 6 Using the Assembler](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731163750.htm)  
7. [Chapter 7 Symbols, Literals, Expressions, and Operators](http://www.keil.com/support/man/docs/armasm/armasm_dom1359731172022.htm)  
8. [Chapter 8 VFP Programming](http://www.keil.com/support/man/docs/armasm/armasm_pge1423655975021.htm)  
9. [Chapter 9 Assembler Command-line Options](http://www.keil.com/support/man/docs/armasm/armasm_dom1361289815333.htm)  
10. [Chapter 10 ARM and Thumb Instructions](http://www.keil.com/support/man/docs/armasm/armasm_dom1361289850039.htm)  
11. [Chapter 11 VFP Instructions](http://www.keil.com/support/man/docs/armasm/armasm_pge1423738743329.htm)  
12. [Chapter 12 Directives Reference](http://www.keil.com/support/man/docs/armasm/armasm_dom1361290000455.htm)  
13. [Chapter 13 Via File Syntax](http://www.keil.com/support/man/docs/armasm/armasm_chr1359125030640.htm)  

## misc.etc
[arm64 memory layout](http://blog.csdn.net/tiantao2012/article/details/60120996)  
[ARMV8 datasheet学习笔记](http://www.cnblogs.com/smartjourneys/tag/ARMV8/)   
[ARM Architecture Reference Manual for ARMv8-A 中文解读](http://armv8-ref.codingbelief.com/zh/) @[github](https://github.com/codingbelief/arm-architecture-reference-manual-for-armv8-a)  

[ARM家族命名 ](http://blog.sina.com.cn/s/blog_5994f1ca0102v554.html)  
[ARM汇编之寄存器](http://blog.csdn.net/tigerjibo/article/details/6050649)  
[ARM寄存器与汇编指令详解](http://blog.csdn.net/wang328452854/article/details/50466795)  
