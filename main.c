#include "holberton.h"

/**
 * main - take EOF signal to exit
 * @argc: count
 * @argv: std input
 * Return: 0.
 */

int main()
{
	char *buffer;
	size_t len = 32;
	ssize_t chars;

	while (1)
	{
		printf("$ ");
		chars = getline(&buffer, &len, stdin);

		if (chars == -1)
		{
			printf("\n");
			return (0);
		}

	}
	return (0);
}
