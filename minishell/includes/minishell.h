/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/21 11:48:35 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Includes: */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
/* Defines: */

/* Structures: */
typedef struct s_minishell
{
	//estrutura para o minisheel a ser criada
}	t_minishell;

/* Functions: */
/* aux: */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);

/* srcs: */
void	print_prompt(void);
void	echo_cmd(char *str);

#endif
