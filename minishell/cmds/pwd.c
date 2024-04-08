/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:42:55 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/08 17:31:38 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* getcwd -> On success, these functions return a
pointer to a string containing the pathname of
the current working directory */

void	pwd_cmd(t_minishell *cmd)
{
	cmd->path = getcwd(0, 0);
	printf("%s\n", cmd->path);
}
