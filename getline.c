#include "main.h"

/**
 * _getline - Custom implementation of getline function
 * @line: Pointer to the buffer storing the line
 * @line_size: Size of the buffer
 * @fd: File descriptor to read from
 * Return: Number of characters read or -1 on failure
 */
ssize_t _getline(char **line, size_t *line_size, int fd)
{
	static char *buffer;
	static size_t buffer_size;
	size_t i = 0;
	char character;
	ssize_t read_result;

	if (!buffer)
	{
		buffer_size = BUFSIZ;
		buffer = malloc(buffer_size);
		if (!buffer)
			return (-1);
	}

	while ((read_result = read(fd, &character, 1)) > 0)
	{
		if (character == '\n')
			break;

		buffer[i++] = character;
		if (i == buffer_size)
		{
			buffer_size *= 2;
			buffer = _realloc(buffer, buffer_size);
			if (!buffer)
				return (-1);
		}
	}

	buffer[i] = '\0';
	*line = buffer;
	*line_size = buffer_size;

	if (read_result <= 0 && i == 0)
		return (-1);
	return (i);
}
