#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char const *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void *exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

char *ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (!(copy = (char*)malloc(sizeof(*copy) * (ft_strlen(str) + 1))))
		return (exit_fatal_ptr());
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

//명령어 전달인자 문자열 배열에 
int add_arg(t_list *cmd, char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char**)malloc(sizeof(*tmp) * (cmd->length + 2))))
		return (exit_fatal());
	while (i < cmd->length)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i++] = ft_strdup(arg);
	cmd->args[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}

//리스트에 노드 하나 추가. 리스트가 없다면 이게 첫 노드가 되
int list_push(t_list **list, char *arg)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (exit_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->previous = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->previous = *list;
	}
	*list = new;
	return (add_arg(new, arg));
}

// 가장 첫 노드로 돌아가기
int list_rewind(t_list **list)
{
	while (*list && (*list)->previous)
		*list = (*list)->previous;
	return (EXIT_SUCCESS);
}
// 리스트 메모리 해제하기
int list_clear(t_list **cmds)
{
	t_list	*tmp;
	int		i;

	list_rewind(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->length)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
	return (EXIT_SUCCESS);
}
  
int parse_arg(t_list **cmds, char *arg)
{
	int	is_break;

	is_break = (strcmp(";", arg) == 0);
	if (is_break && !*cmds)
		return (EXIT_SUCCESS);
	// ;가 아니며, 첫 명령어이거나 파이프 일 ㄸ
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return (list_push(cmds, arg));
	else if (strcmp("|", arg) == 0)			// pipe
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)						//semicolone
		(*cmds)->type = TYPE_BREAK;
	else
		return (add_arg(*cmds, arg));
	return (EXIT_SUCCESS);
}
#include <stdio.h>
void print_list(t_list *cmds)
{
	t_list	*curr;

	if (!cmds)
		return ;
	list_rewind(&cmds);
	curr = cmds;
	while (curr != NULL)
	{
		printf("Type : ");
		switch (curr->type)
		{
			case 0 :
				printf("END\n");
				break ;
			case 1 :
				printf("PIPE\n");
				break ;
			case 2 :
				printf("BREAK\n");
				break ;
			default :
				printf("else\n");
				break ;
		}
		printf("Cmd length : %d\n", curr->length);
		printf("cmd : ");
		for (int i = 0 ; i < curr->length ; i++)
			printf("<%s> ", curr->args[i]);
		printf("\npipe->[%02d,%02d]\n", curr->pipes[0], curr->pipes[1]);
		curr = curr->next;
	}
}

int exec_cmd(t_list *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	// 현재 타입이 파이프이거나, 이전 타입이 파이프였다면 파이프를 오픈한다.
	if (cmd->type == TYPE_PIPE || (cmd->previous && cmd->previous->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0) //자식 프로세스
	{
		// 현재 타입이 파이프인데 dup2에 실패하면 exit fatal
		// 현재 타입이 파이프라는 것은 현재 출력을 다음 표준입력으로 연결하는 것
		// 따라서 pipe[stdin]을 stdout으로 연결해준다.
		if (cmd->type == TYPE_PIPE
			&& dup2(cmd->pipes[SIDE_IN], STDOUT) < 0)
			return (exit_fatal());
		// 이전 타입이 파이프인데 dup2에 실패하면 exit fatal
		// 이전 타입이 파이프라는 것은 이전 출력을 현재 입력으로 연결하는 것
		// pipe[stdout]을 stdin으로 연결해준다.
		if (cmd->previous && cmd->previous->type == TYPE_PIPE
			&& dup2(cmd->previous->pipes[SIDE_OUT], STDIN) < 0)
			return (exit_fatal());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else //부모 프로세스
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[SIDE_IN]);
			// 다음 타입이 브레이크라면 출력 파이프도 닫는다.
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[SIDE_OUT]);
		}
		// 이전 타입이 파이프였으면 이전 명령의 출력 파이프를 닫는다.
		if (cmd->previous && cmd->previous->type == TYPE_PIPE)
			close(cmd->previous->pipes[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int exec_cmds(t_list **cmds, char **env)
{
	t_list	*crt;
	int		ret;

	ret = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds)
	{
		crt = *cmds;
		// 첫 명령어가 cd이면 cd빌트인을 실행하고, 아니면 execve 실행
		if (strcmp("cd", crt->args[0]) == 0)
		{
			ret = EXIT_SUCCESS;
			if (crt->length < 2)
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				ret = show_error("error: cd: cannot change directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(crt, env);
		*cmds = (*cmds)->next;
	}
	return (ret);
}

int main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	print_list(cmds);
	list_clear(&cmds);
	if (TEST)
		while (1);
	return (ret);
}
