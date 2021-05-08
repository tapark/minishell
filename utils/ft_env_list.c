#include "../minishell.h"

t_env	*create_env_list_node(char *value)
{
	t_env *new;

	new = (t_env *)malloc(sizeof(value));
	new->env = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	add_env_list_front(t_env **head, t_env *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_env_list_back(t_env **head, t_env *node)
{
	t_env *index;

	index = (*head);
	if (index == NULL)
		(*head) = node;
	else
	{
		while (index->next != NULL)
			index = index->next;
		index->next = node;
	}
}

void	add_env_list(t_env **head, t_env *node, int n)
{
	t_env *index;
	t_env *temp;

	index = (*head);
	if (n == 1)
	{
		add_env_list_front(head, node);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = node;
	node->next = temp;
}

void	del_env_list(t_env **head, int n)
{
	t_env *index;
	t_env *temp;

	index = (*head);
	if (n == 1)
	{
		(*head) = (*head)->next;
		free(index->env);
		free(index);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = temp->next;
	free(temp->env);
	free(temp);
}
