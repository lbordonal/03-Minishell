/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/19 23:33:15 by lbordona         ###   ########.fr       */
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
/* Defines: */

/* Structures: */
typedef struct s_minishell
{
	//estrutura para o minisheel a ser criada
}	t_minishell;

/* Functions: */

/*AUX*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

/*SOURCES*/
void print_prompt(void);

#endif
