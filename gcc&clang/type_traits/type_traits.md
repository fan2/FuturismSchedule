
[C type](http://en.cppreference.com/w/c/language/type) / [C++ Type](http://en.cppreference.com/w/cpp/language/type) / [C++ Fundamental types](http://en.cppreference.com/w/cpp/language/types)  

There are fundamental types and compound types.  
**Fundamental types** are the arithmetic types, void, and std::nullptr_t.  
**Compound types** are arrays, functions, pointers, references, classes, unions, enumerations, and pointers to non-static members.  

# <type_traits>
This header defines a series of classes to obtain type information on compile-time.

[cppreference](http://en.cppreference.com/w/cpp/header/type_traits) / [cplusplus](http://www.cplusplus.com/reference/type_traits/)  

A basic trait for types is the categories in which they can be classified. This is a chart on how these categories overlap:

<table class="boxed"><tr><th></th><th>primary categories</th><th colspan="3">composite categories</th></tr>
<tr><td rowspan="4"><a href="/is_fundamental">fundamental</a></td><td><a href="/is_void">void</a></td><td></td><td></td><td></td></tr>
<tr><td><tt>std::nullptr_t</tt></td><td></td><td rowspan="7"><a href="/is_scalar">scalar</a></td><td rowspan="10"><a href="/is_object">object</a></td></tr>
<tr><td><a href="/is_integral">integral</a></td><td rowspan="2"><a href="/is_arithmetic">arithmetic</a></td></tr>
<tr><td><a href="/is_floating_point">floating point</a></td></tr>
<tr><td rowspan="10"><a href="/is_compound">compound</a></td><td><a href="/is_pointer">pointer</a></td><td></td></tr>
<tr><td><a href="/is_member_object_pointer">member object pointer</a></td><td rowspan="2"><a href="/is_member_pointer">member pointer</a></td></tr>
<tr><td><a href="/is_member_function_pointer">member function pointer</a></td></tr>
<tr><td><a href="/is_enum">enum</a></td><td></td></tr>
<tr><td><a href="/is_union">union</a></td><td></td><td></td></tr>
<tr><td><a href="/is_class">class</a><span title="(a class that is not a union)">*</span></td><td></td><td></td></tr>
<tr><td><a href="/is_array">array</a></td><td></td><td></td></tr>
<tr><td><a href="/is_lvalue_reference">l-value reference</a></td><td rowspan="2"><a href="/is_reference">reference</a></td><td></td><td></td></tr>
<tr><td><a href="/is_rvalue_reference">r-value reference</a></td><td></td><td></td></tr>
<tr><td><a href="/is_function">function</a></td><td></td><td></td><td></td></tr>
</table>

> `*` = excluding unions

## std::is_fundamental
[cppreference](http://en.cppreference.com/w/cpp/types/is_fundamental) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_fundamental/)

- [Fundamental (built-in) types](https://msdn.microsoft.com/en-us/library/hh279663.aspx)  
- [primitive data types](http://helpcentreonline.com/article/primitiv_console_gcc_framhtml.html)  
- [Basic data types](http://www.keil.com/support/man/docs/armcc/armcc_chr1359125009502.htm)  

include arithmetic type, void, or nullptr_t

[fundamental arithmetic types](http://www.cplusplus.com/reference/type_traits/is_fundamental/)：

<table class="boxed">
<tr><th colspan="2">fundamental arithmetic types</th></tr>
<tr><td rowspan="15">integral types</td><td><tt>bool</tt></td></tr>
<tr><td><tt>char</tt></td></tr>
<tr><td><tt>char16_t</tt></td></tr>
<tr><td><tt>char32_t</tt></td></tr>
<tr><td><tt>wchar_t</tt></td></tr>
<tr><td><tt>signed char</tt></td></tr>
<tr><td><tt>short int</tt></td></tr>
<tr><td><tt>int</tt></td></tr>
<tr><td><tt>long int</tt></td></tr>
<tr><td><tt>long long int</tt></td></tr>
<tr><td><tt>unsigned char</tt></td></tr>
<tr><td><tt>unsigned short int</tt></td></tr>
<tr><td><tt>unsigned int</tt></td></tr>
<tr><td><tt>unsigned long int</tt></td></tr>
<tr><td><tt>unsigned long long int</tt></td></tr>
<tr><td rowspan="3">floating point types</td><td><tt>float</tt></td></tr>
<tr><td><tt>double</tt></td></tr>
<tr><td><tt>long double</tt></td></tr>
<tr><td>void</td><td><tt>void</tt></td></tr>
<tr><td>null pointer</td><td><tt>std::nullptr_t</tt></td></tr>
</table>

### std::is_arithmetic
[cppreference](http://en.cppreference.com/w/cpp/types/is_arithmetic) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_arithmetic/)

is_arithmetic = is_integral || is_floating_point

is_integral：[cppreference](http://en.cppreference.com/w/cpp/types/is_integral) /  [cplusplus](http://www.cplusplus.com/reference/type_traits/is_integral/)  
is_floating_point：[cppreference](http://en.cppreference.com/w/cpp/types/is_floating_point) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_floating_point/)  

#### Notes
Arithmetic types are the types for which the built-in [arithmetic operators](http://en.cppreference.com/w/cpp/language/operator_arithmetic) (+, -, *, /) are defined (possibly in combination with the usual arithmetic conversions)  
Specializations of [std::numeric_limits](http://en.cppreference.com/w/cpp/types/numeric_limits) are provided for all arithmetic types.

All fundamental arithmetic types, along with all their aliases (like those in cstdint), are considered arithmetic types by this class, including their const and volatile qualified variants.  
Enums are not considered arithmetic types in C++ (see [is_enum](http://www.cplusplus.com/is_enum)).

#### Possible implementation

```CPP
template< class T >
struct is_arithmetic : std::integral_constant<bool,
                                              std::is_integral<T>::value ||
                                              std::is_floating_point<T>::value> {};
```

## std::is_compound（复合类型）
[cppreference](http://en.cppreference.com/w/cpp/types/is_compound) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_compound/)

### Notes
Compound types are the types that are **constructed** from fundamental types. 
Any C++ type is either fundamental or compound.

- array, function,   
- object pointer, function pointer, member object pointer, member function pointer,   
- reference, class, union, or enumeration,   
- any cv-qualified variants(c: const, v: volatile, const volatile)  

### Possible implementation

```CPP
template< class T >
struct is_compound : std::integral_constant<bool, !std::is_fundamental<T>::value> {};
```

[cv-qualified and cv-unqualified](http://blog.csdn.net/asongnic/article/details/4571418)  
[What does “cv-unqualified” mean in C++?](https://stackoverflow.com/questions/15413037/what-does-cv-unqualified-mean-in-c)  
[用12个实例来解释几个C++概念：POD，cv-qualified，trivial，aggregate type](http://blog.csdn.net/aladdina/article/details/3953552)  

## std::is_scalar
[cppreference](http://en.cppreference.com/w/cpp/types/is_scalar) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_scalar/)

A scalar type is a type that has built-in functionality for the **addition operator**(<kbd>+</kbd>) without overloads.

- cv-qualified arithmetic,  
- pointer, pointer to member,   
- enumeration, or std::nullptr_t type  
 
```CPP
template< class T >
struct is_scalar : std::integral_constant<bool,
                     std::is_arithmetic<T>::value     ||
                     std::is_enum<T>::value           ||
                     std::is_pointer<T>::value        ||
                     std::is_member_pointer<T>::value ||
                     std::is_null_pointer<T>::value> {};
```

## signedness
### std::is_signed
[cppreference](http://en.cppreference.com/w/cpp/types/is_signed) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_signed/)  

```CPP
T(-1) < T(0)
```

### is_unsigned
[cppreference](http://en.cppreference.com/w/cpp/types/is_unsigned) / [cplusplus](http://www.cplusplus.com/reference/type_traits/is_unsigned/)  

```CPP
T(0) < T(-1)
```