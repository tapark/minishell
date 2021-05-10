#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void ft_swap(char **a, char **b)
{
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

char **sort_env_array(char **sort)
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
	return (sort);
}

int main(void)
{
	char **sort;
	char **dest;
	int i;

	sort = (char **)malloc(sizeof(char *) * 9);
	sort[0] = strdup("z234");
	sort[1] = strdup("123aaaa");
	sort[2] = strdup("asd123");
	sort[3] = strdup("safsadfas12312");
	sort[4] = strdup("46sdf");
	sort[5] = strdup("123bbbb");
	sort[6] = strdup("abc");
	sort[7] = strdup("sdf");
	sort[8] = NULL;

	i  = 0;
	dest = sort_env_array(sort);
	while (i < 9)
	{
		printf("%d. %s\n", i, dest[i]);
		i++;
	}
	return (0);
}