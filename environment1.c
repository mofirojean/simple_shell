#include "main.h"

/**
 * _setenv - Changes or adds an environment variable.
 * @args: Command line arguments.
 * @envp: Environment variables.
 * @argv: Current executable filename.
 * @count: Count.
 *
 * Return: 1 if successful, otherwise 0.
 */
int _setenv(char **args, char **envp, char *argv, int count)
{
	char *output;
	int i = 0, overwrite = 1;
	size_t name_len, val_len;
	char *init_value;

	(void)envp;
	(void)argv;
	(void)count;

	if (args[1] == NULL || args[2] == NULL || args[1][0] == '\0')
		return (1);

	name_len = _strlen(args[1]);
	val_len = _strlen(args[2]);

	output = malloc(name_len + val_len + 2);

	_strcpy(output, args[1]);
	output[name_len] = '=';
	_strcpy(output + name_len + 1, args[2]);
	output[name_len + val_len + 1] = '\0';

	init_value = _getenv(args[1]);

	if (!init_value || overwrite)
		i = _putenv(args[1], output);

	if (i)
		_puts("Error\n");

	free(output);
	return (1);
}

/**
 * _setenv2 - Changes or adds an environment variable.
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 * @overwrite: 1 (true) to overwrite, 0 (false) to keep the existing value.
 *
 * Return: 1 if successful, otherwise 0.
 */
int _setenv2(char *name, char *value, int overwrite)
{
	size_t name_len, val_len;
	char *init_value;
	int i = 0;
	char *output;

	if (name == NULL || value == NULL || name[0] == '\0')
	{
		_puts("Error\n");
		return (1);
	}
	name_len = _strlen(name);
	val_len = _strlen(value);

	output = malloc(name_len + val_len + 2);
	if (!output)
	{
		_puts("Error\n");
		return (1);
	}
	_strcpy(output, name);
	output[name_len] = '=';
	_strcpy(output + name_len + 1, value);
	output[name_len + val_len + 1] = '\0';

	init_value = malloc(_strlen(_getenv(name)) + 1);
	if (!init_value)
	{
		_puts("Error\n");
		free(output);
		return (1);
	}
	_strcpy(init_value, _getenv(name));
	if (!init_value || overwrite)
		i = _putenv(name, output);
	if (i)
		_puts("Error\n");
	free(init_value);
	free(output);
	return (1);
}

/**
 * _unsetenv - Removes an environment variable.
 * @args: Command line arguments.
 * @envp: Environment variables.
 * @argv: Current executable filename.
 * @count: Count.
 *
 * Return: 1 if the operation is successful, otherwise 0.
 */
int _unsetenv(char **args, char **envp, char *argv, int count)
{
	char *name;
	int i;

	(void)envp;
	(void)argv;
	(void)count;

	if (args[1] == NULL || args[1][0] == '\0')
	{
		_puts("Error\n");
		return (1);
	}

	name = malloc(_strlen(args[1]) + 2);
	if (name == NULL)
	{
		_puts("Error\n");
		return (1);
	}

	_strcpy(name, args[1]);
	_strcpy(name + _strlen(args[1]), "=");
	name[_strlen(args[1]) + 1] = '\0';

	i = _putenv(name, name);

	if (i)
		_puts("Error\n");

	free(name);
	return (1);
}

