#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * pall -  prints all the values on the stack, starting
 * from the top of the stack.
 *
 * @stack: the stack to be printed
 * @line_number: the line number (UNUSED)
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	UNUSED(line_number);
	head = *stack;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

