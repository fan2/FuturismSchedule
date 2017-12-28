
[Socks代理和http代理的区别](https://wrfly.kfd.me/SOCKS%E4%BB%A3%E7%90%86%E5%92%8CHTTP%E4%BB%A3%E7%90%86%E7%9A%84%E5%8C%BA%E5%88%AB/)  

## HTTP PROXY
[**HTTP代理原理探索**](http://blog.csdn.net/cszhouwei/article/details/74354166)  
HTTP 代理原理及实现（[一](https://imququ.com/post/web-proxy.html)）（[二](https://imququ.com/post/web-proxy-2.html)）

[npm 那些事儿](https://www.jianshu.com/p/e8755bfbf8f4)  

[20分钟掌握前端编写 CLI 工具](https://cloud.tencent.com/developer/article/1005105)  

爬虫实战 : 爬虫之 web 自动化终极杀手：[上](https://www.qcloud.com/community/article/759574) / [下](https://www.qcloud.com/community/article/565333)  

## [socks](https://en.wikipedia.org/wiki/SOCKS)
[RFC 1928 - SOCKS Protocol Version 5](https://www.ietf.org/rfc/rfc1928.txt)  

[SOCKS5协议原理](http://www.cppblog.com/noflybird/archive/2009/12/26/104149.html)  
[**SOCKS5代理原理探索**](http://blog.csdn.net/cszhouwei/article/details/74362427)  
[BadVPN详解之--始记:透明socks代理与tun2socks](http://blog.csdn.net/dog250/article/details/70343230)  

[设置socks5代理](https://www.jianshu.com/p/ff4093ed893f)  

## macOS 设置代理
### 终端设置代理
[Setting proxy via http_proxy on Mac](https://superuser.com/questions/384398/setting-proxy-via-http-proxy-on-mac)  
[How to set proxy on OS X Terminal permanently?](https://apple.stackexchange.com/questions/226544/how-to-set-proxy-on-os-x-terminal-permanently)  
[Mac OS X Network Proxy Settings in Terminal](https://dmorgan.info/posts/mac-network-proxy-terminal/)  

[**让终端走代理的几种方法**](https://blog.fazero.me/2015/09/15/%E8%AE%A9%E7%BB%88%E7%AB%AF%E8%B5%B0%E4%BB%A3%E7%90%86%E7%9A%84%E5%87%A0%E7%A7%8D%E6%96%B9%E6%B3%95/)  
[**MAC OS X 下怎么设置 Terminal 代理**](https://www.v2ex.com/t/249079)  

1. proxychains4+sslocal  
2. `export all_proxy=socks5://127.0.0.1:1080`  

[ss-local + privoxy 代理](https://www.zfl9.com/ss-local.html)  

### brew 设置代理

### [设置git使用socks5代理](https://gist.github.com/bluethon/45766d0a4541ab633e32a49b6c4e4bdd)

```shell
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'
```
