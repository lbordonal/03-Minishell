/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/09 15:45:52 by goda-sil         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
/* Defines: */

/* Structures: */
typedef struct s_minishell
{
	char	**args;
	char	*args_temp;
	char	*path;
	t_list	*env;
	t_list	*export;
}	t_minishell;

typedef struct s_env
{
	char	*name;
	char	*info;
}	t_env;

/* Functions: */
/* aux: */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	check_input(t_minishell *cmd);
void	print_prompt(t_minishell *cmd);
void	epur_str(char *str);
void	print_list_env(t_list *list);
/* srcs: */
void	return_string(char *cmd);
void	echo_cmd(t_minishell *cmd);
void	cd_cmd(t_minishell *cmd);
void	pwd_cmd(t_minishell *cmd);
void	exit_cmd(t_minishell *cmd);
void	door(t_minishell *cmd, char *temp);

char	*get_name(char *info);

/* lists> */
t_list	*init_env(char **env);
t_env	*ft_create_data(char *info);
t_list	*init_export(char **env);

#endif
