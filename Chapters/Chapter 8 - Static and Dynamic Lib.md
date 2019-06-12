# Chapter 8 - Static and Dynamic Library

## Sharing .h File

```c
#include <encrypt.h>
...
gcc -I/my_header_files ...
```

## Static Library

### `ar` - archiving `.o` files

```c
ar -rcs libhfsecurity.a encrypt.o checksum.o
```

`-r` : update the .a file if it exists  
`-c` : don't show feedback info when creating an archive  
`-s` : create index at the beginning of .a file

`libxxx.a` : name of the archive to be created  
`.o` : files to be archived.

`.a` file is **static library**

you can save the `.a` file in

>`/usr.local/lib`

or personal lib path, e.g.
> `/my_lib`

### compiling

Default path

```c
gcc test_code.c -lhfsecurity -o test_code
```

Personal path

```c
gcc test_code.c -L/my_lib -lhfsecurity -o test_code
```

`-I` : include the path of `.h` files  
`-L` : include the path of `.a` files

Note

* remember to include `source file` before `-lxxx`.

* use ( `ar -t<file_name>` ) to list the target files in `.a`.

* target files are stored independently in `.a` files.

* use ( `ar -x libhfsecurity.a encrypt.o` ) to extract `.o` from `.a`.

### elliptical.c

## Dynamic Library (.dll)

```c
gcc -I/includes -fPIC -c hfcal.c -o hfcal.o
```

`-fPIC` : create lib with address independent code

```c
gcc -shared hfacl.o -o

win: C:\libs\hfcal.dll
cygwin: /libs/libhfcal.dll.a
linux: /lib/libhfcal.so
mac: /libs.libhfcal.dylib
```

### compiling (dynamic)

```c
gcc -I/include -c elliptical.c -o elliptical.o

gcc elliptical.o -L/libs -lhfcal -o elliptical
```

codes for compiling are alomost similar to that used for static lib.

---

However, compiler will not insert the lib code into the executable, instead of which is a placeholder for searching the needed lib while running the program.

---

#### Go through the text from P380
