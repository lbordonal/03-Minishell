/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:28:07 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 23:26:58 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_cmd(char *string)
{
	char	*path;

	path = ft_strjoin("/", string);
	path = ft_strjoin(getcwd(0, 0), path);
	if (chdir(path) != 0)
		perror("chdir");
	free(path);
}
