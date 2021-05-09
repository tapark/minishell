#include "../minishell.h"

char	*ft_strtrim_space(char *s, char c)
{
	int i;
	int j;
	int len;
	char *new_s;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == c)
		i++;
	while (s[len - 1] == c)
	{
		if (s[len - 1] != c)//코드 괜찮나. 
			break ;
		len--;
	}
	if (i == 0 && len == ft_strlen(s)) //공백 없음. 종료
		return (NULL);
	new_s = ft_calloc(1, sizeof(char) * (len - i + 1));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[j] = s[i];
		i++;
		j++;
	}
	new_s[j] = 0;
	return (new_s);
}

// int			main(void)
// {
// 	char buf[BUF];

// 	getcwd(buf, BUF);
// 	printf("%s\n", buf);
// 	return (0);
// }

void	ft_pwd(t_struct *s)
{
	char buf[BUF];
	//예외처리 일단 제외
	// printf("|%s| %d", s->cmd->buf, BUF);
	getcwd(buf, BUF);
	ft_putstr_fd(buf, 1);
	ft_putstr_fd("\n", 1);
}

int		check_cmd(t_struct *s, char **input)
{
	if (!ft_strncmp(input[0], "echo", 4))
	{
		printf("잘 들어옴\n");
		return (0);
		// ft_echo();
	}
	// else (ft_strncmp(s[0], "cd", 2))
	// {
	// 	ft_cd();
	// }
	else if (!ft_strncmp(input[0], "pwd", 3))
	{
		ft_pwd(s);
	}
	// else (ft_strncmp(s[0], "export", 6))
	// {
	// 	ft_export();
	// }
	// else (ft_strncmp(s[0], "unset", 5))
	// {
	// 	ft_unset();
	// }
	// else (ft_strncmp(s[0], "env", 3))
	// {
	// 	ft_env();
	// }
	// else (ft_strncmp(s[0], "exit", 4))
	// {
	// 	ft_exit();
	// }
	else
	{
		printf("error !\n");
		return (0);
	}
	return (0);
}

void	ft_parse(t_struct *s, char **input) //왜 2차 배열인지
{
	t_cmd	cmd;
	char	*tmp;
	int		ret;

	tmp = ft_strtrim_space(input[0], ' ');
	s = ft_split(tmp, ' ');
	ret = 1;
	while (ret == 1)
	{
		ret = check_cmd(s, input);
		
		// if ()
		// 	break ;
	}
}