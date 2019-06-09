#include "fillit.h"

int		solver(column_o *master_co, stack *address_stack)
{
	t_cell *choice;
	column_o *current;
	
	current = master_co->next;
	choice = current->list_header.D;
	while (choice->a == 0 )
	{
		cover_choice(choice);
		push(address_stack, choice);
		if (master_co->next == master_co || master_co->next->union_type == 1)
			return(1);
		if((solver(master_co, address_stack)) == 1)
			return(1);
		uncover_choice(address_stack->array[address_stack->top]);
		choice = (pop(address_stack))->D;
	}
	return(0);
}
