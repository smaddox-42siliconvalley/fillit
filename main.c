#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

piece *make_piece_arr(int i);
void print_pieces(piece *arr, int size);
void move_piece(piece *pc, int direction);
int	try_fit(piece *arr, char id, int size, int board_size);
int	validate_move(piece selected, piece *arr, int arrsize, int board_size );

int main(int argc, char **argv)
{
	struct board board;
	int num;
	int valid;
	int j;
	num = atoi(argv[1]);
	//board.size = ft_sqrt((num * 4));
	board.size = 10;
	
	piece *arr;
   	arr = make_piece_arr(num);

/*	arr[1].blocks[0].x = 1;
	arr[1].blocks[1].x = 1;
	arr[1].blocks[2].x = 1;
	arr[1].blocks[3].x = 1;
*/
	arr[1].blocks[0].y = 0;
	arr[1].blocks[1].y = 1;
	arr[1].blocks[2].y = 2;
	arr[1].blocks[3].y = 3;

	arr[0].blocks[0].y = 0;
	arr[0].blocks[1].y = 1;
	arr[0].blocks[2].y = 2;
	arr[0].blocks[3].y = 3;


	
	arr[0].placed = 1;
	arr[1].placed = 1;

	try_fit(arr, arr[1].id, num, board.size);
	print_pieces(arr, num);
	return (0);
}


int	try_fit(piece *arr, char id, int size, int board_size)
{
	int x;
	int y;
	int valid;
	piece *working;

	working = &arr[id - 'A'];
	y = 0;
	working->placed = 1;
	while ( y < board_size )
	{
		x = 0;
		while ( x < board_size )
		{
			if (!(valid = validate_move(*working, arr, size, board_size)))
				move_piece(working, 0); //move it right
			else
			{
				return (1);
			}
			++x;
		}
		reset(working);
		move_piece(working, 1);
		++y;
	}
	reset(working);
	working->placed = 0;
	return (0);
}


void move_piece(piece *pc, int direction)
{
	int i;
	
	if (direction == 0)
	{
		i = 0;
		while ( i < 4 )
		{
			pc->blocks[i].x++;
			++i;
		}
	}
	else if (direction == 1)
	{
		i = 0;
		while (i < 4)
		{
			pc->blocks[i].y++;
			++i;
		}
	}
}


int		validate_move(piece selected, piece *arr, int arrsize, int board_size )
{
	int i;
	int j;

	i = 0;
	while (i < arrsize)
	{
		if (selected.id != arr[i].id)
		{
			j = 0;
			while ( j < 4 )
			{
				if (selected.blocks[j].x >= board_size)
					return (0);
				if (selected.blocks[j].y >= board_size)
					return (0);
				if (selected.blocks[j].x == arr[i].blocks[j].x)
					if (selected.blocks[j].y == arr[i].blocks[j].y)
						return (0);
				++j;
			}
		}
		++i;
	}
	return(1);
}	

piece *make_piece_arr(int size)
{
	piece *arr;
	int i = 0;
	int j = 0;
	char id = 'A';
	

	arr = (piece*)malloc(size * sizeof(piece));

	while ( i < size )
	{
		arr[i].blocks = (point*)malloc(4 * sizeof(point));
		arr[i].id = id++;
		arr[i].placed = 0;
		j = 0;
		while (j < 4 )
		{
			arr[i].blocks[j].x = 0;
			arr[i].blocks[j].y = 0;
			++j;
		}
		++i;
	}
	return (arr);
}


void print_pieces(piece *arr, int size)
{
	int i = 0;
	int j = 0;

	while ( i < size )
	{
		printf("ID: %c\nPLACED: %d\nCoordinates: ",arr[i].id, arr[i].placed);
		j = 0;
		while ( j < 4 )
		{
			printf("(%d , %d) ", arr[i].blocks[j].x, arr[i].blocks[j].y);
			++j;
		}
		printf("\n\n");
		++i;
	}

		
//	arr[0].blocks[0].x = 2;
//	arr[0].blocks[0].y = 1;

}
