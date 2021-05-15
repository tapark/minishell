#include "../minishell.h"

void delete_env_line(int n)
{
	int i;
	int j;
	int num;
	char **dest;

	num = 0;
	while (g_env[num] != NULL)
		num++;
	if (!(dest = (char **)malloc(sizeof(char *) * num)))
		return ;
	i = 0;
	j = 0;
	while (j < num)
	{
		if (j == n)
			j++;
		dest[i] = ft_strdup(g_env[j]);
		i++;
		j++;
	}
	free_double(g_env);
	dest[i] = NULL;
	g_env = dest;
}

void unset_env_line(char *line)
{
	char *var;
	int n;

	n = env_exist_check(line);
	if (n != -1)
		delete_env_line(n);
}