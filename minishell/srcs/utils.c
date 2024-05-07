/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:06 by lbordona          #+#    #+#             */
/*   Updated: 2024/05/07 03:24:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt(t_minishell *cmd)
{
	cmd->args_temp = readline("Minishell → ");
	add_history(cmd->args_temp);
	while (cmd->args_temp && cmd->args_temp[0] == '\0')
		free(cmd->args_temp);
	if (!cmd->args_temp)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	check_input(cmd);
}

void	check_input(t_minishell *cmd)
{
	char	**temporary;

	temporary = ft_split_new(cmd->args_temp, '|');
	cmd->tokens = init_tokens(temporary);
	cmd->pipes = ft_lstsize(cmd->tokens);
	runner(cmd);
}

void	print_list_env(t_list *list)
{
	t_list	*temporary;

	temporary = list;
	while (temporary != NULL)
	{
		printf("%s\n", ((t_env *)(temporary->content))->info);
		temporary = temporary->next;
	}
}

int	ft_is_builtin(char *args)
{
	if (ft_strcmp(args, "echo") == 0)
		return (1);
	else if (ft_strcmp(args, "pwd") == 0)
		return (1);
	else if (ft_strcmp(args, "cd") == 0)
		return (1);
	else if (ft_strcmp(args, "env") == 0)
		return (1);
	else if (ft_strcmp(args, "exit") == 0)
		return (1);
	return (0);
}

char	**separate_path(t_list *list)
{
	t_list *args;
	char **split;

	args = list;
	while (args)
	{
		if (!ft_strcmp(((t_env *)(args->content))->name, "PATH"))
		{
			split = ft_split(((t_env *)(args->content))->info, ':');
			return (split);
		}
		args = args->next;
	}
	return (NULL);
}
