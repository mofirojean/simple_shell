#include "main.h"

int main(int argc, char *argv[], char *env[])
{
	/* Test the print_env function */
	(void)argc;
	print_env(argv, env, argv);

	return (0);
}
