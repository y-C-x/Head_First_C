# Chapter 3 - Tools

## geo2json.c

```c
./geo2json < gpsdata.csv > output.json
```

## stdin - stdout - stderr

```c
fprintf(stderr,"ERROR!\n");
```

Note

```c
char info [20];
fscanf(stdin,"%19s",info);
```

### Redirection

```c
> ./geo2json < gpsdata.csv 1> output.json 2> errors.txt
```

### secret_message.c

```c
>> ./secret_messages <secret.txt > message1.txt 2> message2.txt
```

```c
int main()
{
    char word[10];
    int i = 0;
    while(scanf("%9s",word) == 1){
        i = i + 1;
        if (i % 2)
            fprintf(stdout, "%s\n",word);
        else
            fprintf(stderr, "%s\n",word);
    }
    return 0;
}
```

## Pipe

```c
> (./bermuda | ./geo2json) < spook.csv > output.json
```

> multi pipes - > pipeliine

IMPORTENT

remember to include the brackets

## Stream

---

### fopen

use `fopen()` to create stream.

```c
FILE *in_file = fopen("input.txt","r");
FILE *out_file = fopen("output.txt","w");
```

"w" = write  
"r" = read  
"a" = append

---
SAFETY CHECK

```c
FILE *in;
if (!(in = fopen("sth.txt","r")))
{
  fprintf(stderr,"Can't open file.\n");
  return 1;
}
```

---

```c
fprintf(out_file,"%s,%s\n","1","2");
fscanf(in_file,"%79[^\n]\n",sentence);
```

### fclose

```c
fclose(in_file);
fclose(out_file);
```

Normally, a process can have at most 256 streams.

### categorize.c

```c
> ./categorize UFO aliens.csv Elvis elvises.csv the_rest.csv
```

search result of `UFO` goes to `aliens.csv`;  
search result of `Elvis` goes to `elvises.csv`;
the rest goes to `the_rest.csv`;

### cmd Option

```c
ps -ae
```

list all the processes, including the background ones.

#### getopt

```c
#include <unistd.h>

...

while((ch = getopt(argc, argv,"ae:")) != EOF)
{
  switch(ch){
    ...
    case 'e':
      engine_count = optarg;
    ...
  }
  // skip the optitions that have been read
  argc -= optind;
  argv += optind;
}
```

`:` means cmd `e` requires an argument;  
`optind` stores the number of options read from the `getopt()` cmd.  
`optarg` reads the required argument;

### order_pizza.c

```c
> ./order_pizza -d now -t Pineapple
```

IMPORTANT
One can use `--` in bash to break from the getopt()

for example

```c  
set_temperature -c -- -4
```
