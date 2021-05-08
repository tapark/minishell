#include "../minishell.h"

void print_env_list(t_env **head)
{
	t_env *index;

	index = (*head);
	while (index != NULL)
	{
		if (index->env != NULL)
		{
			ft_putstr_fd(index->env, 1);
			ft_putstr_fd("\n", 1);
		}
		index = index->next;
	}
}