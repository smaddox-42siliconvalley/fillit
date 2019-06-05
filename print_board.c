/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:50:39 by dchen             #+#    #+#             */
/*   Updated: 2019/06/04 17:57:11 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(piece *arr, int num, int board_size, char **board)
{
	char	cur;
	int		i;
	int		j;

	/*board = (char**)malloc(sizeof(*char) * num);
	i = 0;
	while(i < board_size)
	{
		board[i] = (char*)malloc(sizeof(char) * (board_size + 1));
		i++;
	}
	*/
	i = 0;
	cur = 'A';
	while (i < num) // fill board with pieces
	{
		j = 0;
		while (j <= 3)
		{
			board[arr[i].blocks[j].x - 1 / board_size][arr[i].blocks[j].x - 1 % board_size] = cur;
			j++;
		}
		cur++;
		i++;
	}
}

char	**create_board(int board_size, int num)
{
	char	**board;
	int		i;
	int		j;

	board = (char**)malloc(sizeof(char*) * (board_size + 1));
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
