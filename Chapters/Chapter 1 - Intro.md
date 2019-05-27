# Chapter 1 - Introduction

## cards.c

**Note**
``` 
gcc zork.c -o zork && ./zork
``` 
One can use the code above to run the program immediately after the sucessful compile. 

---
## Character Array
```c
s = "Shatner";
```
what stored in the register is 
```
S h a t n e r \0
```
which means you need
```C
char s[8];
```

**Note**  
* C does not know the length of the array.
* content included by quotes is called the string literal, which is ```CONSTANT```.
  
---
## For, While, do_While
**Note**
* you cann't use ```break``` to exit from ```if``` statement.
* ```continous``` vs. ```break```
* ```chain: (x = y = 0)```
