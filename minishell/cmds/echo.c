/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/22 20:55:15 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_cmd(char **string)
{
	int	i;

	if (verify_option_n(string[1]) == 1)
		i = 1;
	else
		i = 0;
	while (string[++i])
	{
		if (i > 2)
			printf(" ");
		if (test_str(string[i]))
		{
			printf("%s", remove_quote(string[i]));
		}
		else
			printf("%s", "ERROR-> faltou fechar aspas nessa quote");
	}
	if (verify_option_n(string[1]) == 1)
		printf("%s", "$");
	printf("\n");
}

/* verifica se a string[1] = -n */
int	verify_option_n(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = remove_quote(str);
	if (temp[i++] != '-')
		return (0);
	while (temp[i] == 'n')
		i++;
	if (temp[i])
		return (0);
	free(temp);
	return (1);
}

/* remove aspas */
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

/* testa se as aspas estao ok */
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
