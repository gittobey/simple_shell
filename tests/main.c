#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	pid_t child_pid;
	child_pid = fork();/*Create new child process*/

	if (child_pid < 0)
	{
		printf("Fork failed");
		return (1);
	}
	else if (child_pid == 0)
	{
		printf("Child process successfully created\n");
		printf("Child_PID = %d, parent_PID = %d\n", getpid(), getppid());
	}
	else
	{
		wait(NULL);
		printf("Parent process successfully created!\n");
		printf("Child_PID = %d, parent_PID = %d\n", getpid(), getppid());
	}
	return (0);

}
