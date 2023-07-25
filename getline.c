#include "shell.h"
/**
 * bring_line - determines the line variable for fetch_line
 * @input: buffer for storing input string
 * @buffer: the string called
 * @n: size of the line
 * @j: size of the buffer
 */

void bring_line(char **input, size_t *n, char *buffer, size_t j)
{
	if (*input == NULL)
	{
		if (j > BUFSIZ)
			*n = j;
		else
			*n = BUFSIZ;
		*input = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZ)
			*n = j;
		else
			*n = BUFSIZ;
		*input = buffer;
	}
	else
	{
		strcpy(*input, buffer);
		free(buffer);
	}
}
/**
 * fetch_line - fetches the string input
 * @input: buffer for storig input string
 * @n: size of input string
 * @stream: the strean to fetch the string
 * Return: value
 */
ssize_t fetch_line(char **input, size_t *n, FILE *stream)
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

	buffer = malloc(sizeof(char) * BUFSIZ);
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
		if (var >= BUFSIZ)
			buffer = _realloc(buffer, var, var + 1);
		buffer[var] = t;
		var++;
	}
	buffer[var] = '\0';
	bring_line(input, n, buffer, var);
	value = var;
	if (i != 0)
		var = 0;
	return (value);
}
