/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <lbordona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/04 12:10:04 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	door(char *input, t_minishell *cmd, char *temp)
{
	add_history(temp);
	if (ft_strcmp(input, "echo") == 0)
		echo_cmd(cmd);
	else if (ft_strcmp(input, "pwd") == 0)
		pwd_cmd(cmd);
	else if (ft_strcmp(input, "cd") == 0)
		cd_cmd(cmd);
	else if (ft_strcmp(input, "env") == 0)
		print_list_env(cmd->env);
	else if (ft_strcmp(input, "exit") == 0)
		exit_cmd(cmd);
	
}

int	main(int ac, char **av, char **sys_env)
{
	(void)av;

	if (ac > 1)
	{
		printf("Error → Entry should be: ./minishell ");
		printf("and shouldn't contain any arguments.\n");
	}
	else
	{
		t_minishell cmd;
		cmd.env = init_env(sys_env);
		cmd.export = init_export(sys_env);
		while (1)
		{
			print_prompt(&cmd);
		}
	}
	return (0);
}
