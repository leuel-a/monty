#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack it self
 * @line_number: the line number of the operation code
 *
 * Return: Always nothing.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int checkString;
	char *str;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = *stack;
	str = strtok(NULL, " \t\n");
	checkString = checkStringForDigit(str);
	if (checkString == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(str);
	*stack = new;
}

/**
 * checkStringForDigit - checks whether a string is a valid digit
 * @str: the string to be checked
 *
 * Return: If the string is a valid digit, it returns 0. Otherwise,
 * it returns -1.
*/
int checkStringForDigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
