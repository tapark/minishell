#include "../minishell.h"

int env_exist_check(char *var)
{
	char *temp;
	int n;

	n = 0;
	while (g_env[n] != NULL)
	{
		temp = get_env_variable(g_env[n]);
		if (ft_strcmp(var, temp))
		{
			free(temp);
			return (n);
		}
		free(temp);
		n++;
	}
	return (-1);
}

void overwrite_env_line(char *line, int n)
{
	char *temp;

	free(g_env[n]);	
	g_env[n] = ft_strdup(line);
}

void add_new_env_line(char *line)
{
	int n;
	int i;
	char **dest;

	n = 0;
	i = 0;
	while (g_env[n] != NULL)
		n++;
	if (!(dest = (char **)malloc(sizeof(char *) * (n + 2))))
		return ;
	dest[0] = ft_strdup(line);
	while (i < n)
	{
		dest[i + 1] = ft_strdup(g_env[i]);
		free(g_env[i++]);
	}
	free(g_env);
	dest[i] = NULL;
	g_env = dest;
}

void export_env_line(char *line)
{
	char *var;
	int n;

	var = get_env_variable(line);
	n = env_exist_check(var);
	free(var);
	if (n == -1)
		add_new_env_line(line);
	else
		overwrite_env_line(line, n);
}