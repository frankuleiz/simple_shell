#include "shell.h"

char **parse_args(char *command)
{
    char *start = command;
    int i = 0;

    char **args = malloc(BUFSIZE * sizeof(char *));
    if (args == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (*command)
    {
        while (*command && isspace(*command))
        {
            *command = '\0';
            command++;
        }
        if (*command == '\0')
        {
            break;
        }
        start = command;

        if (*command == 'e' && strncmp(command, "exit", 4) == 0)
        {
            command += 4;
            while (*command && isspace(*command))
            {
                command++;
            }
            if (*command == '\0')
            {
                args[i++] = start;
                args[i] = NULL;
                return args;
            }
        }

        while (*command && !isspace(*command))
        {
            command++;
        }
        args[i++] = start;

        if (*command)
        {
            *command++ = '\0';
        }
    }
    args[i] = NULL;
    return args;
}
