#include "shell.h"
/**
 * bring_line - determines the line variable for fetch_line
 * @lineptr: buffer for storing input string
 * @buffer: the string called
 * @n: size of the line
 * @j: size of the buffer
 */

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * fetch_line - fetches the string input
 * @lineptr: buffer for storig input string
 * @n: size of input string
 * @stream: the strean to fetch the string
 * Return: value
 */
ssize_t fetch_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t var;
	ssize_t value;
	char *buffer;
	char t = 'z';

	if (var == 0)
		fflush(stream);
	else
		return (-1);
	var = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && var == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && var != 0)
		{
			var++;
			break;
		}
		if (var >= BUFSIZE)
			buffer = _realloc(buffer, var, var + 1);
		buffer[var] = t;
		var++;
	}
	buffer[var] = '\0';
	bring_line(lineptr, n, buffer, var);
	value = var;
	if (i != 0)
		var = 0;
	return (value);
}
