#include "fillit.h"

t_cell *make_t_cell(void)
{
	t_cell *new;

	new = NULL;
	new = (t_cell*)malloc(sizeof(t_cell));
	new->R = NULL;
	new->L = NULL;
	new->U = NULL;
	new->D = NULL;
	new->C = NULL;
	new->a = 0;
	return(new);
}


column_o *make_column_o(void)
{
	column_o *new;

	new = NULL;
	new = (column_o*)malloc(sizeof(column_o));
	new->list_header.U = NULL;
	new->list_header.D = NULL;
	new->list_header.R = NULL;
	new->list_header.L = NULL;
	new->list_header.C = NULL;
	new->union_type = 0;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

