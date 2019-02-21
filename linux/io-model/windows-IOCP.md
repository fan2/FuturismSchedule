[I/O Completion Ports](https://docs.microsoft.com/zh-cn/windows/desktop/FileIO/i-o-completion-ports)  

[CreateIoCompletionPort](https://docs.microsoft.com/zh-cn/windows/desktop/FileIO/createiocompletionport) / [GetQueuedCompletionStatus](https://msdn.microsoft.com/en-us/library/windows/desktop/aa364986(v=vs.85).aspx)  

## libraries

### libuv

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
