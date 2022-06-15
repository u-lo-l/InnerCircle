/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:45:29 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/16 01:24:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/minishell.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

t_input	*read_command(char *prompt)
{
	t_input	*input;
	char	*trimed_input;
	char	*colored_prompt;
	char	*temp;
	
	input = ft_calloc(1, sizeof(t_input));
	temp = ft_strjoin("\033[1;3;33m", prompt);
	colored_prompt = ft_strjoin(temp, " > \033[0m");
	input->cmd = readline(colored_prompt);
	free(temp);
	free(colored_prompt);
	if (input->cmd == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		free(input);
		input = NULL;
	}
	else
	{
		add_history(input->cmd);
		trimed_input = ft_strtrim(input->cmd, "\t ");
		free(input->cmd);
		input->cmd = trimed_input;
	}
	return (input);
}

void	free_input(t_input *input)
{
	if (!input)
		return ;
	free(input->cmd);
	free(input);
}
