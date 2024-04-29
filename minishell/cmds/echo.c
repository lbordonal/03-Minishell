/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/29 23:15:58 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * Comando echo.
 *
 * @param string Array de strings com tudo o que é passado.
 */
int	echo_cmd(char **string)
{
	t_bool	flag_n;
	size_t	args;
	size_t	i;

	i = 1;
	flag_n = false;
	if (*string == NULL)
		return (printf("\n"));
	args = ft_array_size(string);
	if (ft_strcmp_2("-n\0", string[1]))
	{
		flag_n = true;
		i++;
	}
	printf("%s", string[i++]);
	while (i < args)
		printf(" %s", string[i++]);
	if (!flag_n)
		printf("\n");
	return (0);
}

/**
 * Retorna o tamanho do array.
 *
 * @param array Array de strings a ser medido.
 * @return		Tamanho do array.
 */
size_t	ft_array_size(char *const *array)
{
	size_t	size;

	size = 0;
	while (array && *array)
	{
		size++;
		array++;
	}
	return (size);
}

/**
 * Verifica se " e/ou ' estão completos para a string funcionar corretamente.
 *
 * @param str String a ser analisada.
 */
/* int	test_str(char *str)
{
	auto int i = 0;
	auto int flag = 0;
	auto char c = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == 39)
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
} */
