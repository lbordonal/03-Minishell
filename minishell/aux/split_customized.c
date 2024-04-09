/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_customized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:24:53 by goda-sil          #+#    #+#             */
/*   Updated: 2024/04/09 21:04:26 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str == '"' || *str == '\'')
		{
			trigger++;
			if (trigger == 2)
				trigger = 0;
		}
		if (*str != c && trigger == 0)
			i++;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**send(char **split, char const*s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	int	trigger;

	i = -1;
	j = 0;
	index = -1;
	trigger = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			trigger++;
			if (trigger == 2)
				trigger = 0;
		}
		if (s[i] != c && index < 0)
			index = i;
		else if (((s[i] == c && trigger == 0) || \
		i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return(split);
}

char	**ft_split_new(char const *s, char c)
{
	char	**split;
	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (send(split, s, c));
}