<!--TOC-->

Xcode | Help | Documentation and API Reference：<kbd>⇧</kbd><kbd>⌘</kbd><kbd>0</kbd>

# Networking Concepts & Overview
Networking, Internet, & Web | Guides

## [Networking Concepts](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingConcepts/Introduction/Introduction.html)

![AboutNetworking](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingConcepts/Art/AboutNetworking.png)

### Networking Terminology
![Figure 1-1  Structure of an Ethernet packet](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingConcepts/Art/structure_of_an_ethernet_packet.png)

### Networking Layers
![Networking Layers](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingConcepts/Art/networking_layers.png)

### Addressing Schemes and Domain Names

### Packet Routing and Delivery

### Dynamic Address Assignment

## [Networking Overview](https://developer.apple.com/library/content/documentation/NetworkingInternetWeb/Conceptual/NetworkingOverview/Introduction/Introduction.html)

### Designing for Real-World Networks
![Design for High Latency - Figure 1-1  Comparison of response times for simultaneous and sequential requests](https://developer.apple.com/library/content/documentation/NetworkingInternetWeb/Conceptual/NetworkingOverview/art/latency_diagram.png)

### Assessing Your Networking Needs
Table 2-1  The layers and families of OS X and iOS networking APIs

Layer | Protocol streams | URL loading | Service discovery
-------|---------------------|----------------|--------------------------
**Foundation layer** | `NSStream` | `NSURLConnection` and `NSURLRequest` | `NSNetService`
**Core Foundation layer** | `CFStream` | `CFHTTPMessage` | `CFNetService`
POSIX layer |  `kqueue` |  `libcurl` (for example. Note that this is a third-party API) | `DNS Service Discovery`

> POSIX layer : Built on top of BSD sockets (directly or indirectly)

### Discovering and Advertising Network Services

### Displaying Web and Multimedia Content

### Making HTTP and HTTPS Requests
- Making Requests Using Foundation  
	- Retrieving the Contents of a URL without Delegates  
	- Retrieving the Contents of a URL with Delegates  
	- Downloading the Contents of a URL to Disk  
	- Making a POST Request  
	- Configuring Authentication  
	- Further Information  
- Making Requests Using Core Foundation  
- Working with Web Services  

#### Further Information
To learn more about the `NSURLSession` API, read [URL Session Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/URLLoadingSystem.html#//apple_ref/doc/uid/10000165i). For related sample code, see [SimpleURLConnections](https://developer.apple.com/library/content/samplecode/SimpleURLConnections/Introduction/Intro.html#//apple_ref/doc/uid/DTS40009245), [AdvancedURLConnections](https://developer.apple.com/library/content/samplecode/AdvancedURLConnections/Introduction/Intro.html#//apple_ref/doc/uid/DTS40009558), and [SeismicXML: Using NSXMLParser to parse XML documents](https://developer.apple.com/library/content/samplecode/SeismicXML/Introduction/Intro.html#//apple_ref/doc/uid/DTS40007323).

For details about the `NSURLConnection` API, read [URL Session Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/URLLoadingSystem.html#//apple_ref/doc/uid/10000165i).

To learn more about using the `NSStream` API for making HTTP requests, read [Setting Up Socket Streams](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Streams/Articles/NetworkStreams.html#//apple_ref/doc/uid/20002277) in [Stream Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Streams/Streams.html#//apple_ref/doc/uid/10000188i).

For an example of the `setHTTPBodyStream:` method and the `CFStreamCreateBoundPair` function, see [SimpleURLConnections](https://developer.apple.com/library/content/samplecode/SimpleURLConnections/Introduction/Intro.html#//apple_ref/doc/uid/DTS40009245) in the iOS library. (The sample as a whole is designed to build and run on iOS, but the networking portions of the code are also useful on OS X.)

### Using Sockets and Socket Streams
This chapter describes ways to make socket connections that are completely under the control of your program. Most programs would be better served by higher-level APIs such as `NSURLConnection`, which was described in previous chapters. These APIs should be used only if you need to support some protocol other than the protocols supported by built-in Cocoa or Core Foundation functionality.

#### Choosing a Socket API
At almost every level of networking, software can be divided into two categories: ***clients*** (programs that connect to other apps) and ***services*** (programs that other apps connect to). At a high level, these lines are clear. Most programs written using high-level APIs are purely clients. At a lower level, however, the lines are often blurry.

Socket and stream programming generally falls into one of the following broad categories:

- ***Packet-based*** communication—Programs that operate on one packet at a time, listening for incoming packets, then sending packets in reply.
	With packet-based communication, the only differences between clients and servers are the contents of the packets that each program sends and receives, and (presumably) what each program does with the data. The networking code itself is identical.

- ***Stream-based*** clients—Programs that use TCP to send and receive data as two continuous streams of bytes, one in each direction.
	With stream-based communication, clients and servers are somewhat more distinct. The actual data handling part of clients and servers is similar, but the way that the program initially constructs the communication channel is very different.

The API you choose for socket-based connections depends on whether you are making a connection *to* another host or receiving a connection *from* another host. It also depends on whether you are using TCP or some other protocol. Here are a few factors to consider:

- In OS X, if you already have networking code that is shared with non-Apple platforms, you can use `POSIX` C networking APIs and continue to use your networking code as-is (on a separate thread). If your program is based on a Core Foundation or Cocoa (Foundation) run loop, you can also use the Core Foundation `CFStream` API to integrate the POSIX networking code into your overall architecture on the main thread. Alternatively, if you are using Grand Central Dispatch (GCD), you can add a socket as a dispatch source.  
- In iOS, `POSIX` networking is **discouraged** because it does not activate the cellular radio or on-demand VPN. Thus, as a general rule, you should separate the networking code from any common data processing functionality and rewrite the networking code using higher-level APIs.  
- For daemons and services that listen on a port, or for non-TCP connections, use `POSIX` or Core Foundation (`CFSocket`) C networking APIs.
- For client code in Objective-C, use Foundation Objective-C networking APIs. Foundation defines high-level classes for managing URL connections, socket streams, network services, and other networking tasks. It is also the primary non-UI Objective-C framework in OS X and iOS, providing routines for run loops, string handling, collection objects, file access, and so on.
- For client code in C, use Core Foundation C networking APIs—part of the `CFNetwork` framework. The Core Foundation framework and the CFNetwork framework are two of the primary C-language frameworks in OS X and iOS. Together they define the functions and structures upon which the Foundation networking classes are built.

### Using Networking Securely
Some attacks your program might encounter include:

- Snooping  
- Man-in-the-middle attacks  
	- Spoofing and phishing  
	- Tampering  
	- Session hijacking  
- Injection attacks  
- Buffer overflows and numeric overflows  

#### Enabling TLS or SSL

- Connecting Securely to a URL  
- Connecting Securely Using Streams  
- Connecting Securely Using BSD Sockets  

### Platform-Specific Networking Technologies

### Avoiding Common Networking Mistakes
- Clean Up Your Connections  
- Avoid POSIX Sockets and CFSocket on iOS Where Possible  
- Avoid Synchronous Networking Calls on the Main Thread  

The most appropriate times to use sockets directly are when you are developing a cross-platform tool or high-performance server software. In other circumstances, you typically should use a higher-level API.

If you are performing network operations on your main thread, you must use only asynchronous calls, or your program becomes unresponsive.

## [Networking Programming Topics](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingTopics/Introduction/Introduction.html#//apple_ref/doc/uid/TP40012546-SW1)
### Using Sockets and Socket Streams
- Choosing an API Family  
- Writing a TCP-Based Client  
- Writing a TCP-Based Server  
- Working with Packet-Based Sockets  
- Obtaining the Native Socket Handle for a Socket Stream  

#### Writing a TCP-Based Client
1. Establishing a Connection  
2. Handling Events  
3. Closing the Connection  

The way you make an outgoing connection depends on what programming language you are using, on the type of connection (TCP, UDP, and so forth), and on whether you are trying to share code with other (non-Mac, non-iOS) platforms.

- Use `NSStream` for outgoing connections in Objective-C.  
- Use `CFStream` for outgoing connections in C.  
- Use `POSIX` calls if cross-platform portability is required.  

#### Writing a TCP-Based Server
1. Listening with Core Foundation  
2. Listening with POSIX Socket APIs  
	- Handling Events with Core Foundation  
	- Handling Events with Grand Central Dispatch  
	- Handling Events with Pure POSIX Code  

As mentioned previously, a server and a client are similar once the connection is established. The main difference is that clients make outgoing connections, whereas servers create a **listening socket** (sometimes listen socket)—a socket that listens for incoming connections—then accept connections on that socket. After that, each resulting connection behaves just like a connection you might make in a client.

The API you should choose for your server depends primarily on whether you are trying to share the code with other (non-Mac, non-iOS) platforms. There are ***only two APIs*** that provide the ability to **listen** for incoming network connections: the *`Core Foundation socket API`* and the *`POSIX (BSD) socket API`*. Higher-level APIs cannot be used for accepting incoming connections.

- If you are writing code for OS X and iOS exclusively, use POSIX networking calls to set up your network sockets. Then, use GCD or `CFSocket` to integrate the sockets into your run loop.  
- Use pure POSIX networking code with a POSIX-based run loop (`select`) if cross-platform portability with non-Apple platforms is required.  
	If you are writing networking code that runs exclusively in OS X and iOS, you should generally **avoid** POSIX networking calls because they are harder to work with than higher level APIs. However, if you are writing networking code that must be shared with other platforms, you can use the POSIX networking APIs so that you can use the same code everywhere.  
- Never use `NSSocketPort` or `NSFileHandle` for general socket communication. For details, see [Do Not Use NSSocketPort (OS X) or NSFileHandle for General Socket Communication](https://developer.apple.com/library/content/documentation/NetworkingInternetWeb/Conceptual/NetworkingOverview/CommonPitfalls/CommonPitfalls.html#//apple_ref/doc/uid/TP40010220-CH4-SW3) in Networking Overview.  


As an alternative to the POSIX `select` function, the BSD-specific `kqueue` API can also be used to handle socket events.

### Resolving DNS Hostnames

### Overriding TLS Chain Validation Correctly
- Manipulating Trust Objects  
	- Adding an anchor to a `SecTrustRef` object  
	- Changing the remote hostname for a `SecTrustRef` object  
- Trust Objects and NSURLConnection  
	- Overriding the trust object used by an `NSURLConnection` object  
- Trust Objects and NSStream  
	- Overriding the TLS hostname with `NSStream`  
	- Using custom TLS anchors with `NSStream`  

## [Networking and Multitasking](https://developer.apple.com/library/content/technotes/tn2277/_index.html)
Multitasking was a key feature of iOS 4. Multitasking allows your app to be put into the background and, from there, suspended. This is great for system responsiveness, but can seriously affect your app's ability to work with the network. This technote explains how best to handle multitasking in a network application.

## 其他
### [Living in a Dynamic TCP/IP Environment](https://developer.apple.com/library/content/technotes/tn1145/_index.html)
Networking, Internet, & Web | Sockets & TCP | Guides

![Figure 1  An example multi-homed configuration](https://developer.apple.com/library/content/technotes/tn1145/Art/tn1145_001.gif)
