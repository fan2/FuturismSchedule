[Regular Expression](https://en.wikipedia.org/wiki/Regular_expression)  

A **regular expression**, **regex** or **regexp** (sometimes called a **rational expression**) is, in theoretical computer science and formal language theory, a sequence of characters that define a search [pattern](https://en.wikipedia.org/wiki/Pattern_matching). Usually this pattern is then used by [string searching algorithms](https://en.wikipedia.org/wiki/String_searching_algorithm) for "find" or "find and replace" operations on strings, or for input validation.

The concept arose in the 1950s when the American mathematician Stephen Cole Kleene formalized the description of a regular language. The concept came into common use with Unix text-processing utilities.

Since the 1980s, different syntaxes for writing regular expressions exist, one being the [POSIX](https://en.wikipedia.org/wiki/POSIX) standard and another, widely used, being the [Perl](https://en.wikipedia.org/wiki/Perl) syntax.

[**Regular-Expressions.info**](https://www.regular-expressions.info/) - The Premier website about Regular Expressions

## references

[正则表达式参考手册](http://harttle.land/2016/07/18/intro-to-regexp.html) - [PCRE表达式全集@wiki](https://zh.wikipedia.org/wiki/%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F)  
[正则表达式快速参考](https://ahkcn.github.io/docs/misc/RegEx-QuickRef.htm#%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%EF%BC%88RegEx%EF%BC%89%E2%80%94%E2%80%94%E5%BF%AB%E9%80%9F%E5%8F%82%E8%80%83)  
[正则表达式30分钟入门教程](http://www.deerchao.net/tutorials/regex/regex.htm)  

[第 19 单元：正则表达式](https://www.ibm.com/developerworks/cn/java/j-perry-regular-expressions/index.html)  
MSDN [.NET 正则表达式](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expressions)  [快速参考](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expression-language-quick-reference)  

[RegEx Reference](https://regexr.com/)  

### python

[re](https://docs.python.org/3/library/re.html?highlight=re#module-re) - Support for regular expressions (RE).

### perlre

[perlrequick](https://perldoc.perl.org/perlrequick.html)  
[perlre](https://perldoc.perl.org/perlre.html)  

### RegExp

[ecma262](https://tc39.github.io/ecma262/#sec-regexp-regular-expression-objects)  

w3: [en](https://www.w3schools.com/jsref/jsref_obj_regexp.asp) / [zh](http://www.w3school.com.cn/js/jsref_obj_regexp.asp)  
MDN: [en](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RegExp) / [zh](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/RegExp)  
[liaoxuefeng](https://www.liaoxuefeng.com/wiki/001434446689867b27157e896e74d51a89c25cc8b43bdb3000/001434499503920bb7b42ff6627420da2ceae4babf6c4f2000) / [ruanyifeng](http://javascript.ruanyifeng.com/stdlib/regexp.html)

[Using Regular Expressions with JavaScript](https://www.regular-expressions.info/javascript.html)  
[The Little Guide for Regular Expressions in JS](https://hackernoon.com/guide-for-regular-expressions-in-js-2a33620ca1cf?gi=79aab414369a)  

- `String.match(RegExp)`：返回 RegExpMatchArray；  
- `String.replace(searchValue, replaceValue)`：替换源 searchValue 支持 RegExp 表达式；  
- `RegExp.test(string)`：测试字符串是否匹配模式；  
- `RegExp.exec(string)`：返回 RegExpMatchArray；  

## [standards](https://en.wikipedia.org/wiki/Regular_expression)

### [BRE](https://en.wikipedia.org/wiki/Regular_expression#POSIX_basic_and_extended)

基本的正则表达式（Basic Regular Expressions），又叫 Basic RegEx，简称 `BRE`。

### [ERE](https://en.wikipedia.org/wiki/Regular_expression#POSIX_extended)

扩展的正则表达式（Extended Regular Expressions），又叫 Extended RegEx，简称 `ERE`。

`BRE` and `ERE` work together.

**`BRE`** requires that the metacharacters `( )` and `{ }` be designated `\(\)` and `\{\}`, whereas Extended Regular Syntax (`ERE`) does not.  
***`ERE`*** adds **`?`**, **`+`**, and **`|`**, and it removes the need to escape the metacharacters `( )` and `{ }`, which are required in `BRE`.  

### [Perl and PCRE](https://en.wikipedia.org/wiki/Regular_expression#Perl_and_PCRE)

https://pcre.org/

Perl 的正则表达式（Perl Regular Expressions），又叫 Perl RegEx，简称 `PRE`。  
Perl 兼容格式的正则表达式（Perl Compatible Regular Expressions），简称 `PCRE`。  

[**PCRE**](https://en.wikipedia.org/wiki/Perl_Compatible_Regular_Expressions) is a library written in C, which implements a [regular expression](https://en.wikipedia.org/wiki/Regular_expression) engine, inspired by the capabilities of the [Perl programming language](https://en.wikipedia.org/wiki/Perl). Philip Hazel started writing PCRE in summer 1997. PCRE's syntax is much more powerful and flexible than either of the [POSIX regular expression](https://en.wikipedia.org/wiki/Regular_expression#POSIX) flavors and than that of many other regular-expression libraries.

Because of its expressive power and (relative) ease of reading, many other utilities and programming languages have **adopted** syntax similar to Perl's—for example, `Java`, `JavaScript`, `Python`, `Ruby`, `Qt`, `Microsoft's .NET Framework`, and `XML Schema`.

A number of prominent open-source programs, such as the Apache and Nginx HTTP Servers, and the PHP and R scripting languages, **incorporate** the PCRE library; proprietary software can do likewise, as the library is BSD licensed.

Perl 5.10 implements syntactic extensions originally developed in PCRE and Python.

## man regex

```obj-c
faner@MBP-FAN:~|⇒  man 7 re_format
faner@MBP-FAN:~|⇒  man 3 regex
faner@MBP-FAN:~|⇒  man grep
faner@MBP-FAN:~|⇒  man sed
```

### grep

`grep`, `egrep`, `fgrep` - print lines matching a pattern

the variant programs **`egrep`** and **`fgrep`** are the same as `grep -E` and `grep -F`, respectively.  
These variants are **deprecated**, but are provided for backward compatibility.  

以下为 `man grep` 的选项说明：

```shell
OPTIONS

   Generic Program Information
       --help Output a usage message and exit.

       -V, --version
              Output the version number of grep and exit.

   Matcher Selection
       -E, --extended-regexp
              Interpret PATTERN as an extended regular expression (ERE, see below).

       -F, --fixed-strings
              Interpret PATTERN as a list of fixed strings (instead of regular expressions), separated by newlines, any of which is to be matched.

       -G, --basic-regexp
              Interpret PATTERN as a basic regular expression (BRE, see below).  This is the default.

       -P, --perl-regexp
              Interpret the pattern as a Perl-compatible regular expression(PCRE).  This is experimental and grep -P may warn of unimplemented features.
```

默认选项是 `-G`(`--basic-regexp`)，即 **BRE**。  
如果要支持 **`?`**, **`+`** 和 **`|`**，则需要显式指定 `-E` 选项，即执行 **ERE**。

### [ripgrep](https://github.com/BurntSushi/ripgrep)

ripgrep recursively searches directories for a regex pattern

## regex online

[regexr](https://regexr.com/)  
[regexper](https://regexper.com/)  
[w3cschool](https://www.w3cschool.cn/regexp/6a7w1pr0.html)  
[chinaz](http://tool.chinaz.com/regex) / [oschina](http://tool.oschina.net/regex)  

## [cheatsheet](https://regexr.com/)

[**Regular expressions in Perl**](http://jkorpela.fi/perl/regexp.html)  
[Tables of Perl Regular Expression (PRX) Metacharacters](http://support.sas.com/documentation/cdl/en/lrdict/64316/HTML/default/viewer.htm#a003288497.htm)  

<table class="cheatsheet"> <tbody><tr><th colspan="2" data-id="charclasses">Character classes</th></tr> <tr><td><a>.</a></td><td>any character except newline</td></tr> <tr><td><a>\w</a>&ensp;<a>\d</a>&ensp;<a>\s</a></td><td>word, digit, whitespace</td></tr> <tr><td><a>\W</a>&ensp;<a>\D</a>&ensp;<a>\S</a></td><td>not word, digit, whitespace</td></tr> <tr><td><a>[abc]</a></td><td>any of a, b, or c</td></tr> <tr><td><a>[^abc]</a></td><td>not a, b, or c</td></tr> <tr><td><a>[a-g]</a></td><td>character between a &amp; g</td></tr> <tr><th colspan="2" data-id="anchors">Anchors</th></tr> <tr><td><a>^abc$</a></td><td>start / end of the string</td></tr> <tr><td><a>\b</a>&ensp;<a>\B</a></td><td>word, not-word boundary</td></tr> <tr><th colspan="2" data-id="escchars">Escaped characters</th></tr> <tr><td><a>\.</a>&ensp;<a>\*</a>&ensp;<a>\\</a></td><td>escaped special characters</td></tr> <tr><td><a>\t</a>&ensp;<a>\n</a>&ensp;<a>\r</a></td><td>tab, linefeed, carriage return</td></tr> <tr><th colspan="2" data-id="groups">Groups &amp; Lookaround</th></tr> <tr><td><a>(abc)</a></td><td>capture group</td></tr> <tr><td><a>\1</a></td><td>backreference to group #1</td></tr> <tr><td><a>(?:abc)</a></td><td>non-capturing group</td></tr> <tr><td><a>(?=abc)</a></td><td>positive lookahead</td></tr> <tr><td><a>(?!abc)</a></td><td>negative lookahead</td></tr> <tr><th colspan="2" data-id="quants">Quantifiers &amp; Alternation</th></tr> <tr><td><a>a*</a>&ensp;<a>a+</a>&ensp;<a>a?</a></td><td>0 or more, 1 or more, 0 or 1</td></tr> <tr><td><a>a{5}</a>&ensp;<a>a{2,}</a></td><td>exactly five, two or more</td></tr> <tr><td><a>a{1,3}</a></td><td>between one &amp; three</td></tr> <tr><td><a>a+?</a>&ensp;<a>a{2,}?</a></td><td>match as few as possible</td></tr> <tr><td><a>ab|cd</a></td><td>match ab or cd</td></tr> </tbody></table>

### 常用限定符

| 代码/语法 | 说明            |
| --------- | --------------- |
| ?         | 重复0次或1次    |
| +         | 重复1次或多次   |
| *         | 重复0次或多次   |
| {n}       | 重复n次         |
| {n,}      | 重复n次或更多次 |
| {n,m}     | 重复n到m次      |

### 常用元字符

| 代码 | 说明                                         |
| ---- | -------------------------------------------- |
| .    | 匹配除 `换行符` 以外的任意字符               |
| \w   | 匹配 `字母` 或 `数字` 或 `下划线`（word）    |
| \s   | 匹配任意的 `空白符`（space）                 |
| \d   | 匹配 `数字`（digit）                         |
| \b   | 匹配单词的 `开始` 或 `结束`（word boundary） |
| ^    | 匹配字符串的 `开始`                          |
| $    | 匹配字符串的 `结束`                          |

### 常用反义词

| 代码/语法 | 说明                                             |
| --------- | ------------------------------------------------ |
| \W        | 匹配任意 **不是** 字母，数字，下划线，汉字的字符 |
| \S        | 匹配任意 **不是** 空白符的字符                   |
| \D        | 匹配任意 **非** 数字的字符                       |
| \B        | 匹配 **不是** 单词开头或结束的位置               |
| [^x]      | 匹配除了 x 以外的任意字符                        |
| [^aeiou]  | 匹配除了 aeiou 这几个字母以外的任意字符          |

## vscode extensions

vscode 1.29.0 基于 [ripgrep](https://github.com/BurntSushi/ripgrep) 实现支持 multiline search。

vscode 默认是 `search.useRipgrep`（Deprecated），建议采用 **`search.usePCRE2`**，支持 [lookaround](https://www.regular-expressions.info/lookaround.html) 和 [backreferences](https://www.regular-expressions.info/backref.html) 等特性。

### [Regex Railroad Diagrams](https://marketplace.visualstudio.com/items?itemName=kogai.regex-railroad-diagrams)

> Display railroad diagram of regex under cursor.
>> A regular expression railroad diagram view for regular expression under cursor. This is inspired by [regex railroad diagrams](https://github.com/klorenz/atom-regex-railroad-diagrams).

光标定位到正则表达式（RegExp）所在行，再在控制面板中执行 `Show RegExp preview` 命令，将在右侧新开辅助编辑器显示 `RegExp Diagram Preview`。

![RegExp-Diagram-Preview](./images/RegExp-Diagram-Preview.png)

### [RegExp Preview and Editor](https://marketplace.visualstudio.com/items?itemName=le0zh.vscode-regexp-preivew)

> VSCode extension based on [regexper-static](https://github.com/javallone/regexper-static). Including regexp expression preivewer and realtime preivew editor.

在控制面板中执行 `RegExp Editor`，将打开左侧编辑，和右侧的 `RegExp Preview` 预览。

![RegExp-Preview](./images/RegExp-Preview.png)

### [Regex Previewer](https://marketplace.visualstudio.com/items?itemName=chrmarti.regex)

> Regex matches previewer for JavaScript, TypeScript, PHP and Haxe in Visual Studio Code.

对于已保存文件中的正则表达式，其上会有 `Test Regex...`，点击 `Test Regex...` 或在控制面板中执行 `Toggle Regex Preview In Side-By-Side Editors` 命令将在右侧开启测试编辑器，在其中输入测试字符串，将自动高亮匹配的部分。

![Regex-Previewer](./images/Regex-Previewer.png)

### [Filter Line](https://marketplace.visualstudio.com/items?itemName=everettjf.filter-line)

* By Input String  
* By Input **Regex**  
* By Not Contain Input String  
* By Not Match Input **Regex**  
* By Config File  

#### config

必须在当前文件所在根目录（即 vscode 打开的文件夹）下创建过滤配置文件。

1. 如果打开的是独立文件，不是以文件夹打开，则提示 `Can not locate workspace folder for current file`；  
2. 如果是以文件夹（`~/folder`）打开文件（`~/folder/subfolder/test.log`），执行 `Filter Line By Config File`，则提示 `Can not locate config file ~/folder/.vscode/filterline.json`。  

***Config file format type***

There are 3 format types. As they are so simple, I will not describe them here. Please visit the demo directly :

1. `stringlist`: String list [json](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log0json/.vscode/filterline.json) or [eoml](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log0eoml/.vscode/filterline.eoml)  
2. **`regexlist`**: Regular expressions list [json](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log1json/.vscode/filterline.json) or [eoml](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log1eoml/.vscode/filterline.eoml)  
3. `general`: This is default if type is not specified. [json](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log2json/.vscode/filterline.json) or [eoml](https://github.com/everettjf/vscode-filter-line/blob/master/demo/log2eoml/.vscode/filterline.eoml)  
