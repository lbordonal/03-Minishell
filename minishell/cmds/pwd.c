/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:42:55 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/30 00:15:47 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* getcwd -> On success, these functions return a
pointer to a string containing the pathname of
the current working directory */

void	pwd_cmd(void)
{
	printf("%s\n", getcwd(0, 0));
}
