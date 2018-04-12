# 数据流重定向(REDIRECTION)

参考 BASH(1) manual page 的 `REDIRECTION` 部分。

数据流重定向就是将某个命令执行后本应输出到控制台的结果数据传导到指定的地方，例如文件或打印机之类的设备。

## >, >>

输出导向，分别是 **替换** 与 **累加**

1. 标准输入（stdin）：代码为0，使用 `<` 或 `<<`；  
2. 标准输出（stdout）：代码为1，使用 `>` 或 `>>`；  
3. 标准错误输出（stderr）：代码为2，使用 `2>` 或 `2>>`。  

将 find 执行的正确结果输出到 list_right 文件中；错误信息输出到 list_error 文件中。

```shell
$ find /home -name .bashrc > list_right 2> list_error
```

将 find 执行的正确结果输出到控制台；错误信息导向到垃圾桶黑洞设备，被吞噬不输出。

```shell
$ find /home -name .bashrc 2> /dev/null
```

> `clang -dM -E -arch i386 -x c /dev/null` ？

如何将正确和错误的数据都写入同一文件呢？

```shell
# 错误，两条数据可能交叉写入导致错乱
$ find /home -name .bashrc 2> list 2> list
# 正确
$ find /home -name .bashrc > list 2>&1
$ find /home -name .bashrc &> list
```

**案例**：`ls 2>&1 > dirlist` 

1. 先执行 `2>&1`，stderr 被复制到 stdout，在控制台输出；  
2. 在执行 `ls > dirlist`，只有 stdout 才会被重定向到 dirlist 文件。  

### tee

双向重定向：同时将数据送与文件与控制台（stdout）。  
输出到控制台的部分可以传导给下个命令继续处理。

```shell
# 将 ls -l 结果追加到文件，同时输出到控制台用more分页显示。
faner@MBP-FAN:~|⇒  ls -l / | tee -a ~/homefile | more
```

**经典示例**：

执行 `shadowsocks.sh` 脚本安装 shadowsocks，将执行的 stdout 和 stderr 在控制台输出，并同时写入日志文件 shadowsocks.log： 

```shell
./shadowsocks.sh 2>&1 | tee shadowsocks.log
```

## <, <<

输入导向就是将原本应由键盘输入的数据源改为文件。

`cat > catfile` 将创建 `catfile` 文件，同时需要从键盘输入内容。

```shell
# 用 stdin 替代键盘的输入以创建新文件
cat > catfile < ~/.bashrc
```

`<<` 用于设定终止输入的控制字符串，以下示例中当输入 `eof` 时，则结束输入。

```shell
# 用 stdin 替代键盘的输入以创建新文件
cat > catfile << "eof" 
```

## demos

`enca -L zh_CN -x UTF-8 < file1 > file2`
