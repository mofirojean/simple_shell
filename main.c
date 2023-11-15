#include "main.h"

int main()
{
	char *input = NULL;

	while (get_user_input(&input))
	{
		printf("User input: %s\n", input);
		free(input);
		input = NULL;
	}

	return (0);
}
