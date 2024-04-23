/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/23 12:14:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	door(char **args, t_minishell *cmd)
{
	if (ft_strcmp(args[0], "echo") == 0)
		echo_cmd(args);
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd_cmd();
	else if (ft_strcmp(args[0], "cd") == 0)
		cd_cmd(args[1]);
	else if (ft_strcmp(args[0], "env") == 0)
		print_list_env(cmd->env);
	else if (ft_strcmp(args[0], "exit") == 0)
		exit_cmd(cmd);
}

void	init_fun(t_minishell	*cmd, char **sys_env)
{
	cmd->env = init_env(sys_env);
	cmd->export = init_export(sys_env);
	cmd->pipes = 0;
	cmd->path = separate_path(cmd->env);
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
