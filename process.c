#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int pid;

	pid = fork();

	if (pid > 0)
	{
		 printf("\nthis is parents process return (_pid : %d)\n", pid);
		 printf("\nthis is parents process (current_pid : %d)\n", getpid());
	}
	else if (pid == 0)
	{
		 printf("\nthis is child process return (_pid : %d)\n", pid);
		 printf("\nthis is child process (current_pid : %d)\n", getpid());
		 execve();
	}
	else
		printf("this is error case (pid : %d)\n\n", pid);

	while(1)
		;
	return (0);
}