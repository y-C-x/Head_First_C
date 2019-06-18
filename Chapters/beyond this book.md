# Go Further

## Operator

### inc and dec

```c
++i; // inc 1 and return the new i
i++; // inc 1 and return the old i
```

same for `--i` and `i--`

### ternary conditional operator

```c
return (x == 1) ? 2 : 3;
```

is equivalent to

```c
if (x == 1)
    return 2;
else
    return 3;
```

### bit operation

operator | description | example
:---: | :---: | :---:
 ~a  | invert | ~(00) = 11
a & b | and | 01 & 11 = 01
a \| b | or | 01 | 11 = 11
a ^ b | xor | 01 ^ 11 = 10
 << | left shift | 10 << 1 = 100
>> | right shift | 10 >> 1 = 1

you can use `<<` to quickly double an `int`

### comma

```c
for (i = 0;  i < 10; i++)
...
for (i = 0; i < 10; i++, j++)
```

---

## Preprocess

MACRO

```c
#define DAYS_OF_THE_WEEK 7
...
printf("There are %i days in a week\n", DAYS_OF_THE_WEEK);
```

```c
#define ADD_ONE(x) ((x) + 1)
...
printf("The answer is %i\n", ADD_ONE(3));
```

Preprocessor will replace MACRO with its value before the source file is compiled.

### conditional compilation

```c
#ifdef SPANISH // if MACRO SPANISH exist
char *greeting = "Hola";
#else
char *greeting = "Hello";
#endif
```

---

## keyword `static`

```c
int count = 0;
int counter()
{
    return ++count;
}
```

```c
int counter()
{
    static int count = 0;
    return ++ count;
}
```

`static` makes `count` editable only in the `counter()` function.
In the other word, `count` cannot be changed between two `counter()` calls, otherwise you will get an error during compilation.

### private var or fx

if you use `static` outside the function, it means "only the functions in this `.c` file have access to this `var` or `fx`"

```c
static int days = 365;

static void update_account(int x){
    ...
}
```

---

## Size of defferent data type

`<limits.h>`

```c
#include <stdio.h>
#include <limits.h>

int main()
{
  printf("On this machine an int takes up %lu bytes\n", sizeof(int));
  printf("And ints can store values from %i to %i\n", INT_MIN, INT_MAX);
  printf("AND shorts can store values from %i to %i\n", SHRT_MIN, SHRT_MAX);
  return 0;
}
```

```c
U(unsigned)
S(signed)
L(long)

INT(int)
SHRT(short)
LONG(long)
CHAR(char)
FLT(float)
DBL(double)

_MAX
_MIN
```

---

## Automated testing

[AceUnit](http://aceunit.sourceforge.net/projects/aceunit)

[shunit2](http://code.google.com/p/shunit2/)

---

## gcc

### optimization

opt | description
:-: | :-:
-O  | optimization level 1
-O2 | optimization level 2 (slower compiling)
-O3 | optimization level 3 (slower compiling)
-Ofast| highest optimization level (slowest compiling speed)

### warning

`-Wall` (All Warnings)

For some reasons `-Wall` will not show all warnings. You have to add `-Wextra`.

```c
gcc fred.c -Wall -Wextra -o fred
```

To proceed a strict compile, one may use `-Werror` so that the compile fails once there is an error.

```c
gcc fred.c -Werror -o fred
```

---

## make

### var

var can make your makefile shorter.
You can define a set of std cmd to pass to gcc as a var.

```c
CFLAGS = -Wall -Wextra -v

fred: fred.c
  gcc fred.c $(CFLAGS) -o fred
```

use `=` to define var
use `$()` to access the var

### %, ^, @

```c
fred: fred.c
  gcc fred.c -Wall -o fred
```

```c
%: %.c
  gcc $^ -Wall -o $@
```

`%: %.c` : create `%` depends on `%.c`
`$^` : dependencies
`$@` : target name

### implicit rules

even if you don't have a makefile
you can compile a source code like

```c
> make fred
cc fred.c -o fred
```

cc is another name for gcc

[more about `make`](http://www.gnu.org/software/make/)

---

## develop tools

### gdb

`gdb` (GNU Project Debugger) allows one to analyze the code during its execution.
[more info](http://sourceware.org/gdb/download/onlinedocs/gdb/index.html)

### gprof

`gprof` (GNU Profiler) gives info about which part of the program processes most slowly.
[more info](http://sourceware.org/binutils/docs/gprof)

### gcov

`gcov` (GNU Coverage) tells you which part of your code was executed and which wasn't.

[more info](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html)

---

## Create GUI

Linux - GTK

[GTK+](http://www.gtk.org/)

Windows

[Windows API](http://www/winprog.org/tutorial)

Mac - Carbon

[Cocoa / #C](http://www.bignerdranch.com)

---

## Reference

P552
...
