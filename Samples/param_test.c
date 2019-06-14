// gcc param_test.c -lpthread -o param_test
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void *do_stuff(void *param)
{
	long thread_no = (long)param;
	printf("Thread number %ld\n", thread_no); // l for long
	return (void *)(thread_no + 1);
}

int main()
{
	pthread_t threads[3];
	long t;
	for (t = 0; t < 3; t++)
	{
		pthread_create(&threads[t], NULL, do_stuff, (void *)t);
	}
	void *result;
	for (t = 0; t < 3; t++)
	{
		pthread_join(threads[t],&result);
		printf("Thread %ld returned %ld\n", t, (long)result);
	}
	return 0;
}