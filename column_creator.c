#include "fillit.h"

column_o	*make_columns_part_one(piece *arr, int size, int board_size)
{
	int			i;
	column_o	*master_co;
	column_o	*current;

	i = 0;
	current = make_column_o();
	master_co = current;
	current->union_type = 0;
	current->colname.id = 'h';
	while (i < size)
	{
		current->next = make_column_o();
		current->next->prev = current;
		current = current->next;
		current->union_type = 0;
		current->colname.id = arr[i].id;
		++i;
	}
	part_deux(master_co, current, board_size);
	return (master_co);
}

void		part_deux(column_o *master_co, column_o *current, int board_size)
{
	int	i;

	i = 1;
	while (i <= board_size * board_size)
	{
		current->next = make_column_o();
		current->next->prev = current;
		current = current->next;
		current->union_type = 1;
		current->colname.row_num = i;
		++i;
	}
	current->next = master_co;
	master_co->prev = current;
}

void		link_list_header(column_o *master_co)
{
	column_o	*current;
	int			i;

	i = 0;
	current = master_co;
	while (1)
	{
		if ((current->union_type == 0 && current->colname.id == 'h') && i)
		{
			break ;
		}
		++i;
		current->list_header.U = &(current->list_header);
		current->list_header.D = &(current->list_header);
		current->list_header.L = &(current->prev->list_header);
		current->list_header.R = &(current->next->list_header);
		current->list_header.C = current;
		current->list_header.a = 1;
		current = current->next;
	}
}
