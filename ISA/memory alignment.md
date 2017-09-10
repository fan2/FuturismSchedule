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
