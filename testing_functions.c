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
	{
		printf("empty\n");
		return;
	}
	int i = 0;
	int j = 0;
	t_cell *current_cell;
	printf("Remaining columns: ");
	while(current->colname.id != 'h')
	{
		if(current->union_type == 0)
			printf("%c ", current->colname.id);
		if(current->union_type == 1)
			printf("%d ", current->colname.row_num);
		current= current->next;
	}
	printf("\n---------------------------------------------------------------------------------\n");
	current = master_co->next;
	while(current->union_type == 0)
	{
		current_cell = current->list_header.D;
		while(current_cell->a != 1)
		{
			i = 0;
			printf(" | ");
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
			++j;
			if (j%5==0)
				printf("\n");
		}
		printf("\n---------------------------------------------------------------------------------\n");
		current = current->next;
		j=0;
	}
	printf("end\n");
}

	

void print_choice(t_cell *current_cell)
{
	int i;
	i = 0;
   	printf("choice: ");	
	if(current_cell->a == 1)
		printf("list_headers-> ");
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

void	test_covers(column_o *master_co)
{
	stack *address_stack = init_stack(100);
	t_cell *choice;
	choice = master_co->next->list_header.D;
	while (1)
	{

		system("printf '\033[2J\033[3J\033[1;1H'");
		if(!(is_empty(address_stack)))
		{
			printf("last ");
			print_choice(address_stack->array[address_stack->top]);
		}

		print_matrix(master_co);
		print_choice(choice);
		char x = getchar();
		switch(x)
		{
			case 's': choice = choice->D;
					  break;
			case 'w': choice = choice->U;
					  break;
			case 'c': cover_choice(choice);
					  push(address_stack, choice);
					  choice = master_co->next->list_header.D;
					  break;
			case 'u': uncover_choice(address_stack->array[address_stack->top]);
					  choice = pop(address_stack);
					  break;
		}
	}
}





