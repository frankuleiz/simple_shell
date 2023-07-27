#include "shell.h"

/**
 * search_path - searches for the command in the directories specified in PATH
 * @command: the command to be searched
 * Return: full path to the command or NULL if not found
 */
char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *dir_start, *dir_end;
	char *full_path;
	size_t dir_len, command_len, full_path_size;

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
		command_len = strlen(command);
		full_path_size = dir_len + 1 +command_len + 1;
		full_path = malloc (full_path_size);
		
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strncpy(full_path, dir_start, dir_len);
		full_path[dir_len] = '/';
		strncpy(full_path + dir_len + 1, command, command_len);
		full_path[full_path_size -1] = '\0';

		if (is_regular_file(full_path) && access(full_path, X_OK) == 0)
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
