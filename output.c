#include "holberton.h"

ssize_t _getline(char *buffer, size_t size)
{
	ssize_t r = read(0, buffer, size);

	if (!r)
	{
		return (-1);
	}
	return (r);
}
