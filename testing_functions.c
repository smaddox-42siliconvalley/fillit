#include "fillit.h"

void	print_index(piece pc, int size)
{
	int j = 0;
	printf("Index:\n");
	while(j<4)
	{
		printf("%d ", coordinates_to_index(pc.blocks[j].x, pc.blocks[j].y, size));
		++j;
	}
	printf("\n");
}


void	print_piece(piece pc)
{
	int j = 0;
	printf("%c ", pc.id);
	while(j < 4)
	{
		//printf("(%d, %d) ", pc.blocks[j].x, pc.blocks[j].y);
		printf("%d ", pc.blocks[j].x);	
		++j;
	}
	printf("\n");
}

void	print_matrix(column_o* master_co)
{
	column_o* current = master_co->next;
	if (current == master_co)
		printf("empty\n");
	int i = 0;
	t_cell *current_cell;
	while(current->union_type == 0)
	{
		current_cell = current->list_header.D;
		while(current_cell->a != 1)
		{
			i = 0;
			while(i<5)
			{
				if(current_cell->C->union_type == 0)
					printf("%c ", current_cell->C->colname.id);
				if(current_cell->C->union_type == 1)
					printf("%d ", current_cell->C->colname.row_num);
				current_cell = current_cell->R;
				++i;
			}
			current_cell = current_cell->D;
			printf("\n");
		}
		current = current->next;
	}
}

void print_columns(column_o *column)
{
	int i = 0;
	while (column->next->colname.id != 'h')
	{
		if (column->union_type == 1)
			++i;
		printf("%d %d\n", column->union_type,column->colname.id);
		column = column->next;
	}
	printf("%d %d\n", column->union_type,column->colname.id);
	printf("\n%d\n", i);
}


void print_choice(t_cell *current_cell)
{
	int i;
	i = 0;
	while(i<5)
	{
		if(current_cell->C->union_type == 0)
			printf("%c ", current_cell->C->colname.id);
		if(current_cell->C->union_type == 1)
			printf("%d ", current_cell->C->colname.row_num);
		current_cell = current_cell->R;
		++i;
	}
	printf("\n");
}	
