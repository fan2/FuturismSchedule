# firstGitRepo
This is the first git repository.

测试markdown中混用`<kbd>`标签
---
退出vim:
<kbd>\<Esc\></kbd> 或 <kbd>^</kbd>+<kbd>[</kbd>

测试markdown表格中混用`<br>`标签
---
按键           | 说明        | 备注
--------------|-------------|--------
`u`           | 撤销（undo） | 直到`Already at oldest change`
`U`           | 撤销（undo） | 撤销针对光标所在行的操作：<br>undo all the changes on a line

测试超链接
---
###行内式写法：`[title](href)`
[classeur](http://classeur.io/)

###参考式写法：`[title][href_id] + [href_id]:href_url`
[classeur][classeur-url-id]

参考式简写：  
href_id和title相同，`[title][]`。也可省掉href_id，进一步简写为`[title]`：  
[classeur]

[classeur-url-id]:http://classeur.io/
[classeur]:http://classeur.io/

##测试代码块（Code Block）
###标准Preformatted Code Block

- Preformatted Code Block  
将一段代码块整体向右缩进（<kbd>⌘</kbd> + <kbd>]</kbd>）即可测试。存在以下缺陷：

 - 对多tab及空格的缩进支持不完善！
 - 将宏符号#（#include、#import）误解为H1，可能会影响解析器的TOC！
 - 将顶格空白行（包括行首带tab）误认为Paragraph Break，而割断代码块成片段！

###GFM的Fenced Code Block格式
以下演示了插入一段 Objective-C 代码：

  > 首行：\`\`\`obj-c  
  > 中间：Objective-C Code Block  
  > 末行：\`\`\`

```obj-c
//
//  main.m
//  EmptyApplication
	
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
	
int main(int argc, char * argv[]) {
	@autoreleasepool {
		return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
	}
}
```
