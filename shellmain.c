#include "shell.h"
/**
 *main - main method for shell
 *
 *Return: always 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
		char prompt[] = "#cisfun$ ";

		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		characters = getline(&command, &bufsize, stdin);

		if (characters == -1)
		{
			if (feof(stdin))
			{
				char new_line[] = "\n";

				write(STDOUT_FILENO, new_line, sizeof(new_line) - 1);
				free(command);
				break;
			}
			else
			{
				char error_msg[] = "getline error\n";

				write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
				exit(EXIT_FAILURE);
			}
		}
		if (characters > 0 && command[characters - 1] == '\n')
		{
			command[characters - 1] = '\0';
		}
		execute_command(command);
	}
	return (0);
}
