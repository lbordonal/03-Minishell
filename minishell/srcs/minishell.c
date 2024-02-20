/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/19 23:34:14 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print_prompt(void)
{
    ft_putstr_fd("Minishell$ ", 1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		printf("Error → Entry should be: ./minishell ");
		printf("and shouldn't contain any arguments.\n");
		return (0);
	}
	print_prompt();
	while(1)
		pause();
}
