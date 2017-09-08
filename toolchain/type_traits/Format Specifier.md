## [C data types | Basic types](https://en.wikipedia.org/wiki/C_data_types#Basic_types)

Format Specifier

## [String Programming Guide | String Format Specifiers](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Strings/Articles/formatSpecifiers.html)

## FMT
执行 `clang -dM -E -arch arm64 -x c /dev/null`：

```C
#define __INT8_FMTd__ "hhd"
#define __INT8_FMTi__ "hhi"

#define __INT16_FMTd__ "hd"
#define __INT16_FMTi__ "hi"

#define __INT32_FMTd__ "d"
#define __INT32_FMTi__ "i"

#define __INT64_FMTd__ "lld"
#define __INT64_FMTi__ "lli"

#define __UINT8_FMTu__ "hhu"
#define __UINT8_FMTo__ "hho"
#define __UINT8_FMTx__ "hhx"
#define __UINT8_FMTX__ "hhX"

#define __UINT16_FMTu__ "hu"
#define __UINT16_FMTo__ "ho"
#define __UINT16_FMTx__ "hx"
#define __UINT16_FMTX__ "hX"

#define __UINT32_FMTu__ "u"
#define __UINT32_FMTo__ "o"
#define __UINT32_FMTx__ "x"
#define __UINT32_FMTX__ "X"

#define __UINT64_FMTu__ "llu"
#define __UINT64_FMTo__ "llo"
#define __UINT64_FMTx__ "llx"
#define __UINT64_FMTX__ "llX"
```

## misc.etc
[fmtlib](https://github.com/fmtlib/fmt)  
[Comparison of C++ Format and C library’s printf](http://zverovich.net/2015/02/26/comparison-of-cppformat-and-printf.html)  
