#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to dest.
 * @dest: The destination buffer to copy to.
 * @src: The source string to copy from.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	int length = 0;
	int i;

	while (src[length] != '\0')
	{
		length++;
	}
	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[length] = '\0';

	return (dest);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string, where the result is stored.
 * @src: The source string to be appended.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (*src != '\0')
	{
		dest[dest_len++] = *src++;
	}

	dest[dest_len] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 == *str2);
}

/**
 * _strlen - Returns the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;

	while (*str++)
	{
		len++;
	}

	return (len);
}

