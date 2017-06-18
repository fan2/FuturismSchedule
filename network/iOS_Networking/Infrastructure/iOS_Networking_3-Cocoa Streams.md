<!--TOC-->

# Cocoa Streams
Networking, Internet, & Web | Protocol Streams | Guides | [Stream Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Streams/Streams.html)  

- Introduction  
- Cocoa Streams  
- Reading From Input Streams - `NSInputStream`  
- Writing to Output Streams - `NSOutputStream`  
- Settting Up Socket Streams - `CFReadStreamRef`/`CFWriteStreamRef`  

## Introduction
A stream is a fundamental abstraction in programming: a sequence of bits transmitted serially from one point to another point. Cocoa provides three classes to represent streams and facilitate their use in your programs: `NSStream`, `NSInputStream`, and `NSOutputStream`. With the instances of these classes you can read data from, and write data to, files and application memory. You can also use these objects in socket-based connections to exchange data with remote hosts. You can also subclass the stream classes to obtain specialized stream behavior.

## Cocoa Streams

![Figure 1  Sources and destinations of stream objects](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/Streams/Articles/Art/stream_src_dest.gif)

### NSStream

```obj-c
// NSStream.h

typedef NS_ENUM(NSUInteger, NSStreamStatus) {
    NSStreamStatusNotOpen = 0,
    NSStreamStatusOpening = 1,
    NSStreamStatusOpen = 2,
    NSStreamStatusReading = 3,
    NSStreamStatusWriting = 4,
    NSStreamStatusAtEnd = 5,
    NSStreamStatusClosed = 6,
    NSStreamStatusError = 7
};

typedef NS_OPTIONS(NSUInteger, NSStreamEvent) {
    NSStreamEventNone = 0,
    NSStreamEventOpenCompleted = 1UL << 0,
    NSStreamEventHasBytesAvailable = 1UL << 1, // NSInputStream
    NSStreamEventHasSpaceAvailable = 1UL << 2, // NSOutputStream
    NSStreamEventErrorOccurred = 1UL << 3,
    NSStreamEventEndEncountered = 1UL << 4
};

@interface NSStream : NSObject

@protocol NSStreamDelegate <NSObject>
@optional
- (void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode;
@end

@interface NSInputStream : NSStream
@property (readonly) BOOL hasBytesAvailable;
@end

@interface NSOutputStream : NSStream
@property (readonly) BOOL hasSpaceAvailable;
@end

// NS_AVAILABLE(10_10, 8_0)
@interface NSStream (NSSocketStreamCreationExtensions)

// NS_AVAILABLE(10_10, 8_0)
@interface NSStream (NSStreamBoundPairCreationExtensions)

@interface NSInputStream (NSInputStreamExtensions)

@interface NSOutputStream (NSOutputStreamExtensions)

```

## Reading From Input Streams
- Preparing the Stream Object  
- Handling Stream Events  
- Disposing of the Stream Object  

In Cocoa, reading from an **`NSInputStream`** instance consists of several steps:

1. **Create** and **initialize** an instance of `NSInputStream` from a source of data.  
2. **Schedule** the stream object on a run loop and open the stream.  
3. **Handle** the events that the stream object reports to its delegate.  
4. When there is no more data to read, **dispose** of the stream object.  

If streaming is taking place on another thread, be sure to schedule the stream object on that thread’s run loop. You should never attempt to access a scheduled stream from a thread different than the one owning the stream’s run loop.

## Writing to Output Streams
- Preparing the Stream Object  
- Handling Stream Events  
- Disposing of the Stream Object  

Using an **`NSOutputStream`** instance to write to an output stream requires several steps:

1. **Create** and **initialize** an instance of `NSOutputStream` with a repository for the written data. Also set a delegate.  
2. **Schedule** the stream object on a run loop and open the stream.  
3. **Handle** the events that the stream object reports to its delegate.  
4. If the stream object has written data to memory, obtain the data by requesting the `NSStreamDataWrittenToMemoryStreamKey` property.  
5. When there is no more data to write, **dispose** of the stream object.  

If streaming is taking place on another thread, be sure to schedule the stream object on that thread’s run loop. You should never attempt to access a scheduled stream from a thread different than the one owning the stream’s run loop.

## Polling Versus Run-Loop Scheduling

## Handling Stream Errors

## Settting Up Socket Streams
You can use the `CFStream` API to establish a socket connection and, with the stream object (or objects) created as a result, send data to and receive data from a remote host. You can also configure the connection for security.

- Basic Procedure  
- Securing and Configuring the Connection  
- Initiating an HTTP Request  

The `NSStream` class **does not** support connecting to a remote host on iOS. `CFStream` **does** support this behavior, however, and once you have created your streams with the CFStream API, you can take advantage of the toll-free bridge between CFStream and NSStream to cast your CFStreams to NSStreams. Just call the **`CFStreamCreatePairWithSocketToHost`** function, providing a host name and a port number, to receive both a `CFReadStreamRef` and a `CFWriteStreamRef` for the given host. You can then cast these objects to an `NSInputStream` and an `NSOutputStream` and proceed.

```obj-c
@interface NSStream (NSSocketStreamCreationExtensions)

+ (void)getStreamsToHostWithName:(NSString *)hostname port:(NSInteger)port inputStream:(NSInputStream * _Nullable * _Nullable)inputStream outputStream:(NSOutputStream * _Nullable * _Nullable)outputStream NS_AVAILABLE(10_10, 8_0) __WATCHOS_PROHIBITED;

@end
```

> Sockets & TCP | Guides | [Using NSStreams For A TCP Connection Without NSHost](https://developer.apple.com/library/content/qa/qa1652/_index.html)  

## Sample Code
### [SimpleNetworkStreams](https://developer.apple.com/library/content/samplecode/SimpleNetworkStreams/Introduction/Intro.html)
> Networking, Internet, & Web | Sockets & TCP | Sample Code

Shows how to do simple networking using the **`NSStream`** API. The goal of this sample is very limited: it does not demonstrate everything you need to implement a fully fledged networking product, rather, it focuses on using the NSStream API to move a realistic amount of data across the network.

```
CFN_EXPORT void 
CFStreamCreatePairWithSocketToNetService(
  CFAllocatorRef      __nullable alloc,
  CFNetServiceRef     service,
  CFReadStreamRef   __nullable *  __nullable readStream,
  CFWriteStreamRef __nullable *  __nullable writeStream)           CF_AVAILABLE(10_3, 2_0);

// 将 CFTypeRef 转换成 OC 对象（id）
NS_INLINE id _Nullable CFBridgingRelease(CFTypeRef CF_CONSUMED _Nullable X) {
    return (__bridge_transfer id)X;
}
```
