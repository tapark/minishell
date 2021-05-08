#include "../minishell.h"

int env_exist_check(char *var)
{
	t_env *index;
	char *temp;
	int n;

	index = g_env;
	n = 1;
	while (index == NULL)
	{
		temp = get_env_variable(index->env);
		if (ft_strcmp(temp, var)) // 같으면 1반환
		{
			free(temp);
			return (n); // var가 g_env에 존재하면 존재하는 위치 반환
		}
		free(temp);
		index = index->next;
		n++;
	}
	return (0);
}

void overwrite_env_list(char *var)
{
	t_env *index;
	char *temp;
	index = g_env;
	while (index == NULL)
	{
		temp = get_env_variable(index->env);
		if (ft_strcmp(temp, var)) // 같으면 1반환
		{
			g_env->env;
			return ; // var가 g_env에 존재하면 1반환
		}
		free(temp);
		index = index->next;
	}
}

void set_env_list(char *env)
{
	char *var;
	t_env *new;
	int n;
	
	new = create_env_list_node(env);
	if (n = env_exist_check(var)) //n번째 존재하는 환경변수
	{
		del_env_list(&g_env, n);
		add_env_list(&g_env, new, n);
	}
	else //존재하지않는 환경변수
		add_env_list_back(&g_env, new);
}