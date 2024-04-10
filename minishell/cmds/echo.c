/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 22:56:15 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_cmd(char **string)
{
	int	counter;

	counter = 0;
	while (string[++counter])
	{
		if (counter > 1)
			printf(" ");
		printf("%s", string[counter]);
	}
	printf("\n");
}
