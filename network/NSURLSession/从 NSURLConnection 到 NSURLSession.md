
苹果在 iOS 7.0 开始推出了新的 **`NSURLSession`** 网络框架：

```obj-c
// NSURLSession is a replacement API for NSURLConnection.
NS_CLASS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0)
@interface NSURLSession : NSObject
```

从 iOS 9.0 开始，**`NSURLConnection`** 宣告过期（DEPRECATED），建议使用 **`NSURLSession`** 替代方案：

```obj-c
/***
DEPRECATED: The NSURLConnection class should no longer be used.  NSURLSession is the replacement for NSURLConnection 
***/

@interface NSURLConnection : NSObject

/* Designated initializer */
- (nullable instancetype)initWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate startImmediately:(BOOL)startImmediately NS_DEPRECATED(10_5, 10_11, 2_0, 9_0, "Use NSURLSession (see NSURLSession.h)") __WATCHOS_PROHIBITED;

- (nullable instancetype)initWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate NS_DEPRECATED(10_3, 10_11, 2_0, 9_0, "Use NSURLSession (see NSURLSession.h)") __WATCHOS_PROHIBITED;
+ (nullable NSURLConnection*)connectionWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate NS_DEPRECATED(10_3, 10_11, 2_0, 9_0, "Use NSURLSession (see NSURLSession.h)") __WATCHOS_PROHIBITED;
```

AFNetworking 从 3.0 版本开始移除了 NSURLConnection 目录，取消了旧的  NSURLConnection 支持，完全支持 NSURLSession 代替方案。

> [WWDC 2015 - Networking with NSURLSession](https://developer.apple.com/videos/play/wwdc2015/711/)  
> [从 NSURLConnection 到 NSURLSession](http://blog.csdn.net/icash/article/details/44651765)  

## [differences between NSURLSession and NSURLConnection](https://developer.apple.com/library/content/documentation/NetworkingInternetWeb/Conceptual/NetworkingOverview/WorkingWithHTTPAndHTTPSRequests/WorkingWithHTTPAndHTTPSRequests.html#//apple_ref/doc/uid/TP40010220-CH8-SW2)

For the most part, the `NSURLSession` and `NSURLConnection` classes work similarly at a high level. However, there are a few significant differences:

- The `NSURLSession` API provides support for download tasks that behave much like the `NSURLDownload` class. This usage is described further in [Downloading the Contents of a URL to Disk](https://developer.apple.com/library/content/documentation/NetworkingInternetWeb/Conceptual/NetworkingOverview/WorkingWithHTTPAndHTTPSRequests/WorkingWithHTTPAndHTTPSRequests.html#//apple_ref/doc/uid/TP40010220-CH8-SW8).  
- When you create an `NSURLSession` object, you provide a *reusable* configuration object that encapsulates many common configuration options. With `NSURLConnection`, you must set those options on *each* connection independently.  
- An `NSURLConnection` object handles a **single** request and any follow-on requests.
    An `NSURLSession` object manages **multiple** tasks, each of which represents a single URL request and any follow-on requests. You usually create a ***session*** when your app launches, then create ***tasks*** in much the same way that you would create `NSURLConnection` objects.  
- With `NSURLConnection`, each connection object has a **separate** delegate. With `NSURLSession`, the delegate is **shared** across all tasks within a session. If you need to use a different delegate, you must create a new session.  

When you initialize an [NSURLSession](https://developer.apple.com/documentation/foundation/urlsession) or NSURLConnection object, the connection or session is automatically scheduled in the *current* run loop in the *default* run loop mode.


