# Chapter 6 - Data Structure & Heap (Linked List)

## Linked List

### tour.c

```c
typedef struct island{
  char *name;
  char* opens;
  char* closes;
  struct island *next;
} island;
```

## Heap

### malloc

```c
#include <stdlib.h>
...
island *p = malloc(sizeof(island));
```

---

**IMPORTANT**  
Go through the sample from P281

---

### strdup

```c
island* create(char *name)
{
  island *i = malloc(sizeof(island));
  i -> name = strdup(name); // instead of = name;
  i -> opens = "09:00";
  i -> closes = "17:00";
  return i;
}
```

Use `strdup` to avoid pointer issue.  
While using `name` to create new `island`, the
newly created islands will share the same `name` string.

### free

```c
void release(island *start)
{
  island *i = start;
  island *next = NULL;
  for (; i != NULL; i = next)
  {
    next = i -> next;
    free(i->name);
    free(i);
  }
}
```

---

## spies.c

go through this sample carefully (since P298)

### valgrind

```c
valgrind --leak-check=full ./spies
```
