/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:06 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/30 00:28:07 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt(t_minishell *cmd)
{
	cmd->args_temp = readline("Minishell → ");
	while (cmd->args_temp && cmd->args_temp[0] == '\0')
	{
		free(cmd->args_temp);
		cmd->args_temp = readline("Minishell → ");
	}
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
	auto t_list *args = list; //pode mudar isso? -> t_list *args; / args = list; ??
	auto char **split;
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
