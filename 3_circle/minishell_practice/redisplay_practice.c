#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main()
{
	char *line;

	int i = 1;
	while (i++)
	{
		line = readline("-> : ");
		if (line == NULL)
			break ;
		printf("line : %s\n", line);
		if (i % 2 == 1)
			rl_replace_line("haha", 0);
		rl_on_new_line();
		printf("====redisplay====\n");
		rl_redisplay();
		printf("\n=================\n");
		free(line);
	}
	return (0);
}
