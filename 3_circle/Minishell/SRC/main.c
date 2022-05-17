#include "../INC/minishell.h"
#include <stdlib.h>

int main()
{
	char *command_line;
	
	while (1)
	{
		command_line = read_command("vv MINISHELL vv\n> ");
		free(command_line);
	}
	return (0);
}