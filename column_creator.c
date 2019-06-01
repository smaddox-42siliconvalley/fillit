#include "fillit.h"

//this doesn't make listheaders yet
column_o *make_columns(piece *arr, int size, int board_size)
{
	int i;
	column_o *master_co;
	column_o *current;
	
	current = (column_o*)malloc(sizeof(column_o));
	master_co = current;
	//root column_o
	current->union_type = 0;
	current->colname.id = 'h';
	i = 0;
	while (i < size)
	{
		current->next = (column_o*)malloc(sizeof(column_o));
		current->next->prev = current;
		current = current->next;
		current->union_type = 0;
		current->colname.id = arr[i].id;
		++i;
	}
	i = 1;
	while (i <= board_size * board_size)
	{
		current->next = (column_o*)malloc(sizeof(column_o));
		current->next->prev = current;
		current = current->next;
		current->union_type = 1;
		current->colname.row_num = i;
		++i;
	}	
	current->next = master_co;
	master_co->prev = current;
	return(master_co);
}


void	print_nodes(column_o *column)
{ 
	while (column->next->colname.id != 'h')
	{
		if (column->union_type == 0)
			printf("%c%c", column->colname.id, 9);
		if (column->union_type == 1)
			printf("%d%c", column->colname.row_num, 9);
		column = column->next;
	}
	if (column->union_type == 0)
		printf("%c\n", column->colname.id);
	if (column->union_type == 1)
		printf("%d\n", column->colname.row_num);

}

void	link_list_headers(column_o *master_co)
{
	column_o *current;
	current = master_co;
	current->list_header.U = &(current->list_header);
	current->list_header.D = &(current->list_header);
	current->list_header.R = &(current->next->list_header);
	current->list_header.C = current;
	current->list_header.a = 1;
	current = current->next;
	while(!(current->union_type == 0 && current->colname.id == 'h'))
	{
		current->list_header.U = &(current->list_header);
		current->list_header.D = &(current->list_header);
		current->list_header.L = &(current->prev->list_header);
		current->list_header.R = &(current->next->list_header);
		current->list_header.C = current;
		current->list_header.a = 1;
		current = current->next;
	}
	master_co->list_header.L = &(current->prev->list_header);
}


void print_list_header(t_cell *start)
{
	while(start->R->C->colname.id != 'h')
	{
		printf("%d%c", start->a, 9);
		start = start->R;
	}
	printf("%d%c", start->a, 9);
	
}
