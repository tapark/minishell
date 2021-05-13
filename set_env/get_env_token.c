#include "../minishell.h"

char *get_env_variable(char *env)
{
	int i;
	char *dest;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	dest = ft_strndup(env, i);
	return (dest);
}

char *get_env_value(char *env)
{
	int i;
	char *dest;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	if (env[i] == '=')
		dest = ft_strdup(env + i + 1);
	else
		dest = ft_strdup("");
	return (dest);

}