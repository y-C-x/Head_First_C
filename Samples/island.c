#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct island
{
	char *name;
	char *open;
	char *close;
	struct island *next;
} island;

island *create(char *name)
{
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->open = "09:00";
	i->close = "17:00";
	i->next = NULL;
	return i;
}

void display(island *start)
{
	island *i = start;
	for (; i != NULL; i = i->next)
	{
		printf("Name: %s \n Open: %s-%s\n", i->name, i->open, i->close);
	}
}

void release(island *start)
{
	island *i = start;
	island *next = NULL;
	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i->name);
		free(i);
	}
}

void main()
{
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;

	char name[80];

	for(; scanf("%s", name) == 1; i = next) // use scanf instead of fget to avoid reading carriage return
	{
		next = create (name);
		if (start == NULL)
		{
			start = next;
		}

		if (i != NULL){
			i -> next = next;
		}
	}

	display(start);
	release(start);
}