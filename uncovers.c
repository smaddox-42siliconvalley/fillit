#include "fillit.h"

void		uncover_rows(t_cell *node)
{
	int i;

	i = -1;
	node = node->R;
	while(++i < 4)
	{
		node->U->D = node;
		node->D->U = node;
		node = node->R;
	}
}

void		uncover_column(column_o *column)
{
	t_cell *current_cell;
	column->list_header.L->R = &(column->list_header);
	column->list_header.R->L = &(column->list_header);
	column->prev->next = column;
	column->next->prev = column;
	current_cell = column->list_header.D;
	while(current_cell->a == 0)
	{
		uncover_rows(current_cell);
		current_cell = current_cell->D;
	}
}

void		uncover_choice(t_cell *choice)
{
	int i;

	i = -1;
	choice = choice->R;
	while(++i < 5)
	{
		uncover_column(choice->C);
		choice = choice->R;
	}
}	
