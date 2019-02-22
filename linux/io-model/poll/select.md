
unix/POSIX - [select](http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html)  
FreeBSD/Darwin - [SELECT(2)](https://www.freebsd.org/cgi/man.cgi?query=select)  

linux - [SELECT(2)](http://man7.org/linux/man-pages/man2/select.2.html)  
debian/Ubuntu - [SELECT(2)](https://manpages.debian.org/stretch/manpages-dev/_newselect.2.en.html)  

Windows - [select()](https://docs.microsoft.com/zh-cn/windows/desktop/api/winsock2/nf-winsock2-select)

## libraries

### libuv

### nginx

nginx/src/event/

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h)  
[ngx_select_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_select_module.c)  
[ngx_win32_select_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_win32_select_module.c)  

## refs

[WinSock三种选择I/O模型](https://blog.csdn.net/phunxm/article/details/5085898)  

select 模式、WSAAsyncSelect 以及 WSAEventSelect 都是通过批量轮询 socket 集合来确定哪些 socket 是当前有效的（即存在待决 I/O 需要处理），好处是防止在在阻塞模式的套接字里被锁死，避免在非阻塞套接字里重复检查 `WSAEWOULDBLOCK` 错误。
