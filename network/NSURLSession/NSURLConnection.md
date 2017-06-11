
## [同步请求](http://www.jianshu.com/p/2c9bf0a7d658)

```obj-c
- (NSArray*) doSyncRequest:(NSString*)urlString
{
    // make the NSURL object from the string
    NSURL url = [NSURL URLWithString:urlString];
    
    // Create the request object with a 30 second timeout and a cache policy to
    // always retrieve the feed regardless of cachability.
    NSURLRequest* request = [NSURLRequest requestWithURL:url
                                             cachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData
                                         timeoutInterval:30.0];
    
    // Send the request and wait for a response
    NSHTTPURLResponse* response;
    NSError* error;
    NSData* data = [NSURLConnection sendSynchronousRequest:request
                                         returningResponse:&response
                                                     error:&error];
    
    // check for error
    if (error != nil) {
        NSLog(@"Error on load = %@", [error localizedDescription]);
        return nil;
    }
    
    // check the HTTP status
    if ([response isKindOfClass:[NSHTTPURLResponse class]]) {
        NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
        if (httpResponse.statusCode != 200) {
            return nil;
        }
        // allHeaderFields
        NSLog(@"Headers: %@", [httpResponse allHeaderFields]);
    }
    
    // Parse the data returned into an NSDictionary
    NSDictionary* dictionary = [XMLReader dictionaryForXMLData:data error:&error];
    
    // Dump the dictionary to the log file
    NSLog(@"feed = %@", dictionary);
    
    NSArray* entries = [self getEntriesArray:dictionary];
    
    // return the list if items from the feed.
    return entries;
}
```

## [队列式异步请求](http://www.jianshu.com/p/de9b0507c2b5)

```obj-c
- (void) doQueuedRequest:(NSString*)urlString delegate:(id)delegate
{
    // make the NSURL object
    NSURL url = [NSURL URLWithString:urlString];
    
    // Create the request object with a no cache policy and a 30 second timeout.
    NSURLRequest* request = [NSURLRequest requestWithURL:url
                                             cachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData
                                         timeoutInterval:30.0];
    
    // If the queue doesn`t exist, create one
    if (queue == nil) {
        queue = [[NSOperationQueue alloc] init];
    }
    
    // send the request and specify the code to execute when the request completes or fails.
    [NSURLConnection sendAsynchronousRequest:request
                                       queue:queue
                           completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
                               if (connectionError != nil) {
                                   NSLog(@"Error on load = %@", [connectionError localizedDescription]);
                               } else {
                                   // check the HTTP status
                                   if ([response isKindOfClass:[NSHTTPURLResponse class]]) {
                                       NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
                                       if (httpResponse.statusCode != 200) {
                                           return nil;
                                       }
                                       // allHeaderFields
                                       NSLog(@"Headers: %@", [httpResponse allHeaderFields]);
                                   }
                                   
                                   // Parse the data returned into an NSDictionary
                                   NSDictionary* dictionary = [XMLReader dictionaryForXMLData:data error:&error];
                                   
                                   // Dump the dictionary to the log file
                                   NSLog(@"feed = %@", dictionary);
                                   
                                   NSArray* entries = [self getEntriesArray:dictionary];
                                   
                                   // call the delegate
                                   if (delegate respondsToSelector:@selector(setVideos:)) {
                                       [delegate performSelectorOnMainThread:@selector(setVideios:)
                                                                  withObject:entries
                                                                waitUtilDone:YES];
                                   }
                               }
    }];
}
```

## [异步请求](http://www.jianshu.com/p/a8d6d78a6191)

![与HTTP 请求过程相关的委托调用序列](http://upload-images.jianshu.io/upload_images/1413286-ff35ca75e27e33f5.png?imageMogr2/auto-orient/strip)