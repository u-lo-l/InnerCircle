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
		line = readline("PROMPT");
		if (strcmp(line, "q") == 0)
		{
			free(line);
			break;
		}
		else
		{
			printf("%s\n", line);
			free(line);
		}
	}
	return (EXIT_SUCCESS);
}
