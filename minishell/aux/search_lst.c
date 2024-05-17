/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 03:52:04 by marvin            #+#    #+#             */
/*   Updated: 2024/05/15 03:52:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_checkspecial(char **str)
{
	if (!ft_strncmp(str[0], ">>", 2))
		return (2);
	if (!ft_strncmp(str[0], "<<", 2))
		return (2);
	if (!ft_strncmp(str[0], "<", 1))
		return (1);
	if (!ft_strncmp(str[0], ">", 1))
		return (1);
	return (0);
}

int	search_lst(t_minishell *cmd, t_list *tokens)
{
	t_list	*args;

	cmd->pipes *= 1;
	args = tokens;
	while (args)
	{
		if (ft_checkspecial(((t_token *)(args->content))->args))
			return (1);
		args = args->next;
	}
	return (0);
}
