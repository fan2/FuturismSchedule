参考 `man 1 bash` 中的 EXPANSION | Pathname Expansion | Pattern Matching（glob & extglob）。  
  
参考 [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html)（[PDF](https://www.gnu.org/software/bash/manual/bash.pdf)）的 3.5 Shell Expansions | Filename Expansion | Pattern Matching。  

[Shell GLOB patterns](http://teaching.idallen.com/cst8207/17f/notes/190_glob_patterns.html)  
[Bash Extended Globbing](http://www.linuxjournal.com/content/bash-extended-globbing)  

## [man 7 GLOB](http://man7.org/linux/man-pages/man7/glob.7.html)

NOTES | Regular expressions of man 7 glob 

Note that wildcard patterns are not regular expressions, although they are a bit similar.  
First of all, they match ***filenames***, rather than ***text***, and secondly, the conventions are not the same: for example, in a regular expression '*' means  zero  or  more copies of the **preceding** thing.

Now  that regular expressions have bracket expressions where the negation is indicated by a '^', POSIX has declared the effect of a wildcard pattern  "[\^...]"  to  be undefined.

## [Advanced Bash-Scripting Guide](http://tldp.org/LDP/abs/html/)

[Globbing](http://tldp.org/LDP/abs/html/globbingref.html) & [Wildcards](http://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm)

Bash itself cannot recognize Regular Expressions.  
Inside scripts, it is commands and utilities -- such as sed and awk -- that interpret RE's.

Bash does carry out **filename expansion** -- a process known as *globbing* -- but this does *not* use the standard RE set.  
Instead, globbing recognizes and expands *wild cards*.

Bash performs filename expansion on unquoted command-line arguments.

## [glob](https://en.wikipedia.org/wiki/Glob_(programming))

In computer programming, in particular in a Unix-like environment, **glob patterns** specify sets of filenames with [wildcard characters](https://en.wikipedia.org/wiki/Wildcard_characters).

For example, the Unix command `mv *.txt textfiles/` moves (`mv`) all files with names ending in `.txt` from the current directory to the directory `textfiles`. Here, `mv *.txt textfiles/`, **`*`** is a wildcard standing for "any string of characters" and `*.txt` is a glob pattern.

The other common wildcard is the question mark (**`?`**), which stands for *one* character.

The most common wildcards are `*`, `?`, and `[list]`.

### [wildcards](https://en.wikipedia.org/wiki/Wildcard_character)

In software, a **wildcard character** is a kind of **placeholder** represented by a single character, such as an asterisk (`*`), which can be interpreted as a number of literal characters or an empty string. It is often used in file searches so the full name need not be typed.

Bash 中常用通配符只有3个: `*`, `?`, `[list]`。  

> `**`：出现在路径中，匹配任意级别目录。  

#### *

**`*`**（asterisk）: match any number of any characters  

> matches zero or more of any character in a name, including spaces or other strange characters.  

#### ?

**`?`**（question mark）：match only one single character, any character  

> matches exactly one of any character in a name, including a space or other strange character.  

- The GLOB pattern `???*` matches non-hidden names that are three or more characters long.  

#### [list]

**`[list]`**（square brackets）：match single characters from a list   
> match exactly one character in a name from a list of characters.  

- `[aA]`: it matches any one-character name that is either a or A.  
- `[a][A]`: only matches aA.  

#### demo

```shell
*.txt               # 匹配全部后缀为.txt的文件
file?.log           # 匹配file1.log, file2.log, ...
[a-z]*.log          # 匹配a-z开头的.log文件
[^a-z]*.log         # 上面的反向匹配
/etc/**/*.conf      # 猜猜看?
```

反斜杠(`\`)或引号(`'`, `"`)都会使通配符失效。

如: `\*`, `'*'`, `"*"` 都表示 `*` 本身，不通配任何文件。

### cheatsheet

#### Syntax

The most common wildcards are `*`, `?`, and `[…]`.

<table class="wikitable">
    <tbody>
        <tr>
            <th>Wildcard
            </th>
            <th>Description
            </th>
            <th>Example
            </th>
            <th>Matches
            </th>
            <th>Does not match
            </th>
        </tr>
        <tr>
            <td rowspan="2"><code class="mw-highlight" id="" style="" dir="ltr">*</code>
            </td>
            <td rowspan="2">matches any number of any characters including none
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Law*</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Law</code>, <code class="mw-highlight" id="" style=""
                    dir="ltr">Laws</code>, or <code class="mw-highlight" id="" style="" dir="ltr">Lawyer</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">GrokLaw</code>, <code class="mw-highlight" id=""
                    style="" dir="ltr">La</code>, or <code class="mw-highlight" id="" style="" dir="ltr">aw</code>
            </td>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">*Law*</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Law</code>, <code class="mw-highlight" id="" style=""
                    dir="ltr">GrokLaw</code>, or <code class="mw-highlight" id="" style="" dir="ltr">Lawyer</code>.
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">La</code>, or <code class="mw-highlight" id=""
                    style="" dir="ltr">aw</code>
            </td>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">?</code>
            </td>
            <td>matches any single character
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">?at</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Cat</code>, <code class="mw-highlight" id="" style=""
                    dir="ltr">cat</code>, <code class="mw-highlight" id="" style="" dir="ltr">Bat</code> or <code class="mw-highlight"
                    id="" style="" dir="ltr">bat</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">at</code>
            </td>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[abc]</code>
            </td>
            <td>matches one character given in the bracket
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[CB]at</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Cat</code> or <code class="mw-highlight" id=""
                    style="" dir="ltr">Bat</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">cat</code> or <code class="mw-highlight" id=""
                    style="" dir="ltr">bat</code>
            </td>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[a-z]</code>
            </td>
            <td>matches one character from the (locale-dependent) range given in the bracket
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letter[0-9]</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letter0</code>, <code class="mw-highlight" id=""
                    style="" dir="ltr">Letter1</code>, <code class="mw-highlight" id="" style="" dir="ltr">Letter2</code>
                up to <code class="mw-highlight" id="" style="" dir="ltr">Letter9</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letters</code>, <code class="mw-highlight" id=""
                    style="" dir="ltr">Letter</code> or <code class="mw-highlight" id="" style="" dir="ltr">Letter10</code>
            </td>
        </tr>
    </tbody>
</table>

In all cases the path separator character (`/` on Unix or `\` on Windows) will never be matched.  

#### UNIX

On Linux and POSIX systems `*`, `?` is defined as above while `[…]` has two additional meanings:

<table class="wikitable">
    <tbody>
        <tr>
            <th>Wildcard
            </th>
            <th>Description
            </th>
            <th>Example
            </th>
            <th>Matches
            </th>
            <th>Does not match
            </th>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[!abc]</code>
            </td>
            <td>matches one character that is not given in the bracket
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[!C]at</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Bat</code>, <code class="mw-highlight" id="" style=""
                    dir="ltr">bat</code>, or <code class="mw-highlight" id="" style="" dir="ltr">cat</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Cat</code>
            </td>
        </tr>
        <tr>
            <td><code class="mw-highlight" id="" style="" dir="ltr">[!a-z]</code>
            </td>
            <td>matches one character that is not from the range given in the bracket
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letter[!3-5]</code>
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letter1</code>, <code class="mw-highlight" id=""
                    style="" dir="ltr">Letter2</code>, <code class="mw-highlight" id="" style="" dir="ltr">Letter6</code>
                up to <code class="mw-highlight" id="" style="" dir="ltr">Letter9</code> and <code class="mw-highlight"
                    id="" style="" dir="ltr">Letterx</code> etc.
            </td>
            <td><code class="mw-highlight" id="" style="" dir="ltr">Letter3</code>, <code class="mw-highlight" id=""
                    style="" dir="ltr">Letter4</code>, <code class="mw-highlight" id="" style="" dir="ltr">Letter5</code>
                or <code class="mw-highlight" id="" style="" dir="ltr">Letterxx</code>
            </td>
        </tr>
    </tbody>
</table>

Some shells (such as the C shell and Bash) support additional syntax known as `alternation` or `brace expansion`.

The Bash shell also supports **Extended Globbing** which allows other pattern matching operators to be used to match multiple occurrences of a pattern enclosed in parentheses. It can be enabled by setting the **`extglob`** shell option.

## Globbing vs RegExp

通配符是用来匹配 **文件名** 的，正则表达式则是用来匹配 **文件内容**（文本字符串）的。

BASH 所做的是扩展文件名，基于通配符（globbing/wildcard patterns），并非正则表达式。  
通配符多用在文件名匹配上，比如 `ls`、`find`、`cp`、`rm` 等命令可通配查找出符合匹配条件的文件进行操作。  

BASH 本身没有正则表达式的功能，在脚本里使用正则表达式的是命令（grep,sed）和工具包（awk），它们可以解析正则表达式。  
针对文件内容的文本过滤工具 `grep`(-G,-e,-E),`awk`,`sed` 等，都是基于正则表达式。  

Wildcards are more limited in what they can pattern, as they have fewer metacharacters and a simple language-base.

### Equivalence

| glob        | regexp  | 说明                         |
| ----------- | ------- | ---------------------------- |
| `?`         | `.`     | 除 `换行符` 以外的任意单字符 |
| `*`         | `.*`    | 任意数量（0或多个）的字符    |
| `???*`      | `.{3,}` | 3或多个字符                  |
| `[:digit:]` | `\d`    | 数字                         |
| `[:space:]` | `\s`    | 空白                         |

最主要的区别是通配符是基于 **位置** 匹配，而正则表达式是 **前向** 限定（`a*`、`a+`、`a?`）。

### ranges exclude

Now that regular expressions have bracket expressions where the negation is indicated by a '`^`', POSIX has declared the effect of a wildcard pattern "`[^...]`" to be **undefined**.

通配及正则表达式都支持对字符集范围的匹配和排除匹配。范围匹配表达式都为 `[abc]` 格式，但是排除匹配略有不同。

传统 POSIX 中对于通配字符集排除匹配基于 `!` 的 `[!abc]` 格式，现代大部分通配及正则表达式中，都支持 **`[^abc]`** 格式排除匹配。

## references

[Linux命令ls通配符的使用](http://www.kivixv.com/2016/05/10/linux/Linux%E5%91%BD%E4%BB%A4ls%E9%80%9A%E9%85%8D%E7%AC%A6%E7%9A%84%E4%BD%BF%E7%94%A8/)  
[shell中的正则表达式和通配符](https://www.jianshu.com/p/49d5ee46de47) [@github](https://fengyalv.github.io/Blogs/shell/shell%E8%84%9A%E6%9C%AC%E4%B8%AD%E7%9A%84%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F.html)  
[**Linux基础概要**](https://www.gitbook.com/book/abcfy2/linux_basic) 之 [通配符](https://abcfy2.gitbooks.io/linux_basic/content/first_sense_for_linux/command_learning/wildcard.html) & [正则表达式](https://abcfy2.gitbooks.io/linux_basic/content/regular_expression/index.html)  
[命令行通配符教程](http://www.ruanyifeng.com/blog/2018/09/bash-wildcards.html) - 阮一峰  

**python**: [glob](https://docs.python.org/3/library/glob.html?highlight=glob#module-glob) - Filename globbing utility.
