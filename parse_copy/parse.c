/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:03:42 by sulee             #+#    #+#             */
/*   Updated: 2021/05/15 20:32:44 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		compare_input_n_cmd(char *input, int len)
{
	if (!ft_strcmp(input, "echo"))
		return (1);
	else if (!ft_strcmp(input, "cd"))
		return (1);
	else if (!ft_strcmp(input, "pwd"))
		return (1);
	else if (!ft_strcmp(input, "export"))
		return (1);
	else if (!ft_strcmp(input, "unset"))
		return (1);
	else if (!ft_strcmp(input, "env"))
		return (1);
	else if (!ft_strcmp(input, "exit"))
		return (1);
	return (0);
}

void	check_cmd(char *input)
{
	int		len;
	int		i;
	char	*tmp;

	len = -1;
	while(input[++len])
	{
		if (input[len] == ' ')
			break ;
	}
	if (compare_input_n_cmd(input, len) == 1)
		return ;
	else
	{
		i = -1;
		tmp = malloc(sizeof(char) * len);
		while (++i < len)
		{
			tmp[i] = input[i];
		}
		tmp[i] = 0;
//		ft_error(-1, "Command not found: ", tmp);
	}
}

int			count_separator(char *input)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			while (input[++i])
			{
				if (input[i] == '\"' || input[i] == '\'')
					break ;
			}
		}
		if ((input[i] == '|' || input[i] == '<' || input[i] == '>' ||
			(input[i] == '>' && input[i + 1] == '>') || input[i] == ';')
			&& input[i + 1] != 0) 
		{
			count++;
			if (input[i] == '>' && input[i + 1] == '>')
				i++;
		}
	}
	return (count);
}

// int			is_quote(char quote)
// {
// 	if (quote == '\'')
// 		return (1);
// 	else if (quote == '\"')
// 		return (2);
// 	return (0);
// }

char		**check_separator(t_cmd *cmd, char *input) //input_ps 만들기
{
	int		start;
	int		end;
	int		i;
	int		j;
	int		count;
	int		quote;
	char	**input_ps;


	start = 0;
	end = 0;
	i = 0;
	quote = 0; // 0: 없거나 세트, 1: 작은 따옴표 1개 발견, 2: 큰 따옴표 1개 발견
	count = count_separator(input); // 세퍼레이트 |, <, >, >> 등 개수 세기
	input_ps = malloc(sizeof(char *) * ((count + 1) + 1));
	while (input[end])
	{
		j = 0;
		if (input[end] == '\'')
		{
			quote = 1;
			while (input[end])
			{
				end++;
				if (input[end] == '\'')
				{
					quote = 0;
					break ;
				}
			}
		}
		if (input[end] == '\"')
		{
			quote = 2;
			while (input[end])
			{
				end++;
				if (input[end] == '\"')
				{
					quote = 0;
					break ;
				}
			}
		}
		if (input[end] == '|' || input[end] == '<' || input[end] == '>'
			|| (input[end] == '>' && input[end + 1] == '>')
			|| input[end] == ';' || input[end + 1] == 0)
		{
			if (input[end] == '>' && input[end + 1] == '>')
				end++;
			input_ps[i] = malloc(sizeof(char) * ((end + 1) - start + 1));
			if (input_ps[i] == 0)
				while (--i >= 0)
					free(input_ps[i]);
			while (start <= end)
			{
				input_ps[i][j] = input[start];
				start++;
				j++;
			}
			input_ps[i][j] = 0;
			i++;
		}
		end++;
	}
	input_ps[i] = 0;
	// if ()//quote 1 혹은 2 일때 처리 
	return (input_ps);
}

char		**parse_cmd(t_cmd *cmd, char *input) // 통문장 > 세퍼레이트 기준으로 거칠게 문장 파싱
{
	char	**input_ps;

	input_ps = check_separator(cmd, input);
	return (input_ps);
}

char	*strtrim_space(char *s, char c)
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
		if (s[len - 1] != c)
			break ;
		len--;
	}
	if (i == 0 && len == ft_strlen(s)) // 공백이 없다면, 원래 문장 반환
		return (s);
	new_s = malloc(sizeof(char) * (len - i + 1));
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

void	ready_to_parse(t_cmd *cmd, char **input)
{
	char	*tmp;
	char	**input_ps;
	int		ret;

//	if ((*input)[0] == "" || input[0][0] == '\n')    // 빈문자 예외처리 > 작동안함...
//		exit(1);
	tmp = strtrim_space(input[0], ' '); // 통문장에서 양쪽 스페이스 제거 > 하위 단계에서 또 제거한다면, 이 부분 불필요 할 듯
	input_ps = parse_cmd(cmd, tmp); // 통문장 > 세퍼레이트 기준으로 거칠게 문장 파싱
//	if (!input_ps) // 예외 처리 - 근데 ft_parse_cmd 에서 널을 반환하는 경우가 없음...
//		ft_error(-1, "ERROR: ", "input error.");
	put_cmd_to_s(cmd, input_ps); // 정리해서 구조체에 넣을 준비
}