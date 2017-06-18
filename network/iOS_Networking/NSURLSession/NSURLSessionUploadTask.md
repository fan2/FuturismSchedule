[NSURLSessionUploadTask 上传](http://www.jianshu.com/p/1ab17631b0b3)

## NSURLSessionUploadTask 概述
### NSMutableURLRequest
上传数据的时候，一般要使用 REST API 里的 PUT 或者 POST 方法。所以，要通过这个类来设置一些 HTTP 配置信息。常见的包括：

```
timeoutInterval // timeout的时间间隔
HTTPMethod // HTTP方法

//设置HTTP表头信息
–addValue:forHTTPHeaderField:  
–setValue:forHTTPHeaderField:  
```

HTTP header 的具体信息参见 Wiki，常用的 header 一定要熟悉：

<http://en.wikipedia.org/wiki/List_of_HTTP_header_fields>

### 三种上传数据的方式
#### NSData
如果对象已经在内存里

使用以下两个函数初始化：

```obj-c
uploadTaskWithRequest:fromData:
uploadTaskWithRequest:fromData:completionHandler:
```

Session 会自动计算 Content-length 的 Header

通常，还需要提供一些服务器需要的 Header，Content-Type 就往往需要提供。

#### File
如果对象在磁盘上，这样做有助于降低内存使

使用以下两个函数进行初始化：

```obj-c
uploadTaskWithRequest:fromFile:
uploadTaskWithRequest:fromFile:completionHandler:
```

同样，会自动计算 Content-Length，如果 App 没有提供 Content-Type，Session 会自动创建一个。如果 Server 需要额外的 Header 信息，也要提供。

#### Stream
使用这个函数创建：

```obj-c
uploadTaskWithStreamedRequest:
```

注意，这种情况下一定要提供 Server 需要的 Header 信息，例如 Content-Type 和 Content-Length。

使用 Stream 一定要实现这个代理方法，因为 Session 没办法在重新尝试发送 Stream 的时候找到数据源（例如需要授权信息的情况）。
这个代理函数，提供了Stream的数据源。

```obj-c
URLSession:task:needNewBodyStream:
```

### 代理方法
使用这个代理方法获得 upload 的进度。其他的代理方法

- NSURLSessionDataDelegate  
- NSURLSessionDelegate  
- NSURLSessionTaskDelegate  

同样适用于 UploadTask。

```obj-c
// NSURLSessionTaskDelegate
-(void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
```

## 上传数据
核心代码如下：

```obj-c
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://jsonplaceholder.typicode.com/posts"]];
    [request addValue:@"application/json" forHTTPHeaderField:@"Content-Type"]; //这一行一定不能少，因为后面是转换成JSON发送的
    [request addValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [request setHTTPMethod:@"POST"];
    [request setCachePolicy:NSURLRequestReloadIgnoringCacheData];
    [request setTimeoutInterval:20];
    NSDictionary* dataToUploaddic = @{self.keytextfield.text:self.valuetextfield.text};
    NSData* data = [NSJSONSerialization dataWithJSONObject:dataToUploaddic
                                                   options:NSJSONWritingPrettyPrinted
                                                     error:nil];
    NSURLSessionUploadTask* uploadtask = [self.session uploadTaskWithRequest:request
                                                                    fromData:data
                                                           completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
                                                               if (!error) {
                                                                   NSDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:data
                                                                                                                              options:kNilOptions
                                                                                                                                error:nil];
                                                                   self.responselabel.text = dictionary.description;
                                                               } else {
                                                                   UIAlertController* alert = [UIAlertController alertControllerWithTitle:@Error
                                                                                                                                  message:error.localizedFailureReason
                                                                                                                           preferredStyle:UIAlertControllerStyleAlert];
                                                                   [alert addAction:[UIAlertAction actionWithTitle:@OK style:UIAlertActionStyleCancel handler:nil]];
                                                                   [self presentViewController:alert animated:YES completion:nil];
                                                               }
                                                           }];
    [uploadtask resume];

```

## 上传图片
核心部分代码：

```obj-c
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://www.freeimagehosting.net/upload.php"]];
    [request addValue:@"image/jpeg" forHTTPHeaderField:@"Content-Type"];
    [request addValue:@"text/html" forHTTPHeaderField:@"Accept"];
    [request setHTTPMethod:@"POST"];
    [request setCachePolicy:NSURLRequestReloadIgnoringCacheData];
    [request setTimeoutInterval:20];
    NSData* imagedata = UIImageJPEGRepresentation(self.imageview.image,1.0);
    NSURLSessionUploadTask* uploadtask = [self.session uploadTaskWithRequest:request
                                                                    fromData:imagedata
                                                           completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
                                                               NSString* htmlString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
                                                               UploadImageReturnViewController* resultvc = [self.storyboard instantiateViewControllerWithIdentifier:@resultvc];
                                                               resultvc.htmlString = htmlString;
                                                               [self.navigationController pushViewController:resultvc animated:YES];
                                                               self.progressview.hidden = YES;
                                                               [self.spinner stopAnimating];
                                                               [self.spinner removeFromSuperview];
                                                           }];
    [uploadtask resume];
```

代理函数

```obj-c
-(void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend{
    self.progressview.progress = totalBytesSent/(float)totalBytesExpectedToSend;
}
```