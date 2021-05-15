#include "../minishell.h"


//미사용함수
char *get_single_quote_string(char *buf)
{
	int i;
	char *dest;

	i = 1;
	while (buf[i] != '\'' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	dest = ft_strndup(buf + 1, i - 1);
	return (dest);
}

char *get_double_quote_string(char *buf)
{
	int i;
	char *dest;

	i = 1;
	while (buf[i] != '\"' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	dest = ft_strndup(buf + 1, i - 1);
	return (dest);
}

char *get_normal_string(char *buf)
{
	int i;
	char *dest;

	i = 0;
	while (buf[i] != '\'' && buf[i] != '\"' && buf[i] != '\0')
		i++;
	dest = ft_strndup(buf, i);
	return (dest);
}

char *get_pure_string(char *buf)
{
	int i;
	char *dest;
	char *temp;

	i = 0;
	dest = ft_strdup("");
	while (buf[i] != '\0')
	{
		if (buf[i] == '\'')
		{
			temp = get_single_quote_string(&buf[i]);
			if (temp == NULL)
			{
				free(dest);
				dest = NULL;
				break;
			}
			i = i + ft_strlen(temp) + 2;
			dest = ft_strjoin_free2(dest, temp);
		}
		else if (buf[i] == '\"')
		{
			temp = get_double_quote_string(&buf[i]);
			if (temp == NULL)
			{
				free(dest);
				dest = NULL;
				break;
			}
			i = i + ft_strlen(temp) + 2;
			dest = ft_strjoin_free2(dest, temp);
		}
		else
		{
			temp = get_normal_string(&buf[i]);
			i = i + ft_strlen(temp);
			dest = ft_strjoin_free2(dest, temp);
		}
	}
	return (dest);
}