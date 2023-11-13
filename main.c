#include "main.h"

int main()
{
	int i;

	/* Test the _putenv function */
	_putenv("MY_VAR", "value1");
	_putenv("ANOTHER_VAR", "value2");


	/* Display the updated environment variables */
	for (i = 0; environ[i]; i++) {
		printf("environ[%d]: %s\n", i, environ[i]);
	}

	return (0);
}
