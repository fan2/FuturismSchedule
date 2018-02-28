# FastCGI

## FastCGI 入门
FastCGI 是一个基于套接字的协议，因此它能够适用于任何平台及任何编程语言。

我们已经确定 FastCGI 是一个运行在套接字的通信协议的服务，因此它暗指一个客户端和一个服务器。
客户端显然是 Nginx，作为服务器当然实际上就是十分复杂的 PHP。

默认情况下，PHP 支持 FastCGI 协议。
PHP 二进制命令能够处理脚本并且能够通过套接字与 Nginx 交互。

## Nginx + PHP

### PHP-FPM
PHP-FPM（PHP FastCGUI Process Manager，PHP FastCGI 进程管理模块）是目前公认功能和性能效率最高的进程管理方法，
它将 FastCGI 带到一个全新的水平。

PHP-FPM 本省并不是完整的程序，它当前的形式是作为补丁，在需要时添加到原始的 PHP 源代码中。

#### 必要条件
对于创建具有 PHP-FPM 的 PHP，有两个必要条件 —— libevent 和 libxml 开发库。

#### 创建 PHP

1. configure  
2. make  
3. install  

新安装的不会覆盖旧的，但是需要在安装时指定不同的路径。

```shell
./configure --enable-fpm
```

#### 安装之后的配置
1. 拷贝 php.ini 到先前设置的位置（？），覆盖先前设置；  
2. 打开 `/usr/local/etc/php-fpm.conf` 文件，配置 PHP-FPM。  

- 编辑用于 Unix 套接字和进程的用户和组；  
- PHP-FPM 监听的 IP 地址和端口号；  
- 提供同时处理请求的总数；  
- 允许连接到 PHP-FPM 的 IP 地址。  

#### 运行和控制

```shell
php-fpm start;      # 启动 PHP-FPM
php-fpm stop;       # 停止 PHP-FPM
php-fpm quit;       # 平滑关闭 PHP-FPM
php-fpm restart;    # 重启 PHP-FPM
php-fpm reload;     # 重新载入 PHP-FPM 配置文件
php-fpm logrotate;  # 执行 PHP-FPM 日志轮换
```

#### Nginx 配置
如果已经成功启动 PHP-FPM，就可以调整配置文件，从而将这两部分连接起来。

编辑 Nginx 配置文件的 server 区段，保存配置文件后，重新载入：

```shell
# 或者 service nginx reload
/usr/local/nginx/sbin/nginx -s reload
```

## Nginx + Python
借助于 Django 架构，可以将 Python 作为服务端的编程语言。

Django 提供了 FastCGI 管理，它会使我们通过 Nginx 来运行 Python 脚本更简单。

运行 Python FastCGI 还需要 flup 组件库。

```shell
# Red Hat/CentOS 系统使用 yum 命令安装
yum install flup

# Debian/Ubuntu 系统使用 apt(itude) 命令安装
apt install flup
```


