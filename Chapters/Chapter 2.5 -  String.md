# Chapter 2.5 - More about String

## an Array of an Array

```c
char tracks[][80] = {
    "...","...","..."
}
```

## string.h

Popular function:

```c
1. strchr() // search char in str
2. strcmp() // cmp strs
3. strstr() // search str in str
4. strcpy() // make a copy of str
5. strlen() // return the length of the str
6. strcat() // connet strs;
```

### strstr()

```c
strstr("dysfunctional","fun");
```

Note

`strstr(str1,str2)` will return the `address` of the `str2` in the register.

### Arrary of Pointer & Pointer of Array
