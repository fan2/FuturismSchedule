## SQLITE_API 
### sqlite3_open
/*
** CAPI3REF: Opening A New Database Connection
** CONSTRUCTOR: sqlite3
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_open(
  const char *filename,   /* Database filename (UTF-8) */
  sqlite3 **ppDb          /* OUT: SQLite db handle */
);
```

打开(创建)指定名称的数据库，传入 sqlite3 句柄一级指针，返回二级指针。  

#### sqlite3_close
/*
** CAPI3REF: Closing A Database Connection
** DESTRUCTOR: sqlite3
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_close(sqlite3*);
SQLITE_API int SQLITE_STDCALL sqlite3_close_v2(sqlite3*);
```

当不再操作数据库时，需调用 sqlite3_close 进一步调用 sqlite3 的析构函数，释放数据库句柄。

关闭由sqlite3_open()创建的数据库连接。
在关闭连接之前，所有的预编译语句都应该被 finalize。

### sqlite3_exec
/*
** CAPI3REF: One-Step Query Execution Interface
** METHOD: sqlite3
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_exec(
  sqlite3*,                                  /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*,int,char**,char**),  /* Callback function */
  void *,                                    /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
);
```

执行SQL语句（sql）：无返回值

### sqlite3_prepare
/*
** CAPI3REF: Compiling An SQL Statement
** KEYWORDS: {SQL statement compiler}
** METHOD: sqlite3
** CONSTRUCTOR: sqlite3_stmt
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_prepare(
  sqlite3 *db,            /* Database handle */
  const char *zSql,       /* SQL statement, UTF-8 encoded */
  int nByte,              /* Maximum length of zSql in bytes. */
  sqlite3_stmt **ppStmt,  /* OUT: Statement handle */
  const char **pzTail     /* OUT: Pointer to unused portion of zSql */
);
SQLITE_API int SQLITE_STDCALL sqlite3_prepare_v2(
  sqlite3 *db,            /* Database handle */
  const char *zSql,       /* SQL statement, UTF-8 encoded */
  int nByte,              /* Maximum length of zSql in bytes. */
  sqlite3_stmt **ppStmt,  /* OUT: Statement handle */
  const char **pzTail     /* OUT: Pointer to unused portion of zSql */
);
```

将SQL文本编译成字节码，执行 sqlite3_stmt 的构造函数创建事务，返回事务句柄。

sqlite3_prepare 并非真正执行SQL语句，仅仅**准备**需要执的SQL语句。

**注意**：

> 对于新的应用不建议使用sqlite3_prepare()，而应使用架构更新的接口sqlite3_prepare_v2()代替。

#### sqlite3_finalize
/*
** CAPI3REF: Destroy A Prepared Statement Object
** DESTRUCTOR: sqlite3_stmt
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_finalize(sqlite3_stmt *pStmt);
```

销毁由sqlite3_prepare()创建的预编译语句。
为了防止内存泄露，每条预编译语句必须调用这个方法进行销毁。

对 sqlite3_stmt 执行完所有的 sqlite3_step 之后，调用 `sqlite3_finalize` 。
`sqlite3_finalize` 将调用 sqlite3_stmt 的析构函数，释放事务句柄。

### sqlite3_bind_*
/*
** CAPI3REF: Binding Values To Prepared Statements
** KEYWORDS: {host parameter} {host parameters} {host parameter name}
** KEYWORDS: {SQL parameter} {SQL parameters} {parameter binding}
** METHOD: sqlite3_stmt
**/

**可选步骤**。

如果 `sqlite3_prepare` 中包含 __VA_ARGS__(例如 `column  = ?`），可通过 bind 指定字段值（绑定参数），再执行 `sqlite3_step`。

**参数**：

1. sqlite3_stmt  
2. column index  
3. column value  

**参考**：

> QZKeyValueStore  
> xpDBService & xpCloudFileDBService  

**routines**:

```C
SQLITE_API int sqlite3_bind_blob(sqlite3_stmt*, int, const void*, int n, void(*)(void*));
SQLITE_API int sqlite3_bind_blob64(sqlite3_stmt*, int, const void*, sqlite3_uint64,
                        void(*)(void*));
SQLITE_API int sqlite3_bind_double(sqlite3_stmt*, int, double);
SQLITE_API int sqlite3_bind_int(sqlite3_stmt*, int, int);
SQLITE_API int sqlite3_bind_int64(sqlite3_stmt*, int, sqlite3_int64);
SQLITE_API int sqlite3_bind_null(sqlite3_stmt*, int);
SQLITE_API int sqlite3_bind_text(sqlite3_stmt*,int,const char*,int,void(*)(void*));
SQLITE_API int sqlite3_bind_text16(sqlite3_stmt*, int, const void*, int, void(*)(void*));
SQLITE_API int sqlite3_bind_text64(sqlite3_stmt*, int, const char*, sqlite3_uint64,
                         void(*)(void*), unsigned char encoding);
SQLITE_API int sqlite3_bind_value(sqlite3_stmt*, int, const sqlite3_value*);
SQLITE_API int sqlite3_bind_zeroblob(sqlite3_stmt*, int, int n);
SQLITE_API int sqlite3_bind_zeroblob64(sqlite3_stmt*, int, sqlite3_uint64);
```

### [sqlite3_step](http://www.cnblogs.com/hushaojun/p/5261334.html)
/*
** CAPI3REF: Evaluate An SQL Statement
** METHOD: sqlite3_stmt
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_step(sqlite3_stmt*);
```

传入执行 sqlite3_stmt 到下一个结果或者结束，返回 SQLITE_ROW/SQLITE_DONE 等。  

用来执行之前由sqlite3_prepare()接口创建的预编译语句。
这语句执行到第一行可用的位置，若要执行结果的第二行，需要再次调用sqlite3_step()。
继续调用 sqlite3_step() 直到语句结束。

对于那些不返回结果的语句（比如： INSERT, UPDATE, 或者 DELETE），只需调用一次sqlite3_step()。

枚举记录流程：

- sqlite3_prepare(OUT sqlite3_stmt)    
- sqlite3_step  
- sqlite3_column_*(access column value)  

执行返回值：

```C
    if (SQLITE_ROW == ret) // one row is ready : call getColumn(N) to access it
    {
        mbOk = true;
    }
    else if (SQLITE_DONE == ret) // no (more) row ready : the query has finished executing
    {
        mbOk = false;
    }
```

- SQLITE_BUSY
- SQLITE_DONE
- SQLITE_ROW
- SQLITE_ERROR
- SQLITE_MISUSE

### sqlite3_column_*
/*
** CAPI3REF: Result Values From A Query
** KEYWORDS: {column access functions}
** METHOD: sqlite3_stmt
**/

查询列信息  

```C
SQLITE_API const void *sqlite3_column_blob(sqlite3_stmt*, int iCol);
SQLITE_API int sqlite3_column_bytes(sqlite3_stmt*, int iCol);
SQLITE_API int sqlite3_column_bytes16(sqlite3_stmt*, int iCol);
SQLITE_API double sqlite3_column_double(sqlite3_stmt*, int iCol);
SQLITE_API int sqlite3_column_int(sqlite3_stmt*, int iCol);
SQLITE_API sqlite3_int64 sqlite3_column_int64(sqlite3_stmt*, int iCol);
SQLITE_API const unsigned char *sqlite3_column_text(sqlite3_stmt*, int iCol);
SQLITE_API const void *sqlite3_column_text16(sqlite3_stmt*, int iCol);
SQLITE_API int sqlite3_column_type(sqlite3_stmt*, int iCol);
SQLITE_API sqlite3_value *sqlite3_column_value(sqlite3_stmt*, int iCol);
```

### sqlite3_changes
/*
** CAPI3REF: Total Number Of Rows Modified
** METHOD: sqlite3
**/

```C
SQLITE_API int SQLITE_STDCALL sqlite3_changes(sqlite3*);
```

对 sqlite3_stmt 执行完 sqlite3_step 之后，可调用 sqlite3_changes 返回更新(改动)成功的记录行数。

**参考**：

> xpDBService

### sqlite3_reset
在预编译语句被一次或多次调用 sqlite3_step() 执行之后，它可以通过调用 sqlite3_reset()重置以便于再次执行。对已存在的预编译语句对象使用 sqlite3_reset()而不是创建一个新的预编译语句，避免不必要得调用 sqlite3_prepare()。对于很多SQL语句来说，执行sqlite3_prepare()的时间等于或者超过执行sqlite3_step()的时间。所以避免调用sqlite3_prepare(）可以显著提升性能。

通常情况下，尽管多次执行相同的SQL语句并非有用。更多时候，执行的是相似的语句。比如你可能想要多次执行一条插入语句，但插入的值不同。为了使用这类的灵活性，SQLite允许将要执行的SQL语句包含之前绑定的参数。这些值可以在后面更改，这样相同的预编译语句可以使用新的值执行第二次。