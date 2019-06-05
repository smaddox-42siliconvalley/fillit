#include "fillit.h"

void		cover_rows(t_cell *node)
{
	int i;

	i = -1;
	node = node->L;
	while (++i < 4)
	{
		node->U->D = node->D;
		node->D->U = node->U;
		node = node->L;
	}
}

void		cover_column(column_o *column)
{
	t_cell *current_cell;

	column->list_header.L->R = column->list_header.R;
	column->list_header.R->L = column->list_header.L;
	column->prev->next = column->next;
	column->next->prev = column->prev;
	current_cell = column->list_header.U;
	while (current_cell->a == 0)
	{
		cover_rows(current_cell);
		current_cell = current_cell->U;
	}
}

void		cover_choice(t_cell *choice)
{
	int i;

	i = -1;
	choice = choice->L;
	while (++i < 5)
	{
		cover_column(choice->C);
		choice = choice->L;
	}
}
