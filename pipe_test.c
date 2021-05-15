# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int main(void)
{
	int fd;
	int fds[2];
	pipe(fds);
	pid_t pid;
	int a = 9999;
	char buf[99999];

	pid = fork();

	if (pid == 0) // 자식프로세스
	{
		fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0744);
		write(1, "gogo\n", 5);
		dup2(fd, STDIN_FILENO);
		write(fds[1], "gogo\n", 5);
		printf("fds[1] : %d\n", fds[1]);
		printf("[%d]child process\n\n", a);
	}
	else if (pid > 0) // 부모프로세스
	{
		read(fds[0], buf, 999);
		printf("[%d]parents process : %s\n\n", a, buf);
	}
}