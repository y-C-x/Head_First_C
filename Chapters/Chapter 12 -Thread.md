# Chapter 12 - Thread

Cons of `process`

* creating `process` takes time
* inconvenient to share data
* `process` takes lenthy code

## thread

```c
#include <pthread.h>
```

```c
void* does_not(void *a);
void* does_too(void *a);
...
pthread_t t0;
pthread_t t1;

pthread_create(&t0, NULL,does_not,NULL);
pthread_create(&t1, NULL, does_too, NULL);

void* result;
pthread_join(t0, &result);
pthread_join(t1, &result);
```

argument.c

```c
> gcc argument.c -lpthread -o argument
```

### mutual exclusion lock

```c
pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;
```

Note  
`PTHREAD_MUTEX_INITIALIZER` is a macro.

```c
pthread_mutex_lock(&a_lock);
/*
  shared code starts here
*/
pthread_mutex_unlock(&a_lock);
```

#### param_test.c & beer.c

...

#### Dead lock

---

[More about Thread](https://www.cnblogs.com/mq0036/p/3710475.html)
