#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUF 1024

int			main(void)
{
	char buf[BUF];

	getcwd(buf, BUF);
	printf("%s\n", buf);
	return (0);
}

// int		main(int ac, char **av)
// {
// 	char buf[BUF];

// 	printf("ac : %d av[1] : %s\n", ac, av[1]);
// 	if (ac == 2 && !strcmp(av[1], "pwd"))
// 	{
// 		getcwd(buf, BUF);
// 		printf("%s\n", buf);
// 	}
// 	return (0);
// }