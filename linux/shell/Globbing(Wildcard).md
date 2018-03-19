参考 `man 1 bash` 中的 EXPANSION | Pathname Expansion | Pattern Matching（glob & extglob）。  
  
参考 [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html)（[PDF](https://www.gnu.org/software/bash/manual/bash.pdf)）的 3.5 Shell Expansions | Filename Expansion | Pattern Matching。  

[Shell GLOB patterns](http://teaching.idallen.com/cst8207/17f/notes/190_glob_patterns.html)  
[Bash Extended Globbing](http://www.linuxjournal.com/content/bash-extended-globbing)  

## [glob](https://en.wikipedia.org/wiki/Glob_(programming))
In computer programming, in particular in a Unix-like environment, **glob patterns** specify sets of filenames with [wildcard characters](https://en.wikipedia.org/wiki/Wildcard_characters).

For example, the Unix command `mv *.txt textfiles/` moves (`mv`) all files with names ending in `.txt` from the current directory to the directory `textfiles`. Here, `mv *.txt textfiles/`, `*` is a wildcard standing for "any string of characters" and `*.txt` is a glob pattern.  
The other common wildcard is the question mark (`?`), which stands for *one* character.

The most common wildcards are `*`, `?`, and `[…]`.

> Bash 中常用通配符只有3个: `*`, `?`, `[...]`。  
>> `**`：出现在路径中，匹配任意级别目录。  

## [man 7 GLOB](http://man7.org/linux/man-pages/man7/glob.7.html)

NOTES | Regular expressions of man 7 glob 

Note that wildcard patterns are not regular expressions, although they are a bit similar.  
First of all, they match ***filenames***, rather than ***text***, and secondly, the conventions are not the same: for example, in a regular expression '*' means  zero  or  more copies of the **preceding** thing.

Now  that regular expressions have bracket expressions where the negation is indicated by a '^', POSIX has declared the effect of a wildcard pattern  "[^...]"  to  be undefined.

## [Advanced Bash-Scripting Guide](http://tldp.org/LDP/abs/html/)
[Globbing](http://tldp.org/LDP/abs/html/globbingref.html) & [Wildcards](http://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm)

Bash itself cannot recognize Regular Expressions.  
Inside scripts, it is commands and utilities -- such as sed and awk -- that interpret RE's.

Bash does carry out **filename expansion** -- a process known as *globbing* -- but this does *not* use the standard RE set.  
Instead, globbing recognizes and expands *wild cards*.

Bash performs filename expansion on unquoted command-line arguments.

## Globbing & RE
通配符是用来匹配**文件名**的，正则表达式则是用来匹配**文件内容**（文本字符串）的。

通配符多用在文件名上，比如 `ls`，`find`，`cp` 等等；  
在 `grep`(-G,-e,-E),`awk`,`sed` 等针对文件内容的文本过滤工具里，都是用正则表达式。  

BASH 所做的是扩展文件名，基于通配符（globbing/wildcard patterns），并非正则表达式。  

BASH 本身没有正则表达式的功能，在脚本里使用正则表达式的是命令（grep,sed）和工具包（awk），它们可以解析正则表达式。  

## references

[Linux命令ls通配符的使用](http://www.kivixv.com/2016/05/10/linux/Linux%E5%91%BD%E4%BB%A4ls%E9%80%9A%E9%85%8D%E7%AC%A6%E7%9A%84%E4%BD%BF%E7%94%A8/)  
[shell中的正则表达式和通配符](https://www.jianshu.com/p/49d5ee46de47) [@github](https://fengyalv.github.io/Blogs/shell/shell%E8%84%9A%E6%9C%AC%E4%B8%AD%E7%9A%84%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F.html)  
[**Linux基础概要**](https://www.gitbook.com/book/abcfy2/linux_basic) 之 [通配符](https://abcfy2.gitbooks.io/linux_basic/content/first_sense_for_linux/command_learning/wildcard.html) & [正则表达式](https://abcfy2.gitbooks.io/linux_basic/content/regular_expression/index.html)  
