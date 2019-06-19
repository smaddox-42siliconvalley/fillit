/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toroid_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:55:55 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 14:00:45 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_column_o		*init_toroid(t_piece *arr, int num, int board_size)
{
	t_column_o	*master_co;
	int			i;

	i = 0;
	master_co = NULL;
	master_co = make_columns_part_one(arr, num, board_size);
	link_list_header(master_co);
	while (i < num)
	{
		make_rows(arr[i], board_size, master_co);
		++i;
	}
	return (master_co);
}

void			make_rows(t_piece pc, int board_size, t_column_o *master_co)
{
	int n;
	int y;
	int i;

	y = 0;
	reset(&pc);
	while ((n = valid(pc, board_size)) != 2)
	{
		if (n == 0)
		{
			cell_linker(master_co, generate_rows(), pc);
			move_piece(&pc, 0);
		}
		if (n == 1)
		{
			i = 0;
			++y;
			reset(&pc);
			while (i++ < y)
				move_piece(&pc, 1);
		}
		if (n == 3)
			move_piece(&pc, 0);
	}
}

int				valid(t_piece pc, int board_size)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (pc.blocks[j].x < 0)
			return (3);
		if (pc.blocks[j].x >= board_size)
			return (1);
		if (pc.blocks[j].y >= board_size)
			return (2);
		++j;
	}
	return (0);
}
