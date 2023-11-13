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

