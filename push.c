#include "monty.h"

/**
 * push -  pushes an element to a stack_t
 * @stack: the stack where the new element will be added
 * @line_number: the line number where the opcode is
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *num;
	stack_t *new;

	num = strtok(NULL, " \t\n");
	
	if (num == NULL || isdigit(num[0]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
