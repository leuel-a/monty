#include "monty.h"

/**
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	if (head == NULL)
	{
		fprintf(stdout, "Stack is emptty\n");
		return;
	}

	while (head)
	{
		fprintf(stdout, "%d\n", head->n);
		head = head->next;
	}
}
