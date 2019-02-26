[I/O Completion Ports](https://docs.microsoft.com/zh-cn/windows/desktop/FileIO/i-o-completion-ports)  

[重叠I/O 和 完成端口](https://yq.aliyun.com/articles/567517/)  

重叠是指单套接字缓冲区和应用层缓冲区这两个缓冲重叠的意思，这么一重叠就省了不少空间和不少事情。

重叠缓冲是很好的做法，但是对应每个 socket 都要有预分配投递一个缓冲，那么一万个连接就会有一万个缓冲了。

## SYNOPSIS

```cpp
HANDLE WINAPI CreateIoCompletionPort(
  _In_     HANDLE    FileHandle,
  _In_opt_ HANDLE    ExistingCompletionPort,
  _In_     ULONG_PTR CompletionKey,
  _In_     DWORD     NumberOfConcurrentThreads
);

BOOL WINAPI GetQueuedCompletionStatus(
  _In_  HANDLE       CompletionPort,
  _Out_ LPDWORD      lpNumberOfBytes,
  _Out_ PULONG_PTR   lpCompletionKey,
  _Out_ LPOVERLAPPED *lpOverlapped,
  _In_  DWORD        dwMilliseconds
);

BOOL WINAPI GetQueuedCompletionStatusEx(
  _In_  HANDLE             CompletionPort,
  _Out_ LPOVERLAPPED_ENTRY lpCompletionPortEntries,
  _In_  ULONG              ulCount,
  _Out_ PULONG             ulNumEntriesRemoved,
  _In_  DWORD              dwMilliseconds,
  _In_  BOOL               fAlertable
);
```

## DESCRIPTION

**[CreateIoCompletionPort](https://docs.microsoft.com/zh-cn/windows/desktop/FileIO/createiocompletionport)**: Creates an input/output (I/O) completion port and associates it with a specified file handle, or creates an I/O completion port that is not yet associated with a file handle, allowing association at a later time. Associating an instance of an opened file handle with an I/O completion port allows a process to receive notification of the completion of asynchronous I/O operations involving that file handle.

**[GetQueuedCompletionStatus](https://msdn.microsoft.com/en-us/library/windows/desktop/aa364986(v=vs.85).aspx)**: Attempts to dequeue an I/O completion packet from the specified I/O completion port. If there is no completion packet queued, the function waits for a pending I/O operation associated with the completion port to complete. To dequeue multiple I/O completion packets at once, use the `GetQueuedCompletionStatusEx` function.

**[GetQueuedCompletionStatusEx](https://docs.microsoft.com/zh-cn/windows/desktop/FileIO/getqueuedcompletionstatusex-func)**: Retrieves multiple completion port entries simultaneously. It waits for pending I/O operations that are associated with the specified completion port to complete.

## libraries

### libevent

[iocp-internal.h](https://github.com/libevent/libevent/blob/master/iocp-internal.h)  
[event_iocp.c](https://github.com/libevent/libevent/blob/master/event_iocp.c)  
[buffer_iocp.c](https://github.com/libevent/libevent/blob/master/buffer_iocp.c)  
[regress_iocp](https://github.com/libevent/libevent/blob/master/test/regress_iocp.c)  

### libuv

libuv 中的文件（[fs-event.c](https://github.com/libuv/libuv/blob/v1.x/src/win/fs-event.c)）、管道（[pipe.c](https://github.com/libuv/libuv/blob/v1.x/src/win/pipe.c)）、套接字（[poll.c](https://github.com/libuv/libuv/blob/v1.x/src/win/poll.c)，[tcp.c](https://github.com/libuv/libuv/blob/v1.x/src/win/tcp.c)，[udp.c](https://github.com/libuv/libuv/blob/v1.x/src/win/udp.c)）等均基于 IOCP 等待 I/O 完成通知。

[core.c](https://github.com/libuv/libuv/blob/v1.x/src/win/core.c)  
[test-embed.c](https://github.com/libuv/libuv/blob/v1.x/test/test-embed.c)  

### nginx

nginx/src/event/

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h)  - NGX_HAVE_IOCP  
[ngx_iocp_module.h](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_iocp_module.h)  

## refs

[WinSock完成端口I/O模型](https://blog.csdn.net/phunxm/article/details/5085944)  
[Windows IOCP 完成端口原理详解](https://blog.csdn.net/tgxallen/article/details/77428539)  
[Designing Applications for High Performance – Part III](https://blogs.technet.microsoft.com/winserverperformance/2008/06/25/designing-applications-for-high-performance-part-iii-2/)  

## demos

Managed I/O Completion Ports (IOCP) [1](https://www.codeproject.com/Articles/10280/Managed-I-O-Completion-Ports-IOCP), [2](https://www.codeproject.com/Articles/11609/Managed-I-O-Completion-Ports-IOCP-Part-2)  
[A simple application using I/O Completion Ports and WinSock](http://www.codeproject.com/KB/IP/SimpleIOCPApp.aspx)  
