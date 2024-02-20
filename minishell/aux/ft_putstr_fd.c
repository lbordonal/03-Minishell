#include "../includes/minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	if (!s || !fd)
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
}