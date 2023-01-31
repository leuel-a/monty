#include "monty.h"

char *lineptr;

/**
 * main - Entry point of program
 * @argc: the number of command line arguments
 * @argv: array that has the command line arguments.
 *
 * Return: On success, returns 0, and returns -1 on failure.
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char *first;
	size_t n = 0, lineNo = 1;
	stack_t *stack = NULL;
	instructionFunction function = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, fp) != -1)
	{
		first = strtok(lineptr, " \t\n");
		if (first == NULL)
			continue;
		function = findFunction(first);
		if (function == NULL)
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n", lineNo, first);
		    exit(EXIT_FAILURE);
		}
		function(&stack, lineNo);
		lineNo++;
	}
	exit(EXIT_SUCCESS);
}
