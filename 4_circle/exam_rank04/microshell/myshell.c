#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char *	t_string;

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstrfd(int fd, char const *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) != 1)
			break ;
		i++;
	}
	return (i);
}

int	print_error(char const *err_string)
{
	ft_putstrfd(2, err_string);
	return (EXIT_FAILURE);
}

char	*ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (str == NULL);
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

int main(int argc, char **argv, char **envp)
{
	t_list	*input;
	int		i;
	int		res;

	res = EXIT_SUCCESS;
	int = 0;
	input = parse_command(argc);
	if (input == NULL)
		return (EXIT_FAILURE);
	ret = execute_command(input);
	free_list(input);
	return (ret);
}