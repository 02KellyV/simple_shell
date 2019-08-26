#include "simple_shell.h"

/**
* _getenv - Function that return a string of the environment varaible.
* @env: Variable type char *.
*
* Return: Variable type char *
*/

char *_getenv(char *env)
{
	char *var;
	int i = 0;

	while (environ[i])
	{
		var = strtok(environ[i], "=");
		if (!_strcmp(env, var))
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (0);
}

/**
 *
 */

void printenv()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("\n%s", environ[i]);
	}
}
