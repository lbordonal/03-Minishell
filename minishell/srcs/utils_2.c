/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:49:25 by root              #+#    #+#             */
/*   Updated: 2024/04/30 00:26:18 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_legit2(char **string)
{
	auto int counter = -1;
	auto int counter_2;
	while (string[++counter])
	{
		counter_2 = -1;
		while (string[counter][++counter_2])
		{
			if (string[counter][counter_2] != 32
				&& string[counter][counter_2] != '\t')
				return (0);
		}
	}
	return (1);
}

int	check_legit(t_list *tokens)
{
	auto t_list *args = tokens; //pode mudar isso? -> t_list *args; / args = tokens; ??
	while (args)
	{
		if (check_legit2(((t_token *)(args->content))->args) == 1)
			return (0);
		args = args->next;
	}
	return (1);
}
