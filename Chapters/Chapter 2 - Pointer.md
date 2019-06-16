# Chapter 2 - Pointer

## Structure

```c
From top to bottom
Stack -> Heap -> Global -> Constant -> Code
```

## Address

```c
int main()
{
    int x = 4;
    puts("x is stored at %p", &x);
    return 0;
}
```

Use `%p` to format the `address`

Note

* C pass by value
* Reference and deReference
* Local variable is stored at stack

### Varaiable

```C
void go_south_east(int* lat, int* lon)
{
    *lat -= 1;
    *lon -= 1;
}

int main()
{
    int lat = 32;
    int lon = -64;

    go_south_east(int, lon);
    puts("Current Location: [%i,%i]", lat, lon);
    return 0;
}
```

### String

```C
void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n",msg);
    printf("msg occupies %i bytes\n",sizeof(msg));
}
int main()
{
    char quote[] = "Cookies make you fat";
    fortune_cookie(quote);
}
```

计算机会为字符串的每一个字符以及结束字符\0在栈（stack）上
分配空间，并把`首字符的地址`和quote的变量关联起来，
代码中只要出现这个quote变量，计算机就会把他替换成字符串
`首字符的地址`。

``` C
quote[0] = *quote;
quote[2] = *(quote + 2);
```

IMPORTANT

* `数组变量`可以被用作`指针`
* `sizeof(msg)` 返还的是`指针`的大小 - 8 bytes (x64)
* `sizeof(quote)`返还的是`数组`的大小 - 15

#### 指针退化 - Pointer Degeneration

`数组`变量和`指针`变量有一点小小的区别，所以把数组赋给指针时千万要小心。假如把数组赋给指针变量，指针变量值会包含数组的地址信息，而对数组的长度一无所知，相当于指针丢失了一些信息。我们把这种信息的丢失称为`退化`。  
只要把数组传递给函数，数组免不了退化为指针，但需要记清楚代码中有哪些地方发生过数组退化，因为它们会引发一些不易察觉的错误。

When you pass `char s[]` into a function, it degenerates to a pointer which points to the address of first char in `s[]`.

#### 指针类型 - Pointer Type

因为不同类型的数据的大小不一样。

Different type of data have different size.


Note

```c
int does[] = {1,2,3,1000};
...
does[3] == *(does+3) == *(3+does) == 3[does]
```

#### Scanf() / fgets()

```c
int age;
printf("Enter your age: ");
scanf("%i",age);
```

```c
char first_name[20];
char last_name[20];
printf("enter first and last name: ");
scanf("%19s, %19[^\n]",first_name, last_name);
```

Note

```c
%19[^\n] // read the rest of the line
```

IMPORTANT

the size of string in `scanf` should be specified to avoid buff leak.

```c
char food[5];
printf("enter favorite food: ");
fgets(food, sizeof(food), stdin);
```

Note  

* `fgets()` will read in `CR`.
* `scanf()` will stop reading once it meets a `space`.

#### Literal String

```c
char *cards = "JQK"; // stored in const
```

"JQK" is stored in `CONST` area, which is `read only`.

```c
char cards [] = "JQK"; // sotred in heap
```

Length of the `char array` is not given, has to be specified immediately when the `char cards[]` is initialiated.

```c
void stack_deck(char cards[])
{
    ...
}

void stack_deck(char *cards)
{
    ...
}
```

`cards` is delcared in function and thus is `pointe`.
(The functions above are equivalent).

Note

You can use

```c
const char *s = "some string";  
```

to create a literal string, and get notice during compiling if someone trys to modify the literal string.

Note

when you create a string using

```c
char *s = "some string";
```

computer has no idea pointer `s` is pointing to a literal string.
