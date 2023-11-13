#include "main.h"

int main()
{
	int *arr = malloc(3 * sizeof(int)), *new_arr;
	int i;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	/* Resize the array to accommodate more elements */
	new_arr = _realloc(arr, 5 * sizeof(int));

	/* Display the resized array */
	for (i = 0; i < 5; i++) {
		printf("%d \n", new_arr[i]);
	}

	free(new_arr);

	return (0);
}
