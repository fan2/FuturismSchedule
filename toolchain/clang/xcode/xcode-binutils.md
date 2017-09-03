## toolchain binUtils
> /Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin|

### C/C++
- c89 -- standard C language compiler  
- c99 -- standard C language compiler  

### preprocessor
- gm4(m4)：M4 - macro processor  
- unifdef, unifdefall -- remove preprocessor conditionals from code  

### cl(Compiler/Assembler/Linker)
- clang - the Clang C, C++, and Objective-C compiler - c++/cc/clang++/cpp  
- as - Mac OS X Mach-O GNU-based assemblers  
- ld -- linker  
- ar：archive  

#### as
```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/libexec/as|
⇒  tree
.
├── arm
│   └── as
├── i386
│   └── as
└── x86_64
    └── as

3 directories, 3 files
```

### utility
- indent -- indent and format C program source  
- lorder -- list dependencies for object files  
- strings - find the printable strings in a object, or other binary, file  
- size(llvm-size) - print the size of the sections in an object file  

### libtool
- lipo - create or operate on universal files  
- libtool - create libraries  
- ranlib(libtool) - add or update the table of contents of archive libraries  

### bison(yacc)
- bison - GNU Project parser generator (yacc replacement)  
- flex(lex) - the fast lexical analyser generator  

### otool(objdump)
- nm(llvm-nm) - display name list (symbol table)  
- otool(llvm-otool) - object file displaying tool  
- objdump(llvm-objdump): llvm object file dumper  

### edit
- strip - remove symbols  
- rebase -- Changes base address of dylibs and bundles  

- segedit - extract and replace sections from object files  
- bitcode_strip - remove or leave the bitcode segment in a Mach-O file  

### dwarfdump
- dwarfdump -- dump DWARF debug information.  
- dsymutil -- manipulate archived DWARF debug symbol files.  

## Developer binUtils
> /Applications/Xcode-beta.app/Contents/Developer/usr/bin|

### cl(Compiler and Linker)
- nasm - the Netwide Assembler, a portable 80x86 assembler  
- make - GNU make utility to maintain groups of programs  
- gcc/g++ - clang LLVM compiler  
- ld -- linker  

- bitcode-build-tool  
- symbols -- display symbol information about a file or process  
- lldb -- The debugger  

### SCM
- svn  
- git  
