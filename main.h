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

extern char **environ;

/* Declaration of  */
int _putchar(char c);
void _puts(const char *str);

/* String manipulation functions */
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_strtok(char *src_string, const char *delim);


#endif
