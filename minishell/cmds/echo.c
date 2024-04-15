/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/15 13:40:24 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_cmd(char **string)
{
	int	counter;

	counter = 0;
	//verify_quote(string[counter]);
	while (string[++counter])
	{
		if (counter > 1)
			printf(" ");
		if (test_str(string[counter]))
			printf("%s", remove_quote(string[counter]));
		else
			printf("%s", "ERROR-> faltou fechar aspas nessa quote");
	}
	printf("\n");
}

/* int	verify_quote(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 2;
	test_str(str);
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			quote++;
		i++;
	}
	if (quote % 2 == 0)
		return (1);
	return (0);
} */

char	*remove_quote(char *str) //arrumar essa funcao
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
		if (str[i] != '"')
		{
            new_str[j] = str[i];
            j++;
        }
        i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	test_str(char *str)
{
	auto int i = 0;
	auto int flag = 0;
	auto char c = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			flag = 1;
			c = str[i];
		}
		if (str[i] == c && flag == 1)
			flag--;
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}
