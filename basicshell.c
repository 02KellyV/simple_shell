#include "simple_shell.h"

/**
* my_handler - a signal handler
* @var: Variable type int.
* Return: void function.
*/

void my_handler(int var)
{
	(void) var;
	write(1, "\n", 1);
	write(1, "$ ", 2);
	fflush(stdout);
}

/**
* *_line - Function that use getline.
* Return: Variable type char *.
*/

char *_line(void)
{
	char *buff = NULL;
	size_t size = 0;
	int var_get;

	var_get = getline(&buff, &size, stdin);
	if (var_get == -1)
	{
		printf("\n");
		free(buff);
		exit(0);
	}

	buff[_strlen(buff) - 1] = '\0';
	return (buff);
}

/**
 * usetok - Shell functions
 * @buff: to save info
 * Return: A char value.
 */

char **usetok(char *buff)
{
	unsigned int n = 0;
	char *tok, **toks;

	toks = malloc(64 * sizeof(char *));
	if (toks == NULL)
	{
		return (NULL);
	}
	tok = strtok(buff, " \n\t");

	while (tok != NULL)
	{
		toks[n] = tok;
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

int main()
{
	char **args, *buff;
	int exe, other;
	extern char **environ;
	pid_t pid;

	signal(SIGINT, my_handler);
	while (1)
	{
		write(1, "$ ", 2);
		buff = _line();

		if (buff == NULL)
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
			if(_strcmp(buff, "env") == 0)
			{
				printenv(environ);
			}
			else if(_strcmp(args[0], "exit") == 0)
			{
				printf("palabra: %s", args[0]);
				fflush(stdout);
				fprintf(stdout, "palab:");
			}
			else
			{	exe = execve(args[0], args, NULL);
				if (exe == -1)
				{
					perror("Error");
					free(buff);
					exit(0);
				}
			}
		}
		else
		{
			waitpid(pid, &other, WUNTRACED);
		}
	free(args);
	free(buff);
	}
	return (0);
}
