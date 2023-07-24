#include "shell.h"
/**
 *find_path - Handle the PATH
 *@command: command to search for
 *
 * Return: full path or NULL
 */
char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *dir_start, *dir_end, *full_path;
	struct stat st;
	size_t dir_len;

	if (path == NULL)
	{
		return (NULL);
	}
	dir_start = path;
	while (*dir_start)
	{
		dir_end = strchr(dir_start, ':');
		if (dir_end == NULL)
		{
			dir_end = dir_start + strlen(dir_start);
		}
		dir_len = dir_end - dir_start;
		full_path = malloc(dir_len + 1 + strlen(command) + 1);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strncpy(full_path, dir_start, dir_len);
		full_path[dir_len] = '/';
		strncpy(full_path + dir_len + 1, command, strlen(command) + 1);
		if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		dir_start = dir_end;
		if (*dir_start == ':')
		{
			dir_start++;
		}
	}
	return (NULL);
}
