#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *name)
{
	int i;

	if (!name)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		int j = 0;

		while (name[j] && name[j] == environ[i][j])
			j++;

		if (name[j] == '\0' && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}

	return (NULL);
}


/**
 * _putenv - Replaces or adds an environment variable.
 * @name: Name of the environment variable.
 * @string: Environment variable in the form "name=value".
 *
 * This function replaces or adds an environment variable
 * with the specified name and value.
 *
 * Return: 0 on success, -1 on failure.
 */
int _putenv(char *name, char *string)
{
	int i;
	int entries_count;
	char *new_entry;

	if (!name || !string)
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		int j = 0;

		while (name[j] && name[j] == environ[i][j])
			j++;
		if (name[j] == '\0')
		{
			/* Found a matching environment variable */
			free(environ[i]);
			environ[i] = malloc(_strlen(string) + 1);
			if (!environ[i])
				return (-1);
			/* Update the environment variable with the new value */
			_strcpy(environ[i], string);
			return (0);
		}
	}
	/* If the name is not found, add a new environment variable */
	new_entry = malloc(_strlen(string) + 1);

	if (!new_entry)
		return (-1);
	_strcpy(new_entry, string);
	entries_count = 0;

	while (environ[entries_count])
		entries_count++;

	environ[entries_count] = new_entry;
	entries_count++;
	environ[entries_count] = NULL;

	return (0);
}

