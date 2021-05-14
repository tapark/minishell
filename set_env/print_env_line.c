#include "../minishell.h"

void ft_swap(char **a, char **b)
{
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_env_array(char **sort)
{
	int i;
	int j;
	int k;

	i = -1;
	while (sort[++i] != NULL)
	{
		j = i;
		while (sort[++j] != NULL && sort[i] != NULL)
		{
			k = 0;
			while (sort[i][k] != '\0' && sort[j][k] != '\0')
			{
				if (sort[i][k] > sort[j][k])
				{
					ft_swap(&sort[i], &sort[j]);
					break;
				}
				else if (sort[i][k] < sort[j][k])
					break;
				k++;
			}
		}
	}
}

void print_export_form(char *sort)
{
	int i;

	i = 0;
	ft_putstr_fd("declare -x ", 1);
	while (sort[i] != '\0')
	{
		write(1, &sort[i], 1);
		if (sort[i] == '=')
			write(1, "\"", 1);
		i++;
	}
	ft_putstr_fd("\"\n", 1);
}

void print_sort_env_line(void)
{
	int i;
	int n;
	char **sort;

	i = 0;
	sort = copy_envp(g_env);
	sort_env_array(sort);
	while (sort[i] != NULL)
	{
		print_export_form(sort[i]);
		free(sort[i]);
		i++;
	}
	free(sort);
}

void print_env_line(void)
{
	int i;

	i = 0;
	while (g_env[i] != NULL)
	{
		ft_putstr_fd(g_env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}