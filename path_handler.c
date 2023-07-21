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
	char *dir, *full_path;
	struct stat st;

	if (path == NULL)
	{
		return (NULL);
	}
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
