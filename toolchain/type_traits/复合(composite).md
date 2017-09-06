## 复合

### 比特组合
芯片规格说明书，寄存器位串（bitset）。

嵌入式（单片机MCU/嵌入式SoC）按按位与或非。

options:

```CPP
rc = WSAAsyncSelect(s, hWnd, wMsg, FD_READ|FD_WRITE);
```

uuid,md5,SHA

IMEI：  
MAC：uint32 mac[6];  

### 字节复合
1. COLORREF

```C
typedef DWORD               COLORREF
```

2. 消息 [lParam](https://msdn.microsoft.com/en-us/library/windows/desktop/ms741540(v=vs.85).aspx)

```CPP
#include <windows.h>

#define WSAGETSELECTEVENT(lParam)       LOWORD(lParam)
#define WSAGETSELECTERROR(lParam)       HIWORD(lParam)
```

3. *Int64

```obj-c
// *OS.sdk/usr/include/MacTypes.h

#ifndef _OS_OSTYPES_H
#if TARGET_RT_BIG_ENDIAN
// ...
#else
struct wide {
  UInt32              lo;
  SInt32              hi;
};
typedef struct wide                     wide;
struct UnsignedWide {
  UInt32              lo;
  UInt32              hi;
};
typedef struct UnsignedWide             UnsignedWide;
#endif  /* TARGET_RT_BIG_ENDIAN */

#endif

#if TYPE_LONGLONG
// ...
#else
typedef wide                            SInt64;
typedef UnsignedWide                    UInt64;
#endif  /* TYPE_LONGLONG */
```

### 联合（union）
一个地址（一块内存）多重解析

fixed point / floating point  
socket addr  
IP 地址：点分十进制和字符串  

测试大小序

### 原始类型复合（record）
tuple or struct

1. 除法结果 [div_t](http://www.cplusplus.com/reference/cstdlib/div_t/)：商和余数

```CPP
typedef struct {
  int quot;
  int rem;
} div_t;
```

2. ctime

- struct **timespec**

```obj-c
// *OS.sdk/usr/include/sys/_types/_timespec.h

struct timespec // _STRUCT_TIMESPEC
{
	__darwin_time_t	tv_sec;
	long            tv_nsec;
};
```

- struct **timeval**

```obj-c
// *OS.sdk/usr/include/sys/_types/_timeval.h

struct timeval // _STRUCT_TIMEVAL
{
	__darwin_time_t	        tv_sec;	        /* seconds */
	__darwin_suseconds_t    tv_usec;        /* and microseconds */
};
```

- struct **tm**  

```C
// *OS.sdk/usr/include/time.h

struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	long	tm_gmtoff;	/* offset from UTC in seconds */
	char	*tm_zone;	/* timezone abbreviation */
};
```

- struct sockaddr

```cpp
// *OS.sdk/usr/include/socket.h

struct sockproto {
	__uint16_t	sp_family;		/* address family */
	__uint16_t	sp_protocol;		/* protocol */
};

struct sockaddr {
	__uint8_t	sa_len;		/* total length */
	sa_family_t	sa_family;	/* [XSI] address family */
	char		sa_data[14];	/* [XSI] addr value (actually larger) */
};

struct	linger {
	int	l_onoff;		/* option on/off */
	int	l_linger;		/* linger time */
};
```

4. 复数（class [complex](http://www.cplusplus.com/reference/complex/)）

- std::complex::real：Real part  
- std::complex::imag：Imaginary part  

### Utility types
times, dates and monetary values and memory
