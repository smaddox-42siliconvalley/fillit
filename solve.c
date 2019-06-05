#include "fillit.h"

int		solver(column_o *master_co, piece *arr)
{
	t_cell *choice;
	column_o *current;
	
	current = master_co->next;
	if (current->union_type == 1)
		return (1);
	if (current->list_header.D == &(current->list_header))
		return (0);
	while(current->union_type == 0)
	{
		choice = current->list_header.D;
		while (choice->a == 0)
		{
			cover_choice(choice);
			if((solver(master_co, arr)))
			{
				uncover_choice(choice);
				choice_helper(choice, arr);	
				return(1);
			}
			uncover_choice(choice);
			choice = choice->D;
		}
		current = current->next;
	}
	return(0);
}

void	choice_helper(t_cell *choice, piece *arr)
{
	char	id;
	int 	i;
	int		j;

	j = -1;
	i = -1;
	id = choice->C->colname.id;
	choice = choice->R;
	while(arr[++i].id != id){;}
	while(++j<4)
	{
		arr[i].blocks[j].x = choice->C->colname.row_num;
		choice = choice->R;
	}
}


		
