#include "../minishell.h"

int single_error_check(char *buf)
{
	int i;

	i = 1;
	while (buf[i] != '\'' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (-1);
	return (i + 1);
}

int double_error_check(char *buf)
{
	int i;

	i = 1;
	while (buf[i] != '\"' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (-1);
	return (i + 1);
}

int normal_error_check(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\'' && buf[i] != '\"' && buf[i] != '\0')
		i++;
	return (i);
}
int quote_error_check(char *buf)
{
	int i;
	int n;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\'')
			n = single_error_check(&buf[i]);
		else if (buf[i] == '\"')
			n = double_error_check(&buf[i]);
		else
			n = normal_error_check(&buf[i]);
		if (n == -1)
			return (0);
		i = i + n;
	}
	return (1);
}