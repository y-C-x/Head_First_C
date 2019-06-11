# Chapter 5 - Struct, Union, Enum, Bit Field

## struct

* the size of a struct is fixed
* every variable in struct has a name

---

```c
struct fish{
  const char *name;
  const char *species;
  int teeth;
  int age
}

...

struct fish snappy = {
  "Snappy","Piranha",69,4
}
```

---
Use `"."` to access the variables in a `struct` ;

---

### Struct Nesting

```c
struct preferences{
  const char *food;
  float exercise_hours';
};

...

struct fish {
  ... // same as above
  struct preferences care;
}

struct fish snappy = { "Snappy","Piranha",69,4, {"Meat",7.5}};
```

### typedef

```c
typedef struct cell_phone{ // struct name
  int cell_no;
  const char *wallpaper;
  float minutes_of_charge;
} phone; // nickname

...
phone p = {1,"x.png",1.35};
```

---

### turtle.c

struct pointer

```c
void happy_birthday(turtle *t){...}
...

turtle t = myrtle;
happy_birthday(&myrtle)
```

#### （*t).age vs. *t.age

`(*t).age == t -> age`

---
---

## Union

```c
typedef union{
  short count;
  float weight;
  float volume;
} quantity;
```

the size of quantity = max size of count, weight, volumn

---

**IMPORTANT**  
Union only stores one type of data.

---

### Initialization

```c
quantity q = {.weight = 1.5};
//============================//
quantity q;
q.volume = 3.7;
//============================//
quantity q = {4}; // will save to the first field
```

Sample

```c
typedef struct {
  const char *name;
  const char *country;
  quantity amount;
} fruit_order;

...

fruit_order apples = {"apples","England",.amount.weight = 4.2};
```

**IMPORTANT**  
`union` has to be initialized in the same line once it is declared. Otherwise, the compiler will treate it as an `array` instead of a `union`.

For example, you cannot write as follow,

```c
margarita m;
m = {2.0, 1.0, {0.5}};
```

---
---

## Enum

```c
enum colors {RED, GREEN, PUCE};
...
enum colors favorite = PUCE;
```

### enumtest.c

---
---

## Bit Field

```c
typedef struct{
  unsigned int low_pass_vcf: 1;
  // use only one bit to store the data
}
```

number of bit is determined by the range or need
of the var.
