#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

#define TRUE 1

int main()
{
	char *line;

	while (TRUE)
	{
		line = readline("PROMPT > ");
		if (line == NULL)
		{
			printf("\b\bexit\n");
			free(line);
			break;
		}
		else
		{
			add_history(line);
			printf("%s\n", line);
			free(line);
		}
	}
	return (EXIT_SUCCESS);
}
