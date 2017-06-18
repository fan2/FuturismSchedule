<!--TOC-->

# CFNetwork
Networking, Internet, & Web | Guides | [CFNetwork Programming Guide](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Introduction/Introduction.html#//apple_ref/doc/uid/TP30001132)

![Figure 1-1  CFNetwork and other software layers on OS X](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Art/layers_2x.png)

![Figure 1-2  CFStream API structure](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Art/framework_layers_2x.png)

## When to Use CFNetwork
`CFNetwork` has a number of advantages over BSD sockets. It provides *run-loop* **integration**, so if your application is run loop based you can use network protocols ***without*** implementing threads. `CFNetwork` also contains a number of objects to help you use network protocols ***without*** having to implement the details yourself. For example, you can use FTP protocols without having to implement all of the details with the CFFTP API. If you understand the networking protocols and need the low-level control they provide but don't want to implement them yourself, then CFNetwork is probably the right choice.

There are a number of advantages of using CFNetwork instead of Foundation-level networking APIs. CFNetwork is focused more on the **network protocols**, whereas the Foundation-level APIs are focused more on **data access**, such as transferring data over HTTP or FTP. Although Foundation APIs do provide some configurability, CFNetwork provides a lot more. For more information on Foundation networking classes, read URL Session Programming Guide.

Now that you understand how CFNetwork interacts with the other OS X networking APIs, you're ready to become familiar with the CFNetwork APIs along with two APIs that form the infrastructure for CFNetwork.

## CFNetwork Concepts
CFNetwork relies on two APIs that are part of the **Core Foundation** framework, ***CFSocket*** and ***CFStream***.

- CFNetwork Infrastructure  
	- CFSocket API  
	- CFStream API  
- CFNetwork API Concepts  
	- CFFTP API  
	- CFHTTP API  
	- CFHTTPAuthentication API  
	- CFHost API  
	- CFNetServices API  
	- CFNetDiagnostics API  

### [CFSocket](https://developer.apple.com/documentation/corefoundation/cfsocket-rg7)
**CFSocket** is an abstraction for BSD sockets. With very little overhead, CFSocket provides almost all the functionality of BSD sockets, and it integrates the socket into a *run loop*. 

A **CFSocket** is a communications **channel** implemented with a BSD socket.  

`CoreFoundation/CFSocket.h`

> A **CFSocket** contains a native socket within a structure that can be used to read from the socket in the background and make the data thus read available using a runloop source.  

## Working with Streams

- Working with Read Streams  
- Working with Write Streams  
- Preventing Blocking When Working with Streams  
	- Using a *Run Loop* to Prevent Blocking  
	- *Polling* a Network Stream  
- Navigating Firewalls  

### [CFStream](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Concepts/Concepts.html#//apple_ref/doc/uid/TP30001132-CH4-SW4)
Read and write streams provide an easy way to **exchange data** to and from a variety of media in a device-independent way. You can create streams for data located in *memory*, in a *file*, or on a *network* (using sockets), and you can use streams without loading all of the data into memory at once.

A stream is **a sequence of bytes** transmitted *serially* over a communications path. Streams are ***one-way*** paths, so to communicate bidirectionally an **input** (read) stream and **output** (write) stream are necessary. Except for file-based streams, you *cannot* seek within a stream; once stream data has been provided or consumed, it *cannot* be retrieved again from the stream.

**`CFStream`** is an API that provides an abstraction for these streams with two new CFType objects: ***CFReadStream*** and ***CFWriteStream***. Both types of stream follow all of the usual Core Foundation API conventions. For more information about Core Foundation types, read [Core Foundation Design Concepts](https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFDesignConcepts/CFDesignConcepts.html#//apple_ref/doc/uid/10000122i).

**`CFStream`** is built on top of **CFSocket** and is the foundation for *CFHTTP* and *CFFTP*. As you can see in Figure 1-2, even though CFStream is not officially part of CFNetwork, it is the *basis* for almost all of CFNetwork.

You can use read and write streams in much the same way as you do UNIX file descriptors. First, you instantiate the stream by specifying the stream type (memory, file, or socket) and set any options. Next, you open the stream and read or write any number of times. While the stream exists, you can get information about the stream by asking for its properties. A stream property is any information about the stream, such as its source or destination, that is not part of the actual data being read or written. When you no longer need the stream, close and dispose of it.

CFStream functions that read or write a stream will suspend, or block, the current process until at least one byte of the data can be read or written. To avoid trying to read from or write to a stream when the stream would block, use the **asynchronous** version of the functions and *schedule* the stream on a run loop. Your callback function is called when it is possible to read and write without blocking.

In addition, CFStream has built-in support for the Secure Sockets Layer (SSL) protocol. You can set up a dictionary containing the stream's SSL information, such as the security level desired or self-signed certificates. Then pass it to your stream as the `kCFStreamPropertySSLSettings` property to make the stream an SSL stream.

The chapter Working with Streams describes how to use read and write streams.

### Cocoa Streams
[Stream Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Streams/Streams.html)  

## Communicating with HTTP Servers
This chapter explains how to create, send, and receive HTTP requests and responses with **`CFHTTP`** API.

## Communicating with Authenticating HTTP Servers
This chapter describes how to interact with authenticating HTTP servers by taking advantage of the **`CFHTTPAuthentication`** API.

- Deciding How to Respond to an Authentication Challenge  
- Responding to an Authentication Challenge  
	- Providing Credentials  
	- Continuing Without Credentials  
	- Canceling the Connection  
- Performing Custom TLS Chain Validation  

![Figure 4-1  Handling authentication](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Art/apply_2x.png)

![Figure 4-2  Finding an authentication object](https://developer.apple.com/library/content/documentation/Networking/Conceptual/CFNetwork/Art/authentication_2x.png)

## Sample Code
### [CFHostSample](https://developer.apple.com/library/content/samplecode/CFHostSample/Introduction/Intro.html)
> Networking, Internet, & Web | Sockets & TCP | Sample Code

The main program is a simple command line tool that accepts parameters, creates query objects, runs them, and prints the results.

The various query classes are each a simple wrapper around **`CFHost`**; each has extensive comments explaining how to use the class and how the class works internally.

### [SimplePing](https://developer.apple.com/library/content/samplecode/SimplePing/Introduction/Intro.html)
> Networking, Internet, & Web | Sockets & TCP | Sample Code

SimplePing demonstrates ping (ICMP) send and receive based on `socket` & `CFSocketRef`.

@interface SimplePing: An object wrapper around the low-level BSD Sockets ping function.

### [UDPEcho](https://developer.apple.com/library/content/samplecode/UDPEcho/Introduction/Intro.html)
> Networking, Internet, & Web | Sockets & TCP | Sample Code

UDPEcho shows how to do UDP communications with **`CFSocket`**.

### [SimpleFTPSample](https://developer.apple.com/library/content/samplecode/SimpleFTPSample/Introduction/Intro.html)
> Networking, Internet, & Web | Protocol Streams | Sample Code

SimpleFTPSample shows how to do simple FTP operations using the **`NSURLConnection`** and **`CFFTPStream`** APIs. It can **download** a file using both NSURLConnection and CFFTPStream. Also, it can **upload** a file, list a directory, and create a directory using CFFTPStream.

### [CocoaEcho](https://developer.apple.com/library/content/samplecode/CocoaEcho/Introduction/Intro.html)
> Networking, Internet, & Web | Sample Code

This sample code shows you how to write a basic echo **client/server** pair. It demonstrates how to make services available on both IPv4 and IPv6, publishing the services using Bonjour, and how to respond to network events asynchronously.

based on **`CFSocket`**, **`CFStreamCreatePairWithSocket`** and **`NSInputStream`**/**`NSOutputStream`**.

- EchoServer  
- EchoConnection  

参考 [Networking Programming Topics](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingTopics/Introduction/Introduction.html#//apple_ref/doc/uid/TP40012546-SW1) | Writing a TCP-Based Server：

> There are ***only two APIs*** that provide the ability to **listen** for incoming network connections: the *`Core Foundation socket API`* and the *`POSIX (BSD) socket API`*. Higher-level APIs cannot be used for accepting incoming connections.
> 
> Call [CFSocketCreateWithNative](https://developer.apple.com/documentation/corefoundation/1543295-cfsocketcreatewithnative). Then follow the directions in [Listening with Core Foundation](Listening with Core Foundation), beginning at step 3.
>> Bind a socket with the [CFSocketSetAddress](https://developer.apple.com/documentation/corefoundation/1542729-cfsocketsetaddress) function. Provide a `CFData` object containing a `sockaddr` struct that specifies information about the desired port and family.  
>> Begin listening on a socket by adding the socket to a run loop.  


