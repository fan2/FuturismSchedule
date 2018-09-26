[Regular Expression](https://en.wikipedia.org/wiki/Regular_expression)  

[regexr](https://regexr.com/)

[正则表达式参考手册](http://harttle.land/2016/07/18/intro-to-regexp.html) - [PCRE表达式全集@wiki](https://zh.wikipedia.org/wiki/%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F)  
[正则表达式快速参考](https://ahkcn.github.io/docs/misc/RegEx-QuickRef.htm#%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%EF%BC%88RegEx%EF%BC%89%E2%80%94%E2%80%94%E5%BF%AB%E9%80%9F%E5%8F%82%E8%80%83)  
[正则表达式30分钟入门教程](http://www.deerchao.net/tutorials/regex/regex.htm)  

[第 19 单元：正则表达式](https://www.ibm.com/developerworks/cn/java/j-perry-regular-expressions/index.html)  
MSDN [.NET 正则表达式](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expressions)  [快速参考](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expression-language-quick-reference)  

## regex command

```obj-c
faner@MBP-FAN:~|⇒  man 7 re_format
faner@MBP-FAN:~|⇒  man 3 regex
faner@MBP-FAN:~|⇒  man grep
faner@MBP-FAN:~|⇒  man sed
```

## [cheatsheet](https://regexr.com/)

<table class="cheatsheet"> <tbody><tr><th colspan="2" data-id="charclasses">Character classes</th></tr> <tr><td><a>.</a></td><td>any character except newline</td></tr> <tr><td><a>\w</a>&ensp;<a>\d</a>&ensp;<a>\s</a></td><td>word, digit, whitespace</td></tr> <tr><td><a>\W</a>&ensp;<a>\D</a>&ensp;<a>\S</a></td><td>not word, digit, whitespace</td></tr> <tr><td><a>[abc]</a></td><td>any of a, b, or c</td></tr> <tr><td><a>[^abc]</a></td><td>not a, b, or c</td></tr> <tr><td><a>[a-g]</a></td><td>character between a &amp; g</td></tr> <tr><th colspan="2" data-id="anchors">Anchors</th></tr> <tr><td><a>^abc$</a></td><td>start / end of the string</td></tr> <tr><td><a>\b</a>&ensp;<a>\B</a></td><td>word, not-word boundary</td></tr> <tr><th colspan="2" data-id="escchars">Escaped characters</th></tr> <tr><td><a>\.</a>&ensp;<a>\*</a>&ensp;<a>\\</a></td><td>escaped special characters</td></tr> <tr><td><a>\t</a>&ensp;<a>\n</a>&ensp;<a>\r</a></td><td>tab, linefeed, carriage return</td></tr> <tr><th colspan="2" data-id="groups">Groups &amp; Lookaround</th></tr> <tr><td><a>(abc)</a></td><td>capture group</td></tr> <tr><td><a>\1</a></td><td>backreference to group #1</td></tr> <tr><td><a>(?:abc)</a></td><td>non-capturing group</td></tr> <tr><td><a>(?=abc)</a></td><td>positive lookahead</td></tr> <tr><td><a>(?!abc)</a></td><td>negative lookahead</td></tr> <tr><th colspan="2" data-id="quants">Quantifiers &amp; Alternation</th></tr> <tr><td><a>a*</a>&ensp;<a>a+</a>&ensp;<a>a?</a></td><td>0 or more, 1 or more, 0 or 1</td></tr> <tr><td><a>a{5}</a>&ensp;<a>a{2,}</a></td><td>exactly five, two or more</td></tr> <tr><td><a>a{1,3}</a></td><td>between one &amp; three</td></tr> <tr><td><a>a+?</a>&ensp;<a>a{2,}?</a></td><td>match as few as possible</td></tr> <tr><td><a>ab|cd</a></td><td>match ab or cd</td></tr> </tbody></table>

RegEx Reference

## regex online

w3cschool [正则表达式测试工具](https://www.w3cschool.cn/regexp/6a7w1pr0.html)  
oschina [在线正则表达式测试](http://tool.oschina.net/regex)  
chinaz [正则表达式在线测试](http://tool.chinaz.com/regex)  
ip138 [在线正则测试](http://www.ip138.com/zhengze/)  

## [正则表达式](https://en.wikipedia.org/wiki/Regular_expression) 的分类

1. 基本的正则表达式（Basic Regular Expressions 又叫 Basic RegEx 简称 [BRE](https://en.wikipedia.org/wiki/Regular_expression#POSIX_basic_and_extended)） 
2. 扩展的正则表达式（Extended Regular Expressions 又叫 Extended RegEx 简称 [ERE](https://en.wikipedia.org/wiki/Regular_expression#POSIX_extended)） 
3. Perl 的正则表达式（Perl Regular Expressions 又叫 Perl RegEx 简称 [PRE](https://en.wikipedia.org/wiki/Regular_expression#Perl_and_PCRE)） 

## 插件

vscode extensions:  

- [Regex Previewer](https://marketplace.visualstudio.com/items?itemName=chrmarti.regex)  
- [RegExp Preview and Editor](https://marketplace.visualstudio.com/items?itemName=le0zh.vscode-regexp-preivew)  
