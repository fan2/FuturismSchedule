## Toolchains
/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain|
⇒  tree -L 3
.
├── Developer
│   └── Platforms
│       ├── AppleTVSimulator.platform
│       ├── MacOSX.platform
│       └── iPhoneSimulator.platform
├── ToolchainInfo.plist
└── usr
    ├── bin
    ├── include
    │   ├── FlexLexer.h
    │   ├── c++
    │   └── swift
    ├── lib
    │   ├── arc
    │   ├── clang
    │   ├── libIndexStore.dylib
    │   ├── libLTO.dylib
    │   ├── libclang.dylib
    │   ├── libswiftDemangle.dylib
    │   ├── libtapi.dylib
    │   ├── sourcekitd.framework
    │   ├── swift
    │   └── swift_static
    ├── libexec
    │   ├── as
    │   ├── migcom
    │   └── swift
    └── share
        ├── bison
        └── man
```

usr/lib/clang/9.0.0/include/

## Platforms
### macOS
/Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk|
⇒  tree -L 3
.
├── SDKSettings.plist
├── System
│   └── Library
│       ├── CoreServices
│       ├── Frameworks
│       └── PrivateFrameworks
└── usr
    ├── bin
    ├── include
    ├── lib
    └── share

```

### iOS
/Applications/Xcode-beta.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk|
⇒  tree -L 3
.
├── Entitlements.plist
├── Library
│   └── Application\ Support
├── SDKSettings.plist
├── System
│   └── Library
│       ├── CoreServices
│       ├── Frameworks
│       └── TextInput
└── usr
    ├── include
    ├── lib
    └── share
```

## header
忽略 iPhone Simulator、AppleTV OS 及 Simulator、Watch OS 及 Simulator 下的 `/usr/include/` 。

```
./Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/ 

./Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS.sdk/
./Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator.sdk/

./Platforms/WatchOS.platform/Developer/SDKs/WatchOS.sdk/
./Platforms/WatchSimulator.platform/Developer/SDKs/WatchSimulator.sdk/
```

### search path
关于 clang 编译器下的 C/C++ 头文件包含路径 search list，参考《xcode-Build_Settings.md》的 Header Search Paths 章节。

### cstddef(stddef.h)
在 `./Toolchains/XcodeDefault.xctoolchain/`、`./Platforms/MacOSX.platform/`、`./Platforms/iPhoneOS.platform/` 3个路径下查找 C 标准库头文件 <stddef.h> 及其对应的 C++ 标准库头文件 <cstddef>：

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name stddef.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/stddef.h
./Toolchains/XcodeDefault.xctoolchain//usr/lib/clang/9.0.0/include/stddef.h

./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stddef.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenCL.framework/Versions/A/lib/clang/2.0/include/stddef.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/stddef.h

./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/stddef.h

faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name cstddef
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/cstddef
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/cstddef
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/cstddef
```

#### XcodeDefault.xctoolchain
- usr/include/c++/v1/cstddef  
- usr/include/c++/v1/stddef.h  
- usr/lib/clang/9.0.0/include/stddef.h  

#### MacOSX.sdk
- usr/include/stddef.h  
- usr/include/c++/4.2.1/cstddef  

#### iPhoneOS.sdk
- usr/include/stddef.h  
- usr/include/c++/4.2.1/cstddef  

### cstdint(stdint.h)
since C++11

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name stdint.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/stdint.h
./Toolchains/XcodeDefault.xctoolchain//usr/lib/clang/9.0.0/include/stdint.h

./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stdint.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenCL.framework/Versions/A/lib/clang/2.0/include/stdint.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/stdint.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/stdint.h

./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/stdint.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/stdint.h
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|

⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name cstdint
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/cstdint
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/cstdint
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/cstdint
```

#### XcodeDefault.xctoolchain
- usr/include/c++/v1/cstdint  
- usr/include/c++/v1/stdint.h  
- usr/lib/clang/9.0.0/include/stdint.h  

#### MacOSX.sdk
- usr/include/stdint.h  
- usr/include/c++/4.2.1/tr1/cstdint  
- usr/include/c++/4.2.1/tr1/stdint.h  

- System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stdint.h  
- System/Library/Frameworks/OpenCL.framework/Versions/A/lib/clang/2.0/include/stdint.h  

#### iPhoneOS.sdk
- usr/include/stdint.h  
- usr/include/c++/4.2.1/tr1/cstdint  
- usr/include/c++/4.2.1/tr1/stdint.h  

### cstdio(stdio.h)
在 `./Toolchains/XcodeDefault.xctoolchain/`、`./Platforms/MacOSX.platform/`、`./Platforms/iPhoneOS.platform/` 3个路径下查找 C 标准库头文件 <stdio.h> 及其对应的 C++ 标准库头文件 <cstdio>：

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name stdio.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/stdio.h

./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/sys/stdio.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/stdio.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/stdio.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/sys/stdio.h

./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/stdio.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/stdio.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/sys/stdio.h

faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name cstdio
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/cstdio
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/cstdio
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/cstdio
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/cstdio
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/cstdio
```

#### XcodeDefault.xctoolchain
- usr/include/c++/v1/cstdio  
- usr/include/c++/v1/stdio.h  

#### MacOSX.sdk
- usr/include/stdio.h  
- usr/include/sys/stdio.h  

- usr/include/c++/4.2.1/cstdio  
- usr/include/c++/4.2.1/tr1/cstdio  
- usr/include/c++/4.2.1/tr1/stdio.h  

- System/Library/Frameworks/Kernel.framework/Versions/A/Headers/sys/stdio.h  

#### iPhoneOS.sdk
- usr/include/stdio.h
- usr/include/sys/stdio.h

- usr/include/c++/4.2.1/cstdio
- usr/include/c++/4.2.1/tr1/cstdio
- usr/include/c++/4.2.1/tr1/stdio.h

### cstdlib(stdlib.h)
在 `./Toolchains/XcodeDefault.xctoolchain/`、`./Platforms/MacOSX.platform/`、`./Platforms/iPhoneOS.platform/` 3个路径下查找 C 标准库头文件 <stdlib.h> 及其对应的 C++ 标准库头文件 <cstdlib>：

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name stdlib.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/stdlib.h

./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/stdlib.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h

./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/stdlib.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/stdlib.h

faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name cstdlib 
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/cstdlib
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/cstdlib
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/cstdlib
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/cstdlib
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/cstdlib
```


#### XcodeDefault.xctoolchain
- usr/include/c++/v1/cstdlib  
- usr/include/c++/v1/stdlib.h  

#### MacOSX.sdk
- usr/include/stdlib.h  
- usr/include/c++/4.2.1/cstdlib  
- usr/include/c++/4.2.1/tr1/cstdlib  
- usr/include/c++/4.2.1/tr1/stdlib.h  

#### iPhoneOS.sdk
- usr/include/stdlib.h  
- usr/include/c++/4.2.1/cstdlib  
- usr/include/c++/4.2.1/tr1/cstdlib  
- usr/include/c++/4.2.1/tr1/stdlib.h  

### cstring(string.h)
在 `./Toolchains/XcodeDefault.xctoolchain/`、`./Platforms/MacOSX.platform/`、`./Platforms/iPhoneOS.platform/` 3个路径下查找 C 标准库头文件 <string.h> 及其对应的 C++ 标准库头文件 <cstring>：

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name string.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/string.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/string.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/string.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/string.h

faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name cstring
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/cstring
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/cstring
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/cstring
```

#### XcodeDefault.xctoolchain
- usr/include/c++/v1/cstring  
- usr/include/c++/v1/string.h  

#### MacOSX.sdk
- usr/include/string.h  
- usr/include/c++/4.2.1/cstring  
- System/Library/Frameworks/Kernel.framework/Versions/A/Headers/string.h  

#### iPhoneOS.sdk
- usr/include/string.h  
- usr/include/c++/4.2.1/cstring  

### climits(limits.h)
在 `./Toolchains/XcodeDefault.xctoolchain/`、`./Platforms/MacOSX.platform/`、`./Platforms/iPhoneOS.platform/` 3个路径下查找 C 标准库头文件 <limits.h> 及其对应的 C++ 标准库头文件 <climits>：

```Shell
faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name limits.h
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/limits.h
./Toolchains/XcodeDefault.xctoolchain//usr/lib/clang/9.0.0/include/limits.h

./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/i386/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/machine/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenCL.framework/Versions/A/lib/clang/2.0/include/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/i386/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/limits.h
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/machine/limits.h

./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/arm/limits.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/limits.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/limits.h
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/machine/limits.h

faner@THOMASFAN-MB0:/Applications/Xcode-beta.app/Contents/Developer|
⇒  find ./Toolchains/XcodeDefault.xctoolchain/ ./Platforms/MacOSX.platform/ ./Platforms/iPhoneOS.platform/ -name climits 
./Toolchains/XcodeDefault.xctoolchain//usr/include/c++/v1/climits
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/climits
./Platforms/MacOSX.platform//Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1/tr1/climits
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/climits
./Platforms/iPhoneOS.platform//Developer/SDKs/iPhoneOS.sdk/usr/include/c++/4.2.1/tr1/climits
```

#### XcodeDefault.xctoolchain
- usr/include/c++/v1/climits  
- usr/include/c++/v1/limits.h  
- usr/lib/clang/9.0.0/include/limits.h  

#### MacOSX.sdk
- usr/include/limits.h  
- usr/include/machine/limits.h  
- usr/include/i386/limits.h  

- usr/include/c++/4.2.1/climits  
- usr/include/c++/4.2.1/tr1/climits  
- usr/include/c++/4.2.1/tr1/limits.h  

- System/Library/Frameworks/OpenCL.framework/Versions/A/lib/clang/2.0/include/limits.h  
- System/Library/Frameworks/Kernel.framework/Versions/A/Headers/i386/limits.h  
- System/Library/Frameworks/Kernel.framework/Versions/A/Headers/machine/limits.h  

#### iPhoneOS.sdk
- usr/include/limits.h  
- usr/include/machine/limits.h  
- usr/include/arm/limits.h  

- usr/include/c++/4.2.1/climits  
- usr/include/c++/4.2.1/tr1/climits  
- usr/include/c++/4.2.1/tr1/limits.h  