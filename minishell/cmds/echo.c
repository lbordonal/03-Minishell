/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <lbordona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/03/28 16:51:13 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	return_string(t_minishell *ms)
{
	int	counter;

	counter = 1;
	while (ms->args[counter] != '\''
		&& ms->args[counter] != '"' && ms->args[counter])
	{
		write(1, &ms->args[counter], 1);
		counter++;
	}
	printf("\n");
}

void	echo_cmd(t_minishell *ms)
{
	if (ms->args[0] == '"' || ms->args[0] == '\'')
		return_string(ms);
		//meter condição para verificar se tem mais " para priorizar o que ta dentro do "..."
	else
		epur_str(ms->args);
}
