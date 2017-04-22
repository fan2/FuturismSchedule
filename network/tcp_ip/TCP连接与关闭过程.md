[TCP连接与关闭过程](http://blog.csdn.net/phunxm/article/details/5085792)

## 建立连接：三次握手
在 TCP/IP 协议中，TCP 协议提供可靠的连接服务，采用三次握手建立一个连接，如图1所示。

![TCP三次握手建立连接](http://p.blog.csdn.net/images/p_blog_csdn_net/phunxm/EntryImages/20091227/TCPConnect.JPG)
图1 TCP三次握手建立连接

1. 客户端 A 发送 SYN 包（SYN=j）到服务器 B，并进入 **SYN_SEND** 状态，等待服务器 B 确认。  
2. 服务器 B 收到 SYN 包，必须确认客户 A 的 SYN（ACK=j+1），同时自己也发送一个 SYN 包（SYN=k），即 ACK+SYN 包，此时服务器 B 进入 **SYN_RECV** 状态。  
3. 客户端 A 收到服务器 B 的 SYN＋ACK 包，向服务器 B 发送确认包 ACK（ACK=k+1）。此包发送完毕，客户端 A 和服务器 B 进入 **ESTABLISHED** 状态，完成三次握手。  

完成三次握手，客户端与服务器开始传送数据。

## 断开连接：四次挥手
由于 TCP 连接是全双工的，因此每个方向都必须单独进行关闭。  
这个原则是当一方完成它的数据发送任务后就能发送一个 FIN 来终止这个方向的连接。  
收到一个 FIN 只意味着这一方向上没有数据流动，一个 TCP 连接在收到一个 FIN 后仍能发送数据。

首先进行关闭的一方将执行主动关闭，而另一方执行被动关闭。  
TCP采用四次挥手关闭连接如图2所示。  

![TCP四次挥手关闭连接](http://p.blog.csdn.net/images/p_blog_csdn_net/phunxm/EntryImages/20091227/TCPClose.JPG)
图2  TCP四次挥手关闭连接

1. 客户端 A 发送一个 FIN，用来关闭客户 A 到服务器 B 的数据传送。  
2. 服务器 B 收到这个 FIN，它发回一个 ACK，确认序号为收到的序号加1。和 SYN 一样，一个 FIN 将占用一个序号。  
3. 服务器 B 关闭与客户端 A 的连接，发送一个 FIN 给客户端 A。  
4. 客户端 A 发回 ACK 报文确认，并将确认序号设置为收到序号加1。

## FAQ
1．为什么建立连接协议是三次握手，而关闭连接却是四次握手呢？

	这是因为服务端的 LISTEN 状态下的 SOCKET 当收到 SYN 报文的建连请求后，它可以把 ACK 和 SYN（ACK 起应答作用，而 SYN 起同步作用）放在一个报文里来发送。  
	但关闭连接时，当收到对方的 FIN 报文通知时，它仅仅表示对方没有数据发送给你了；但未必你所有的数据都全部发送给对方了，所以你未必会马上会关闭 SOCKET,也即你可能还需要发送一些数据给对方之后，再发送 FIN 报文给对方来表示你同意现在可以关闭连接了，所以它这里的 ACK 报文和 FIN 报文多数情况下都是分开发送的。

2．为什么 TIME_WAIT 状态还需要等 2MSL 后才能返回到 CLOSED 状态？

	这是因为虽然双方都同意关闭连接了，而且握手的4个报文也都协调和发送完毕，按理可以直接回到CLOSED状态（就好比从SYN_SEND状态到ESTABLISH状态那样）；但是因为我们必须要假想网络是不可靠的，你无法保证你最后发送的ACK报文会一定被对方收到，因此对方处于LAST_ACK状态下的SOCKET可能会因为超时未收到ACK报文，而重发FIN报文，所以这个TIME_WAIT状态的作用就是用来重发可能丢失的ACK报文。

## 参考
《TCP/IP详解-卷1》第18章《[TCP连接的建立与终止](http://course.ccniit.com/CSTD/Linux/reference/files/018.PDF)》  
《UNIX网络编程-卷1》第2.6节《TCP连接的建立和终止》  

《[TCP连接的状态转换图深度剖析](http://www.diybl.com/course/6_system/linux/Linuxjs/2007104/76065.html)》  

《[TCP状态转换图](http://www.cnblogs.com/qlee/archive/2011/07/12/2104089.html)》  
《[传输控制协议（TCP） -- TCP状态转换图](http://www.cnblogs.com/xiehongfeng100/p/4605786.html)》  
《[TCP状态转换图、滑动窗口、半连接状态、2MSL](http://blog.csdn.net/fadefaraway/article/details/54633278)》  
