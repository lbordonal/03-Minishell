/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:06 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 15:34:32 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt(t_minishell *cmd)
{
	cmd->path = getcwd(0, 0);
	cmd->args_temp = readline("Minishell->");
	if (ft_strlen(cmd->args_temp) <= 0)
		exit(1);
	else
		check_input(cmd);
}

void	check_input(t_minishell *cmd)
{
	cmd->args = ft_split(cmd->args_temp, ' ');
	door(cmd, cmd->args_temp);
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
