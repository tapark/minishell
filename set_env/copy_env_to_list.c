#include "../minishell.h"

void copy_env_to_list(char **envp)
{
	int i;
	t_env *new;

	i = 0;
	g_env = NULL;
	while (envp[i] != NULL)
	{
		new = create_env_list_node(envp[i]);
		add_env_list_back(&g_env, new);
		i++;
	}
}