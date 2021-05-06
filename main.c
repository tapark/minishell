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

	show_pixel_art();

//*환경변수 출력	
	i = 0;
	printf("\n[envp_check]\n");
	while (envp[i] != NULL)
	{
//		if (envp[i][0] == 'P' && envp[i][1] == 'W' && envp[i][2] == 'D')
//			envp[i][5] = 'Z';
		printf("%s\n", envp[i++]);
	}
	printf("[total : %d]\n", i);
//
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