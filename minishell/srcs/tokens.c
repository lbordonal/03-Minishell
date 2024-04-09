/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:06:05 by goda-sil          #+#    #+#             */
/*   Updated: 2024/04/09 20:14:14 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*init_tokens(char **string)
{
	int		counter;
	t_list	*head;
	t_list	*temporary;

	counter = 0;
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(create_tokens(string[counter])));
	temporary = head;
	counter++;
	while (string[counter] != NULL)
	{
		temporary->next = ft_lstnew(create_tokens(string[counter]));
		temporary = temporary->next;
		counter++;
	}
	return (head);
}

t_token	*create_tokens(char *info)
{
	t_token	*data;

	data = (t_token *)malloc(sizeof(t_token));
	data->args = ft_split_new(info, ' ');
	return (data);
}
