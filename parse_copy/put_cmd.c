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
    while (is_separator(input[len - 1]) || input[len - 1] == ' ')//오류
    {
//       printf("%d\n", len);
		len--;
    }
	new = malloc(sizeof(char) * (len - i + 1));
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
//	printf("TEST: \033[43;31m buf에 담긴 문장 \033[0m [%s]\n", cmd->buf);
	len = 0;
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

    i = -1;
//    head_node = create_node(cmd, input_ps[i]); // 첫 노드 생성
    while (input_ps[++i]) // 뒤 이을 노드 생성
    {
//        printf("[%s]\n", remove_other(input_ps[i]));
        new_node = create_node(head_node, input_ps[i]);
        add_cmd_list_back(&head_node, new_node);
    }

    while (head_node != NULL)
    {
        printf("%s\n", head_node->buf);
        sleep(1);
        head_node = head_node->next;
    }

}