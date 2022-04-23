#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*thread(void *vargp)
{
	int i = 0;
	char *str = malloc(sizeof(char) * 4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 0;
	if (vargp == 0)
		printf("%d%s\n", i, str);
	free(str);
	return (NULL);
}

int main()
{
	pthread_t	pid;
	pthread_create(&pid, NULL, thread, NULL);
	pthread_detach(pid);
	sleep(1);
	void *res = NULL;
	// pthread_join(pid, &(res));
	if (res == NULL)
		printf("null\n");
	else
	printf("res %d\n", *(int *)res);
}
