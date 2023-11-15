#include "main.h"

/**
 * handle_cd - Handles the 'cd' built-in command.
 * @args: Command line arguments.
 * @env: Environment variables.
 * @argv: Name of the current executable file.
 * @count: Current count.
 *
 * This function handles the 'cd' command, changing the
 * current working directory.
 *
 * Return: 0 (Success), 1 (Fail)
 */
int handle_cd(char **args, char **env, char *argv, int count)
{
	char *dir = NULL, *oldpwd = NULL, cwd[1024], *new_dir;
	int result;

	(void)env;
	if (args[1])
		dir = _strdup(args[1]);
	if (!getcwd(cwd, sizeof(cwd)))
		perror("Failed to get Path\n");
	oldpwd = _strdup(cwd);
	if (args[1] != NULL && (!_strcmp(dir, "-") || !_strcmp(dir, "~")))
	{
		result = chdir(dir);
		dir = fix_dir(dir, cwd);
	}
	else
	{
		new_dir = _getdir(dir);
		result = chdir(new_dir);
		free(dir);
		dir = new_dir;
	}
	if (result == -1)
	{
		print_cd_error(argv, count, args[1]);
		return (1);
	}
	if (_strcmp(args[1], "..") || _strcmp(args[1], "."))
	{
		_setenv2("PWD", getcwd(cwd, sizeof(cwd)), 1);
	}
	else
	{
		_setenv2("PWD", dir, 1);
	}
	_setenv2("OLDPWD", oldpwd, 1);
	free(oldpwd);
	free(dir);
	return (0);
}

/**
 * print_cd_error - Prints an error message for the 'cd' command.
 * @argv: Name of the executable file.
 * @count: Current count.
 * @name: Directory name for 'cd'.
 *
 * This function prints an error message when the 'cd'
 * command encounters an issue.
 */
void print_cd_error(char *argv, int count, char *name)
{
	_puts(argv);
	_puts(": ");
	_putchar(count + '0');
	_puts(": cd: can't cd to ");
	_puts(name);
	_putchar('\n');
}

/**
 * handle_exit - Handles the exit command.
 * @args: Command line arguments.
 * @av: Array containing the name of the executable file.
 * @env: Environment variables.
 * @count: Current count.
 * @reads: Array of read strings.
 * @read: Current read string.
 *
 * Return: Integer exit status.
 */
int handle_exit(char **args, char **av, char **env, int count,
		char **reads, char *read)
{
	int exit_status;

	(void)env;

	if (args[1] == NULL || _strcmp(args[1], "0"))
	{
		free_args(args);
		free(read);
		free_args(reads);
		exit(0);
	}
	exit_status = _atoi(args[1]);
	if (exit_status <= 0)
	{
		pid_t child = fork();

		if (child == 0)
		{
			print_exit_error(av[0], count, args[1]);
			free_args(args);
			free_args(reads);
			free(read);
			exit(2);
		}
		else
		{
			int child_stat;

			waitpid(child, &child_stat, 0);
			if (WIFEXITED(child_stat))
				exit_status = WEXITSTATUS(child_stat);
			return (0);
		}
	}
	free_args(reads);
	free(read);
	free_args(args);
	exit(exit_status);
}


/**
 * print_exit_error - Prints an exit error message.
 * @av: Name of the executable file.
 * @count: Current count.
 * @status: Exit status string.
 *
 * Prints an error message when an invalid exit status is provided.
 */
void print_exit_error(char *av, int count, char *status)
{
	_puts(av);
	_puts(": ");
	_putchar(count + '0');
	_puts(": exit: Illegal number: ");
	_puts(status);
	_putchar('\n');
}
