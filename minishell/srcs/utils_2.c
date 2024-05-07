/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:49:25 by root              #+#    #+#             */
/*   Updated: 2024/05/07 02:39:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_legit2(char **string)
{
	int counter;
	int counter_2;

	counter = -1;
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
	t_list *args; //pode mudar isso? -> t_list *args; / args = tokens; ??

	args = tokens;
	while (args)
	{
		if (check_legit2(((t_token *)(args->content))->args) == 1)
			return (0);
		args = args->next;
	}
	return (1);
}
