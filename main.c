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
	char c[999] = "PATH\"=\"a\"shd\'kjah\'sz12\'34";
	char *dest;
	char **token;
//
//	printf("var : %s\n", get_env_variable(c));
//	printf("val : %s\n", get_env_value(c));

	show_pixel_art();
	copy_env_to_list(envp);
//	print_env_list(&g_env);

//	dest = get_pure_string(c);
//	printf("pure : %s\n", dest);
	while (1)
	{
		show_pwd_line();

		get_cmd_line(&input);

		ft_putstr_fd("\nthe input value is      : ", 1);
		ft_putstr_fd(input, 1);
		ft_putstr_fd("\n", 1);

		dest = get_pure_string(input);
		ft_putstr_fd("\nthe pure value is       : ", 1);
		if (dest != NULL)
			ft_putstr_fd(dest, 1);
		else
			ft_putstr_fd("quote_error", 1);
		ft_putstr_fd("\n\n", 1);
		printf("error_check : %d\n\n", quote_error_check(input));
		printf("count_token : %d\n\n", count_token(input));
		token = get_token(input);
		i = 0;
		while (token[i] != NULL)
		{
			printf("token(%d) : %s\n", i, token[i]);
			i++;
		}
	}
	return (0);
}