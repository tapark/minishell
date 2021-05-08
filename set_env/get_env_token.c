#include "../minishell.h"

char *get_env_variable(char *env)
{
	int i;
	char *dest;

	i = 0;
	while (env[i] != '=')
		i++;
	dest = ft_strndup(env, i);
	return (dest);
}

char *get_env_value(char *env)
{
	int i;
	char *dest;

	i = 0;
	while (env[i] != '=')
		i++;
	dest = ft_strdup(env + i + 1);
	return (dest);

}