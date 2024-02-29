/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/02/29 00:07:37 by lbordona         ###   ########.fr       */
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
# include <sys/types.h> //opendir,readdir,closedir
# include <dirent.h> //opendir,readdir,closedir
# include "../libft/libft.h"
/* Defines: */

/* Structures: */
typedef struct s_minishell
{
	char	*args;
	char	*path;
}	t_minishell;

/* Functions: */
/* aux: */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	check_input(t_minishell *cmd);
void	print_prompt(void);
void	epur_str(char *str);
/* srcs: */
void	return_string(t_minishell *cmd);
void	door(char *string, t_minishell *cmd);
void	echo_cmd(t_minishell *cmd);
void	cd_cmd(t_minishell *cmd);
void	pwd_cmd(t_minishell *cmd);

#endif
