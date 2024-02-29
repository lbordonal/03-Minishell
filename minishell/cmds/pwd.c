/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:42:55 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/29 00:59:31 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* getcwd -> On success, these functions return a
pointer to a string containing the pathname of
the current working directory */

void	pwd_cmd(t_minishell *cmd)
{
	free(cmd->path);
	cmd->path = getcwd(0, 0);
	printf("%s\n", cmd->path);
}
