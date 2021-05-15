#include "../minishell.h"

void get_built_in_cmd(t_cmd *cmd)
{
	if (ft_strcmp(cmd->token[0], "env"))
		ft_env();
	else if (ft_strcmp(cmd->token[0], "export"))
		ft_export(cmd);
	else if (ft_strcmp(cmd->token[0], "unset"))
		ft_unset(cmd);
	else if (ft_strcmp(cmd->token[0], "exit"))
		ft_exit(cmd);
	else
	{
		ft_putstr_fd(cmd->token[0], 1);
		ft_putstr_fd(" :command not found\n", 2);
	}
}