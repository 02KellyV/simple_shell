#include "simple_shell.h"

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *get_path(void)
{
        char *var;
        int i = 0;

        while (environ[i])
        {
                var = strtok(environ[i], "=");
                if (!_strcmp(var, "PATH"))
                {
                        return strtok(NULL, "=");
                }
                var = strtok(NULL, "=");
                i++;
        }
	return NULL;
}

char **concat_path(char **args)
{
        char *path, **paths, *tok;
        int n = 0;

        path = get_path();
        tok = strtok(path, ":");

	paths = malloc(64 * sizeof(char *));

        while (tok != NULL)
        {
		paths[n] = concat(tok, concat("/", args[0]));
                n++;
                tok = strtok(NULL, ":");
        }
        paths[n] = NULL;
        return paths;
}

/**
* my_handler - a signal handler
* @var: Variable type int.
* Return: void function.
*/

void _execve(char **args)
{
	int exe, flag = 0, n = 0;
	char **path, **exec;

	path = concat_path(args);

        exe = execve(args[0], args, NULL);
	exec = malloc(64 * sizeof(char *));
	while(path[n] != NULL)
	{
		exec[0] = path[n];
		exec[1] = NULL;
		exe = execve(exec[0], exec, NULL);
		if(exe != -1)
		{
			flag = 1;
		}
		n++;
	}
	if (flag == 0)
	{
		perror("Error");
		exit(0);
	}
}
