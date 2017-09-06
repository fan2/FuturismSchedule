## `__WCHAR_TYPE__`
armv7(s) 和 arm64 下的 `sizeof(wchar_t)` 均为 4。

```C
#define __WCHAR_TYPE__ int
#define __WCHAR_WIDTH__ 32
```

## -fshort-wchar
[Implication of using -fshort-wchar](https://stackoverflow.com/questions/15286568/implication-of-using-fshort-wchar)  

[linux 下的 wchar_t](http://blog.csdn.net/kusey/article/details/6186710)  
[Android NDK 下的宽字符编码转换及icu库的使用](http://www.cnblogs.com/likwo/archive/2012/08/22/2651380.html)  

[WCHAR我不再惧怕了](http://www.cppblog.com/shongbee2/archive/2009/04/28/81349.html)  
[字符编码及宽字符类型(wchar_t)的跨平台处理](http://blog.csdn.net/willib/article/details/51583044)  

## [wint_t](http://www.cplusplus.com/reference/cwchar/wint_t/)
[wchar_t vs wint_t](https://stackoverflow.com/questions/1081456/wchar-t-vs-wint-t)  

## CHAR_UNSIGNED
### `__CHAR_UNSIGNED__`
GCC defines this macro if and only if the data type *`char`* is unsigned on the target machine. It exists to cause the standard header file `limits.h` to work correctly. You should not use this macro yourself; instead, refer to the standard macros defined in `limits.h`.

### `__WCHAR_UNSIGNED__`
Like `__CHAR_UNSIGNED__`, this macro is defined if and only if the data type *`wchar_t`* is unsigned and the front-end is in C++ mode.
