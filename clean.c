#include "fillit.h"

void		cleanup(column_o *master_co)
{
	column_o	*current;
	t_cell		*current_cell;
	column_o	*next_column;
	t_cell		*next_cell;
	int i = 0;
	int j = 0;
	current = master_co->next;
	while(current->colname.id != 'h')
	{
		next_column = current->next;
		current_cell = current->list_header.D;
		while(current_cell->a == 0)
		{
			++i;
			/*if (current_cell->C->union_type == 0)
				printf("%c ", current_cell->C->colname.id);
			if(current_cell->C->union_type == 1)
				printf("%d ", current_cell->C->colname.row_num);
		*/	next_cell = current_cell->D;
			free(current_cell);
			current_cell = next_cell;
		}
		free(current);
		current = next_column;
		++j;
	}
	free(current);
	printf("%d ", i + j);
}
