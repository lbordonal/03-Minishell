/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:16:46 by root              #+#    #+#             */
/*   Updated: 2024/05/17 05:20:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	configure_fd(t_minishell *cmd)
{
	if (search_lst(cmd, cmd->tokens) == 1)
		change_fd(cmd, cmd->tokens);
}

void	change_fd(t_minishell *cmd, t_list *tokens)
{
	t_list	*args;

	cmd->pipes *= 1;
	args = tokens;
	while (args)
	{
		if (ft_checkspecial(((t_token *)(args->content))->args))
		{
			// handle_special(cmd, ((t_token *)(args->content))->args);
			return ;
		}
		args = args->next;
	}
}

void handle_special(t_minishell *cmd, char **string)
{
	if (!ft_strncmp(string[0], ">>", 3))
		appendredirection(cmd);
}