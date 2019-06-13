# Chapter 4 - Head File

## Data Type

* `char` - char is stored as char code: A == 65

* `int` - 16 bits; within 10 times thousands

* `short` - half size of `int`

* `long` - twice size of `int`; billions; 32 bits

* `float` - float point

* `double` - twice size of `float`; more precise

Note  
Try not to cast a bigger data type into a smaller one.

```c
int x = 100000;
short y = x;
printf("y = %hi\n",y); // %hi to format short

x <- 0001 1000 0110 1010 0000
y <- 1000 0110 1010 0000
```

---

```c
int x = 7;
int y = 2;
float z = x / y; // = 3.0000
float z = (float) x / (float) y; // = 3.5000
float z = (float) x / y; // = 3.5000
```

---

### unsigned & long

```c
unsigned char c; // range from 0 - 255
long double d; // longer...
```

---
---

## Head File (.h)

Seperate **Declaration** & **Implementation**

---

Note

When the compiler sees an unkown funciton, it assumes the return type is `int`

---

### Difference of `".h"` and `"<.h>"`

`".h"` means the .h file is under the same path as .c file

`<.h>` means the .h file is under the `stdlib`

### totaller.c

### Process of Compiling

1. Precompile  
   insert the relavant code in the #include file to the main source code.

2. Compiler
   translate to the assembly code.

3. Assembler
   translate the assembly code into object code
   which in the form of binary code.

4. Linker
   link the object codes to an executable file.

### message_hider.c encrypt.c

```c
gcc message_hider.c encrypt.c -o message_hider
```

---
---

## MakeFile

DO NOT RECOMPILE EVERYTHING

steps:

```c
> gcc -c *.c
> gcc *o -o launch
```

Target - Dependence - Rule

Sample:

```c
launch.o: launch .c launch.h thruster.h
    gcc -c launch.c

thruster.o: thruster.h thruster.c
    gcc -c thruster.c

launch: launch.o thruster.o
    gcc launch.o thruster.o -o launch
```
