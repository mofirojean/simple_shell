#include "main.h"

int main()
{
	/* Test the replace function */
	char *line = NULL;
	size_t line_size = 0;
	ssize_t chars_read;

	printf("Enter a line of text:\n");
	chars_read = _getline(&line, &line_size, STDIN_FILENO);

	if (chars_read == -1)
	{
		fprintf(stderr, "Error reading line\n");
		free(line);
		return (EXIT_FAILURE);
	}

	printf("You entered: %s\n", line);
	free(line);


	return (0);
}
