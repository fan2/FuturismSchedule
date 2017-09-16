[Data type](https://en.wikipedia.org/wiki/Data_type)  
[C data types](https://en.wikipedia.org/wiki/C_data_types)  
[How does my computer store things in memory?](http://tldp.org/HOWTO/Unix-and-Internet-Fundamentals-HOWTO/core-formats.html)  

# wiki
## [Data type](https://en.wikipedia.org/wiki/Data_type)
In [computer science](https://en.wikipedia.org/wiki/Computer_science) and [computer programming](https://en.wikipedia.org/wiki/Computer_programming), a **data type** or simply **type** is a classification of data which tells the [compiler](https://en.wikipedia.org/wiki/Compiler) or [interpreter](https://en.wikipedia.org/wiki/Interpreter_(computing)) how the programmer intends to **use** the data.

The type defines the operations(access or manipulate) that can be done on the data, the meaning of the data, and the way values of that type can be stored.

### [Overview](https://en.wikipedia.org/wiki/Data_type#Overview)
Data types are used within type systems, which offer various ways of defining, implementing and using them.  
Almost all programming languages explicitly include the notion of data type, though different languages may use different terminology.  

For example, in the [C programming language](https://en.wikipedia.org/wiki/C_(programming_language)), the "int" type represents the set of [32-bit](https://en.wikipedia.org/wiki/32-bit) [integers](https://en.wikipedia.org/wiki/Integer_(computer_science)) ranging in value from `-2,147,483,648` to `2,147,483,647`, as well as the operations that can be performed on integers, such as addition, subtraction, and multiplication. Colors, on the other hand, are represented by three [bytes](https://en.wikipedia.org/wiki/Byte) denoting the amounts each of red, green, and blue, and one string representing that color's name; allowable operations include addition and subtraction, but not multiplication.

### [Classes of data types](https://en.wikipedia.org/wiki/Data_type#Classes_of_data_types)
#### Primitive data types
##### Machine data types
All data in computers based on digital electronics is represented as [bits](https://en.wikipedia.org/wiki/Bit) (alternatives 0 and 1) on the lowest level. The smallest **addressable** unit of data is usually a *group* of bits called a [byte](https://en.wikipedia.org/wiki/Byte) (usually an [octet](https://en.wikipedia.org/wiki/Octet_(computing)), which is 8 bits). The unit processed by [machine code](https://en.wikipedia.org/wiki/Machine_code) instructions is called a [word](https://en.wikipedia.org/wiki/Word_(data_type)) (as of 2011, typically 32 or 64 bits). Most instructions interpret the word as a [binary number](https://en.wikipedia.org/wiki/Binary_number).

Machine data types need to be exposed or made available in [systems](https://en.wikipedia.org/wiki/Systems_programming) or [low-level programming languages](https://en.wikipedia.org/wiki/Low-level_programming_language), allowing fine-grained control over hardware. The [C programming language](https://en.wikipedia.org/wiki/C_programming_language), for instance, supplies integer types of various widths, such as `short` and `long`. If a corresponding native type does not exist on the target platform, the compiler will **break** them down into code using types that do exist. For instance, if a 32-bit integer is requested on a 16 bit platform, the compiler will tacitly treat it as an *array* of two 16 bit integers.

#### [Composite types](https://en.wikipedia.org/wiki/Data_type#Composite_types)
Composite types are derived from more than one primitive type. This can be done in a number of ways. The ways they are combined are called [data structures](https://en.wikipedia.org/wiki/Data_structure). Composing a primitive type into a compound type generally results in a new type, e.g. *array-of-integer* is a different type to integer.

- [array](https://en.wikipedia.org/wiki/Array_data_type) - [list](https://en.wikipedia.org/wiki/List_(abstract_data_type))  
- [Record](https://en.wikipedia.org/wiki/Record_(computer_science))  
- [Union](https://en.wikipedia.org/wiki/Union_(computer_science)) - A [tagged union](https://en.wikipedia.org/wiki/Tagged_union) (also called a [variant](https://en.wikipedia.org/wiki/Variant_type))  
- [set](https://en.wikipedia.org/wiki/Set_(abstract_data_type))  
- [object](https://en.wikipedia.org/wiki/Object_(computer_science))  

## [C data types](https://en.wikipedia.org/wiki/C_data_types)
[Primitive data type](https://en.wikipedia.org/wiki/Primitive_data_type)  
[Composite data type](https://en.wikipedia.org/wiki/Composite_data_type)  

# C++ data types
## Fundamental types
[C type](http://en.cppreference.com/w/c/language/type)  
[C++ Type](http://en.cppreference.com/w/cpp/language/type)： [**C++ Fundamental types**](http://en.cppreference.com/w/cpp/language/types)  

> The signedness of char depends on the compiler and the target platform: the defaults for ARM and PowerPC are typically **unsigned**, the defaults for x86 and x64 are typically **signed**.

[C++98](http://www.cplusplus.com/doc/oldtutorial/) [Variables. Data Types.](http://www.cplusplus.com/doc/oldtutorial/variables/)

MSDN 的 [C++ Type System (Modern C++)](https://msdn.microsoft.com/en-us/library/hh279663.aspx) & [Fundamental Types (C++)](https://msdn.microsoft.com/en-us/library/cc953fe1.aspx)

GNU 的 [The GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html) / [Primitive-Types](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Primitive-Types)、[GCC C++: Primitive Data Types, Variables and Constants Introduction](http://helpcentreonline.com/article/primitiv_console_gcc_framhtml.html)  

ARM/Keil 的 [Basic data types in ARM C and C++](http://www.keil.com/support/man/docs/armcc/armcc_chr1359125009502.htm)  

### limits(range)

MSDN 的 [Data Type Ranges](https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.140).aspx) 和 GNU 的 [Data Type Measurements](http://www.gnu.org/software/libc/manual/html_node/Data-Type-Measurements.html#Data-Type-Measurements) & [Layout of Source Language Data Types](https://gcc.gnu.org/onlinedocs/gccint/Type-Layout.html)  