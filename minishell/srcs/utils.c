#include "../includes/minishell.h"

void	print_prompt(void)
{

	char *input;
	ssize_t bytes_read;
	ft_putstr_fd("Minishell$ ", 1);
	input = ft_calloc(1024, sizeof(char *));
	bytes_read = read(STDIN_FILENO, input, sizeof(input));
	if (bytes_read <= 0)
		exit (1);
	else
		check_input(input);
	input[bytes_read] = '\0';
}

void check_input(char *string)
{
	int counter;
	int i;
	char *temporary;

	counter = 0;
	while(string[counter] != ' ' && string[counter] != '\0')
		counter++;
	temporary = ft_calloc(counter + 1, sizeof(char));
	i = 0;
	while(i < counter - 1)
	{
		temporary[i] = string[i];
		i++;
	}
    temporary[i] = '\0';
	door(temporary);
	free(temporary);
}
