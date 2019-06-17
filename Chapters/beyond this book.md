# Go Further

## Operator

### inc and dec

```c
++i; // inc 1 and return the new i
i++; // inc 1 and return the old i
```

same for `--i` and `i--`

### ternary conditional operator

```c
return (x == 1) ? 2 : 3;
```

is equivalent to

```c
if (x == 1)
    return 2;
else
    return 3;
```

### bit operation

operator | description | example
:---: | :---: | :---:
 ~a  | invert | ~(00) = 11
a & b | and | 01 & 11 = 01
a \| b | or | 01 | 11 = 11
a ^ b | xor | 01 ^ 11 = 10
 << | left shift | 10 << 1 = 100
>> | right shift | 10 >> 1 = 1 

you can use `<<` to quickly double an `int`
