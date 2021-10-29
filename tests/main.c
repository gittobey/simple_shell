#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 *main - start a new process
 *
 *Return: Always 0
 */
int main(__attribute__((unused)) int argc, __attribute__((unused))char *argv[])
{
	char *str;
       	ssize_t chars = 0;
	size_t buf_size;
	
	while (1)
	{
		write(1, "$ ", 2);
		chars = getline(&str, &buf_size, stdin);

		if (*str == '\0')
			continue;
		if (chars < 0)
			exit(1);
		else
		{
			exec_command(str);
		}
	}
	free(str);
	str = NULL;
	return(0);
}

/**
 *exec_cmd - Creates a new child process
 *executes a command, and waits for the child process.
 *@cmd command
 *@argv: vector of pointers to commands
 *
 *Return: void
 */
void exec_command(char *cmd)
{
	pid_t pid;
	int status;
	char *argv[3];

	argv[0] = "/bin/";
	argv[1] = cmd;
	argv[2] = NULL;

	pid = fork();
	if (pid < 0)
		perror("/bin/");
	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("./shell");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
