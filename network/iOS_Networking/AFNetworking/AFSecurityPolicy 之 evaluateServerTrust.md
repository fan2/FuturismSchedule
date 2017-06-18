# [AFSecurityPolicy 之 evaluateServerTrust](http://blog.csdn.net/phunxm/article/details/73051902)
## App Transport Security(ATS)
iOS9 引入了新特性 [App Transport Security](http://www.jianshu.com/p/bc9792f86850) ([**ATS**](https://developer.apple.com/videos/play/wwdc2016/706/))，要求 App 内访问的网络必须使用 HTTPs  协议。

在 WWDC 2016 开发者大会上，苹果宣布了一个最后期限：到 2017年1月1日 App Store 中的[所有应用都必须启用 App Transport Security 安全功能](http://www.cnblogs.com/YatHo/p/6118796.html)。

ATS 要求后台服务器必须支持最新的 TLS_V1.2 协议和 ECDH 加密算法。鉴于 HTTP 全面改造升级 HTTPs 的业务铺设尚需时日，苹果[延迟了 App 强制接入 ATS 的 deadline](http://blog.csdn.net/u012847940/article/details/52677838)。目前允许开发者设置 `NSAllowsArbitraryLoads=YES` 来暂时关闭 ATS，从而继续使用 HTTP 连接。

1. 在 `Info.plist` 中添加 App Transport Security Settings (或 [NSAppTransportSecurity](https://developer.apple.com/library/content/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html)), 类型为 Dictionary。  
2. 在 App Transport Security Settings 下添加 Allow Arbitrary Loads (或 NSAllowsArbitraryLoads)，类型为 Boolean，值设为 YES。  

![NSAllowsArbitraryLoads](https://i.stack.imgur.com/LqXFE.png)

> [How to migrate to HTTPS using App Transport Security when developing iOS apps](http://www.techrepublic.com/article/how-to-migrate-to-https-using-app-transport-security-when-developing-ios-apps/)  
> [Transport security has blocked a cleartext HTTP](https://stackoverflow.com/questions/31254725/transport-security-has-blocked-a-cleartext-http)  
> [ATS 对 HTTP 协议屏蔽引起的问题](http://www.cnblogs.com/Zev_Fung/p/5591241.html)  
> [iOS9 & iOS10 HTTP 不能正常使用的解决办法](https://segmentfault.com/a/1190000002933776)  
> [IOS-关于App Transport Security相关说明及适配](http://blog.csdn.net/Maxdong24/article/details/53610127)  
> [关于iOS9中的App Transport Security相关说明及适配](https://my.oschina.net/vimfung/blog/494687)  
> [Xcode7.2与iOS9之坑 ](http://www.cnblogs.com/znios/p/4917704.html) [iOS 9之适配ATS](http://www.cocoachina.com/ios/20151012/13722.html)  

使用更安全的 HTTPs 替代 HTTP 是大势所趋，作为程序开发者必须了解 HTTPs 原理机制和 ATS 适配开发要点。  
本篇续接 [TLS Handshake Flow（extracts from RFCs）](http://blog.csdn.net/phunxm/article/details/72852670) 和 [TLS握手协商流程解析](http://blog.csdn.net/phunxm/article/details/72853552)，介绍实际访问 HTTPs 服务器的 TLS(SSL) 握手阶段需要客户端处理的  NSURLAuthenticationChallenge。

## NSURLAuthenticationChallenge.NSURLProtectionSpace
iOS 中的 **NSURLAuthenticationChallenge** 是认证挑战类，也就是要求客户端进行挑战。
而服务器要求的挑战方式则由 NSURLAuthenticationChallenge 的属性 `NSURLProtectionSpace *protectionSpace` 来描述。
那么 **NSURLProtectionSpace**（保护空间）里面有哪些信息呢？可以肯定的是包括挑战的方式（401授权、客户端证书、服务端要求信任等），服务器的 URL 地址，端口号，协议等等。

以下为` @interface NSURLProtectionSpace` 向外暴露的主要属性：

```obj-c
@interface NSURLProtectionSpace : NSObject <NSSecureCoding, NSCopying>

@property (nullable, readonly, copy) NSString *realm;

@property (readonly) BOOL receivesCredentialSecurely;

@property (readonly) BOOL isProxy;

@property (readonly, copy) NSString *host;

@property (readonly) NSInteger port;

@property (nullable, readonly, copy) NSString *proxyType;

@property (nullable, readonly, copy) NSString *protocol;

@property (readonly, copy) NSString *authenticationMethod;

@end
```

对于 SSL（TLS HandShake），`authenticationMethod` 对应有2种类型：

- **NSURLAuthenticationMethodClientCertificate**：SSL Client certificate，表示服务器要求客户端提供证书（收到 CertificateRequest）。  
- **NSURLAuthenticationMethodServerTrust**：SecTrustRef validation required，表示需要评估是否信任服务器证书。  

对于 NSURLAuthenticationMethodServerTrust，NSURLProtectionSpace 提供了一个 SecTrustRef 属性。

```obj-c
@interface NSURLProtectionSpace(NSServerTrustValidationSpace)

/*!
    @method serverTrust
    @abstract Returns a SecTrustRef which represents the state of the servers SSL transaction state
    @result A SecTrustRef from Security.framework.  (Nil if the authenticationMethod is not NSURLAuthenticationMethodServerTrust)
 */
@property (nullable, readonly) SecTrustRef serverTrust NS_AVAILABLE(10_6, 3_0);

@end
```

## NSURLCredential
客户端若要接受挑战，则需提供挑战的凭证（用户和密码，或者提供客户端证书，或者信任服务器证书，或者代理）。
iOS 提供了一个 [NSURLCredential](http://blog.csdn.net/majiakun1/article/details/17013379) 的类来表示挑战凭证。

针对 `HTTP 401 错误 - 未授权： (Unauthorized)`，需要通过用户账号密码建立凭证：

```obj-c
// Initialize a NSURLCredential with a user and password
+[NSURLCredential(NSInternetPassword) credentialWithUser:password:persistence:]
```

针对 TLS HandShake 中服务器下发的 `Certificate`，macOS/iOS 的 **Security.framework** 的 SecPolicy.h/SecTrust.h 中定义了证书校验信任评估的接口。

```obj-c
// Evaluates a trust reference synchronously.
OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType * __nullable result);
```

调用 `SecTrustEvaluate` 对证书校验通过后，客户端需要基于对服务器的信任来建立凭证。

```obj-c
// Create a new NSURLCredential which specifies that a handshake has been trusted.
+[NSURLCredential(NSServerTrust) credentialForTrust:];
```

## Apple Developer Guide for Security
[Security Starting Point](https://developer.apple.com/library/content/referencelibrary/GettingStarted/GS_Security/index.html)  
[Secure Coding Guide](https://developer.apple.com/library/content/documentation/Security/Conceptual/SecureCodingGuide/Introduction.html#//apple_ref/doc/uid/TP40002415)  
[Certificate, Key, and Trust Services](https://developer.apple.com/documentation/security/certificate_key_and_trust_services)  

[Cryptographic Services Guide](https://developer.apple.com/library/content/documentation/Security/Conceptual/cryptoservices/Introduction/Introduction.html)  
[Certificate, Key, and Trust Services Programming Guide](https://developer.apple.com/library/content/documentation/Security/Conceptual/CertKeyTrustProgGuide/)  

[Security.SecureTransport](https://developer.apple.com/documentation/security/secure_transport)  
[Using the Secure Socket Layer for Network Communication](https://developer.apple.com/documentation/security/secure_transport/using_the_secure_socket_layer_for_network_communication)  

[HTTPS Server Trust Evaluation](https://developer.apple.com/library/content/technotes/tn2232/_index.html)  
[Overriding TLS Chain Validation Correctly](https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/NetworkingTopics/Articles/OverridingSSLChainValidationCorrectly.html#//apple_ref/doc/uid/TP40012544-SW1)  
[Authentication Challenges and TLS Chain Validation](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/Articles/AuthenticationChallenges.html#//apple_ref/doc/uid/TP40009507-SW1)  

### Sample Code
#### [AdvancedURLConnections](https://developer.apple.com/library/content/samplecode/AdvancedURLConnections/Introduction/Intro.html)

> Networking, Internet, & Web | Protocol Streams | Sample Code

This sample demonstrates various advanced networking techniques with **`NSURLConnection`**. Specifically, it demonstrates how to respond to *authentication challenges*, how to modify the default *server trust evaluation* (for example, to support a server with a self-signed certificate), and how to provide client identities.

#### [CustomHTTPProtocol](https://developer.apple.com/library/content/samplecode/CustomHTTPProtocol/Introduction/Intro.html)

> Core Services Layer | Foundation | Sample Code

CustomHTTPProtocol shows how to use an **`NSURLProtocol`** subclass to intercept the **`NSURLConnections`** made by a high-level subsystem that does not otherwise expose its network connections. In this specific case, it intercepts the *HTTPS* requests made by a web view and overrides *server trust evaluation*, allowing you to browse a site whose certificate is not trusted by default.

## AFSecurityPolicy
当基于 NSURLConnection 或 NSURLSession 访问 HTTPs 网站时，NSURLConnection 或 NSURLSession 并没有验证证书是否合法，无法避免中间人攻击。
要做到真正的安全通信，需要客户端校验确认是否信任服务器证书（链）并提供凭证。否则会返回以下错误：

```Shell
NSURLSession/NSURLConnection HTTP load failed (kCFStreamErrorDomainSSL, -9843)
```

AFNetworking 的 AFSecurityPolicy 接口封装了证书验证的过程。

### 收到 NSURLAuthenticationChallenge
在收到 `Certificate` 后，相关回调 NSURLConnectionDelegate/NSURLSessionDelegate 中调用 AFSecurityPolicy 对 NSURLAuthenticationChallenge 进行处理。

AFNetworking 2.x 的 AFURLConnectionOperation/NSURLConnection  
回调 **NSURLConnectionDelegate**：
`-[AFURLConnectionOperation connection:willSendRequestForAuthenticationChallenge:]`；

AFNetworking 3.x 的 AFURLSessionManager 的回调 **NSURLSessionDelegate**：
`-[AFURLSessionManager URLSession:didReceiveChallenge:completionHandler:]` 
或 **NSURLSessionTaskDelegate**：
 `-[AFURLSessionManager URLSession:task:didReceiveChallenge:completionHandler:]`

### 接受 NSURLAuthenticationChallenge
在 `willSendRequestForAuthenticationChallenge` 或 `didReceiveChallenge` 中均需要处理如何接受挑战（NSURLAuthenticationChallenge）。

```obj-c
    if ([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]) {
        // 校验评估是否信任证书（链）
        if ([self.securityPolicy evaluateServerTrust:challenge.protectionSpace.serverTrust forDomain:challenge.protectionSpace.host]) {
            // 创建 NSURLCredential 对象
            NSURLCredential *credential = [NSURLCredential credentialForTrust:challenge.protectionSpace.serverTrust];
            // NSURLConnectionDelegate/willSendRequestForAuthenticationChallenge：为 challenge 的发送方提供 credential
            [[challenge sender] useCredential:credential forAuthenticationChallenge:challenge];
            // NSURLSessionDelegate/didReceiveChallenge：回调 completionHandler
            // completionHandler(NSURLSessionAuthChallengeUseCredential, credential);
        } else {
            // NSURLConnectionDelegate/willSendRequestForAuthenticationChallenge
            [[challenge sender] cancelAuthenticationChallenge:challenge];
            // NSURLSessionDelegate/didReceiveChallenge：回调 completionHandler
            // completionHandler(NSURLSessionAuthChallengeCancelAuthenticationChallenge, nil);
        }
    }
```

#### evaluateServerTrust forDomain
**`-[AFSecurityPolicy evaluateServerTrust:forDomain:]`** 主要调用了 `SecPolicyCreateSSL`、`SecTrustSetPolicies` 和 `SecTrustEvaluate` 这3个函数。

```obj-c
-[AFSecurityPolicy evaluateServerTrust:forDomain:]
{
    // 1. 为服务器 domain 创建 SecPolicyRef
    [policies addObject:(__bridge_transfer id)SecPolicyCreateSSL(true, (__bridge CFStringRef)domain)];

	// 2. 为 SecTrustRef 设置 SecPolicyRef[]
	SecTrustSetPolicies(serverTrust, (__bridge CFArrayRef)policies);

	// 3.调用 SecTrustEvaluate 校验证书（链）——SecTrustRef
	if (self.SSLPinningMode == AFSSLPinningModeNone) {
	    return self.allowInvalidCertificates || AFServerTrustIsValid(serverTrust);
	}

}
```

challenge.protectionSpace.**serverTrust** 为证书，challenge.protectionSpace.**host**（或调用 [[connection currentRequest] valueForHTTPHeaderField:@"host"] 获取）为服务器域名。
以上展示的是 `AFSSLPinningModeNone` 模式完全信任服务器（domain）证书的基本处理流程。

### SSL Pinning
除了去系统信任 CA 机构列表验证的 `AFSSLPinningModeNone` 模式，AFNetworking 还提供了 SSL Pinning 方式的验证。

SSL Pinning 方式（`AFSSLPinningModeCertificate`，`AFSSLPinningModePublicKey`）把服务端下发的证书预先打包到 APP 的 bundle 中，然后通过比较服务端下发的证书和本地证书是否相同来校验证书。
使用该方式的原因是CA机构颁发的证书比较昂贵，一些企业或者个人不申请CA颁发的证书，而是自己手动创建证书。用 SSL Pinning 的方式只要比较证书内容一样，无需验证证书的权威性。

- AFSSLPinningModeNone  

	这个模式表示不做 SSL pinning，只跟浏览器一样**在系统的信任机构列表里验证**服务端返回的证书（链）。  
	若证书是信任机构签发的就会通过；若是自己服务器生成的证书，这里是不会通过的。  

- AFSSLPinningModeCertificate  

	这个模式表示用证书绑定方式验证证书，需要客户端保存服务端的证书拷贝。  
	适用于非浏览器应用，因为浏览器跟很多未知服务端打交道，无法把每个服务端的证书都保存到本地。但CS架构的APP应用一般**事先知道要进行通信的服务端**（例如 QQ 文件后台服务器：`*.ftn.qq.com`），可以直接在客户端保存这些固定服务端的证书用于校验。  
	
	验证分两步：第一步验证证书的域名/有效期等信息；第二步是对比服务端返回的证书跟客户端返回的是否一致。  
	从代码上看，和去系统信任机构列表里验证一样调用 `SecTrustEvaluate`，只是这里的列表换成了客户端预先保存的证书列表（链）。  

- AFSSLPinningModePublicKey  

	这个模式同样是用证书绑定方式验证，客户端要有服务端的证书拷贝，只是验证时**只验证证书里的公钥**，不验证证书的有效期等信息。  
	只要公钥是正确的，就能保证通信不会被窃听，因为中间人没有私钥，无法解开通过公钥加密的数据。  

#### AFSSLPinningModeCertificate
`AFCertificateTrustChainForServerTrust` 中调用 `SecTrustGetCertificateCount(serverTrust)` 取得 SecTrustRef 证书链的长度；通过 SecTrustGetCertificateAtIndex 获取到证书链（trustChain）上的每一个证书（SecCertificateRef）。
然后对 trustChain(`serverCertificates`) 进行验证，具体参考源码注释。

#### AFSSLPinningModePublicKey
`AFPublicKeyTrustChainForServerTrust` 中获取证书链（trustChain）上的每一个证书（SecCertificateRef）后， 调用 `SecTrustCreateWithCertificates` 获取每个证书（SecCertificateRef）对应的 SecTrustRef，进而调用 `SecTrustEvaluate` 校验。
校验通过后，调用 `SecTrustCopyPublicKey` 获取每个证书 SecTrustRef 对应的公钥（SecKeyRef）。
然后对 trustChain(`publicKeys`)进行校验，具体参考源码注释。 

##### 源代码
以下摘自最新 AFNetworking 3.x 源码，稍作注释：

```obj-c
-[AFSecurityPolicy evaluateServerTrust:forDomain:]
{

    // 4.从 SecTrustRef 获取 trustChain，进行 SSL Pinning 验证。

    switch (self.SSLPinningMode) {
        case AFSSLPinningModeNone: // 预期上面已经处理，不应走到这里
        default:
            return NO;
        case AFSSLPinningModeCertificate: {
            NSMutableArray *pinnedCertificates = [NSMutableArray array];
            for (NSData *certificateData in self.pinnedCertificates) {
                [pinnedCertificates addObject:(__bridge_transfer id)SecCertificateCreateWithData(NULL, (__bridge CFDataRef)certificateData)];
            }

            // The SecTrustEvaluate function looks for an anchor certificate in the array of certificates specified by the SecTrustSetAnchorCertificates function
            SecTrustSetAnchorCertificates(serverTrust, (__bridge CFArrayRef)pinnedCertificates);
            // 指定在本地证书列表（pinnedCertificates）中验证服务端返回证书的有效性(从当前证书一直逐级追溯到根证书都验证通过)
            if (!AFServerTrustIsValid(serverTrust)) {
                return NO;
            }

            // obtain the chain after being validated, which *should* contain the pinned certificate in the last position (if it's the Root CA)
            NSArray *serverCertificates = AFCertificateTrustChainForServerTrust(serverTrust);
            // 反向遍历服务器下发的证书链（serverCertificates），一般如果本地预存证书包含服务器返回的证书（或证书链的根证书），则校验通过。
            for (NSData *trustChainCertificate in [serverCertificates reverseObjectEnumerator]) {
                if ([self.pinnedCertificates containsObject:trustChainCertificate]) {
                    return YES;
                }
            }
            
            return NO;
        }
        case AFSSLPinningModePublicKey: {
            NSUInteger trustedPublicKeyCount = 0;
            // 获取服务器下发的证书链（serverCertificates）对应的公钥
            NSArray *publicKeys = AFPublicKeyTrustChainForServerTrust(serverTrust);

            // 遍历对比服务器下发证书公钥和本地预存证书公钥(pinnedPublicKeys)
            for (id trustChainPublicKey in publicKeys) {
                for (id pinnedPublicKey in self.pinnedPublicKeys) {
                    if (AFSecKeyIsEqualToKey((__bridge SecKeyRef)trustChainPublicKey, (__bridge SecKeyRef)pinnedPublicKey)) {
                        trustedPublicKeyCount += 1;
                    }
                }
            }

            // AFPublicKeyTrustChainForServerTrust 并没有严格要求证书链都通过 SecTrustEvaluate，这里匹配上一个即算验证通过。
            return trustedPublicKeyCount > 0;
        }
    }

}
```

## 参考
[HTTP协议授权访问](http://blog.csdn.net/yangtiang/article/details/22793215)  
[https信任证书的三种方案](http://blog.csdn.net/github_34613936/article/details/51490032)  

[AFNetworking 2.3.1](https://github.com/AFNetworking/AFNetworking/tree/2.3.1) 源码解析之 [三. AFSecurityPolicy](http://blog.cnbang.net/tech/2416/)  
[AFNetworking 2.6.2](https://github.com/AFNetworking/AFNetworking/tree/2.6.2) 源码解析之 [AFSecurityPolicy](http://www.jianshu.com/p/eb4fcfa910f3)  
[通读AFN ③--HTTPS访问控制(AFSecurityPolicy)](http://www.jianshu.com/p/11241691389a)  
AFNetworking 源码分析之 [ （五）验证 HTTPS 请求的证书](https://github.com/Draveness/Analyze/blob/master/contents/AFNetworking/%E9%AA%8C%E8%AF%81%20HTTPS%20%E8%AF%B7%E6%B1%82%E7%9A%84%E8%AF%81%E4%B9%A6%EF%BC%88%E4%BA%94%EF%BC%89.md)    
[AFNetworking 3.0 源码解读（二）之 AFSecurityPolicy](http://www.cnblogs.com/machao/p/5704201.html)  

[iOS https自建证书 请求服务器 和 WKWebView](http://www.jianshu.com/p/ff0c317fd1c7)  
