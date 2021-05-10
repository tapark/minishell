#include "../minishell.h"

int		get_num_of_env_list(t_env **head)
{
	t_env	*index;
	int		num;

	index = (*head);
	num = 0;
	if (index == NULL)
		return (0);
	while (index != NULL)
	{
		index = index->next;
		num++;
	}
	return (num);
}

char **env_list_to_array(t_env **head)
{
	int n;
	int i;
	char **dest;
	t_env *index;

	n = get_num_of_env_list(head);
	i = 0;
	index = (*head);
	if (!(dest = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		dest[i++] = ft_strdup(index->env);
		index = index->next;
	}
	dest[i] = NULL;
	return (dest);
}

void ft_swap(char **a, char **b)
{
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

char **sort_env_array(char **sort)
{
	int i;
	int j;
	int k;

	i = -1;
	while (sort[++i] != NULL)
	{
		j = i;
		while (sort[++j] != NULL && sort[i] != NULL)
		{
			k = 0;
			while (sort[i][k] != '\0' && sort[j][k] != '\0')
			{
				if (sort[i][k] > sort[j][k])
				{
					ft_swap(&sort[i], &sort[j]);
					break;
				}
				else if (sort[i][k] < sort[j][k])
					break;
				k++;
			}
		}
	}
	return (sort);
}

void print_sort_env_list(t_env **head)
{
	int i;
	int n;
	char **sort;

	i = 0;
	n = get_num_of_env_list(head);
	sort = env_list_to_array(head);
	sort = sort_env_array(sort);
	while (i < n)
	{
		ft_putstr_fd(sort[i], 1);
		ft_putstr_fd("\n", 1);
		free(sort[i]);
		i++;
	}
	free(sort[i]);
	free(sort);
}