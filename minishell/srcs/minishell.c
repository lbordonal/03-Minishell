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

void print_prompt(void)
{
    ft_putstr_fd("Minishell$ ", 1);
}

int main(int ac, char **av)
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
        char *input;
        ssize_t bytes_read;

        print_prompt();
        input = ft_calloc(1024, sizeof(char));
        bytes_read = read(STDIN_FILENO, input, sizeof(input));
        if (bytes_read <= 0)
		{
        	break;
        }
        //else
        //{
            printf("%ld", bytes_read);
            //echo_cmd(input);
        //}
        input[bytes_read] = '\0';

	}
    return 0;
}
