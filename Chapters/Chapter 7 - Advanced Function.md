# Chapter 7 - Advanced Function

## Function Pointer

Once you create a function in C, you create a `function pointer` which is stored in `constant`.

Note  
C does not has function type.

```c
int go_to_warp_speed(int speed)
{
  ...
}

int (*warp_fn) (int);
warp_fn = go_to_warp_speed;
warp_fn(4);

char** album_names(char *artist, int year)
{
  ...
}

char** (*name_fn) (char*,int)
name_fn = album_names;
char** result = names_fn("Sacha Distel",1972);
```

---

### find.c

---

## qsort

```c
qsort(void *array, size_t length, size_t item_size, int (*compar)(const void *, const void *));
// void can be used to represent any kind of data type
```

`qsort()` will return  
pos - A > B  
neg - A < B  
0 - A == B

### Compare Method

---

#### sort in ascending order

```c
int compare_score(const void* score_a, const void* score_b)
{
  int a = *(int*) score_a;
  int b = *(int*) score_b;
  return a - b;
}
```

#### sort in descending order

```c
int compare_score_desc(const void* score_a, const void* score_b)
{
  compare_score(b,a);
}
```

#### sort according to rect area

```c
typedef struct{
  int width;
  int height;
} rectangle;

int compare_areas(const void* a, const void *b)
{
  rectangle* ra = (rectangle*) a;
  rectangle* rb = (rectangle*) b;
  int area_a = (ra -> width * ra -> height);
  int area_b = (rb -> width * rb -> height);
  return area_a - area_b;
  }
```

#### sort alphabetically 

```c
int compare_names(const void* a, const void* b)
{
  char** sa = (char**)a;
  char** sb = (char**)b;
  return strcmp(*sa,*sb);
}
```

---

**`qsort()` sample**

```c
int main()
{
  int scores[] = {1,9,3,5,6,3};
  int i;
  qsort(scores,7,sizeof(int),compare_scores_desc);
  puts("These are the scores in order:");
  for (i = 0; i < 7; i++)
  {
    printf("Score = %i\n", scores[i]);
  }

  char *names[] = {"Karen","Mark","Brett","Molly"};
  qsort(names, 4, sizeof(char*), compare_names);
  puts("These are the names in order:");
  for (i = 0; i < 4, i++){
    printf("%s\n", names[i]);
  }

  return 0;
}
```

Note  
`qsort()` will modify the original array.

p334