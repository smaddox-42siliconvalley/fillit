/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cells.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:55:29 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 15:34:27 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cell		*generate_rows(void)
{
	t_cell	*first_node;
	t_cell	*current;
	int		i;

	i = 0;
	first_node = make_t_cell();
	current = first_node;
	while (i < 4)
	{
		current->r = make_t_cell();
		current->r->l = current;
		current->a = 0;
		current = current->r;
		++i;
	}
	current->r = first_node;
	first_node->l = current;
	return (first_node);
}

void		linker(t_column_o *current_co, t_cell *current_cell)
{
	current_cell->u = current_co->list_header.u;
	current_cell->d = &(current_co->list_header);
	current_cell->c = current_co;
	current_cell->u->d = current_cell;
	current_cell->d->u = current_cell;
}

void		cell_linker(t_column_o *master_co, t_cell *row, t_piece pc)
{
	t_column_o	*current_co;
	t_cell		*current_cell;
	int			i;
	int			board_size;

	i = 0;
	board_size = ft_sqrt(master_co->prev->u_colname.row_num);
	current_co = master_co->next;
	current_cell = row;
	while (current_co->u_colname.id != pc.id)
		current_co = current_co->next;
	linker(current_co, current_cell);
	current_cell = current_cell->r;
	link_helper(current_co, current_cell, pc, board_size);
}

void		link_helper(t_column_o *current_co,
		t_cell *current_cell, t_piece pc, int board_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (current_co->union_type == 1)
		{
			if ((coordinates_to_index(pc.blocks[i].x, pc.blocks[i].y,
							board_size)) == current_co->u_colname.row_num)
			{
				linker(current_co, current_cell);
				current_cell = current_cell->r;
				++i;
			}
		}
		current_co = current_co->next;
	}
}
