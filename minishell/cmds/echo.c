/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/08 17:29:55 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	return_string(t_minishell *cmd)
{
	int	counter;

	counter = 1;
	while (cmd->args[counter] != '\''
		&& cmd->args[counter] != '"' && cmd->args[counter])
	{
		write(1, &cmd->args[counter], 1);
		counter++;
	}
	printf("\n");
}

void	echo_cmd(t_minishell *cmd)
{
	if (cmd->args[0] == '"' || cmd->args[0] == '\'')
		return_string(cmd);
	else
		epur_str(cmd->args);
}
