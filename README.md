# <font color='red'>firstGitRepo</font>
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

本站相对链接测试  
![坳口](../../../github-pages/blob/master/source/_posts/images/col.dog/coltree.jpg)

##测试代码块（Code Block）
###标准Preformatted Code Block

- Preformatted Code Block  
将一段代码块整体向右缩进（<kbd>⌘</kbd> + <kbd>]</kbd>）即可测试。  

（1）以tab开头：

	these lines begin with tab will be show as pre code block.
	these lines begin with tab will be show as pre code block.
	these lines begin with tab will be show as pre code block.
	
（2）以四个空格开头：

    these lines begin with 4 spaces will be show as pre code block.
    these lines begin with 4 spaces will be show as pre code block.
    these lines begin with 4 spaces will be show as pre code block.

存在以下缺陷：

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

## 脚标
标准 Markdown 不支持脚标，只能通过内嵌 HTML 的`<sup>`和`<sub>`标签实现。

### 上脚标：
Haroopad 语法：`^Superscript^`  
HTML 语法：`<sup>superscript</sup>`

**示例：**
2^10^ = 2<sup>10</sup> = 1024;

### 下脚标：
Haroopad 语法：`~Subscript~`  
HTML 语法：`<sub>subscript</sub>`

**示例：**
H~2~O = H<sub>2</sub>O is a liquid.

##块引用（blockquote）
HTML 中的 `<blockquote>` 标签定义摘自另一个源的块引用。  
`<blockquote>` 与 `</blockquote>` 之间的所有文本都会从常规文本中分离出来，经常会在左右两边进行**缩进**，而且有时会使用**斜体**。
也就是说，块引用拥有它们自己的<u>空间</u>。
Markdown 标记区块引用是使用类似 email 的引用方式，在断好的行前加上 `>` ：
> 爱上一个人  
> 恋上一座城

##列表（List）
###无序列表（Unordered）
示例效果：
-   Red
-   Green
-   Blue

nested list
- - -
- 链接（Hyperlink）
	- 自动链接（autolink）
	- 文字（text href）
		- 行内式（Inline）
		- 参考式（Reference）
	- 图片（image href）
		- 插入图片
		- 图片链接
	- 锚点（inner link）
		- 书签（Bookmark）
		- 脚注（Footnote）
- 引用（Blockquote）

### 有序列表（Ordered）

[Step-by-step walkthrough for starting a blog](http://startbloggingonline.com/):

1. GETTING STARTED  
	Choosing Blogging Platform (WordPress)
2. GETTING YOUR BLOG ONLINE  
	Choosing Domain Name & Web Hosting
3. DESIGNING AND TWEAKING YOUR BLOG  
	Quick and easy ways to get your blog look the way you want
4. WRITING BLOG POSTS AND PAGES  
	Adding new content for your Blog (Posts, Pages, Images etc…)

### task list
- [ ] task1 to do
- [x] task2 done
1. [ ] task3 to do
2. [x] task4 done
