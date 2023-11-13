#include "main.h"

/**
 * fix_path - Fixes the path if the file exists.
 * @filename: File name to be fixed.
 *
 * This function checks if the file exists in the current path. If it does,
 * it appends the appropriate extension to the file name; otherwise, it returns
 * the original file name.
 *
 * Return: Fixed file name.
 */
char *fix_path(char *filename)
{
	if (checkexe(filename))
	{
		return (str_add(filename));
	}
	else
	{
		char *stringexe = malloc(_strlen(filename) + 1);

		_strcpy(stringexe, filename);
		return (stringexe);
	}
}

/**
 * str_add - Adds "/bin/" prefix to a given string.
 * @filename: Input string.
 *
 * This function dynamically allocates memory to concatenate the "/bin/"
 * prefix to the specified string, creating a new string.
 *
 * Return: The resulting string with the "/bin/" prefix.
 */
char *str_add(char *filename)
{
	size_t length = _strlen(filename);
	char *result = malloc(length + 1 + 5);

	if (result == NULL)
		return (NULL);

	_strcpy(result, "/bin/");
	_strcpy(result + 5, filename);
	result[length + 5] = '\0';

	return (result);
}

/**
 * string_add - Generates the string "/bin/" needed to fix the path.
 *
 * This function dynamically allocates memory and creates the string "/bin/".
 *
 * Return: The dynamically allocated string "/bin/".
 */
char *string_add(void)
{
	/* Allocate memory for the string "/bin/" */
	char *binstr = malloc(6);

	if (binstr == NULL)
		return (NULL);

	binstr[0] = '/';
	binstr[1] = 'b';
	binstr[2] = 'i';
	binstr[3] = 'n';
	binstr[4] = '/';
	binstr[5] = '\0';

	return (binstr);
}

