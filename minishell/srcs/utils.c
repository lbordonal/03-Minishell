/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:06 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/15 08:14:19 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt(t_minishell *cmd)
{
	cmd->path = getcwd(0, 0);
	cmd->args_temp = readline("Minishell->");
	while (cmd->args_temp && cmd->args_temp[0] == '\0') {
        free(cmd->args_temp);
        cmd->args_temp = readline("Minishell->");
    }
    if (!cmd->args_temp) {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    check_input(cmd);
}

void	check_input(t_minishell *cmd)
{
	char	**temporary;

	temporary = ft_split(cmd->args_temp, '|');
	cmd->tokens = init_tokens(temporary);
	door(cmd->tokens, cmd->args_temp, cmd);
}

void	print_list_env(t_list *list)
{
	t_list	*temporary;

	temporary = list;
	while (temporary != NULL)
	{
		printf("%s\n", ((t_env *)(temporary->content))->info);
		temporary = temporary->next;
	}
}
