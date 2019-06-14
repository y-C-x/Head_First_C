/* problems happens here
rssgossip doesn't seem to work in this OS*/
/* 2019.05.30
Problem solved:
1. Add NULL at the end of the vars[].
2. USE a useable RSS source/
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int main(int argc, char *argv[])
{

	char *phrase = argv[1];
	// char *vars[] = {"RSS_FEED=http://rss.cnn.com/rss/edition.rss",NULL};
	char *vars[] = {"RSS_FEED=https://docs.microsoft.com/en-us/msdn-files/feeds/msdn/en-us/magazine/rss.xml", NULL};
	FILE *f = fopen("stories.txt", "w");
	if (!f)
	{
		error("Can't open stories.txt");
	}

	pid_t pid = fork();

	if (pid == -1)
	{
		error("Can't fork process");
	}

	if (!pid)
	{
		if (dup2(fileno(f), 1) == -1)
		{
			error("Can't redirect Standard Ouput");
		}
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
		{
			error("Can't run script");
		}
	}

	int pid_status;
	if (waitpid(pid, &pid_status, 0) == -1)
	{
		error("Error while waiting the child to end");
	}
	return 0;
}