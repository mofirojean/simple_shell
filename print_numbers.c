#include "main.h"

/**
 * print_nums - Converts an integer to its string representation.
 * @num: The integer to convert.
 *
 * Return: String represention of the integer.
 */
char *print_nums(int num)
{
	int pow = 10, tracker = 0;
	char *string;
	int j = 0;

	while ((pow * 10) <= num)
	{
		j++;
		pow *= 10;
	}
	string = malloc(j + 3);
	j = 0;

	while (num >= 10)
	{
		int digit = num / pow;

		num -= (pow * digit);
		string[j++] = (digit + '0');

		if (num == 0)
		{
			while (pow != 1)
			{
				pow /= 10;
				tracker++;
			}
			break;
		}

		pow /= 10;
	}

	if (num != 0)
		string[j++] = (num + '0');
	else
		for (int i = 0; i < tracker; i++)
			string[j++] = '0';

	string[j] = '\0';
	return (string);
}

