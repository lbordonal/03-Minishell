/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 23:35:14 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	door(t_list *token, char *temp, t_minishell *cmd)
{
	t_list	*args;

	args = token;
	add_history(temp);
	while (args != NULL)
	{
		if (ft_strcmp(((t_token *)(args->content))->args[0], "echo") == 0)
			echo_cmd(((t_token *)(args->content))->args);
		else if (ft_strcmp(((t_token *)(args->content))->args[0], "pwd") == 0)
			pwd_cmd(cmd);
		else if (ft_strcmp(((t_token *)(args->content))->args[0], "cd") == 0)
			cd_cmd(((t_token *)(args->content))->args[1]);
		else if (ft_strcmp(((t_token *)(args->content))->args[0], "env") == 0)
			print_list_env(cmd->env);
		else if (ft_strcmp(((t_token *)(args->content))->args[0], "exit") == 0)
			exit_cmd(cmd);
		args = args->next;
	}
}

void	init_fun(t_minishell	*cmd, char **sys_env)
{
	cmd->env = init_env(sys_env);
	cmd->export = init_export(sys_env);
}

int	main(int ac, char **av, char **sys_env)
{
	t_minishell	cmd;

	(void)av;
	if (ac > 1)
	{
		printf("Error → Entry should be: ./minishell ");
		printf("and shouldn't contain any arguments.\n");
	}
	else
	{
		while (1)
		{
			init_fun(&cmd, sys_env);
			print_prompt(&cmd);
		}
	}
	return (0);
}
