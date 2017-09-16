- C(++) Standard Library  
- toolchain：GNU(GCC) / LLVM(CLANG) / Visual Studio(VC)  
- SDK  

## datasheet
### IA
`325462-sdm-vol-1-2abcd-3abcd.pdf`

Volume 1: Basic Architecture

> CHAPTER 4 DATA TYPES  
>> 4.1 FUNDAMENTAL DATA TYPES 

```
The fundamental data types are bytes, words, doublewords, quadwords, and double quadwords (see Figure 4-1). A byte is eight bits, a word is 2 bytes (16 bits), a doubleword is 4 bytes (32 bits), a quadword is 8 bytes (64 bits), and a double quadword is 16 bytes (128 bits). A subset of the IA-32 architecture instructions operates on these fundamental data types without any additional operand typing.
```

### ARM
`DEN0024A_v8_architecture_PG.pdf`  

Table 5-1 Variable width

### MIPS

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
LLP64（or P64）：long long，pointer 是 64-bit；  

[64-bit computing#64-bit data models](https://en.wikipedia.org/wiki/64-bit_computing#64-bit_data_models)

## [Fundamental types corresponding Data Model](http://en.cppreference.com/w/cpp/language/types)

<table class="wikitable" style="text-align:center;">
<tr>
<th rowspan="2"> Type specifier
</th>
<th rowspan="2"> Equivalent type
</th>
<th colspan="5"> Width in bits by data model
</th></tr>
<tr>
<th> C++ standard
</th>
<th> LP32
</th>
<th> ILP32
</th>
<th> LLP64
</th>
<th> LP64
</th></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">short</span></span></span></div>
</td>
<td rowspan="4"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">short</span> <span class="kw4">int</span></span></span>
</td>
<td rowspan="6"> at least<br /> <b>16</b>
</td>
<td rowspan="6"> <b>16</b>
</td>
<td rowspan="6"> <b>16</b>
</td>
<td rowspan="6"> <b>16</b>
</td>
<td rowspan="6"> <b>16</b>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">short</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">short</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">short</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">short</span></span></span></div>
</td>
<td rowspan="2"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">short</span> <span class="kw4">int</span></span></span>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">short</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">int</span></span></span></div>
</td>
<td rowspan="3"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">int</span></span></span>
</td>
<td rowspan="5"> at least<br /> <b>16</b>
</td>
<td rowspan="5"> <b>16</b>
</td>
<td rowspan="5"> <b>32</b>
</td>
<td rowspan="5"> <b>32</b>
</td>
<td rowspan="5"> <b>32</b>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span></span></span></div>
</td>
<td rowspan="2"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">int</span></span></span>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span></span></span></div>
</td>
<td rowspan="4"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span> <span class="kw4">int</span></span></span>
</td>
<td rowspan="6"> at least<br /> <b>32</b>
</td>
<td rowspan="6"> <b>32</b>
</td>
<td rowspan="6"> <b>32</b>
</td>
<td rowspan="6"> <b>32</b>
</td>
<td rowspan="6"> <b>64</b>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">long</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span></span></span></div>
</td>
<td rowspan="2"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span> <span class="kw4">long</span></span></span></div>
</td>
<td rowspan="4"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span> <br /> <span class="t-mark-rev t-since-cxx11">(C++11)</span>
</td>
<td rowspan="6"> at least<br /> <b>64</b>
</td>
<td rowspan="6"> <b>64</b>
</td>
<td rowspan="6"> <b>64</b>
</td>
<td rowspan="6"> <b>64</b>
</td>
<td rowspan="6"> <b>64</b>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">long</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">long</span> <span class="kw4">long</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">signed</span> <span class="kw4">long</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span> <span class="kw4">long</span></span></span></div>
</td>
<td rowspan="2"> <span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span> <br /> <span class="t-mark-rev t-since-cxx11">(C++11)</span>
</td></tr>
<tr>
<td> <div style="text-align:left; width:auto; margin-left:auto; margin-right:auto;"><span class="t-c"><span class="mw-geshi cpp source-cpp"><span class="kw4">unsigned</span> <span class="kw4">long</span> <span class="kw4">long</span> <span class="kw4">int</span></span></span></div>
</td></tr></table>
