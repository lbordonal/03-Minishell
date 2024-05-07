/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:11:52 by root              #+#    #+#             */
/*   Updated: 2024/05/07 02:38:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	runner(t_minishell *cmd)
{
	add_history(cmd->args_temp);
	if (check_legit(cmd->tokens) == 1)
	{
		if (cmd->pipes == 1)
			runner_single_cmd(cmd, cmd->tokens);
		else if (cmd->pipes > 1)
			runner_mul_cmds(cmd, cmd->tokens);
	}
	else
		free_program(cmd);
}

void	runner_single_cmd(t_minishell *cmd, t_list *tokens)
{
	t_list *args; //pode mudar isso? -> t_list *args; / args = tokens; ??

	args = tokens;
	if (ft_is_builtin(((t_token *)(args->content))->args[0]))
		door(((t_token *)(args->content))->args, cmd);
	else
		ft_not_builtin(cmd, ((t_token *)(args->content))->args);
	args = args->next;
}

void	runner_mul_cmds(t_minishell *cmd, t_list *tokens)
{
	t_list *args< //pode mudar isso? -> t_list *args; / args = tokens; ??

	args = tokens;
	while (args)
	{
		if (ft_is_builtin(((t_token *)(args->content))->args[0]))
			door(((t_token *)(args->content))->args, cmd);
		else
			ft_not_builtin(cmd, ((t_token *)(args->content))->args);
		args = args->next;
	}
}

void	ft_not_builtin(t_minishell *cmd, char **args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		ft_execute(cmd, args);
	else
		waitpid(pid, NULL, WNOHANG);
}

void	ft_execute(t_minishell *cmd, char **args)
{
	char	*temp;
	int		counter;
	char	*path;
	char	**env;

	counter = 0;
	env = env_copy(cmd->env);
	if (execve(args[0], args, env))
	{
		while (cmd->path[counter])
		{
			temp = ft_strjoin("/", args[0]);
			path = ft_strjoin(cmd->path[counter], temp);
			free(temp);
			if (!access(path, X_OK))
				execve(path, args, env);
			free(path);
			counter++;
		}
		free_splited(env);
	}
}
