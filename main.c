/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:41:29 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 17:10:53 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	do_stuff(struct s_board *board, char *file)
{
	t_piece		*piece_arr;
	t_column_o	*master_co;

	board->fd = open(file, O_RDONLY);
	if ((piece_arr = read_file(board->fd, &(board->num))))
	{
		board->size = ft_sqrt(board->num * 4);
		master_co = init_toroid(piece_arr, board->num, board->size);
		while (!(solver(master_co, board->answers)))
		{
			cleanup(master_co);
			++board->size;
			master_co = init_toroid(piece_arr, board->num, board->size);
		}
		format_board(board, master_co);
		free_pieces(piece_arr, board->num);
	}
	else
	{
		ft_putstr("error\n");
		return ;
	}
}

int		main(int argc, char **argv)
{
	struct s_board	board;

	board.answers = init_stack(100);
	if (argc == 2)
	{
		do_stuff(&board, argv[1]);
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
