#include "../minishell.h"

char *remove_space_side(char *input)
{
	int start;
	int end;
	int i;
	char *dest;

	start = 0;
	end = ft_strlen(input) - 1;
	while (input[start] == ' ' && input[start] != '\0')
		start++;
	while (input[end] == ' ' && end)
		end--;
	if (start > end)
		dest = ft_strdup("");
	else
		dest = ft_strndup(input + start, start - end);
	free(input);
	return (dest);
}

int		is_separator(char c, int *i)
{
    if (c == '|' || c == '<' || c == ';')
        return (1);
	
    return (0);
}

void skip_quote(char *input, int *i)
{
	int i;

	i = 0;
	if (input[(*i)++] == '\'')
	{
		while(input[*i] != '\'' && input[*i] != '\0')
			(*i)++;
	}
	else if (input[(*i)++] == '\"')
	{
		while(input[*i] != '\"' && input[*i] != '\0')
			(*i)++;
	}
}

int count_input_array(char *input)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '\"')
			skip_quote(input, &i);
		if (is_separator(input[i]))
			n++;
		if (input[i] != '\0')
		i++;
	}
}

t_cmd get_input_list(char *input)
{
	char *dest;

	dest = remove_space_side(input);
}
