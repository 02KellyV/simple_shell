#include "simple_shell.h"

/**
* main - Shell functions
* @argc: The number of arguments, variable unused.
* @argv: Arguments.
* 
* Return: A int value.
*/
int main(void)
{
	char *buff, *tok[100];
	size_t size = 0;
	int line, exe, other, n = 1;

	buff = malloc(sizeof(char *) * 1024);
	if(buff == NULL)
		return(0);
	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buff, &size, stdin);
		buff[strlen(buff) - 1] = '\0';
		if (line == -1)
		{
			perror("Error");
			break;
		}
		tok[0] = strtok(buff, " \n\t");
		while(tok[n] != '\0')
		{
			tok[n] = strtok(NULL, " \n\t");
			n++;
		}
		tok[n] = NULL;
	/*	printf("%s\n", tok[1]); */
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
