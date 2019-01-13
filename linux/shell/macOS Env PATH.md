> [设置Linux环境变量的方法和区别](http://www.powerxing.com/linux-environment-variable/)  
> [Mac 设置环境变量](http://elf8848.iteye.com/blog/1582137)  
> [MAC 设置环境变量](http://www.flakor.cn/2014-09-14-714.html)  
> 
> [MAC OS X上找不到.bash_profile？](http://blog.csdn.net/hsyj_0001/article/details/5403939)  
> [Creating a .bash_profile on your mac](http://redfinsolutions.com/blog/creating-bashprofile-your-mac)  
> [How To Edit Your PATH Environment Variables On Mac OS X](http://hathaway.cc/post/69201163472/how-to-edit-your-path-environment-variables-on-mac)  
> 
> [MY MAC OSX BASH PROFILE](http://natelandau.com/my-mac-osx-bash_profile/)  

`export`：显示所有环境变量
`set`：显示全部环境变量
`echo`：显示单个环境变量，例如echo \$PATH，echo \$HOME，echo \$SHELL

由于export变量的父子传递特性，如果想一直保持一个UNIX环境变量，必须到 `/etc/profile` 或 `/etc/bashrc` 或  `~/.bash_profile`  或 `~/.bashrc` 或 `~/.profile` 中配置，在其他地方定义和 export 都不会生效。

**Mac系统的环境变量加载顺序为：**

1. `/etc/profile`  
2. `/etc/paths`  
3. `~/.bash_profile`  
4. `~/.bash_login`  
5. `~/.profile`  
6. `~/.bashrc`  

**说明：**

- `/etc/profile` 和 `/etc/paths` 是系统级别的，系统启动就会加载；后面4个是当前用户级的环境变量。  
- 3-5按照从前往后的顺序读取：  
	 - 如果 `~/.bash_profile` 文件存在，则后面2个文件就被忽略不读了；  
	 - 如果 `~/.bash_profile` 文件不存在，才会依此类推读取后面的文件。  
- `~/.bashrc` 没有上述规则，它是 bash shell 打开的时候载入的。  

## /etc/profile

全局（公有）配置，不管是哪个用户，登录时都会读取该文件。

    ➜  /etc  cat profile
    # System-wide .profile for sh(1)
    
    if [ -x /usr/libexec/path_helper ]; then
    	eval `/usr/libexec/path_helper -s`
    fi
    
    if [ "${BASH-no}" != "no" ]; then
    	[ -r /etc/bashrc ] && . /etc/bashrc
    fi
    
    # redirect subversion to the lastest as global configuration
    # export PATH=/opt/subversion/bin:$PATH%    

> **建议不修改这个文件**

## /etc/bashrc

全局（公有）配置，bash shell执行时，不管是何种方式，都会读取此文件。

    ➜  /etc  cat bashrc
    # System-wide .bashrc file for interactive bash(1) shells.
    if [ -z "$PS1" ]; then
       return
    fi
    
    PS1='\h:\W \u\$ '
    # Make bash check its window size after a process completes
    shopt -s checkwinsize
    
    [ -r "/etc/bashrc_$TERM_PROGRAM" ] && . "/etc/bashrc_$TERM_PROGRAM"

**注意**： 

> 一般在这个文件中添加**系统级**环境变量。  
> 请不要在 `~/.bashrc` 中设置 PATH ，否则会导致 PATH 中目录的意外增长。因为每次打开一个新的 shell终端窗口，都会读取 `~/.bashrc`。  

## /etc/paths

编辑 paths，将环境变量添加到 paths文件中 ，一行一个路径。

    ➜  ~  cat /etc/paths
    /usr/local/bin
    /usr/bin
    /bin
    /usr/sbin
    /sbin

> 全局建议修改这个文件

## ~/.bash_profile

当 bash shell 是以 login 方式执行时，才会读取此文件，该文件仅仅执行一次。

> 一般在这个文件中添加**用户级**环境变量
