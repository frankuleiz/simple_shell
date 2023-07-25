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

int  is_regular_file(const char *path);
#define IS_EXECUTABLE_FILE(path)(access(path, X_OK) == 0 && is_regular_file(path))
extern char **environ;
void execute_command(char *command);
char **parse_args(char *command);
char *find_path(char *command);
void execute_env(void);
int is_executable_file(const char *path);
int is_regular_file(const char *path);
char *_strcpy(char *dest, char *src);
void bring_line(char **input, size_t *n, char *buffer, size_t j);
ssize_t fetch_line(char **input, size_t *n, FILE *stream);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
