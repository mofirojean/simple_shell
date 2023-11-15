#include "main.h"

/**
 * _putchar - Prints a single character to the console.
 * @c: The character to be printed.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a null-terminated string to the console.
 * @str: The string to be printed.
 *
 * Return: void
 */
void _puts(const char *str)
{
	if (!str)
		return;

	/* Loop through the string and print each character */
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

