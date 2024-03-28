/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <lbordona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:28:07 by lbordona          #+#    #+#             */
/*   Updated: 2024/03/28 17:01:21 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* chdir -> */
/* perror -> */

void	cd_cmd(t_minishell *ms)
{
	char	*path;

	path = ft_strjoin("/", ms->args);
	path[ft_strlen(path) - 1] = '\0';
	path = ft_strjoin(getcwd(0, 0), path);
	printf("%ld\n", ft_strlen(path)); //remover se ok
	if (chdir(path) != 0)
		perror("chdir");
	free(path);
}
