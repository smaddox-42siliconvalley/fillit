/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:47:30 by dchen             #+#    #+#             */
/*   Updated: 2019/06/13 15:47:31 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		cover_rows(t_cell *node)
{
	int		i;
	t_cell	*current;

	i = -1;
	current = node->R;
	while (current != node)
	{
		current->U->D = current->D;
		current->D->U = current->U;
		current = current->R;
	}
}

void		cover_column(column_o *column)
{
	t_cell *current_cell;

	column->list_header.L->R = column->list_header.R;
	column->list_header.R->L = column->list_header.L;
	column->prev->next = column->next;
	column->next->prev = column->prev;
	current_cell = column->list_header.D;
	while (current_cell->a == 0)
	{
		cover_rows(current_cell);
		current_cell = current_cell->D;
	}
}

void		cover_choice(t_cell *choice)
{
	t_cell *current;

	cover_column(choice->C);
	current = choice->R;
	while (current != choice)
	{
		cover_column(current->C);
		current = current->R;
	}
}
