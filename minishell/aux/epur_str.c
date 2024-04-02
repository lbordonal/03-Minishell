/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:56:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/28 23:57:43 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	epur_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (flag == 1)
				write(1, " ", 1);
			flag = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
	printf("\n");
}
