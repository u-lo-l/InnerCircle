#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	int status;
	
	if (fork() == 0)
	{
		execve(argv[1], argv + 1, NULL);
		printf("child1\n");
		exit (1);
	}
	else
		wait(&status);
	chdir("../");
	printf("ha..\n");
	if (fork() == 0)
	{
		execve(argv[1], argv + 1, NULL);
		printf("child2\n");
		exit (1);
	}
	else
		wait(&status);
}
