/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:48:00 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 16:17:59 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_column_o	*make_columns_part_one(t_piece *arr, int size, int board_size)
{
	int			i;
	t_column_o	*master_co;
	t_column_o	*current;

	i = 0;
	current = make_column_o();
	master_co = current;
	current->union_type = 0;
	current->u_colname.id = 'h';
	while (i < size)
	{
		current->next = make_column_o();
		current->next->prev = current;
		current = current->next;
		current->union_type = 0;
		current->u_colname.id = arr[i].id;
		++i;
	}
	part_deux(master_co, current, board_size);
	return (master_co);
}

void		part_deux(t_column_o *master_co,
											t_column_o *current, int board_size)
{
	int	i;

	i = 1;
	while (i <= board_size * board_size)
	{
		current->next = make_column_o();
		current->next->prev = current;
		current = current->next;
		current->union_type = 1;
		current->u_colname.row_num = i;
		++i;
	}
	current->next = master_co;
	master_co->prev = current;
}

void		link_list_header(t_column_o *master_co)
{
	t_column_o	*current;
	int			i;

	i = 0;
	current = master_co;
	while (1)
	{
		if ((current->union_type == 0 && current->u_colname.id == 'h') && i)
		{
			break ;
		}
		++i;
		current->list_header.u = &(current->list_header);
		current->list_header.d = &(current->list_header);
		current->list_header.l = &(current->prev->list_header);
		current->list_header.r = &(current->next->list_header);
		current->list_header.c = current;
		current->list_header.a = 1;
		current = current->next;
	}
}
