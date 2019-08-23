#include "simple_shell.h"

/**
 * usetok - Shell functions
 * @buff: to save info
 * @tok: pointer to chars array
 * Return: A char value.
 */

char **usetok(char *buff)
{
	unsigned int n = 0;
	char *tok;
	char **toks;

	toks = malloc(64 * sizeof(char *));
	if(toks == NULL)
		return(NULL);
	tok = strtok(buff, " \n\t");
	while (tok != NULL)
	{	toks[n] = tok;
		n++;
	tok = strtok(NULL, " \n\t");
	}
	toks[n] = NULL;
return (toks);
}

/**
* main - Contains the basic Shell functions
* Return: void.
*/

int main(void)
{
	char *buff = NULL, **args;
	size_t size = 0;
	int line, exe, other;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buff, &size, stdin);
		buff[strlen(buff) - 1] = '\0';
		if (line == -1)
		{
			write(1, "\n", 2);
			free(buff);
			exit(0);
			break;
		}
		args = usetok(buff);
		pid = fork();
		if (pid == 0)
		{
			exe = execve(args[0], args, NULL);
			if (exe == -1)
			{
				perror("Error");
				free(buff);
				exit(0);
			}
		}
		else
		{	waitpid(pid, &other, WUNTRACED);
		}
	}
	free(buff);
	free(args);
	return (0);
}
