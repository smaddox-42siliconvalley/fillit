/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:13:04 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 17:09:55 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_connection(char *str)
{
	int i;
	int connection;

	i = 0;
	connection = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				connection++;
			if (str[i - 1] == '#')
				connection++;
			if (str[i - 5] == '#')
				connection++;
			if (str[i + 5] == '#')
				connection++;
		}
		i++;
	}
	return ((connection == 6 || connection == 8) ? 1 : 0);
}

int		check_valid_tetris(char *str)
{
	int	i;
	int block;

	i = 0;
	block = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#')
				block++;
			if (block > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (check_connection(str) == 0)
		return (0);
	return (1);
}

t_piece	get_piece(char *str, char id)
{
	t_piece	piece;
	int		i;
	int		j;

	piece.blocks = (t_point *)malloc(sizeof(t_point) * 4);
	i = 0;
	j = 0;
	piece.id = id;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			piece.blocks[j].y = i / 5;
			piece.blocks[j].x = i % 5;
			j++;
		}
		i++;
	}
	reset(&piece);
	return (piece);
}

t_piece	*read_file(const int fd, int *num_pieces)
{
	char			id;
	char			*buf;
	struct s_bytes	byte;
	t_piece			*piece_arr;

	piece_arr = (t_piece *)malloc(sizeof(t_piece) * 28);
	id = 'A';
	byte.i = 0;
	buf = ft_strnew(21);
	while ((byte.b_read = read(fd, buf, 21)) >= 20)
	{
		if (check_valid_tetris(buf) == 0)
			return (NULL);
		piece_arr[byte.i] = get_piece(buf, id);
		byte.i++;
		id++;
		byte.last = byte.b_read;
	}
	*num_pieces = id - 'A';
	if (*num_pieces == 0 || (byte.b_read < 20 && byte.b_read != 0)
			|| (byte.b_read == 0 && byte.last != 20))
		return (NULL);
	free(buf);
	return (piece_arr);
}
