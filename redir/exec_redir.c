#include "../minishell.h"

void exec_output_redir(t_cmd *cmd)
{
	int fd;

	fd = open(cmd->next->token[0], O_WRONLY | O_CREAT, 0744);
	if (fd < 0)
		return ;
	dup2(fd, 1);
	get_built_in_cmd(cmd);
	close(fd);
}

void exec_double_output_redir(t_cmd *cmd)
{
	int fd;

	fd = open(cmd->next->token[0], O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd < 0)
		return 0;
	dup2(fd, 1);
	get_built_in_cmd(cmd);
	close(fd);
}

void exec_redir(t_cmd *cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		;
	else if (pid == 0)
	{
		if (cmd->redir == 1)
			exec_output_redir(cmd);
		else if (cmd->redir == 2)
			exec_double_output_redir(cmd);
		else if (cmd->redir == 3)
			;
	}
	else
	{
		wiatpid(pid, &status, 0);
	}
}