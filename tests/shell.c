#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	/* fork a process*/
	pid_t pid = fork();
	/*the parent and child will execute 
	 * every line of code
	 * after the fork
	 * each separately
	 */
	if (pid == 0)
		printf("Hello world from child\n");
	else
		wait(NULL);
		printf("Hello world from the parent\n");
	return (0);
}
