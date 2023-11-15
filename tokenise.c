#include "main.h"

/**
 * tokenise - Tokenizes the given string into an array of arguments.
 * @str: Input string to be tokenized.
 *
 * This function tokenizes the input string based on space (' ') delimiters,
 * excluding lines starting with '#' or containing only spaces. It returns
 * an array of arguments.
 *
 * Return: Array of arguments (NULL if unsuccessful).
 */
char **tokenise(char *str)
{
	char *token, **args = NULL, *str_copy;
	int i = 0;

	if (!str)
		return (NULL);
	str_copy = _strdup(str);
	if (!str_copy)
		return (NULL);
	token = _strtok(str_copy, " ");
	while (token)
	{
		if (_strcmp(token, "#") || token[0] == '#')
			break;
		if (!_strcmp(token, ""))
		{
			args = _realloc2(args, i * sizeof(char *), (i + 1) * sizeof(char *));
			if (args == NULL)
			{
				while (i > 0)
					free(args[--i]);
				free_arguments(args, str_copy);
				return (NULL);
			}
			args[i++] = _strdup(token);
			if (args[i - 1] == NULL)
			{
				while (i > 0)
					free(args[--i]);
				free_arguments(args, str_copy);
				return (NULL);
			}
		}
		token = _strtok(NULL, " ");
	}
	args = _realloc2(args, i * sizeof(char *), (i + 1) * sizeof(char *));
	if (args)
		args[i] = NULL;
	free(str_copy);
	return (args);
}

/**
 * free_arguments - Free array of arguments.
 * @args: Input argument to be freed.
 * @str_copy: Input argument to be freed.
 *
 * Return: void.
 */
void free_arguments(char **args, char *str_copy)
{
	free(args);
	free(str_copy);
}

