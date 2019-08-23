#include "simple_shell.h"

/**
 * usetok - Shell functions
 * @buff: to save info
 * @tok: pointer to chars array
 * Return: A char value.
 */

void usetok(char *buff, char *tok[])
{
	int n = 1;

	tok[0] = strtok(buff, " \n\t");
	while (tok[n] != '\0')
	{
		tok[n] = strtok(NULL, " \n\t");
		n++;
	}
	tok[n] = NULL;
}

/**
* main - Contains the basic Shell functions
* Return: void.
*/

int main(void)
{
	char *buff, *tok[100];
	size_t size = 0;
	int line, exe, other;

	buff = malloc(sizeof(char *) * 1024);
	if (buff == NULL)
		return (0);
	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buff, &size, stdin);
		buff[strlen(buff) - 1] = '\0';
		if (line == -1)
		{
			write(1, "\n", 2);
			exit(0);
			break;
		}
		usetok(buff, tok);
		if (fork() == 0)
		{
			exe = execve(tok[0], tok, NULL);
			if (exe == -1)
			{
				perror("Error");
				free(buff);
				exit(0);
			}
		}
		else
		{
			wait(&other);
		}
	}
	free(buff);
	return (0);
}
