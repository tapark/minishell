#include "../minishell.h"

void ft_unset(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->token[++i] != NULL)
	{
		if (var_valid_check(cmd->token[i]))
		{
			ft_putstr_fd("unset: `", 1);
			ft_putstr_fd(cmd->token[i], 1);
			ft_putstr_fd("\': not a valid identifier\n", 1);
		}
		else
			unset_env_line(cmd->token[i]);
	}
}