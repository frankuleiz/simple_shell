#include "shell.h"
/**
 * _strcpy - copies a string
 * @dest: points to the destination of string
 * @src: points to the source of string
 * Return: the destination
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
