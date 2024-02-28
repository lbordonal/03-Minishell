#include "../includes/minishell.h"

void	print_prompt(void)
{

	t_minishell cmd;
	ssize_t bytes_read;
	cmd.args = ft_calloc(1024, sizeof(char *));
	if (!cmd.args)
		exit(0);
	bytes_read = read(STDIN_FILENO, cmd.args, 1024);
	if (bytes_read <= 0)
		exit (1);
	else
		check_input(&cmd);
	cmd.args[bytes_read] = '\0';
}

void check_input(t_minishell *cmd)
{
	int counter;
	int i;
	char *temporary;

	counter = 0;
	while(cmd->args[counter] != ' ' && cmd->args[counter] != '\0')
		counter++;
	temporary = ft_calloc(counter + 1, sizeof(char));
	if(temporary == NULL)
		exit(1);
	i = 0;
	while(i < counter)
	{
		temporary[i] = cmd->args[i];
		i++;
	}
    temporary[counter] = '\0';
	cmd->args = cmd->args + counter + 1;
	door(temporary, cmd);
	free(temporary);
}
