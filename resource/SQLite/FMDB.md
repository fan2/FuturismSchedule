[LevelDB](https://github.com/google/leveldb)： 快速键值存储库

## [SQLite](http://www.sqlite.org/)

一个完全嵌入式的，功能齐全的关系数据库，只有几百KB，可以正确包含到你的项目中。

- sqlite3_open()  
- sqlite3_prepare()  
- sqlite3_step()  
- sqlite3_column()  
- sqlite3_finalize()  
- sqlite3_close()  

**`sqlite3_exec`** 是 `sqlite3_prepare_v2`，`sqlite3_step` 和 `sqlite3_finalize` 的封装，能让程序多次执行 sql 语句而不要写许多重复的代码。

### references
[iOS学习笔记15-数据库SQLite](http://blog.csdn.net/xyz_lmn/article/details/8968203)  
[iOS学习笔记15-序列化、偏好设置和归档](http://www.jianshu.com/p/b5b9628d8db7)  
[iOS学习笔记16-数据库SQLite](http://www.jianshu.com/p/a23ce428180a)  
[对比iOS中的四种数据存储](http://www.infoq.com/cn/articles/data-storage-in-ios)  

【译】SQLite C/C++ 接口 [介绍](http://blog.cocoabit.com/sqlite-jie-kou-jie-shao/)  [简介](https://segmentfault.com/a/1190000002771737)  

[SQLite常用函数](http://www.cnblogs.com/wendingding/p/3871792.html)  
[sqlite3使用简介](http://www.cnblogs.com/kfqcome/archive/2011/06/27/2136999.html)  
[SQLite3深入浅出](http://www.jianshu.com/p/132dc0280474)  

[SQLite 3的中文读写](http://www.cnblogs.com/junchu25/p/3425183.html)  
[SQLite模糊查询](http://www.cnblogs.com/wendingding/p/3871577.html)  

[谈数据库索引和Sqlite中索引的使用](http://www.uml.org.cn/sjjm/201301175.asp)  
[SQLite优化(一)：了解SQLite数据库的锁](http://yanghao123.com/sqliteyou-hua-yi-liao-jie-sqliteshu-ju-ku-de-suo/)  
[SQLite学习手册(锁和并发控制)](https://wizardforcel.gitbooks.io/sqlite-learning-manual/content/14.html)  

[移动客户端中高效使用 SQLite](https://dev.qq.com/topic/57b57f2a0703f7d31b9a3932)  
[微信iOS SQLite源码优化实践](https://dev.qq.com/topic/57b58022433221be01499480)  

[iOS基于runtime实现的简单ORM](http://www.jianshu.com/p/802ef63ab1d7)  

### command line
[Linux sqlite3基本命令](http://blog.csdn.net/cnbloger/article/details/11596569)

```Shell
faner@FAN-MB0:~|⇒  sqlite3
SQLite version 3.16.0 2016-11-04 19:09:39
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
sqlite> .help
```

- `.help`：打印出帮助文档；  
- `.quit`：退出sqlite3，回来shell界面。  

## [FMDB](https://github.com/ccgus/fmdb)
以 OC 封装了 SQLite 的 C 语言 API。

### Framework
- **FMDatabase**

	> FMDatabase 对象代表一个单独的 SQLite 数据库，用来执行 SQL 语句

- **FMResultSet**

	> 使用 FMDatabase 执行查询后的结果集

- **FMDatabaseQueue**

	> 用于在多线程中执行多个查询或更新，它是线程安全的

### execution
在 FMDB 中，除查询以外的所有操作，都称为“更新”。

- create、drop、insert、update、delete 等操作统一调用 **`executeUpdate`** 接口。  
- select 等查询操作调用 **`executeQuery`** 接口。  

### references
[FMDB 简介1](http://www.cnblogs.com/jingdizhiwa/p/5644213.html)  FMDatabaseQueue 多线程  
[FMDB 简介2](http://www.cnblogs.com/wendingding/p/3871848.html)  文件路径；更新&查询  

[FMDB 使用1](http://www.cnblogs.com/wuhenke/archive/2012/02/07/2341656.html)  
[iOS学习笔记16-FMDB操作](http://blog.csdn.net/xyz_lmn/article/details/9312837)  
[FMDB 使用2](http://www.jianshu.com/p/d60ee3c85d63)  文件路径；更新&查询；占位绑定；事务  

[iOS学习笔记17-FMDB你好！](http://www.jianshu.com/p/82b2b06e3172)  事务；多线程  
[iOS学习笔记18-CoreData](http://www.jianshu.com/p/5e8e8517a00c)  

[iOS开发数据库篇—FMDB数据库队列](http://www.cnblogs.com/wendingding/p/3873874.html)  事务  
