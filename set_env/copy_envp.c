#include "../minishell.h"

char **copy_envp(char **envp)
{
	int n;
	int i;
	char **dest;

	n = 0;
	i = 0;
	while (envp[n] != NULL)
		n++;
	if (!(dest = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		dest[i] = ft_strdup(envp[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}