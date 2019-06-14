#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int score = 0;
int count = 0;

void end_game(int sig)
{
	printf("\nFinal score: %i / %i\n", score, count);
	exit(0);
}

void p_add(int a, int b)
{
	printf("\nWhat is %i plus %i? ", a, b);
}

void p_sub(int a, int b)
{
	printf("\nWhat is %i minus %i? ", a, b);
}

void p_mut(int a, int b)
{
	printf("\nWhat is %i times %i? ", a, b);
}

void p_div(int a, int b)
{
	printf("\nWhat is %i divided by %i? ", a, b);
	if (b == 0)
		printf("\nWoops, SYS ERROR, you earn a lucky point: ");
}

int v_add(int a, int b, int answer)
{
	return answer == (a + b);
}
int v_sub(int a, int b, int answer)
{
	return answer == (a - b);
}
int v_mut(int a, int b, int answer)
{
	return answer == (a * b);
}
int v_div(int a, int b, int answer)
{
	if (b == 0)
		return 1;
	return answer == (a / b);
}

void (*printAlgo[])(int, int) = {p_add, p_sub, p_mut, p_div};

int (*eval[])(int, int, int) = {v_add, v_sub, v_mut, v_div};

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

void times_up(int sig)
{
	puts("\nTIME'S UP!");
	raise(SIGINT);
}

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int main()
{
	catch_signal(SIGALRM, times_up);
	catch_signal(SIGINT, end_game);
	srandom(time(0));

	count = 0;

	alarm(30);
	puts("Your 30s begins");
	while (1)
	{
		int a = random() % 11;
		int b = random() % 11;
		char txt[4];

		int algoNo = random() % 4;
		(printAlgo[algoNo])(a, b);

		++count;
		// alarm(5);

		fgets(txt, 4, stdin);
		int answer = atoi(txt);

		if ((eval[algoNo])(a, b, answer))
			++score;
		else
			printf("Wrong!\n");
	}
	return 0;
}
