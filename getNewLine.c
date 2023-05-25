#include "monty.h"

/**
 * getNewLine - Reads a line from a file.
 * @fp: Pointer to the file to read from.
 * Return: On success, returns a pointer to the line read from the file.
 * On failure, returns NULL.
 */

char *getNewLine(FILE *fp)
{
	char *line = (char *)malloc(MAX_LINE_LENGTH);

	if (!line)
	{
		return (NULL);
	}
	if (fgets(line, MAX_LINE_LENGTH, fp))
	{
		return (line);
	}
	free(line);
	return (NULL);
}
