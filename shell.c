#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/**
 *call_command - A child process running a new program
 *@program: name of the executable to run
 *@arg_list: a NULL terminated list of character 
 *strings to be passed as the programs argument list.
 *
 * Return: The process id of the executed program
 */
int call_command(char *program, char **arg_list)
{
	pid_t child_pid;
	child_pid = fork();
	if (child_pid != 0)
		/*This is the parent process*/
		return (child_pid);
	else
	{
		/*Search for program in path and execute*/
		execve(program, arg_list, NULL);
		perror("./shell");
	}

}

/**
 *main - start a new process
 *
 *Return: Always 0
 */
int main()
{
	char *cmd;
	char *token;
	char stream_chars;
	char *arg_list[] = {NULL, NULL};

       	/* environment variable
	char *envp[] = {"PATH=/bin", 0};*/
	size_t buf_size = 10;

	cmd = (char *)malloc(buf_size);
	while (1)
	{
		write(1, "$ ", 2); /* display prompt on screen*/

		char **str_ptr = &cmd; /*double pointer to cmd*/
		stream_chars = getline(str_ptr, &buf_size, stdin); /* read input from terminal*/
		token = strtok(cmd, "\n");

		arg_list[0] = token;

		if (stream_chars < 0)
			break;
		call_command(arg_list[0], arg_list);

	}
	free(cmd);
	return(0);
}
