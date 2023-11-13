#include "main.h"

/**
 * checkexe - Checks if a file is in the system's executable path.
 * @filename: File name to be checked.
 *
 * This function searches the system's executable path ("/usr/bin/") to see
 * if the specified file exists in the path.
 *
 * Return: 1 if the file is found, 0 if not found or an error occurs.
 */
int checkexe(char *filename)
{
	struct dirent *dirent;
	DIR *dir;

	/* Open the directory "/usr/bin/" */
	dir = opendir("/usr/bin/");

	/* Check if the directory was opened successfully */
	if (dir)
	{
		/* Iterate through the directory entries */
		while ((dirent = readdir(dir)))
		{
			/* Check if the current entry matches the specified filename */
			if (_strcmp(dirent->d_name, filename))
			{
				closedir(dir);
				return (1);
			}
		}
	}
	else
	{
		perror("Error! Could not find path");
	}

	/* Close the directory and return 0 (file not found or an error occurred) */
	closedir(dir);
	return (0);
}

