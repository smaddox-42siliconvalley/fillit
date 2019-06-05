#include "fillit.h"

int		solver(column_o *master_co, piece *arr)
{
	t_cell *choice;
	column_o *current;

	current = master_co->next;
	if (current == master_co)
		return(1);
	choice = current->list_header.D;
	choice_helper(choice, arr);
	cover_choice(choice);
	while (choice->a == 0)
	{
		if((solver(master_co, arr)) == 1)
		{
			return(1);
		}
		uncover_choice(choice);
		choice = choice->D;
		choice_helper(choice, arr);
		cover_choice(choice);
	}
	uncover_choice(choice);
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


		
