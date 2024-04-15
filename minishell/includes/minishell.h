/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/15 13:40:02 by lbordona         ###   ########.fr       */
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
	char	*args_temp;
	char	*path;
	t_list	*env;
	t_list	*export;
	t_list	*tokens;
}	t_minishell;

typedef struct s_tokens
{
	char	**args;
}	t_token;

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
char	**ft_split_new(char const *s, char c);

/* srcs: */
void	echo_cmd(char **string);
//int		verify_quote(char *str);
char	*remove_quote(char *str);
int		test_str(char *str);
void	cd_cmd(char *string);
void	pwd_cmd(t_minishell *cmd);
void	exit_cmd(t_minishell *cmd);
void	door(t_list *token, char *temp, t_minishell *cmd);
void	init_fun(t_minishell	*cmd, char **sys_env);

char	*get_name(char *info);

/* lists> */
t_list	*init_env(char **env);
t_list	*init_export(char **env);
t_list	*init_tokens(char **string);
t_env	*ft_create_data(char *info);
t_token	*create_tokens(char *info);

#endif
