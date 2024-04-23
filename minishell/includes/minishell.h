/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/23 12:14:02 by root             ###   ########.fr       */
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
	char	**path;
	t_list	*env;
	t_list	*export;
	t_list	*tokens;
	int		pipes;
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

/* srcs: */
void	echo_cmd(char **string);
void	cd_cmd(char *string);
void	pwd_cmd();
void	exit_cmd(t_minishell *cmd);
void	door(char **args, t_minishell *cmd);
void	init_fun(t_minishell	*cmd, char **sys_env);
void	runner(t_minishell *cmd);
void	runner_single_cmd(t_minishell *cmd, t_list *tokens);
void	runner_mul_cmds(t_minishell *cmd, t_list *tokens);
void	ft_execute(t_minishell *cmd, char **args);
void	free_splited(char **array);
char	**env_copy(t_list *lst);

int		test_str(char *str);
int		ft_is_builtin(char *args);

int		verify_option_n(char *str);
char	*option_n_ta_on(char *str);
char	**ft_split_new(char const *s, char c);
char	*get_name(char *info);
char	*remove_quote(char *str);
char	**separate_path(t_list *list);

/* lists> */
t_list	*init_env(char **env);
t_list	*init_export(char **env);
t_list	*init_tokens(char **string);
t_env	*ft_create_data(char *info);
t_token	*create_tokens(char *info);

#endif
