[how to view, edit, unset and delete an environment variable in linux](http://www.lostsaloon.com/technology/how-to-view-edit-and-delete-an-environment-variable-in-linux/)

通过等号（`=`）可赋值修改系统变量 PATH，增加可执行路径：

```shell
# 头部插入
pi@raspberrypi:~ $ PATH=/usr/local/bin:$PATH
pi@raspberrypi:~ $ PATH=/usr/local/bin:${PATH}

# 尾部追加
pi@raspberrypi:~ $ PATH=$PATH:/usr/local/sbin
pi@raspberrypi:~ $ PATH=${PATH}:/usr/local/sbin
```

关于 PATH 变量，参考 `PARAMETERS | Shell Variables`：

**PATH**: The search path for commands.  

> It is a colon-separated list of directories in which the shell looks for commands (see COMMAND EXECUTION below).

## 自定义变量（local variable）

通过等号（`=`）可自定义变量，但是变量的作用域只局限于当前 shell 进程：

```shell
faner@THOMASFAN-MB0:~|⇒  http_proxy=socks5://127.0.0.1:1080
faner@THOMASFAN-MB0:~|⇒  echo $http_proxy
socks5://127.0.0.1:1080
```

在当前 shell 进程执行 `bash` 命令 fork 子进程，仅会继承父进程的环境变量，但是不会继承父进程自定义的变量（`http_proxy`）：

```shell
faner@THOMASFAN-MB0:~|⇒  bash
bash-3.2$ echo $http_proxy

bash-3.2$ 
```

## export（global variable）

使用 export 设置的环境变量，对当前终端 Shell 及其子进程有效：

```shell
faner@THOMASFAN-MB0:~|⇒  export HTTP_PROXY=socks5://127.0.0.1:1080
faner@THOMASFAN-MB0:~|⇒  echo $HTTP_PROXY 
socks5://127.0.0.1:1080
```

在当前 shell 进程执行 `bash` 命令 fork 子进程，将会继承父进程通过 export 导出的环境变量（`HTTP_PROXY`）：

```shell
faner@THOMASFAN-MB0:~|⇒  bash
bash-3.2$ echo $HTTP_PROXY 
socks5://127.0.0.1:1080
bash-3.2$ 
```

典型的执行 `export PATH=somepath:$PATH` 可将 somepath 添加到当前可执行路径 PATH 中。  
但是新建终端（New Command: `/bin/bash`）将无法引用变量。所以，export 适合设置一些当次 shell 交互用到的临时变量。  

> [Mac OS Yosemite and java classpaths](https://stackoverflow.com/questions/26014079/mac-os-yosemite-and-java-classpaths)  
> [Where is JAVA_HOME on macOS](https://stackoverflow.com/questions/6588390/where-is-java-home-on-osx-sierra-10-12-el-capitan-10-11-yosemite-10-10)  
> [Mac下配置JAVA_HOME](http://blog.csdn.net/shallowgrave/article/details/39367119)  

### 示例1：[替换Homebrew Bottles源](https://lug.ustc.edu.cn/wiki/mirrors/help/homebrew-bottles)

临时替换：

```shell
export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles
```

### 示例2：[设置 homebrew 代理](https://www.logcg.com/archives/1617.html)

man brew 里有提到设置 http proxy 的方法：

```shell
USING HOMEBREW BEHIND A PROXY
       Homebrew uses several commands for downloading files (e.g. curl, git,  svn).  Many
       of these tools can download via a proxy. It's common for these tools to read proxy
       parameters from environment variables.

       For the majority of cases setting http_proxy is enough. You can set this  in  your
       shell profile, or you can use it before a brew command:



           http_proxy=http://<host>:<port> brew install foo



       If your proxy requires authentication:



           http_proxy=http://<user>:<password>@<host>:<port> brew install foo
```

可以执行 `export http_proxy` 和 `export https_proxy` 设置 HTTP 和 HTTPS 代理：

```shell
export http_proxy=socks5://127.0.0.1:1080
export https_proxy=socks5://127.0.0.1:1080
```

或

```shell
export ALL_PROXY=socks5://127.0.0.1:1080
```

> 执行 `unset http_proxy unset https_proxy` 或 `unset ALL_PROXY` 可取消代理。

## profile（process/system variable）

以下节选自 bash(1) - Linux manual page 的 INVOCATION 章节：

```shell
When bash is invoked as an interactive login shell, or as a non-interactive shell with the --login option, it first reads and executes commands from the file /etc/profile, if that file exists. After reading that file, it looks for ~/.bash_profile, ~/.bash_login, and ~/.profile, in that order, and reads and executes commands from the first one that exists and is readable.

When an interactive login shell exits, or a non-interactive login shell executes the exit builtin command, bash reads and executes commands from the file ~/.bash_logout, if it exists.

When an interactive shell that is not a login shell is started, bash reads and executes commands from ~/.bashrc, if that file exists.

This may be inhibited by using the --norc option. The --rcfile file option will force bash to read and execute commands from file instead of ~/.bashrc.
```

- `.bash_history` ：记录了以前输入的命令  
- `.bash_logout` ：退出 shell 时要执行的命令  

亦可参考《鸟哥的linux私房菜》<11.2 shell 的变量功能> 和 <11.4 Bash Shell 的操作环境> 。

### 全局环境变量

首先是设置全局环境变量，对所有用户都会生效：

- **`etc/profile`**: 此文件为系统级配置信息（Systemwide configuration file）。当用户登录时，该文件被执行一次，并从 `/etc/profile.d` 目录的配置文件中搜集shell 的设置。一般用于设置所有用户使用的全局变量。

- **`/etc/bashrc`**: 当 bash shell 被打开时，该文件被读取。也就是说，每次新打开一个终端 shell，该文件就会被读取。

> [UNIX系统级别环境文件profile](http://blog.sina.com.cn/s/blog_6151984a0100ej4n.html)  

### 用户环境变量

bash 在读完了系统整体环境配置的 `/etc/profile` 并借此调用其他配置文件后，接下来则会读取用户的个人配置文件（per-user configuration file）。

在 login shell 的 bash 环境中，依次会读取以下三个个人偏好配置文件：

- `~/.bash_profile`  
- `~/.bash_login`  
- `~/.profile`  

> 以上3个文件只对单个用户生效，当用户登录时该文件**仅执行一次**。  
>> 如果 `~/.bash_profile` 存在，则不会再读取其他两个文件；  
>> 如果`~/.bash_profile` 不存在，才会去读取 `~/.bash_login`。

只对单个用户生效，当在 bash 中再执行 bash 打开新的 shell 时，都会读取 `~/.bashrc` 文件：

- `~/.bashrc`  

> 当取得 non-login shell 时，该 bash 的配置文件仅会读取 `~/.bashrc`。  
>>  `~/.bashrc` 

### 设置环境变量

可修改 system-wide 级别的配置`/etc/profile`，但 `/etc/profile` 会被 `~/.bash_profile` 修改覆盖， `~/.bash_profile` 会被 `~/.bashrc` 修改覆盖。

若想定义所有新建 bash shell 进程中都可见的跨进程系统级变量，则可将 export 语句添加到 bash shell 的环境配置文件中，在启动 shell 进程时会读取配置文件以规划好 bash 的操作环境。

```shell
echo 'export PATH=somepath:$PATH' >> ~/.bash_profile
```

以下为 brew install openssl/sqlite 的 Caveats：

```shell
If you need to have this software first in your PATH run:
  echo 'export PATH="/usr/local/opt/openssl/bin:$PATH"' >> ~/.zshrc

If you need to have this software first in your PATH run:
   echo 'export PATH="/usr/local/opt/sqlite/bin:$PATH"' >> ~/.zshrc
```

以下节选自本人 macOS 的 zsh 配置文件 `~/.zshrc`：

```shell
faner@THOMASFAN-MB0:~|⇒  cat .zshrc
# Path to your oh-my-zsh installation.
export ZSH=/Users/faner/.oh-my-zsh



# User configuration

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin"
# export MANPATH="/usr/local/man:$MANPATH"
```

#### export HOMEBREW_BOTTLE_DOMAIN to profile

如果是 bash shell，可将 `export HOMEBREW_BOTTLE_DOMAIN` 加到 `~/.bash_profile` 或 `~/.bashrc`：

```shell
echo 'export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.ustc.edu.cn/homebrew-bottles' >> ~/.bash_profile
source ~/.bash_profile
```

如果是 zsh shell，可将 `export HOMEBREW_BOTTLE_DOMAIN` 加到 `~/.zshrc`：

```shell
echo 'export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.ustc.edu.cn/homebrew-bottles' >> ~/.zshrc
source ~/.zshrc
```

#### export ALL_PROXY to profile

用如下语句来将命令直接导入到配置文件里：

```shell
# for bash
echo export ALL_PROXY=socks5://127.0.0.1:1080 >> ~/.bash_profile

# for zsh
echo export ALL_PROXY=socks5://127.0.0.1:1080 >> ~/.zshrc
```

#### system-wide

`~/` 下的配置文件 `.bash_profile` 只对当前登录用户生效。  
若要设置面向所有登录用户都生效的环境变量，可将 export 导出语句添加到 `/etc/profile` 配置文件中。  

以下为 raspbian 的 `/etc/profile` 中导出的系统级 PATH 变量：

```shell
pi@raspberrypi:~ $ cat /etc/profile
# /etc/profile: system-wide .profile file for the Bourne shell (sh(1))
# and Bourne compatible shells (bash(1), ksh(1), ash(1), ...).

if [ "`id -u`" -eq 0 ]; then
  PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
else
  PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games"
fi
export PATH

```

## 参考

> [Linux下查看和添加PATH环境变量](http://blog.csdn.net/dlutbrucezhang/article/details/8811456)  
> [设置Linux环境变量的方法和区别](http://www.powerxing.com/linux-environment-variable/)  
> [Linux系统修改环境变量PATH路径](http://opsmysql.blog.51cto.com/2238445/665990)  
> [Linux里设置环境变量的方法（export PATH）](http://blog.51cto.com/kangyang/590840)  
> [UNIX下的环境变量](http://blog.sina.com.cn/s/blog_6151984a0100ej4v.html)  
> [UNIX环境变量设置总结](http://www.cnblogs.com/aicro/archive/2011/03/30/2000068.html)  
