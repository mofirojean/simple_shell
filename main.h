#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>

extern char **environ;

/* Declaration of simple shell function */
int _putchar(char c);
void _puts(const char *str);
void free_args(char **args);

/* excution functions */
void execute_command(char **args, char *stringexe, char **env, char **av);
int execute_read(char *read, char **env, char **argv, int count,
		char **reads, char *reader);

/* get commandline arguments */
ssize_t _getline(char **line, size_t *line_size, int fd);
int get_user_input(char **input);

/* handle error to the console */
void print_exit_error(char *av, int count, char *status);
void print_cd_error(char *argv, int count, char *name);

/* handle common system task */
int handle_cd(char **args, char **env, char *argv, int count);
int handle_exit(char **args, char **av, char **env, int count,
		char **reads, char *read);

/* String tokenization function */
void free_arguments(char **args, char *str_copy);
char **tokenise(char *str);

/* Replace environment variable */
char **replace(char **args);

/* Shell path and navigation functions */
char *fix_path(char *filename);
int checkexe(char *filename);
char *str_add(char *filename);
char *string_add(void);

/* String manipulation functions */
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_strtok(char *src_string, const char *delim);
char *_strdup(const char *str);

/* Environment manipulation functions */
int _setenv(char **args, char **env, char *argv, int count);
int _setenv2(char *name, char *value, int overwrite);
int _unsetenv(char **args, char **env, char *argv, int count);
int print_env(char **args, char **env, char **argv);
char *_getenv(char *name);
int _putenv(char *name, char *string);

/* Memory manipulation functions */
void *_realloc(void *old_ptr, unsigned int new_size);
void *_realloc2(void *ptr, unsigned int old_size, unsigned int new_size);

/* Type conversion functions */
int _atoi(char *str);
char *print_nums(int num);

/* Handle common system task*/
int handle_built(char **args, char **env, char **argv, int count,
		char **reads, char *read);

/* Handles directory manipulation task*/
char *fix_dir(char *dir, char *cwd);
char *_getdir(char *dir);

/* Command error handling functions */
void command_not_found(char *program_name, int count, char *command_name);

#endif
