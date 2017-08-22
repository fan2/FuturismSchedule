
## CLANG_CXX_
*.xcodeproj

```
CLANG_CXX_LANGUAGE_STANDARD = compiler-default
CLANG_CXX_LANGUAGE_STANDARD = gnu++0x
```

```
CLANG_CXX_LANGUAGE_STANDARD = "gnu++0x";
CLANG_CXX_LIBRARY = "libc++";
CLANG_WARN_CXX0X_EXTENSIONS = YES;
```

```
GCC_C_LANGUAGE_STANDARD = gnu99;
GCC_DYNAMIC_NO_PIC = NO;
GCC_OPTIMIZATION_LEVEL = 0;

GCC_WARN_UNUSED_FUNCTION = YES;
GCC_WARN_UNUSED_VARIABLE = YES;

GCC_ENABLE_CPP_EXCEPTIONS = NO;
GCC_ENABLE_CPP_RTTI = NO;
```

## clang [Feature Checking Macros](http://clang.llvm.org/docs/LanguageExtensions.html#id2)

```C
#ifndef __has_feature         // Optional of course.
  #define __has_feature(x) 0  // Compatibility with non-clang compilers.
#endif
#ifndef __has_extension
  #define __has_extension __has_feature // Compatibility with pre-3.0 compilers.
#endif

...
#if __has_feature(cxx_rvalue_references)
// This code will only be compiled with the -std=c++11 and -std=gnu++11
// options, because rvalue references are only standardized in C++11.
#endif

#if __has_extension(cxx_rvalue_references)
// This code will be compiled with the -std=c++11, -std=gnu++11, -std=c++98
// and -std=gnu++98 options, because rvalue references are supported as a
// language extension in C++98.
#endif
```

clang [Checks for Standard Language Features](http://clang.llvm.org/docs/LanguageExtensions.html#id9)  
[C++11 feature checking](https://stackoverflow.com/questions/10225451/c11-feature-checking)  on stackoverflow  

### [Compiler.h](https://hackage.haskell.org/package/LibClang-3.4.0/src/llvm/include/llvm/Support/Compiler.h)
KSCrash/Source/KSCrash/llvm/Support/Compiler.h

```C
#if __has_feature(cxx_constexpr)

#if __has_feature(cxx_thread_local)
```

**constexpr specifier** (since C++11)

> constexpr - specifies that the value of a variable or function can appear in [constant expressions](http://en.cppreference.com/w/cpp/language/constant_expression)

### [NULL和nullptr](http://yulingtianxia.com/blog/2015/03/08/Insight-of-Null/)

```
#ifndef Nil
# if __has_feature(cxx_nullptr)
```

### objc_arc
CLANG_ENABLE_OBJC_ARC = YES;

```obj-c
#if !__has_feature(objc_arc)
#error  does not support Objective-C Automatic Reference Counting (ARC)
#endif
```