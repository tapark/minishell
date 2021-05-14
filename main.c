#include "minishell.h"

//표준입력(std_in) : 0
//표준출력(std_out) : 1

void show_pixel_art(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n", 1);
	ft_putstr_fd("@                                       @\n", 1);
	ft_putstr_fd("@           TEAM_WATER_MELON            @\n", 1);
	ft_putstr_fd("@                                       @\n", 1);
	ft_putstr_fd("@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n", 1);
	ft_putstr_fd("\n", 1);
}

void show_pwd_line(void)
{
	ft_putstr_fd(getcwd(NULL, 1024), 1);
	ft_putstr_fd(" $ ", 1);
}

void get_cmd_line(char **input)
{
	int ret;

	while (1)
	{
		ret = get_next_line(0, input);
		if (ret != 0)
			break;
		if (ft_strlen(*input) == 0)
			break;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_cmd cmd;
	char *input;


	show_pixel_art();
	g_env = copy_envp(envp);

	while (1)
	{
		show_pwd_line();
		get_cmd_line(&input);
		if (quote_error_check(input) == 0)
			ft_putstr_fd("qeote: error: not a valid identifier\n", 1);
		else
		{
			cmd.token = get_token(input);
			if (ft_strcmp(cmd.token[0], "env"))
				ft_env();
			else if (ft_strcmp(cmd.token[0], "export"))
				ft_export(&cmd);
			else if (ft_strcmp(cmd.token[0], "unset"))
				ft_unset(&cmd);
			else if (ft_strcmp(cmd.token[0], "exit"))
				ft_exit(&cmd);
			else
			{
				ft_putstr_fd(cmd.token[0], 1);
				ft_putstr_fd(" :command not found\n", 1);
			}
		}
	}
	return (0);
}