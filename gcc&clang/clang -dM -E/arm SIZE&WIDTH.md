
```Shell
clang -dM -E -arch arm64
```

## arch
### armv7(s)

```C
#define _ILP32 1
#define __ILP32__ 1
#define __ARM_ARCH 7
#define __ARM_32BIT_STATE 1
#define __BIGGEST_ALIGNMENT__ 4
```

### arm64

```C
#define _LP64 1
#define __LP64__ 1
#define __ARM_ARCH 8
#define __ARM_64BIT_STATE 1
#define __BIGGEST_ALIGNMENT__ 8
```

## `__BYTE_ORDER__`

```C
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
```

## `__SIZEOF_INT__`
```C
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_INT__ 4
```

## `__SIZEOF_LONG__`
### armv7(s)
```C
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_LONG__ 8
```

### arm64
```C
#define __SIZEOF_LONG__ 8
#define __SIZEOF_LONG_LONG__ 8
```

## `__SIZE_TYPE__`
`__SIZE_TYPE__` 被定义为 `long unsigned int`。

### armv7(s)
```C
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 32
#define __SIZEOF_SIZE_T__ 4
```

### arm64
```C
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 64
#define __SIZEOF_SIZE_T__ 8
```

## `__SIZEOF_POINTER__`
`__SIZEOF_POINTER__` = `__SIZEOF_LONG__`

### armv7(s)
```C
#define __SIZEOF_POINTER__ 4
#define __POINTER_WIDTH__ 32
```

### arm64
```C
#define __SIZEOF_POINTER__ 8
#define __POINTER_WIDTH__ 64
```

## `__UINTPTR_TYPE__`
存储指针整形值。

### armv7(s)
```C
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 32

#define __UINTPTR_TYPE__ long unsigned int
#define __UINTPTR_WIDTH__ 32
```

### arm64
```C
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 64

#define __UINTPTR_TYPE__ long unsigned int
#define __UINTPTR_WIDTH__ 64
```

## `__PTRDIFF_TYPE__`
用于存储指针加减（偏移）计算结果整形值。

### armv7(s)
```C
#define __PTRDIFF_TYPE__ int
#define __PTRDIFF_WIDTH__ 32
#define __SIZEOF_PTRDIFF_T__ 4
```

### arm64
```C
#define __PTRDIFF_TYPE__ long int
#define __PTRDIFF_WIDTH__ 64
#define __SIZEOF_PTRDIFF_T__ 8
```

## `__WCHAR_TYPE__`
armv7(s) 和 arm64 下的 `sizeof(wchar_t)` 均为 4。

```C
#define __WCHAR_TYPE__ int
#define __WCHAR_WIDTH__ 32
```

## `__SIZEOF_DOUBLE__`

```C
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG_DOUBLE__ 8
```