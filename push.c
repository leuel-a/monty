#include "monty.h"

/**
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *new;
	char *num;

	(void) line_number;
	head = *stack;
	num = strtok(NULL, " \n");
	
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	
	if (isdigit(num[0]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);
	new->next = head;
	new->prev = NULL;

	if (head != NULL)
		head->prev = new;
	head = new;
	*stack = head;
}	
