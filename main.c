#include "main.h"

int main()
{
	/* Test the str_add function */
	char *result = str_add("command");
	printf("Result: %s\n", result);
	free(result);

	return (0);
}
