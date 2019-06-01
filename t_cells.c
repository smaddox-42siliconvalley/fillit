#include "fillit.h"

t_cell *generate_row(void)
{
	t_cell *first_node;
	t_cell *current;
	int i;

	i = 0;
	first_node = (t_cell*)malloc(sizeof(t_cell));
	current = first_node;
	while (i < 4)
	{
		current->R  = (t_cell*)malloc(sizeof(t_cell));
		current->R->L = current;
		current->a = 0;
		current = current->R;
		++i;
	}
	current->R =first_node;
	first_node->L = current;
	return(first_node);
}

void	cell_linker(column_o *master_co, t_cell *row, piece pc)
{
	column_o *current_co;
	t_cell		*current_cell;
	int			i;

	i = 0;
	current_co = master_co->next; //move off of root
	current_cell = row;
	while(current_co->colname.id != 'h')
	{
		if (current_co->union_type == 0 && current_co->colname.id == pc.id)
		{
			current_cell->U = current_co->list_header.U;
			current_cell->D = &(current_co->list_header);
			current_cell->C = current_co;
			current_cell->U->D = current_cell;
			current_cell->D->U = current_cell;
			current_cell = current_cell->R;
		}
		else if (current_co->union_type == 1 && current_co->colname.row_num ==
				coordinates_to_index(pc.blocks[i].x,
					pc.blocks[i].y,
					ft_sqrt(master_co->prev->colname.row_num)))
		{
			current_cell->U = current_co->list_header.U;
			current_cell->D = &(current_co->list_header);
			current_cell->C = current_co;
			current_cell->U->D = current_cell;
			current_cell->D->U = current_cell;
			current_cell = current_cell->R;
			++i;
		}
		/*
		if (current_co->union_type == 0)
		{
			printf("%c %p", current_co->colname.id, current_co);
			getchar();
		}
		if(current_co->union_type == 1)
		{
			printf("%d %p", current_co->colname.row_num, current_co);
			getchar();
		}*/
		current_co = current_co->next;
	}
}


void	test_matrix(column_o* master_co)
{
	column_o* current;
	int i = 0;	
	t_cell *current_cell;
	current = master_co->next;
	while(current->union_type == 0)
	{
		current_cell = current->list_header.D;
		while(current_cell->a != 1)
		{
			i = 0;
			while(i<5)
			{
				if (current_cell->C->union_type == 0)
					printf("%c " ,current_cell->C->colname.id);
				if (current_cell->C->union_type == 1)
					printf("%d " ,current_cell->C->colname.row_num);
				current_cell = current_cell->R;
				++i;
			}
			current_cell = current_cell->D;
			printf("\n");
		}
		current = current->next;
	}
}

void	print_cells(t_cell *start)
{
	while(start->L->a != 1)
	{
		printf("%d ", start->a);
		start = start->L;
	}
	printf("%d\n", start->a);
}

