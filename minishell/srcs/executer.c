/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:11:52 by root              #+#    #+#             */
/*   Updated: 2024/04/22 13:29:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void runner(t_minishell *cmd, t_list *token)
{
	auto t_list *args = token;
	add_history(cmd->args_temp);
	while(args)
	{
		door(((t_token *)(args->content))->args, cmd);
		args = args->next;
	}
}
