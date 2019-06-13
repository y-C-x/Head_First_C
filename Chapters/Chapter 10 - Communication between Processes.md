# Chapter 10 - Communication between Processes

## Stream

| # | stream  
|:-:| :----:
| 0 | keyboard - stdin
| 1 | screen - stdout
| 2 | screen - stderr
| 3 | SQL

### Redirection

```c
./myprog > output.txt 2> errors.log
```

### `fileno()`

`fileno()` returns the descriptor.

```c
FILE *my_file = fopen("guitar.mp3","r");
```

---
| # | stream  
|:-:| :----:
| 0 | keyboard - stdin
| 1 | screen - stdout
| 2 | screen - stderr
| 3 | SQL
| 4 | guitar.mp3
---

```c
int descriptor = fileno(my_file); // will return 4
```

Note  
`fileno()` will not return `-1` even if it fails.

### `dup2()`

`dup2()` duplicates one stream to another.

```c
dup2(4,3)
```

---
| # | stream
|:-:| :----:
| 0 | keyboard - stdin
| 1 | screen - stdout
| 2 | screen - stderr
| 3 | ~~SQL~~ (guitar.mp3)
| 4 | guitar.mp3
---

### `waitpid()`

```c
#include <sys/wait.h>
...
int pid_status;
if (waitpid(pid, &pid_status,0) == -1 ) {
  error("Error when waiting for child");
}
```

\* `error()` is included in *chapter 9*.

```c
waitpid(pid, pid_status, options);
```

* `pid`
* `pid_status` - stores the process exit info, has to be a pointer
* `options` - `0`: wait for `pid` to end

you can type in `man waitpid` to look for help.

#### newshound2.c

## PIPE

```c
> ./child | ./parent
```

```c
int fd[2];
if (pipe(fd) == -1)
{
  error("Can't create the pipe");
}
```

---
| # | stream
|:-:| :----:
| 0 | stdin
| 1 | stdout
| 2 | stderr
| 3 | pipe read - `fd[0]`
| 4 | pipe write - `fd[1]`
---

### child

---
| # | stream
|:-:| :----:
| 0 | stdin
| 1 | ~~stdout~~ (pipe write)
| 2 | stderr
| 3 | ~~pipe read~~
| 4 | pipe write
---

```c
close(fd[0]);
dup2(fd[1],1);
```

### parent

---
| # | stream
|:-:| :----:
| 0 | ~~stdin~~ (pipe read)
| 1 | stdout
| 2 | stderr
| 3 | pipe read
| 4 | ~~pipe write~~
---

```c
dup2(fd[0],0);
close(fd[1]);
```

## Signal

include `<signal.h>`

---
signal | fx
:-:| :-:
SIGURG | do nothing
SIGINT | call `exit()`
---

### `sigaction`

`sigaction` is a `struct`

```c
struct sigaction action;
action.sa_handler = diediedie;
sigemptyset(&action.sa_mask);
action.sa_flags = 0;
```

```c
void diediedie(int sig)
{
  ...
  exit(1);
}
```

Use `sigaction()` to register `sigaction`

```c
sigaction(signal_no, &new_action, &old_action);
```

sample

```c
int catch_signal(int sig, void (*handler)(int))
{
  struct sigactionaction;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flag = 0;
  return sigaction (sig, &action, NULL);
}
...
catch_signal(SIGINT, diediedie)
```

### greetings.c

### SIGxxx

signal | fx
:--: | :--:
SIGINT | break the process
SIGQUIT | stop the process and store the content in the register to the core dump file
SIGFPE | float point error
SIGTRAP | how far has the process reached
SIGSEGV | segmentation fault
SIGWINCH | cmd window's size change
SIGTERM | some one ask to terminate teh process
SIGPIPE | writing to a pipe unread
SIGKILL | kill the process under all circumstance
...|...

#### kill

`kill` will send `SIGTERM` by default,
but it can alos send

```c
kill -INT
kill -SEGV
kill -KILL
```

### `raise()`

`raise(SIGTERM)`
send a signal to the process itself, whic is called *signal upgrade*

```c
alarm(120);
do_sth();
```

```c
catch_signal(SIGALRM, pour_coffee);
```

#### math_master.c

### Reset and Ignore

```c
catch_signal(SIGTERM, SIG_DFL); // reset
catch_signal(SIGINT, SIG_IGN); // ignore
```
