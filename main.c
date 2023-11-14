#include "main.h"

int main()
{
	/* Test the tokenise function */
	int i;
	char **result;

	result = tokenise("arg1 arg2 arg3 # comment");

	for (i = 0; result[i] != NULL; i++) {
		printf("Arg %d: %s\n", i + 1, result[i]);
		free(result[i]);
	}

	free(result);

	return (0);
}
