#include "main.h"

/**
 * _strtok - Tokenizes a string.
 * @src_string: The string to tokenize.
 * @delim: List of delimiters.
 *
 * Return: The next token or NULL if no more tokens.
 */
char *_strtok(char *src_string, const char *delim)
{
	static char *last_token;
	char *token = NULL;

	if (src_string != NULL)
		last_token = src_string;
	else if (last_token == NULL)
		return (NULL);

	token = last_token;

	while (*last_token != '\0')
	{
		const char *p = delim;

		while (*p != '\0')
		{
			if (*last_token == *p++)
			{
				*last_token++ = '\0';
				return (token);
			}
		}

		last_token++;
	}

	last_token = NULL;
	if (_strcmp(token, ""))
		return (_strtok(NULL, " "));

	return (token);
}

/**
 * _strdup - Duplicates a string.
 * @str: Input string to duplicate.
 *
 * This function allocates memory for a new string containing a duplicate
 * of the input string. The caller is responsible for freeing the allocated
 * memory.
 *
 * Return: Pointer to the duplicated string (NULL if memory allocation fails).
 */
char *_strdup(const char *str)
{
	char *duplicate;
	size_t length, i;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	length = 0;
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicated string */
	duplicate = malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	/* Copy the characters from the input string to the duplicated string */
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

