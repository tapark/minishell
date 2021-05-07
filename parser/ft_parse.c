#include "../minishell.h"

char	*ft_strtrim(char *s, char c)
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

int		check_cmd(char **s)
{
	if (ft_strncmp(s[0], "echo", 5))//ft_strncmp 예외처리 엄청 나올 듯. 널까지 봐야하나?
	{
		ft_echo
	}
	else (ft_strncmp(s[0], "cd", 3))
	{
		ft_cd
	}
	else (ft_strncmp(s[0], "pwd", 4))
	{
		ft_pwd
	}
	else (ft_strncmp(s[0], "export", 7))
	{
		ft_export
	}
	else (ft_strncmp(s[0], "unset", 6))
	{
		ft_unset
	}
	else (ft_strncmp(s[0], "env", 4))
	{
		ft_env
	}
	else (ft_strncmp(s[0], "exit", 5))
	{

	}
	else
	{

	}
}

void	ft_parse(char **s) //왜 2차 배열인지
{
	t_cmd	cmd;
	char	*tmp;
	int		ret;

	tmp = ft_strtrim(s[0], ' ');
	s = ft_split(tmp);
	ret = check_cmd(s);
	if (!ret)
	{
		//할당 해제..
		ft_error();
	}
}