/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:06 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/29 01:04:49 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt(void)
{
	t_minishell	cmd;

	cmd.path = getcwd(0, 0);
	cmd.args = readline("Minishell->");
	if (ft_strlen(cmd.args) <= 0)
		exit(1);
	else
		check_input(&cmd);
}

void	check_input(t_minishell *cmd)
{
	int		counter;
	int		i;
	char	*input;
	char	*temp;
	counter = 0;
	while (cmd->args[counter] != ' ' && cmd->args[counter] != '\0')
		counter++;
	input = ft_calloc(counter + 1, sizeof(char));
	if (input == NULL)
		exit(1);
	i = 0;
	while (i < counter)
	{
		input[i] = cmd->args[i];
		i++;
	}
	input[i] = '\0';
	temp = cmd->args;
	cmd->args = cmd->args + counter + 1;
	door(input, cmd, temp);
	free(input);
}
