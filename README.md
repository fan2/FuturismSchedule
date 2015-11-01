# firstGitRepo
This is the first git repository.

##文本格式
###强调
```Markdown
Some of these words *are emphasized*.
Some of these words _are emphasized also_.
```

###加粗
```Markdown
Use two asterisks for **strong emphasis**.
Or, if you prefer, __use two underscores instead__.
```

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

###autolink
http://daringfireball.net/projects/markdown/  
<http://pad.haroopress.com/>

###imglink
[![](http://pad.haroopress.com/assets/images/logo-small.png "haroopad")](http://pad.haroopress.com/)

<img src="http://my.csdn.net/uploads/avatar/9/D/B/1_phunxm.jpg" align="middle"  alt="程序猿-弦苦" />

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

##测试空格
普通段落一般都是顶格开始，不建议在普通段落使用空格或制表符来缩进，包括引用（>）、列表（bullet list indicator）后面的空格都无法实现行首缩进。  
如果硬要输入空格占位缩进，可以嵌入空格对应的 HTML Entity 实体码。例如：

***
  普通自然行行首敲2个空格无占位缩进效果。  
&nbsp;&nbsp;&#160;&#160;该行行首添加了4个不断行的空白格：no-break space(`&nbsp;`或`&#160;`）  
&ensp;&ensp;&ensp;&ensp;该行行首添加了4个半方大的空白：en space（`&ensp;`或`&#8194;`）  
&emsp;&emsp;&#8195;&#8195;该行行首添加了4个全方大的空白：em space（`&emsp;`或`&#8195;`） 
___

## MathJax（不支持）

You can render *LaTeX* mathematical expressions using **MathJax**, as on [math.stackexchange.com][1]:
The *Gamma function* satisfying $\Gamma(n) = (n-1)!\quad\forall n\in\mathbb N$ is via the Euler integral

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$


