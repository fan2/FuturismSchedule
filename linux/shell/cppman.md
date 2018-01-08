# cppman
github [aitjcize](https://github.com/aitjcize) / [**cppman**](https://github.com/aitjcize/cppman)

C++ 98/11/14 manual pages for Linux, with source from www.cplusplus.com and www.cppreference.com.

Package Index > [cppman > 0.4.8](https://pypi.python.org/pypi/cppman)  

[looking up c++ documentation inside of vim](https://stackoverflow.com/questions/2272759/looking-up-c-documentation-inside-of-vim)  
[Ubuntu manuals - cppman](http://manpages.ubuntu.com/manpages/xenial/man1/cppman.1.html)  

```shell
DESCRIPTION
       cppman  generates  C++  manual  pages  from cplusplus.com and provide a
       man-like interface to view man pages.

       By default, cppman fetches man pages on-the-fly, by running the command
       'cppman -c', all available manpages are cached, making offline browsing
       possible. This is also required if you want to  use  the  system  'man'
       command.
```

## Install from PyPI
```shell
$ pip install cppman
```

pip3 搜索 cppman：

```shell
faner@MBP-FAN:~|⇒  pip3 search cppman
cppman (0.4.8)   - C++ 98/11/14 manual pages for Linux/MacOS
cppmangle (0.2)  - A parser for mangled C++ names
```

pip3 安装 cppman：

```shell
faner@MBP-FAN:~|⇒  pip3 install cppman
Collecting cppman
  Downloading cppman-0.4.8.tar.gz (218kB)
    100% |████████████████████████████████| 225kB 1.2MB/s 
Collecting beautifulsoup4 (from cppman)
  Downloading beautifulsoup4-4.6.0-py3-none-any.whl (86kB)
    100% |████████████████████████████████| 92kB 923kB/s 
Collecting html5lib (from cppman)
  Downloading html5lib-1.0.1-py2.py3-none-any.whl (117kB)
    100% |████████████████████████████████| 122kB 26kB/s 
Collecting webencodings (from html5lib->cppman)
  Downloading webencodings-0.5.1-py2.py3-none-any.whl
Collecting six>=1.9 (from html5lib->cppman)
  Downloading six-1.11.0-py2.py3-none-any.whl
Building wheels for collected packages: cppman
  Running setup.py bdist_wheel for cppman ... done
  Stored in directory: /Users/faner/Library/Caches/pip/wheels/c3/2a/b0/1240e9f71aa5b61ef8630897f15e85f85aa77f9bdff3fae7e1
Successfully built cppman
Installing collected packages: beautifulsoup4, webencodings, six, html5lib, cppman
Successfully installed beautifulsoup4-4.6.0 cppman-0.4.8 html5lib-1.0.1 six-1.11.0 webencodings-0.5.1
```

查看 cppman 版本：

```shell
faner@MBP-FAN:~|⇒  cppman -v
/usr/local/bin/cppman Ver 0.4.8
Copyright (C) 2010 Wei-Ning Huang
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Wei-Ning Huang (AZ) <aitjcize@gmail.com>.%                                           
```

查看 cppman 帮助：

```shell
faner@MBP-FAN:~|⇒  cppman -h
Usage: cppman [OPTION...] PAGE...

Options:
  -s SOURCE, --source=SOURCE
                        Select source, either 'cppreference.com' or
                        'cplusplus.com'. Default is 'cplusplus.com'.
  -c, --cache-all       Cache all available man pages from cppreference.com
                        and cplusplus.com to enable offline browsing.
  -C, --clear-cache     Clear all cached files.
  -f KEYWORD, --find-page=KEYWORD
                        Find man page.
  -o, --force-update    Force cppman to update existing cache when '--cache-
                        all' or browsing man pages that were already cached.
  -m MANDB, --use-mandb=MANDB
                        Accepts 'true' or 'false'. If true, cppman adds
                        manpage path to mandb so that you can view C++
                        manpages with `man' command. The default value is
                        'false'.
  -p PAGER, --pager=PAGER
                        Select pager to use, accepts 'vim', 'less' or
                        'system'. 'system' uses $PAGER environment as pager.
                        The default value is 'vim'.
  -r, --rebuild-index   rebuild index database for the selected source, either
                        'cppreference.com' or 'cplusplus.com'.
  -v, --version         Show version information.
  --force-columns=FORCE_COLUMNS
                        Force terminal columns.
  -h, --help            show this help message and exit
```

## Debian / Ubuntu
```shell
$ sudo apt-get install cppman
```
