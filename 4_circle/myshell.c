#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#define	FALSE 0
#define	TRUE 1
#define STDIN 0
#define	STDOUT 1
#define STDERR 2

typedef struct s_simplecmd
{
	char				**argv;
	int					size;
	int					pipe;
	int					fd[2];
	struct s_simplecmd	*next;
}	t_simplecmd;

typedef struct s_shell
{
	t_simplecmd	*head;
	t_simplecmd *tail;
	struct s_shell *next;
}	t_shell;

typedef struct s_totalcmd
{
	t_shell	*head;
	t_shell	*tail;
}	t_totalcmd;
/*=======ERROR=======*/
void		exit_fatal(void);
void		exit_execve(char *str);
void		exit_cd_badargs(void);
void		exit_cd_wrongarg(char  *str);
/*=======UTILS=======*/
int			ft_strlen(char *str);
char		*ft_strdup(char *str);

t_simplecmd	*create_simplecmd(char	**argv, int size);
void		free_simplecmd(t_simplecmd *cmd);

int			add_simplecmd_to_shell(t_shell *shell, t_simplecmd *cmd);
void		free_shell(t_shell *);

int			add_branch_to_totalcmd(t_totalcmd *tot, t_shell *shell);
void		free_totalcmd(t_totalcmd *tot);
/*=======PARSE=======*/
int			count_args(char **argv);
t_totalcmd	*parse_arg(char **argv);
void		print_tree(t_totalcmd *tot);
/*======EXECUTE======*/


/*========MAIN=======*/
int main(int argc, char **argv, char **envp)
{
	t_totalcmd *cmd = parse_arg(argv + 1);
	print_tree(cmd);
}
//ERROR
void	exit_fatal(void)
{
	char	*err = "error: fatal\n";
	write(STDERR, err, ft_strlen(err));
	exit(1);
}
void	exit_execve(char *str)
{
	char	*err = "error: cannot execve";
	write(STDERR, err, ft_strlen(err));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(2);
}
void	exit_cd_badargs(void)
{
	char	*err = "error: cd: bad arguments\n";
	write(STDERR, err, ft_strlen(err));
	exit(1);
}
void	exit_cd_wrongarg(char *str)
{
	char	*err = "error: cd: cannot change directory to";
	write(STDERR, err, ft_strlen(err));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(1);
}

//UTILS
int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len]);
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	write(2, "strduping\n", ft_strlen("strduping\n"));
	int		len = ft_strlen(str);
	printf("len : %d\n", len);
	char	*dup = malloc(len + 1);
	if (dup == NULL)
		exit_fatal();
	for (int i = 0 ; i <= len; i++)
		dup[i] = str[i];
	write(2, dup, ft_strlen(dup));
	return (dup);
}


t_simplecmd	*create_simplecmd(char	**argv, int size)
{
	printf("creating simpcmd : %d\n", size);
	t_simplecmd	*cmd = malloc(sizeof(t_simplecmd));
	cmd->argv = malloc(sizeof(char *) * (size + 1));
	if (cmd == NULL)	return (NULL);
	int i = 0;
	printf("size : %d\n", size);
	while (i < size)
	{
		printf("i: %d | str: %s\n", i , argv[i]);
		cmd->argv[i] = malloc(2);
		cmd->argv[i][0] = 'a'

		cmd->argv[i][1] = '\0';
		i++;
	}
	printf("bye\n");
	cmd->argv[i] = NULL;
	cmd->size = size;
	cmd->pipe = 0;
	cmd->next = NULL;
	printf("simpcmd created\n");
	return (cmd);
}

void		free_simplecmd(t_simplecmd *cmd)
{
	if (!cmd)
		return ;
	if (!cmd->argv)
		return ;
	int	i = 0;
	while (cmd->argv[i])
		free(cmd->argv[i++]);
	free(cmd->argv);
	free(cmd);
}

int			add_simplecmd_to_shell(t_shell *shell, t_simplecmd *cmd)
{
	if (shell == NULL)		return (FALSE);
	if (shell->head == NULL)
		shell->head = cmd;
	if (shell->tail != NULL)
		shell->tail->next = cmd;
	shell->tail = cmd;
	return (TRUE);
}

void		free_shell(t_shell *shell)
{
	t_simplecmd *temp;
	t_simplecmd *next;
	if (!shell) return ;
	temp = shell->head;
	while (temp)
	{
		next = temp->next;
		free_simplecmd(temp);
		temp = next;
	}
	free (shell);
}

int			add_branch_to_totalcmd(t_totalcmd *tot, t_shell *shell)
{
	printf("adding branch\n");
	if (tot == NULL)		return (FALSE);
	if (tot->head == NULL)
		tot->head = shell;
	if (tot->tail != NULL)
		tot->tail->next = shell;
	printf("don3\n");
	tot->tail = shell;
	return (TRUE);
}

void		free_totalcmd(t_totalcmd *tot)
{
	if (!tot)	return;
	t_shell	*curr = tot->head;
	t_shell	*next;
	while (curr)
	{
		next = curr->next;
		free_shell(curr);
		curr = next;
	}
	free(tot);
}
//PARSE
int count_args(char **argv)
{
	int	i = 0;

	if (!argv)
		return (0);
	while (argv[i] != NULL)
	{
		if (!strcmp(argv[i], "|") || !strcmp(argv[i], ";"))
			break ;
		printf("\t<%s>\n", argv[i]);
		i++;
	}
	printf("arg cnt : %d\n", i);
	return (i);
}

t_totalcmd	*parse_arg(char **argv)
{
	t_totalcmd	*cmd = malloc(sizeof(t_totalcmd));
	if (!cmd)	return (NULL);
	int	cnt;
	int i = 0;
	if ((cmd->head = malloc(sizeof(t_shell))) == NULL)
	{
		free(cmd);
		exit_fatal();
	}
	while (argv[i])
	{
		if (!strcmp(argv[i], "|"))
		{
			t_shell	*newshell = malloc(sizeof(t_shell));
			add_branch_to_totalcmd(cmd, newshell);
			i += 1;
		}
		else if (!strcmp(argv[i], ";"))
		{	
			i += 1;
		}
		else
		{
			cnt = count_args(argv + i);
			t_simplecmd *tok = create_simplecmd(argv + i, cnt);
			i += cnt;
			add_simplecmd_to_shell(cmd->tail, tok);
			printf("\033[32m");
			print_tree(cmd);
			printf("\033[0m");
			printf("next : [%s]\n", argv[i]);
		}
	}
	return (cmd);
}

void	print_tree(t_totalcmd *tot)
{
	printf("=========tree==============\n");
	t_shell *curr = tot->head;
	int c = 1;
	while (curr)
	{
		printf("%d | ", c++);
		t_simplecmd	*cmd;
		cmd = curr->head;
		while (cmd)
		{
			for (int i = 0; cmd->argv[i]; i++)
				printf("%s ", cmd->argv[i]);
			cmd = cmd->next;
			printf(";");
		}
		printf("\n");
		curr = curr->next;
	}
}
