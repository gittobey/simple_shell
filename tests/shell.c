#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int shell_exec()
{
	printf("Shell executable called\n");
	return (0);
}
