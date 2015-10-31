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
