https://en.wikipedia.org/wiki/IP_fragmentation

[关于mss df的讨论](http://km.oa.com/group/18297/articles/show/154053)  
[用户端MTU引发的血案解码](http://km.oa.com/group/22651/articles/show/195576)  
[内核中分片&重组总结](http://km.oa.com/group/15354/articles/show/88070)  
[关于网络各层协议的数据分片](http://km.oa.com/group/15988/articles/show/104616)  

[IP分片原理及分析](https://my.oschina.net/u/212993/blog/276713)  
[IP分片原理及分析](http://blog.chinaunix.net/uid-20788470-id-1841647.html)  

[IP分片、TCP分段、IP分片中的UDP首部](http://ousysrobin.blog.hexun.com/57221777_d.html)

为什么TCP不会造成IP分片呢？原因是TCP自身支持分段，在TCP进行三次握手的时候，会协商MSS的大小（一般就是MTU），该MSS值存放在TCP段的选项中。当TCP要传输长度超过MSS（Maxitum Segment Size）的数据时，会先对数据进行分段，因此，TCP一般不会造成IP分片。 

而UDP和ICMP就不支持这种分段功能了，UDP和ICMP认为网络层可以传输无限长（实际上有65535的限制）的数据，当这两种协议发送数据时，它们不考虑数据长度，仅在其头部添加UDP或ICMP首部，然后直接交给网络层就万事大吉了。接着网络层IP协议对这种“身长头短”的数据进行分片，不要指望IP能很“智能”地识别传给它的数据上层头部在哪里，载荷又在哪里，它会直接将整个的数据切成N个分片，这样做的结果是，只有第一个分片具有UDP或者ICMP首部，而其它分片则没有。 

