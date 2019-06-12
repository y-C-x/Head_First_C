# Chapter 9 - Process and System

if you have any question, go through the chapter in the book. 

## `system()`

### guard_log.c

---

**Kernel** - Process, Register, Hardware

`system()` is used to commute between `kernel` and `process` (P403)

---

## `exec()`

`PID` - process identifier

require `<unistd.h>`

### `execl()`, `execlp()`, `execle()`

---

arguments for `exec()`

* Program - path
* cmd argument - same as previous
* NULL - end sign of arguments
* Environment Variable

---

`l` : argument list  
`v` : argument vector  
`p` : search according to PATH  // search automatically  
`e` : environment var

`exec...` = `exec` + `l` / `v` + (`p` + `e`)

#### `getenv()`

```c
char *my_env[] = {"JUICE=peach and apple",NULL};

execle("dinner_info", "dinner_info", "4", NULL, my_env)'
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Dinners: %s\n", argv[1]);
  printf(Juice: %s\n", getenv("JUICE"));
  return 0;
}
```

---

## errno

### errno.h

```c
fprintf(stderr, "Error: %s", strerror(errno));
```

---

**IMPORTANT**  
Once you call the `exec()`, system will run a new program and terminate your current program. Which means `exec()` is the last line of the program.

---

## `fork()`

```c
pid_t pid = fork();

if (pid == -1){
  return 1;
}

if(!pid){
  execle(...);
  return 1;
}
```

---

## RSS (skip here)