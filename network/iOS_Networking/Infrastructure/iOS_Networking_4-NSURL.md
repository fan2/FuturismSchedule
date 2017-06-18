# NSURL
![NSURL-Hierarchy](http://cdn3.infoqstatic.com/statics_s2_20170530-0600u1/resource/articles/afn_vs_asi/zh/resources/image018.gif)

## [NSURLConnection](https://developer.apple.com/documentation/foundation/nsurlconnection)

## NSURLSession
Networking, Internet, & Web | Protocol Streams | Guides | [URL Session Programming Guide](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/URLLoadingSystem.html#//apple_ref/doc/uid/10000165i)

The URL loading system is a set of classes and protocols that allow your app to access content referenced by a URL.  
At the heart of this technology is the ***NSURL*** class, which lets your app manipulate URLs and the resources they refer to.  

The URL loading system provides support for accessing resources using the following protocols:

- File Transfer Protocol (`ftp://`)  
- Hypertext Transfer Protocol (`http://`)  
- Hypertext Transfer Protocol with encryption (`https://`)  
- Local file URLs (`file:///`)  
- Data URLs (`data://`)  

[URL Loading System](https://developer.apple.com/documentation/foundation/url_loading_system)  

![URL loading system helper classes](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/Art/nsobject_hierarchy_2x.png)

## Sample Code
### [SimpleURLConnections](https://developer.apple.com/library/content/samplecode/SimpleURLConnections/Introduction/Intro.html)
> Networking, Internet, & Web | Protocol Streams | Sample Code

SimpleURLConnections shows how to do simple networking using the **`NSURLConnection`** API. The goal of this sample is very limited: it does not demonstrate everything you need to implement a fully fledged networking product, rather, its goal is to demonstrate simple HTTP GET, PUT and POST using the NSURLConnection API.

> -[GetController connection:didReceiveData:]  
>> -[NSOutputStream write:maxLength:]  

### [AdvancedURLConnections](https://developer.apple.com/library/content/samplecode/AdvancedURLConnections/Introduction/Intro.html)
> Networking, Internet, & Web | Protocol Streams | Sample Code

This sample demonstrates various advanced networking techniques with **`NSURLConnection`**. Specifically, it demonstrates how to respond to *authentication challenges*, how to modify the default *server trust evaluation* (for example, to support a server with a self-signed certificate), and how to provide client identities.

> -[GetController connection:didReceiveData:]  
>> -[NSOutputStream write:maxLength:]  

### [SimpleFTPSample](https://developer.apple.com/library/content/samplecode/SimpleFTPSample/Introduction/Intro.html)
> Networking, Internet, & Web | Protocol Streams | Sample Code

SimpleFTPSample shows how to do simple FTP operations using the **`NSURLConnection`** and **`CFFTPStream`** APIs. It can **download** a file using both NSURLConnection and CFFTPStream. Also, it can **upload** a file, list a directory, and create a directory using CFFTPStream.

### [CustomHTTPProtocol](https://developer.apple.com/library/content/samplecode/CustomHTTPProtocol/Introduction/Intro.html)
CustomHTTPProtocol shows how to use an **`NSURLProtocol`** subclass to intercept the **`NSURLConnections`** made by a high-level subsystem that does not otherwise expose its network connections. In this specific case, it intercepts the *HTTPS* requests made by a web view and overrides *server trust evaluation*, allowing you to browse a site whose certificate is not trusted by default.

based on **`NSURLConnection`** & **`NSURLSession`**.

### [LinkedImageFetcher](https://developer.apple.com/library/content/samplecode/LinkedImageFetcher/Introduction/Intro.html)
> Networking, Internet, & Web | Sample Code

Shows how to use **`NSOperation`** for both CPU operations and run loop-based *network operations*. The code downloads an HTML *page*, parses the page using libxml2's HTML parser, and then downloads all of the *images* referenced by that page.

- NSURLRequest/NSHTTPURLResponse  
- NSURLConnection/NSOutputStream  

```obj-c
@interface QWatchedOperationQueue : NSOperationQueue


@interface QRunLoopOperation : NSOperation
@interface QHTTPOperation : QRunLoopOperation

@interface PageGetOperation : QHTTPOperation
@interface ImageDownloadOperation : QHTTPOperation
```