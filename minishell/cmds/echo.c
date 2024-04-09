/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 16:53:43 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	return_string(char *cmd)
{
	int	counter;

	counter = 1;
	while (cmd[counter] != '\'' && cmd[counter] != '"')
	{
		printf("%c", cmd[counter]);
		counter++;
	}
}

void	echo_cmd(t_minishell *cmd)
{
	int	counter;

	counter = 0;
	while(cmd->args[++counter])
	{
		if (counter > 1)
			printf(" ");
		if (cmd->args[counter][0] == '"' || cmd->args[counter][0] == '\'')
			return_string(cmd->args[counter]);
		else
		{
			printf("%s", cmd->args[counter]);
		}
	}
	printf("\n");
}
