/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:13:04 by dchen             #+#    #+#             */
/*   Updated: 2019/05/21 22:53:05 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

// checks if tetris is valid
int		check_valid_tetris(char	*str, int b_read)
{
	int	i;
	int block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		if(i % 5 < 4)
		{
			if(str[i] != '#' || str[i] != '.')
				return (0);
			if (str[i] == '#')
				block++;
			if (block > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if (b_read == 21 && str[20] != '\n')
		return (1);
	return (1);
}


// gets coords for each blocks
piece	*get_piece(char *str, char id)
{
	piece	*s_piece;
	point	*blocks;
	int		i;
	int		j;
	
	if(!(s_piece = malloc(sizeof(piece))))
		return (NULL);
	if(!(blocks = malloc(sizeof(point) * 4)))
		return (NULL);
	i = 0;
	j = 0;
	s_piece->id = id;
	while (i < 20)
	{
		if(str[i] == '#' && j == 0)
		{
			s_piece->blocks[j].x = i / 5;
			s_piece->blocks[j].y = i % 5;
			j++;
		}
		i++;
	}
	return (s_piece);
}
piece	*read_file(const int fd)
{
	char 	id;
	char	*buf;
	int		b_read;
	int 	i;
	piece	**pieceArr;

	pieceArr = malloc(sizeof(piece) * 28);
	id = 'A';
	i = 0;
	buf = ft_strnew(21);
	while ((b_read = read(fd, buf, 21)) >= 20)
	{
		if(check_valid_tetris(buf, b_read) == 1)
		{
			pieceArr[i] = get_piece(buf, id);
			i++;
			id++;
		}
		else if(check_valid_tetris(buf, b_read) == 0)
		{
			i = id - 'A' + '0';
			while (i >= 0)
			{
				free(pieceArr[i]);
				i--;
			}
			free(pieceArr);
		}
	}
	return (*pieceArr);
}
