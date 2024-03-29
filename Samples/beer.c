// gcc beer.c -lpthread -o beer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int beers = 2000000;

void *drink_lots(void *a)
{
	int i;
	for (i = 0; i < 100000; i++)
	{
		beers -= 1;
	}
	return NULL;
}

int main()
{
	pthread_t threads[20];
	int t;
	printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
	for (t = 0; t < 20; t++)
	{
		pthread_create(&threads[t], NULL, drink_lots, NULL);
	}
	void *result;
	for (t = 0; t < 20; t++)
	{
		pthread_join(threads[t], &result);
	}
	printf("There are now %i bottles of beer on the wall\n", beers);
	return 0;
}