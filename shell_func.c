#include "main.h"

/**
 * free_args - Frees the memory allocated for an array of strings.
 * @args: The array of strings to be freed.
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}

	free(args);
}

/**
 * get_user_input - Reads a line of input from the user.
 * @input: Pointer to store the user input.
 * Return: 1 on success, 0 on failure.
 */
int get_user_input(char **input)
{
	ssize_t chars_read;
	size_t buffer_size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	chars_read = _getline(input, &buffer_size, STDIN_FILENO);

	if (chars_read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (0);
	}

	return (1);
}

/**
 * command_not_found - Prints an error message for a command not found.
 * @program_name: Name of the program being executed.
 * @count: The command count in the shell.
 * @command_name: The name of the command that was not found.
 *
 * This function prints an error message indicating that the specified
 * command was not found. It uses the program name, command count, and
 * the name of the command in the output.
 */
void command_not_found(char *program_name, int count, char *command_name)
{
	_puts(program_name);
	_puts(": ");
	_putchar(count + '0');
	_puts(": ");
	_puts(command_name);
	_puts(": not found\n");
}

