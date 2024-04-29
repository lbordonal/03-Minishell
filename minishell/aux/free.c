/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:26:44 by root              #+#    #+#             */
/*   Updated: 2024/04/29 14:32:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_splited(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_program(t_minishell *cmd)
{
	if (cmd->args_temp)
		free(cmd->args_temp);
	if (cmd->path)
		free_splited(cmd->path);
	if (cmd->tokens)
		free_list(cmd->tokens, &free);
	if (cmd->export)
		free_list(cmd->export, &free);
	if (cmd->env)
		free_list(cmd->env, &free);
}

void	free_list(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = (lst)->next;
		ft_lstdelone(lst, del);
		lst = temp;
	}
	lst = NULL;
}
