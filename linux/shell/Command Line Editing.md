# Command Line Editing

> [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>> [8 Command Line Editing](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  

## readline

The GNU Readline Library: [Library for command-line editing](https://tiswww.case.edu/php/chet/readline/rltop.html)

在 BASH(1) 的 man page 输入 `/^READLINE`（`^` 为 vim 中的行首字元位置），可搜索 READLINE 相关的说明（the READLINE section of the bash(1) man page）。

This is the library that <u>handles reading input</u> when using an interactive shell, unless the `--noediting` option is given at shell invocation. Line editing is also used when using the `-e` option to the *read* builtin.  
By default, the line editing commands are similar to those of **Emacs**. A **vi**-style line editing interface is also available.  
Line editing can be enabled at any time using the `-o emacs` or `-o vi` options to the set builtin.  

> [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>> [8 Command Line Editing](https://www.gnu.org/software/bash/manual/bashref.html#Command-Line-Editing)  
>>> [8.2 Readline Interaction](https://www.gnu.org/software/bash/manual/bashref.html#Readline-Interaction)  

## Moving

BASH(1) 的 man page 中输入 `/Commands for Moving` 即可定位到对应章节。

[emacs-compatible keybindings](https://stackoverflow.com/questions/81272/is-there-any-way-in-the-os-x-terminal-to-move-the-cursor-word-by-word)

```Shell
beginning-of-line (C-a)
      Move to the start of the current line.
end-of-line (C-e)
      Move to the end of the line.
forward-char (C-f)
      Move forward a character.
backward-char (C-b)
      Move back a character.
forward-word (M-f)
      Move forward to the end  of  the  next  word.   Words  are  composed  of
      alphanumeric characters (letters and digits).
backward-word (M-b)
      Move  back to the start of the current or previous word.  Words are com-
      posed of alphanumeric characters (letters and digits).
clear-screen (C-l)
      Clear the screen leaving the current line at  the  top  of  the  screen.
      With  an argument, refresh the current line without clearing the screen.
redraw-current-line
      Refresh the current line.
```

`<C-l>`：滚动屏幕将当前行置顶，同 clear 命令。不清除缓冲区，可继续下拉滚动翻看过往记录。

- `<C-b>`/`<C-f>`（←/→）：按**字符**为单位移动  
- `<M-b>`/`<M-f>`（⌥+←/→）：按**单词**为单位移动  
- `<C-a>`/`<C-e>`：定位句**首/尾**  

## Editing

BASH(1) 的 man page 中输入 `/Commands for Changing Text` 即可定位到对应章节。

```Shell
delete-char (C-d)
      Delete the character at point. If this function is bound to the same character as the tty EOF character, as C-d commonly is, see above for the effects.
```

- `C-h`：delete char backward（向左回删一个**字符**）.  
- `C-d`：delete-char (forward)（向右删除一个**字符**）.  

## Killing and Yanking

BASH(1) 的 man page 中输入 `/Killing and Yanking` 即可定位到对应章节。

```Shell
kill-line (C-k)
      Kill the text from point to the end of the line.
backward-kill-line (C-x Rubout)
      Kill backward to the beginning of the line.
unix-line-discard (C-u)
      Kill backward from point to the beginning of the line.   The  killed  text  is saved on the kill-ring.
kill-whole-line
      Kill all characters on the current line, no matter where point is.
kill-word (M-d)
      Kill  from  point  to the end of the current word, or if between words, to the end of the next word.  Word boundaries are the same  as  those  used  by  for ward-word.
backward-kill-word (M-Rubout)
      Kill  the  word  behind  point.  Word boundaries are the same as those used by backward-word.
shell-kill-word
      Kill from point to the end of the current word, or if between  words,  to  the end  of  the  next  word.   Word  boundaries  are  the  same  as those used by shell-forward-word.
shell-backward-kill-word
      Kill the word behind point.  Word boundaries are the same  as  those  used by shell-backward-word.
unix-word-rubout (C-w)
      Kill  the word behind point, using white space as a word boundary.  The killed text is saved on the kill-ring.

yank (C-y)
      Yank the top of the kill ring into the buffer at point.
yank-pop (M-y)
      Rotate  the  kill  ring,  and  yank the new top.  Only works following yank or yank-pop.
```

- `C-w` / `M-delete`(backspace)，向后（backward）删除至**单词**开头；  
- `M-d`：向前（forward）删除至**单词**末尾；  
- `C-u`：删除至**行首**（raspbian/CentOS） or 删除整行（macOS）；  
- `C-k`：删除至**行末**；  

`<C-y>`：召回（yank）粘贴 `<C-w>`、`<M-d>`、`<C-u>`、`<C-k>` 剪切删除（kill）的文本。

## Completing

complete (`TAB`)  
possible-completions (`M-?`)  
possible-filename-completions (`C-x /`)  
possible-variable-completions (`C-x $`)  

## Keyboard Macros

BASH(1) 的 man page 中输入 `/Keyboard Macros` 即可定位到对应章节。
