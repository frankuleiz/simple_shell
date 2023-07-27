#include "shell.h"

/**
 * read_line - reads the input string
 * @i_eof: getline return value
 * return: input string
 */

char *read_line(int *i_eof)
{
	char *var = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&var, &bufsize, stdin);

	return (var);
}
