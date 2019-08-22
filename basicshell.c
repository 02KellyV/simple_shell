int main()
{
	char *buff = NULL;
	char *argv[] = {"", NULL}; 
	char *tok;
	size_t size = 0;
	int line, exe;

	while (1)
	{
		write(1, "$ ", 2);
		line = getline(&buff, &size, stdin);

		if (status == -1)
		{
		/* Acá debemos considerar el error, pero no entiendo bien que hace perror */
			perror();
			free(buff);
		}

		tok = strtok(buff, " \n");
		if (fork() == 0)
		{
		exe = execve(tok, argv, NULL);
			if (exe == -1)
			{
			/* Acá debemos considerar el error, pero no entiendo bien que hace perror */
			perror();
			free(buff);
			}	
		}
		/* Entender como funciona wait dentro del fork, que debe llevar */
		}
		free(buff);
	}
return (0);
}
