#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void diediedie(int sig)
{
	puts("\nGoodbye cruel world...");
	exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig,&action,NULL);
}

int main()
{
	if (catch_signal(SIGINT,diediedie) == -1){
		fprintf (stderr, "Can't map the handler");
		exit(2);
	}
	char name[30];
	printf("Enter your name: ");
	fgets(name, 30, stdin);
	printf("Hello %s", name);
	return 0;
}