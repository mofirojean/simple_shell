#include "main.h"

/**
 * replace - replaces variables
 * @args: list of cmd line arguments
 * Return: modified args
 */
char **replace(char **args) {
    int i;
    char *ptr, *ptr2, *envValue;

    for (i = 0; args[i] != NULL; i++) {
        if (args[i][0] == '$') {
            if ((args[i][1] == '$') && args[i][2] == '\0') {
                char pidStr[10];
                sprintf(pidStr, "%d", getpid());
                ptr2 = &args[i][0];
                args[i] = realloc(ptr2, strlen(args[i]) + 1 + sizeof(pidStr));
                strcpy(args[i], pidStr);
            } else {
                ptr = &args[i][1];
                envValue = getenv(ptr);
                if (envValue != NULL) {
                    ptr2 = &args[i][0];
                    args[i] = realloc(ptr2, strlen(args[i]) + 1 + strlen(envValue));
                    strcpy(args[i], envValue);
                }
            }
        }
    }
    return (args);
}



