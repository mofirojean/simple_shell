#include "main.h"

/**
 * fix_dir - Combines the directory path 'dir' with 'cwd'.
 * @dir: Original directory path to be combined.
 * @cwd: Current working directory path.
 *
 * This function appends the original directory path to
 * the current working directory and returns the modified
 * directory path. The original 'dir' is freed, and the
 * modified path is allocated dynamically.
 *
 * Return: Pointer to the combined and fixed directory path.
 */
char *fix_dir(char *dir, char *cwd)
{
	cwd[_strlen(cwd)] = '/';
	cwd[_strlen(cwd) + 1] = '\0';
	_strcpy(&(cwd[_strlen(cwd)]), dir);
	free(dir);
	dir = malloc(_strlen(cwd) + 1);
	_strcpy(dir, cwd);

	return (dir);
}

/**
 * _getdir - Gets the directory path based on the input.
 * @dir: User-provided directory path or NULL.
 *
 * This function returns the appropriate directory path based
 * on the input 'dir'.If 'dir' is NULL, it returns the home
 * directory path. If 'dir' is "-", it returns the previous
 * working directory path ('OLDPWD').
 *
 * Return: Allocated directory path (should be freed by the caller).
 */
char *_getdir(char *dir)
{
	char *result = NULL;

	if (dir == NULL)
	{
		result = _strdup(_getenv("HOME"));
	}
	else if (_strcmp(dir, "-"))
	{
		result = _strdup(_getenv("OLDPWD"));
		_puts(result);
		_putchar('\n');
	}

	return (result);
}

