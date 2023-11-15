#include "main.h"

/**
 * execute_command - Executes cmd after fixing them.
 * @args: Arguments
 * @stringexe: Executable file
 * @envp: environment variables
 * @av: argv
 *
 * Return: void
 */
void execute_command(char **args, char *stringexe, char **envp, char **av)
{
	(void)envp;
	if (execve(stringexe, args, environ) == -1)
	{
		perror(av[0]);
		exit(1);
	}
}
