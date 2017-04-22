
# [linux ip 转发设置 ip_forward](http://blog.sina.com.cn/s/blog_3f83aa130100s8jo.html)

Linux 系统缺省并没有打开 IP 转发功能，要确认 IP 转发功能的状态，可以查看 `/proc` 文件系统，使用下面命令： 

```Shell
cat /proc/sys/net/ipv4/ip_forward
```

- 如果上述文件中的值为 0，说明**禁止**进行 IP 转发；  
- 如果是 1，则说明 IP 转发功能已经打开。  

要想打开 IP 转发功能，可以直接修改上述文件：

```Shell
echo 1 > /proc/sys/net/ipv4/ip_forward
```

把文件的内容由 0 修改为 1；把 1 改为 0 则禁用 IP 转发。

上面的命令并没有保存对 IP 转发配置的更改，下次系统启动时仍会使用原来的值，要想永久修改 IP 转发，需要修改 **`/etc/sysctl.conf`** 文件，修改下面一行的值：

```Shell
net.ipv4.ip_forward = 1 
```

修改后可以重启系统来使修改生效，也可以执行下面的命令来使修改生效： 

```Shell
sysctl -p /etc/sysctl.conf
```

进行了上面的配置后，IP 转发功能就永久使能了。