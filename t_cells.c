#include "fillit.h"

t_cell		*generate_rows(void)
{
	t_cell	*first_node;
	t_cell	*current;
	int		i;

	i = 0;
	first_node = make_t_cell();
	current = first_node;
	while (i < 4)
	{
		current->R = make_t_cell();
		current->R->L = current;
		current->a = 0;
		current = current->R;
		++i;
	}
	current->R = first_node;
	first_node->L = current;
	return (first_node);
}

void		linker(column_o *current_co, t_cell *current_cell)
{
	current_cell->U = current_co->list_header.U;
	current_cell->D = &(current_co->list_header);
	current_cell->C = current_co;
	current_cell->U->D = current_cell;
	current_cell->D->U = current_cell;
}

void		cell_linker(column_o *master_co, t_cell *row, piece pc)
{
	column_o	*current_co;
	t_cell		*current_cell;
	int			i;

	i = 0;
	current_co = master_co->next;
	current_cell = row;
	while (current_co->colname.id != 'h')
	{
		if (current_co->union_type == 0 && current_co->colname.id == pc.id)
		{
			linker(current_co, current_cell);
			current_cell = current_cell->R;
		}
		else if (current_co->union_type == 1)
		{
			if (i < 4)
			{
				if ((coordinates_to_index(pc.blocks[i].x, pc.blocks[i].y,
				ft_sqrt(master_co->prev->colname.row_num))) == current_co->colname.row_num)
				{
					linker(current_co, current_cell);
					current_cell = current_cell->R;
					++i;
				}
			}
		}
		current_co = current_co->next;
	}
}
