#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	(void) line_number;
	aux = *stack;
	while (aux != NULL)
		fprintf(stdout, "%d\n", aux->n), aux = aux->next;
}
