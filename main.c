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
	int i;
	char *input;
	int ret;
	char c[999] = "PATH=ashdkjahsz1234";

	printf("var : %s\n", get_env_variable(c));
	printf("val : %s\n", get_env_value(c));

	show_pixel_art();
	copy_env_to_list(envp);
	print_env_list(&g_env);

	while (1)
	{
		show_pwd_line();

		get_cmd_line(&input);

		ft_putstr_fd("[the input value is : ", 1);
		ft_putstr_fd(input, 1);
		ft_putstr_fd("]\n", 1);
	}
	return (0);
}