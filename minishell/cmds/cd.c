/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:28:07 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/29 01:07:24 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* chdir -> */
/* perror -> */

void	cd_cmd(t_minishell *cmd)
{
	char	*path;

	path = ft_strjoin("/", cmd->args);
	path[ft_strlen(path) - 1] = '\0';
	path = ft_strjoin(getcwd(0, 0), path);
	printf("%ld\n", ft_strlen(path));
	if (chdir(path) != 0)
		perror("chdir");
	free(path);
}
