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

