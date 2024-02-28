/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/21 11:57:32 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	door(char *string, t_minishell *cmd)
{
    if (ft_strcmp(string, "echo") == 0) {
        echo_cmd(cmd);
    }
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
	while (1)
	{
		ft_putstr_fd("Minishell$ ", 1);
		print_prompt();
	}
	return 0;
}
