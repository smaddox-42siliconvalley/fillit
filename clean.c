#include "fillit.h"

void		cleanup(column_o *master_co)
{
	column_o	*current;
	t_cell		*current_cell;
	column_o	*next_column;
	t_cell		*next_cell;
	current = master_co->prev;
	while(current->colname.id != 'h')
	{
		next_column = current->prev;
		current_cell = current->list_header.U;
		while(current_cell->a == 0)
		{
			next_cell = current_cell->D;
			free(current_cell);
			current_cell = next_cell;
		}
		free(current);
		current = next_column;
	}
	free(current);
}
