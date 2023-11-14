#include "main.h"

/**
 * _realloc - Reallocates memory.
 * @old_ptr: Pointer to the memory to be reallocated.
 * @new_size: New size of the memory block.
 *
 * This function reallocates the memory block pointed
 * to by old_ptr to a new size.
 *
 * Return: A pointer to the reallocated memory block.
 */
void *_realloc(void *old_ptr, unsigned int new_size)
{
	void *new_ptr;
	unsigned int old_size;

	if (!old_ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(old_ptr), NULL);
	if (new_size == sizeof(old_ptr))
		return (old_ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = sizeof(old_ptr) < new_size ? sizeof(old_ptr) : new_size;
	while (old_size--)
		((char *)new_ptr)[old_size] = ((char *)old_ptr)[old_size];

	free(old_ptr);
	return (new_ptr);
}

/**
 * _realloc2 - Reallocates memory with zero initialization.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Old size of the allocated memory.
 * @new_size: New size to reallocate.
 *
 * Return: Pointer to the reallocated memory.
 */
void *_realloc2(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		char *old_ptr = ptr;
		char *new_ptr_char = new_ptr;
		unsigned int i;

		/* Copy the contents of the old memory to the new memory */
		for (i = 0; i < old_size && i < new_size; ++i)
		{
			new_ptr_char[i] = old_ptr[i];
		}
		free(ptr);
	}

	return (new_ptr);
}

