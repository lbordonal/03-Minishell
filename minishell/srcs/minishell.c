/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <lbordona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:45:51 by lbordona          #+#    #+#             */
/*   Updated: 2024/03/28 17:01:04 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	door(char *input, t_minishell *ms)
{
	if (ft_strcmp(input, "echo") == 0)
		echo_cmd(ms);
	else if (ft_strcmp(input, "pwd") == 0)
		pwd_cmd(ms);
	else if (ft_strcmp(input, "cd") == 0)
		cd_cmd(ms);
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
	return (0);
}
