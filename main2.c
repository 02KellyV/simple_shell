#include "holberton.h"

/**
 * main - shel functions, EOF and /bin/ls.
 * Return: Always 0.
 */

int main(void)
{
	char *buff = NULL;
	size_t size = 0;
	ssize_t line;
	char *tok, *argv[] = {"", NULL};
	int exe;

	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buff, &size, stdin);
		if (line == -1)
		{
			printf("\n");
			return (0);
		}
		tok = strtok(buff, " \n");
		if (fork() == 0)
		{
			exe = execve(tok, argv, NULL);
			if (exe == -1)
			{
				perror("hsh");
				free(buff);
			}
		}
		free(buff);
	}
	return (0);
}
