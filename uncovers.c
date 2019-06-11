#include "fillit.h"

void		uncover_rows(t_cell *node)
{
	t_cell *current;

	current = node->L;
	while (current != node)
	{
		current->U->D = current;
		current->D->U = current;
		current = current->L;
	}
}

void		uncover_column(column_o *column)
{
	t_cell *current_cell;

	current_cell = NULL;
	column->list_header.L->R = &(column->list_header);
	column->list_header.R->L = &(column->list_header);
	column->prev->next = column;
	column->next->prev = column;
	current_cell = column->list_header.U;
	while (current_cell->a == 0)
	{
		uncover_rows(current_cell);
		current_cell = current_cell->U;
	}
}

void		uncover_choice(t_cell *choice)
{
	t_cell *current;

	current = NULL;
	uncover_column(choice->C);
	current  = choice->L;
	while (current != choice)
	{
		uncover_column(current->C);
		current = current->L;
	}
}
