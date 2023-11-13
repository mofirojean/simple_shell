#include "main.h"

/**
 * _atoi - Converts a string into an integer.
 * @str: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *str)
{
	int sign = 1, i = 0;
	unsigned int result = 0;

	/* Handle sign */
	while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	/* Convert digits to integer */
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}

	/* Apply sign to the result */
	result *= sign;

	return (result);
}

