#include "shell.h"
/**
 * is_executable_file - checks if it is anexecutable file
 * @path: path handler
 * Return: 1 if executable, 0 otherwise
 */
int is_executable_file(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0 && S_ISREG(st.st_mode) && access(path, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * is_regular_file - regular path
 * @path: path handler
 * Return: 1 if regular, 0 otherwise
 */
int is_regular_file(const char *path)
{
	struct stat st;

	return (stat(path, &st) == 0 && S_ISREG(st.st_mode));
}
