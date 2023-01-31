#include "monty.h"

/**
 * findFunction - finds the respective stack function based
 * on the opcode
 * @str: the opcode
 *
 * Return: On success, it returns the function. Otherwise, it
 * returns NULL
*/
instructionFunction findFunction(char *str)
{
	instruction_t instructions[] = {
	{"pall", pall},
	{"push", push},
	{NULL, NULL}
	};

	size_t i = 0;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(str, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (NULL);
}
