#include "../minishell.h"

int ft_is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	return (1);
}

int ft_is_char(char c)
{
	if ('A' <= c && c <= 'Z')
		return (0);
	if ('a' <= c && c <= 'z')
		return (0);
	return (1);
}

int var_valid_check(char *line)
{
	char *var;
	int i;

	i = -1;
	var = get_env_variable(line);
	if (ft_is_char(var[0]))
	{
		free(var);
		return (1);
	}
	while (var[++i] != '\0')
	{
		if (var[i] == ' ' || (ft_is_num(var[i]) && ft_is_char(var[i])))
		{
			free(var);
			return (1);
		}
	}
	free(var);
	return (0);
}

int check_equal_char(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void ft_export(t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->token[1] == NULL)
		print_sort_env_line();
	while (cmd->token[++i] != NULL)
	{
		if (check_equal_char(cmd->token[i]))
			;
		else if (var_valid_check(cmd->token[i]))
		{
			ft_putstr_fd("export: `", 1);
			ft_putstr_fd(cmd->token[i], 1);
			ft_putstr_fd("\': not a valid identifier\n", 1);
		}
		else
			export_env_line(cmd->token[i]);
	}
}