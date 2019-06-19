/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:47:30 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 15:06:53 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		cover_rows(t_cell *node)
{
	int		i;
	t_cell	*current;

	i = -1;
	current = node->r;
	while (current != node)
	{
		current->u->d = current->d;
		current->d->u = current->u;
		current = current->r;
	}
}

void		cover_column(t_column_o *column)
{
	t_cell *current_cell;

	column->list_header.l->r = column->list_header.r;
	column->list_header.r->l = column->list_header.l;
	column->prev->next = column->next;
	column->next->prev = column->prev;
	current_cell = column->list_header.d;
	while (current_cell->a == 0)
	{
		cover_rows(current_cell);
		current_cell = current_cell->d;
	}
}

void		cover_choice(t_cell *choice)
{
	t_cell *current;

	cover_column(choice->c);
	current = choice->r;
	while (current != choice)
	{
		cover_column(current->c);
		current = current->r;
	}
}
