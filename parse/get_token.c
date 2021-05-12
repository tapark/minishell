#include "../minishell.h"

char *get_quote_token(char *buf, int *i)
{
	char *dest;
	int j;

	j = 0;
	(*i)++;
	if (buf[(*i) - 1] == '\'')
	{
		while (buf[*i] != '\'')
		{
			(*i)++;
			j++;
		}
	}
	else if (buf[(*i) - 1] == '\"')
	{
		while (buf[*i] != '\"')
		{
			(*i)++;
			j++;
		}
	}
	dest = ft_strndup(buf + (*i) - j , j);
	(*i)++;
	return (dest);
}

char *get_normal_token(char *buf, int *i)
{
	char *dest;
	int j;

	j = 0;
	while (buf[*i] != '\'' && buf[*i] != '\"' &&
			buf[*i] != ' ' && buf[*i] != '\0')
	{
		(*i)++;
		j++;
	}
	dest = ft_strndup(buf + (*i) - j , j);
	return (dest);
}

char **init_set_token(char *buf)
{
	int n;
	int i;
	char **dest;

	i = 0;
	n = count_token(buf);
	if (!(dest = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n)
		dest[i++] = ft_strdup("");
	dest[i] = NULL;
	return (dest);
}

char **get_token(char *buf)
{
	char **token;
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	token = init_set_token(buf);
	while (buf[i] != '\0')
	{
		if (buf[i] == ' ' || buf[i] == '\0')
		{
			while (buf[i] == ' ')
				i++;
			j++;
			temp = ft_strdup("");
		}
		else if (buf[i] == '\'' || buf[i] == '\"')
			temp = get_quote_token(buf, &i);
		else
			temp = get_normal_token(buf, &i);
		token[j] = ft_strjoin_free2(token[j], temp);
	}
	return (token);
}