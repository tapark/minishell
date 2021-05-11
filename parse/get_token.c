#include "../minishell.h"

char *single_quote_token(char *buf, int *i, int *j)
{
	char *dest;

	(*i) = 1;
	while (buf[*i] != '\'')
		(*i)++;
	dest = ft_strndup(buf + 1, ((*i) - 1));
	(*i)++;
	if (buf[*i] == ' ' || buf[*i] == '\0')
	{
		while (buf[*i] == ' ')
			(*i)++;
		(*j)++;
	}
	return (dest);
}

char *double_quote_token(char *buf, int *i, int *j)
{
	char *dest;

	(*i) = 1;
	while (buf[*i] != '\"')
		(*i)++;
	dest = ft_strndup(buf + 1, ((*i) - 1));
	(*i)++;
	if (buf[*i] == ' ' || buf[*i] == '\0')
	{
		while (buf[*i] == ' ')
			(*i)++;
		(*j)++;
	}
	return (dest);
}

char *normal_char_token(char *buf, int *i, int *j)
{
	char *dest;

	(*i) = 0;
	while (buf[*i] != '\'' && buf[*i] != '\"' &&
			buf[*i] != ' ' && buf[*i] != '\0')
		(*i)++;
	dest = ft_strndup(buf, (*i));
	if (buf[*i] == '\0')
		(*j)++;
	else if (buf[*i] == ' ')
	{
		while (buf[*i] == ' ')
			(*i)++;
		(*j)++;
	}
	return (dest);
}

char **get_token(char *buf)
{
	char **token;
	int n;
	int i;
	int j;

	i = 0;
	j = -1;
	n = count_token(buf);
	if (!(token = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (buf[i] != '\0' && j < n - 1)
	{
		if (buf[i] == '\'')
			token[j] = single_quote_token(&buf[i], &i, &j);
		else if (buf[i] == '\"')
			token[j] = double_quote_token(&buf[i], &i, &j);
		else
			token[j] = normal_char_token(&buf[i], &i, &j);
	}
	token[++j] = NULL;
	return (token);
}