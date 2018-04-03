BASH Command History 是按照输入时间由远到近尾部追加的，编号越小时间越久远，最近输入的上一条命令编号最大。

# history
在 BASH(1) 的 man page 输入 `/^HISTORY` 可以查看内建 history 命令的帮助说明部分。

可在 BASH(1) 的 man page 中 `/` 或 `?` 搜索以下议题：

- Searching  
- Commands for Manipulating the History   

[history 增加详细历史记录](http://www.cnblogs.com/jjzd/p/5798603.html)  
[Linux 用户登录后精确命令记录](http://blog.csdn.net/lixiaohuiok111/article/details/34428161)  
[让 history 命令显示日期和时间](http://ju.outofmemory.cn/entry/340737)  

[Linux下history命令用法](http://blog.sina.com.cn/s/blog_5caa94a00100gyls.html)  
[Linux下history命令配置及高级应用](http://blog.itpub.net/29306197/viewspace-1062708/)  
[Linux中history历史命令使用方法详解](http://os.51cto.com/art/201205/335040.htm)  

## HISTFILE & HISTSIZE
环境变量 **HISTFILE** 定义了保存历史输入记录的文件路径；  
环境变量 **HISTSIZE** 则定义了保存最近历史记录的条数。  

```Shell
# macOS
faner@THOMASFAN-MB0:~|⇒  echo $HISTFILE
/Users/faner/.zsh_history
faner@THOMASFAN-MB0:~|⇒  echo $HISTSIZE
10000
```

```Shell
# raspbian
pi@raspberrypi:~ $ echo $HISTFILE
/home/pi/.bash_history
pi@raspberrypi:~ $ echo $HISTSIZE
1000
```

当我们以 bash 登录 linux(raspbian) 时，系统会从 `~/.bash_history` 中读取以前敲过的命令，总共不超过 1000 条。  
假设此次执行 `/bin/bash` 新建 shell 窗口，登录 Bash Shell 后共输入了100条命令，则当我们 exit 注销退出 Bash Shell 时，系统会将最新的 101~1100 条历史命令更新到 `~/.bash_history` 中。

我们可以在终端偏好设置中修改 Scrollback lines 行数限制。

或者 `vim .bashrc` 修改 `~/.bashrc` 中的 `HISTSIZE` 和 `HISTFILESIZE` 这两个 Shell Variables：

```Shell
pi@raspberrypi:~ $ vim .bashrc

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000
```

> 也可修改 system-wide 级别的配置`/etc/profile`，但 `/etc/profile` 会被 `~/.bash_profile` 修改覆盖， `~/.bash_profile` 会被 `~/.bashrc` 修改覆盖。  

## rolling
在终端按下 `C-p`/`C-n`（**↑**/↓，同 `<M-p>`/`<M-n>`）可以调出上一条/下一条历史命令。

```Shell
previous-history (C-p)
      Fetch the previous command from the history list, moving back in the list.
next-history (C-n)
      Fetch the next command from the history list, moving forward in the list.

non-incremental-reverse-search-history (M-p)
      Search backward through the history starting at the current line using  a  non-incremental search for a string supplied by the user.
non-incremental-forward-search-history (M-n)
      Search  forward through the history using a non-incremental search for a string supplied by the user.

beginning-of-history (M-<)
      Move to the first line in the history.
end-of-history (M->)
      Move to the end of the input history, i.e., the line currently being entered.
```

## display
在 macOS/raspbian 终端输入 `history` 命令可查看历史输入记录。

如果过往输入历史接近 HISTSIZE，`history` 命令列表较长，不便翻阅。  
此时，可通过管道命令导向 `head` / `tail` 筛选查看开头/结尾部分，或导向 `more` / `less` 翻页查看。  

当然，也可以在 `history` 命令后接参数 `[n]` 查看指定行数的历史记录。

- raspbian 下输入 `history N` 列显结尾（最近）的 N 条历史输入记录。  
- macOS 下输入 `history N` 列显开头的 N 条历史输入记录。

可通过管道将 `history` 导向 `tail -n N` 选取列显结尾（最近）的 N 条历史输入记录：

```shell
# 查看最近10条输入命令记录
faner@MBP-FAN:~|⇒  history | tail -n 10
```

## Event Designators
针对 history list，支持以下前缀为 `!` 的 Event Designators：

```Shell
!      Start a history substitution, except when followed by a blank,  newline,  carriage return, = or ( (when the extglob shell option is enabled using the shopt builtin).
!n     Refer to command line n.
!-n    Refer to the current command minus n.
!!     Refer to the previous command.  This is a synonym for `!-1'.
!string
      Refer to the most recent command preceding the current position in the history list starting with string.
!?string[?]
      Refer to the most recent command preceding the current position in the history list containing string.  The trailing ? may be omitted if string  is  followed immediately by a newline.
^string1^string2^
      Quick  substitution.   Repeat  the  previous  command,  replacing string1 with string2.  Equivalent to ``!!:s/string1/string2/'' (see Modifiers below).
!#    The entire command line typed so far.
```

- `!!`：选定上一条命令；  
- `!n`：选定编号为 n 的历史记录；  
- `!-n`：选定编号为 -n（最近第 n-1 条） 的历史记录；  
- `!string`：选定最近历史记录中以 string 开头的历史记录；  
- `!?string`：选定最近历史记录中包含 string 的历史记录；  

```shell
# 最近一条以 curl 开头的命令
faner@MBP-FAN:~|⇒  !curl
faner@MBP-FAN:~|⇒  curl http://linux.vbird.org/linux_basic/0330regularex/regular_express.txt -o regular_express.txt

# 最近一条包含 curl 的命令
faner@MBP-FAN:~|⇒  !?curl
faner@MBP-FAN:~|⇒  curl http://linux.vbird.org/linux_basic/0330regularex/regular_express.txt -o regular_express.txt
```

更复杂的可以基于 grep 正则查找符合某些规定的历史命令记录：

```shell
# 查找包含 curl 且以 regular_express.txt 结尾的历史命令
faner@MBP-FAN:~|⇒  history | grep 'curl.*regular_express.txt$' 
 9950  curl http://linux.vbird.org/linux_basic/0330regularex/regular_express.txt
 9953  curl http://linux.vbird.org/linux_basic/0330regularex/regular_express.txt -o regular_express.txt
```

## Search

```Shell
reverse-search-history (C-r)
      Search backward starting at the current line and moving `up' through  the  history as necessary. This is an incremental search.

forward-search-history (C-s)
      Search  forward starting at the current line and moving `down' through the history as necessary. This is an incremental search.
```

重复按 `C-r` 可翻看过往匹配的命令。

- 连按两下 <kbd>esc</kbd> 确认选定；  
- 按下 <kbd>enter</kbd> 或 `C-j` 选定执行；  
- 按下 `C-g` 取消放弃当前搜索匹配结果；  
