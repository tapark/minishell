#include "../minishell.h"

t_cmd	*create_cmd_list_node(char *buf, int redir, int pipe, int semi)
{
	t_cmd *new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->buf = ft_strdup(buf);
	new->redir = redir;
	new->pipe = pipe;
	new->semi = semi;
	new->next = NULL;
	return (new);
}

void	add_cmd_list_front(t_cmd **head, t_cmd *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_cmd_list_back(t_cmd **head, t_cmd *node)
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