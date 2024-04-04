#include "../includes/minishell.h"

t_list	*init_env(char **env)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 0;
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(ft_create_data(env[i])));
	tmp = head;
	i++;
	while (env[i] != NULL)
	{
		tmp->next = ft_lstnew(ft_create_data(env[i]));
		tmp = tmp->next;
		i++;
	}
	return (head);
}

t_env	*ft_create_data(char *info)
{
	t_env	*data;

	data = (t_env *)malloc(sizeof(t_env));
	data->name = get_name(info);
	data->info = ft_strdup(info);
	return (data);
}

char	*get_name(char *info)
{
	char	*name;
	int		size;

	size = 0;
	while (info[size] && info[size] != '=')
		size++;
	name = (char *)malloc(sizeof(char) * size + 1);
	ft_strlcpy(name, info, size + 1);
	return (name);
}