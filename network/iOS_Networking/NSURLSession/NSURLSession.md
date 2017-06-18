
***NSURLSession*** is a replacement API for **NSURLConnection**.  

It provides options that affect the policy of, and various aspects of the mechanism by which **NSURLRequest** objects are retrieved from the network.

An NSURLSession may be bound to a delegate object.  The delegate is invoked for certain events during the lifetime of a session, such as server authentication or determining whether a resource to be loaded should be converted into a download.
 
NSURLSession instances are **threadsafe**.

The default NSURLSession uses a system provided delegate and is appropriate to use in place of existing code that uses `+[NSURLConnection sendAsynchronousRequest:queue:completionHandler:]`

An NSURLSession creates **NSURLSessionTask** objects which represent the action of a resource being loaded.  These are analogous to NSURLConnection objects but provide for more control and a unified delegate model.

**NSURLSessionTask** objects are always created in a suspended state and must be sent the -resume message before they will execute.

*Subclasses* of **NSURLSessionTask** are used to syntactically differentiate between **data** and **file** downloads.

An **NSURLSessionDataTask** receives the resource as a series of calls to the  `URLSession:dataTask:didReceiveData:` delegate method.  This is type of task most commonly associated with retrieving objects for *immediate parsing* by the consumer.

An **NSURLSessionUploadTask** differs from an NSURLSessionDataTask in how its instance is constructed.  Upload tasks are explicitly created by referencing a file or data object to  upload, or by utilizing the
 `-URLSession:task:needNewBodyStream:` delegate message to supply an upload
 body.

An **NSURLSessionDownloadTask** will directly write the response data to a *temporary file*.  When completed, the delegate is sent
 `URLSession:downloadTask:didFinishDownloadingToURL:` and given an opportunity to move this file to a permanent location in its sandboxed container, or to otherwise read the file. If canceled, an NSURLSessionDownloadTask can produce a data blob that can be used to **resume** a download at a later time.

Beginning with iOS 9 and Mac OS X 10.11, **NSURLSessionStream** is available as a task type.  This allows for **direct** TCP/IP connection to a given host and port with optional secure handshaking and navigation of proxies.  Data tasks may also be upgraded to a NSURLSessionStream task via the HTTP Upgrade: header and appropriate use of the pipelining option of NSURLSessionConfiguration.  See RFC 2817 and RFC 6455 for information about the Upgrade: header, and comments below on turning data tasks into stream tasks.
