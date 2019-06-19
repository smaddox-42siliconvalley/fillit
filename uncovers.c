/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncovers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:56:49 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 14:58:32 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		uncover_rows(t_cell *node)
{
	t_cell *current;

	current = node->l;
	while (current != node)
	{
		current->u->d = current;
		current->d->u = current;
		current = current->l;
	}
}

void		uncover_column(t_column_o *column)
{
	t_cell *current_cell;

	current_cell = NULL;
	column->list_header.l->r = &(column->list_header);
	column->list_header.r->l = &(column->list_header);
	column->prev->next = column;
	column->next->prev = column;
	current_cell = column->list_header.u;
	while (current_cell->a == 0)
	{
		uncover_rows(current_cell);
		current_cell = current_cell->u;
	}
}

void		uncover_choice(t_cell *choice)
{
	t_cell *current;

	current = NULL;
	uncover_column(choice->c);
	current = choice->l;
	while (current != choice)
	{
		uncover_column(current->c);
		current = current->l;
	}
}
