/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:41:29 by dchen             #+#    #+#             */
/*   Updated: 2019/06/14 17:24:26 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	struct board	board;
	piece			*piece_arr;
	column_o		*master_co;

	board.answers = init_stack(100);
	if (argc == 2)
	{
		board.fd = open(argv[1], O_RDONLY);
		if ((piece_arr = read_file(board.fd, &board.num)))
		{
			board.size = ft_sqrt(board.num * 4);
			master_co = init_toroid(piece_arr, board.num, board.size);
			while (!(solver(master_co, board.answers)))
			{
				cleanup(master_co);
				master_co = init_toroid(piece_arr, board.num, ++(board.size));
			}
		}
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit file\n");
	format_board(&board, master_co);
	return (0);
}
