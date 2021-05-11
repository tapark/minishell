#include "../minishell.h"

int single_quote_space(char *buf, int *token)
{
	int i;

	i = 1;
	while (buf[i] != '\'')
		i++;
	i++;
	if (buf[i] == ' ' || buf[i] == '\0')
	{
		while (buf[i] == ' ')
			i++;
		(*token)++;
	}
	return (i);
}

int double_quote_space(char *buf, int *token)
{
	int i;

	i = 1;
	while (buf[i] != '\"')
		i++;
	i++;
	if (buf[i] == ' ' || buf[i] == '\0')
	{
		while (buf[i] == ' ')
			i++;
		(*token)++;
	}
	return (i);
}

int normal_char_space(char *buf, int *token)
{
	int i;

	i = 0;
	while (buf[i] != '\'' && buf[i] != '\"' &&
			buf[i] != ' ' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		(*token)++;
	else if (buf[i] == ' ')
	{
		while (buf[i] == ' ')
			i++;
		(*token)++;
	}
	return (i);
}

int count_token(char *buf)
{
	int i;
	int n;
	int token;

	i = 0;
	token = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\'')
			n = single_quote_space(&buf[i], &token);
		else if (buf[i] == '\"')
			n = double_quote_space(&buf[i], &token);
		else
			n = normal_char_space(&buf[i], &token);
		i = i + n;
	}
	return (token);
}