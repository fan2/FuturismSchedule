
unix/POSIX - [poll](http://pubs.opengroup.org/onlinepubs/9699919799/functions/poll.html)  
FreeBSD/Darwin - [poll](https://www.freebsd.org/cgi/man.cgi?query=poll)  

linux - [POLL(2)](http://man7.org/linux/man-pages/man2/poll.2.html)  
debian/Ubuntu - [poll](https://manpages.debian.org/stretch/manpages-dev/poll.2.en.html)  

## libraries

### libuv

### nginx

nginx/src/event/

[ngx_event.h](https://github.com/nginx/nginx/blob/master/src/event/ngx_event.h) -NGX_HAVE_POLL,NGX_HAVE_DEVPOLL  
[ngx_poll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_poll_module.c)  
[ngx_win32_poll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_win32_poll_module.c)  
[ngx_devpoll_module.c](https://github.com/nginx/nginx/blob/master/src/event/modules/ngx_devpoll_module.c)  

### [muduo](https://github.com/chenshuo/muduo)

[PollPoller.cc](https://github.com/chenshuo/muduo/blob/master/muduo/net/poller/PollPoller.cc)  
