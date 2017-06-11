
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
