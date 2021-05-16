/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sulee <sulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:00:06 by sulee             #+#    #+#             */
/*   Updated: 2021/05/16 17:00:07 by sulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_separator(char c)
{
    if (c == '|' || c == '<' || c == '>' || c == ';')
        return (1);
    return (0);
}

/* cmd->buf 에 담을 문장 정리용 함수 */
char    *remove_other(char *input)
{
    char    *new;
    int     len;
    int		i;
	int		j;

	i = 0;
    len = ft_strlen(input);
    while (input[i] == ' ')
		i++;
    while (len > 0 && (is_separator(input[len - 1]) || input[len - 1] == ' '))
		len--;
    if (len == 0 || i == len)
    {
        // char *str = (char *)input[len - 1];
		ft_putstr_fd("bash: syntax error near unexpected token `", 1);
		if (input[ft_strlen(input) - 1] == '>')
            ft_putstr_fd("newline'\n", 1);
        else if (input[ft_strlen(input) - 1] == '|')
            ft_putstr_fd("|'\n", 1);
        else if (input[ft_strlen(input) - 1] == ';')
            ft_putstr_fd(";'\n", 1);
        exit(1);
    }
    new = malloc(sizeof(char) * (len - i + 1));
	if(!new)
        exit(1);//return (NULL);
	len = len - i;
	j = 0;
	while (j < len)
	{
		new[j] = input[i];
		i++;
		j++;
	}
	new[j] = 0;
    return (new);
}

t_cmd   *create_node(t_cmd *cmd, char *input) // 링크드리스트 구조체 생성
{
    int     len;
    int     i;
    int     count_token;
    char    *org_input;
	char	**do_token;
    t_cmd   *new_cmd;

	/* cmd->buf 채우기 */
	cmd->buf = remove_other(input); //세퍼레이터와 양쪽 스페이스 제거
	printf("TEST: \033[43;31m buf에 담긴 문장 \033[0m |%s|\n", cmd->buf);
	// do_token = ft_split(cmd->buf, ' ');
	// count_token = 0;
    // while (do_token[count_token])
    //     count_token++;
	// printf("TEST: 한 구조체 안에 들어갈 token 개수 : %d\n", count_token);
	// /* 토큰 2차 배열 할당, malloc 예외처리 */
    // if (!(cmd->token = malloc(sizeof(char *) * (count_token + 1))))
    //     ft_error(1, "ERROR: ", "malloc error.");
    // cmd->token[count_token] = 0;
	len = 0;
    // cmd->token = ft_split(cmd->buf, ' ');
    // int i = -1;
    // while (++i < count_token)
    //     cmd->token[i] = malloc(sizeof(char) * (ft_strlen(do_token[i]) + 1));
    // parse_into_tokens(new_cmd, count_token);
    len = ft_strlen(input);
    if (input[len - 1] == '|')
        new_cmd = create_cmd_list_node(cmd->buf, 0, 1, 0);
    else if (input[len - 1] == '<')
        new_cmd = create_cmd_list_node(cmd->buf, 1, 0, 0);
    else if (input[len - 1] == '>' && input[len - 2] != '>')
        new_cmd = create_cmd_list_node(cmd->buf, 2, 0, 0);
    else if (input[len - 1] == '>' && input[len - 2] == '>')
        new_cmd = create_cmd_list_node(cmd->buf, 3, 0, 0);
    else if (input[len - 1] == ';')
        new_cmd = create_cmd_list_node(cmd->buf, 0, 0, 1);
    return (new_cmd);
}

void    put_cmd_to_s(t_cmd *cmd, char **input_ps)
{
    int     i;
    int     len;
    t_cmd   *new_node;
    t_cmd   *head_node;

    i = 0;
    head_node = create_node(cmd, input_ps[i]); // 첫 노드 생성
    while (input_ps[++i]) // 뒤 이을 노드 생성
    {
        new_node = create_node(head_node, input_ps[i]);
        add_cmd_list_back(&head_node, new_node);
    }
}