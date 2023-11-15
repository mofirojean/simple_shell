#include "main.h"

/**
 * handle_builtin - Handles built-in shell commands.
 * @args: List of command line arguments.
 * @env: Environment variables.
 * @argv: Contains the name of the running shell executable.
 * @count: Command count.
 * @reads: Array of previously read input lines.
 * @read: Current input line being processed.
 *
 * This function checks if the first argument in the command line corresponds
 * to a built-in shell command (e.g., exit, setenv, unsetenv, cd, env).
 * If a built-in command is found, the corresponding handler is invoked.
 *
 * Return: 1 if a built-in command is found and handled, 0 otherwise.
 */
int handle_built(char **args, char **env, char **argv, int count,
		char **reads, char *read)
{
	if (_strcmp(args[0], "exit"))
	{
		handle_exit(args, argv, env, count, reads, read);
		return (1);
	}
	else if (_strcmp(args[0], "setenv"))
	{
		_setenv(args, env, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv"))
	{
		_unsetenv(args, env, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "cd"))
	{
		handle_cd(args, env, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "env"))
	{
		print_env(args, env, argv);
		return (1);
	}
	return (0);
}

