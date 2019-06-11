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
>> ./geo2json < gpsdata.csv 1> output.json 2> errors.txt
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
>> (./bermuda | ./geo2json) < spook.csv > output.json
```

> multi pipes - > pipeliine

IMPORTENT

remember to include the brackets

## Stream

### fopen

use `fopen()` to create stream.

```c
FILE *in_file = fopen("input.txt","r");
FILE *out_file = fopen("output.txt","w");
```

"w" = write  
"r" = read  
"a" = append

```c
fprintf(out_file,"%s,%s","1","2");
fscanf(in_file,"%79[^\n]\n",sentence);
```
