#include "monty.h"
#include <unistd.h>

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: Array of pointers to the arguments passed
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	processFile(fp);
	fclose(fp);
	return (EXIT_SUCCESS);
}
