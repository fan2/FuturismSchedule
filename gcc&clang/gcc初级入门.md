gcc 后跟要编译的源码文件（可多个），不指定任意选项，则自动生成可执行文件，默认文件名为 `a.out`：

> gcc  test.c

运行命令 `./a.out` 启动执行。

## -E
-E 选项指示编译器只对输入的文件进行预处理，且预处理的结果直接输送到标准输出流（stdout）而非储存在文件里。

> gcc -E test.c

## -c
-c 选项只把源代码（`*.c`）编译成目标代码（`*.o`），但不链接。  
它能使编译多个C程序时的速度更快且更加容易管理。  
gcc建立的目标代码文件默认只有一个 `.o` 的扩展名。  

> gcc -c test.c

## -S
-S 选项告诉 gcc 只执行编译汇编，产生的汇编文件默认扩展名为 `.s`。

> gcc -S test.c

## -o
通过使用选项 `-o` 指定编译链接生成的可执行文件名：

> gcc -o result test.c

运行命令 `./result` 启动执行。

### 编译实例——coroutine
```Shell
⇒  
faner@THOMASFAN-MB0:~/Projects/git/framework/coroutine|master⚡ 
⇒  mkdir out
faner@THOMASFAN-MB0:~/Projects/git/framework/coroutine|master⚡ 
⇒  gcc coroutine.c main.c -o out/coroutine 
```
