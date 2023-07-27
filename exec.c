#include "shell.h"
/**
 *execute_command - execute a given command
 *@command: the command to be executed
 */
void execute_command(char *command)
{
        int status;
        char **args;
        pid_t pid;

        if (strcmp(command, "exit") == 0)
           {
              char *arg = strchr(command, ' ');

              if (arg != NULL)
                {
                   status = atoi(arg + 1);
                } else {
                   status = 0;
                }
              _exit(status);
    }

        if (strcmp(command, "env") == 0)
        {
                execute_env();
                return;
        }
        args = parse_args(command);
        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                free(args);
                exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
                execve(command, args, NULL);
                perror(command);
                free(args);
                exit(EXIT_FAILURE);
        }
        else
        {
                wait(&status);
                free(args);
        }
}
