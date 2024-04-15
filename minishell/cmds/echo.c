/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/14 16:36:51 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_cmd(char **string)
{
	int	counter;

	counter = 0;
	verify_quote(string[counter]);
	while (string[++counter])
	{
		if (counter > 1)
			printf(" ");
		if (verify_quote(string[counter]))
			printf("%s", remove_quote(string[counter]));
		else
			printf("%s", "ERROR-> faltou fechar aspas nessa quote");
	}
	printf("\n");
}

int	verify_quote(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 2;
	//printf("%s", str);
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			quote++;
		i++;
	}
	if (quote % 2 == 0)
		return (1);
	return (0);
}

char	*remove_quote(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '"') {
            new_str[j] = str[i];
            j++;
        }
        i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
