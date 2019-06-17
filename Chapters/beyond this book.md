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
a & b | and | 01 & 11 =  