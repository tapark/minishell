#include "../minishell.h"

int check_numeric(char *token)
{
	int i;

	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] < '0' || '9' < token[i])
			return (1);
		i++;
	}
	return (0);
}

void numeric_error(char *token)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(1);
}

void ft_exit(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->token[i] != NULL)
		i++;
	if (i == 1)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	else if (i >= 2)
	{
		if (check_numeric(cmd->token[1]))
			numeric_error(cmd->token[1]);
		else
		{
			if (i == 2)
			{
				ft_putstr_fd("exit\n", 2);
				exit(0);
			}
			else
				ft_putstr_fd("exit\nexit: too many arguments\n", 2);
		}
	}
}