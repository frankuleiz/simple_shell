#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024
void execute_command(char *command);
char **parse_args(char *command);
char *find_path(char *command);

#endif
