#include "main.h"

/**
 * replace - Replaces variables in a list of command line arguments.
 * @args: List of command line arguments.
 *
 * This function iterates through the list of command line arguments,
 * and for each argument that starts with '$', it replaces the variable
 * with its corresponding value. If the variable is '$$', it is replaced
 * with the process ID. For other variables, it looks up their values
 * using the _getenv function and replaces them accordingly.
 *
 * Return: Modified list of command line arguments.
 */
char **replace(char **args)
{
	int n = 0;
	char *ptr, *ptr2, *get = NULL;

	while (args[n])
	{
		if (args[n][0] == '$')
		{
			if ((args[n][1] == '$') && args[n][2] == '\0')
			{
				/* still to implement this */
				get = print_nums(getpid());
				ptr2 = &args[n][0];
				args[n] = _realloc(ptr2, sizeof(get));
				_strcpy(args[n], get);
				free(get);
			}
			else
			{
				ptr = &args[n][1];
				ptr2 = &args[n][0];
				get = malloc(_strlen(_getenv(ptr)) + 1);
				_strcpy(get, _getenv(ptr));
				args[n] = _realloc(ptr2, sizeof(get));
				_strcpy(args[n], get);
				free(get);
			}
		}
		n++;
	}
	return (args);
}


