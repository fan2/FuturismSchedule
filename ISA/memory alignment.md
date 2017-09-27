- align  
- alignment  
- Unaligned  

[what is “stack alignment”?](https://stackoverflow.com/questions/672461/what-is-stack-alignment)  
[Data Alignment](http://www.songho.ca/misc/alignment/dataalign.html)  
[Data structure alignment](https://en.wikipedia.org/wiki/Data_structure_alignment)  
MSDN [align (C++)](https://msdn.microsoft.com/en-us/library/83ythb65.aspx)  

## [ARM7的体系结构](http://blog.csdn.net/tigerjibo/article/details/6127026) - tigerjibo
**非对齐的存储器访问**

- ARM结构希望所有存储器访问时都对齐。即字访问的地址是字对齐的，半字访问的地址是半字对齐的。若不满足上述条件的即为非对齐的存储器访问。  
- 把一个非字对齐（或非半字对齐）的地址写入 ARM 状态（或 Thumb 状态的）R15 寄存器中，将会引起非对齐的指令取指。  
- 在一个非字对齐（或非半字对齐）的地址处读写一个字或半字会引起非对齐的数据访问。

**编程时应该注意的问题**：

ARM处理器直接支持对齐存放的半字或字数据的存取，也就是可以使用一条相应的指令来实现对应操作。  
如果访问非对齐的半字或字数据，将需要多条指令组合才能实现对应操作，这对程序的执行效率影响较大。  
因此，在C语言编程中，定义的多字节变量或结构体，最好使其为对齐存放。  

[How do the ARM Compilers handle memcpy()?](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka3934.html)

## datasheet
### IA
`325462-sdm-vol-1-2abcd-3abcd.pdf`

Volume 1: Basic Architecture

- 4.1.1 Alignment of Words, Doublewords, Quadwords, and Double Quadwords  
- 6.2.2 Stack Alignment  

### ARM
`DDI0406C_c_armv7(A&R)_arm.pdf`

- A3.2 Alignment support  
	- A3.2.2 Cases where unaligned accesses are UNPREDICTABLE  
	- A3.2.3 Unaligned data access restrictions in ARMv7 and ARMv6  

`DEN0013D_cortex_a_series_PG.pdf`

- 14-2 Alignment 
- 17.3.10 Unaligned access  

`ARM_Architecture_Overview.pdf`

- 1. Programmer's Model | Data alignment

### MIPS
For MIPS instructions, the layout of the bit fields in instructions is **little-endian**, regardless of the endianness mode in which the processor is executing.

`MD00082-2B-MIPS32INT-AFP-06.01.pdf`

- 4.5: Memory Alignment  
	- 4.5.1: Addressing Alignment Constraints  
	- 4.5.2: Unaligned Load and Store Instructions (Removed in Release 6)  

- 7.2.1.1 Data Alignment in Loads, Stores, and Moves  
- Appendix B: Misaligned Memory Accesses  

`MIPS_Architecture_MIPS32_InstructionSet_AFP_P_MD00086_06.05.pdf`

未对齐的加载和存储操作展开序列：

- Unaligned Word Load  
- Unaligned Word Store  

## memory order
[如何理解 C++11 的六种 memory order？](https://www.zhihu.com/question/24301047)

std::memory_order: [cppreference](http://en.cppreference.com/w/cpp/atomic/memory_order) / [cplusplus](http://www.cplusplus.com/reference/atomic/memory_order/)  
