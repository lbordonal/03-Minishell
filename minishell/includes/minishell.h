/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:51:39 by lbordona          #+#    #+#             */
/*   Updated: 2024/05/17 05:18:31 by root             ###   ########.fr       */
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
# include <sys/wait.h>
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
	int		stdout;
	int		stdin;
	int		stdintmp;
	int		stdouttmp;
}	t_minishell;

typedef struct s_tokens
{
	char	**args;
	char	**comand_args;
}	t_token;

typedef struct s_env
{
	char	*name;
	char	*info;
}	t_env;

typedef enum e_bool
{
	false,
	true
}	t_bool;

/* Functions: */
/* aux: */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	check_input(t_minishell *cmd);
void	print_prompt(t_minishell *cmd);
void	epur_str(char *str);
void	print_list_env(t_list *list);
void	free_program(t_minishell *cmd);
void	free_list(t_list *lst, void (*del)(void *));
t_bool	ft_strcmp_2(const char *str1, const char *str2);

/* srcs: */
int		echo_cmd(char **string);
void	cd_cmd(char *string);
void	pwd_cmd(void);
void	exit_cmd(t_minishell *cmd);
void	door(char **args, t_minishell *cmd);
void	init_fun(t_minishell	*cmd, char **sys_env);
void	runner(t_minishell *cmd);
void	runner_single_cmd(t_minishell *cmd, t_list *tokens);
void	runner_mul_cmds(t_minishell *cmd, t_list *tokens);
void	ft_execute(t_minishell *cmd, char **args);
void	free_splited(char **array);
void	ft_not_builtin(t_minishell *cmd, char **args);
void	configure_fd(t_minishell *cmd);
void	change_fd(t_minishell *cmd, t_list *tokens);
void	appendredirection(t_minishell *cmd);

int		check_quotes(const char *str);
int		check_quotes_cont(int in_quotes, char expected_quote);
int		ft_is_builtin(char *args);
int		check_legit(t_list *tokens);
int		search_lst(t_minishell *cmd, t_list *token);
int		ft_checkspecial(char **str);

char	**env_copy(t_list *lst);
char	**ft_split_new(char const *s, char c);
char	*get_name(char *info);
char	**separate_path(t_list *list);
size_t	ft_array_size(char *const *array);

/* lists> */
t_list	*init_env(char **env);
t_list	*init_export(char **env);
t_list	*init_tokens(char **string);
t_env	*ft_create_data(char *info);
t_token	*create_tokens(char *info);

#endif
