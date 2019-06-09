/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:50:39 by dchen             #+#    #+#             */
/*   Updated: 2019/06/08 12:17:41 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_board(piece *arr, int num, int board_size, char **board)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < num)
	// fill board with pieces
	{
		j = 0;
		while (j <= 3)
		{
			board[(arr[i].blocks[j].x - 1) / board_size]
				[(arr[i].blocks[j].x - 1) % board_size] = arr[i].id;
			j++;
		}
		i++;
	}
	print_board(board, board_size, num);
}

char	**create_board(int board_size, int num)
{
	char	**board;
	int		i;
	int		j;

	board = (char**)malloc(sizeof(char*) * (board_size));
	i = 0;
	while (i < board_size)
	{
		board[i] = (char*)malloc(sizeof(char) * board_size + 1);
		i++;
	}
	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	return (board);
}

void	free_board(char **board, int board_size)
{
	int i;

	i = 0;
	while (i < board_size)
	{
		ft_memdel((void **)&(board[i]));
		i++;
	}
	ft_memdel((void **)&board);
}

void	print_board(char **board, int board_size, int num)
{
	int		i;
	int		j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			write(1,&board[i][j],1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	return ;
}
