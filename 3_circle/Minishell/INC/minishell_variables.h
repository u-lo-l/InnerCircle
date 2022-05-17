#ifndef MINISHELL_VARIABLES_H
# define MINISHELL_VARIABLES_H

typedef struct s_shell_env_type
{
	char					*name;
	char					*val;
	struct s_shell_env_type	*next;
}							t_shell_env;

typedef struct s_shell_var_type
{
	t_shell_env	*env_list;
}	t_shell_var;

#endif