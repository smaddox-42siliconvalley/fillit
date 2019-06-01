#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

piece *make_piece_arr(int i);
void print_piece(piece pc);
void move_piece(piece *pc, int direction);
int	valid(piece pc, int board_size);
void translator(piece pc, int board_size, column_o *master_co);
void swap(point *a, point *b);

int main(int argc, char **argv)
{
	struct board board;
	int num;
	int valid;
	int j;
	int fd;
	piece *arr;
	column_o *master_co;
	int i;
	
//	Read/Parse file	
	fd = open(argv[1], O_RDONLY);
	arr = read_file(fd, &num);
	board.size = ft_sqrt((num * 4));
//	Toroid construction
	master_co = make_columns(arr, num, board.size);
	link_list_headers(master_co);
	i = 0;
	while(i < num)
	{
		translator(arr[i], board.size, master_co);
		i++;
	}
	test_matrix(master_co);
	return (0);
}

void	translator(piece pc, int board_size, column_o *master_co)
{
	int n;
	int y;
	int i;

	y = 0;
	while((n = valid(pc, board_size)) != 2)
	{
		if (n == 0)
		{
			cell_linker(master_co, generate_row( ), pc);
			move_piece(&pc, 0);
		}
		if (n == 1)
		{
			i = 0;
			y++;
			reset(&pc);
			while(i < y)
			{	
				move_piece(&pc, 1);
				i++;
			}
		}
	}
}


int valid(piece pc, int board_size)					//0 okay 1 move down 2 done
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (pc.blocks[j].x >= board_size)
			return (1);
		if (pc.blocks[j].y >= board_size)
			return (2);
		++j;
	}
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

void	print_index(piece pc, int size)
{
	int j = 0;
	printf("Index:\n");
	while(j<4)
	{
		printf("%d ", coordinates_to_index(pc.blocks[j].x, pc.blocks[j].y, size));
		++j;
	}
	printf("\n\n");
}
		
void print_piece(piece pc)
{
	int j = 0;

	printf("ID: %c\nCoordinates: ", pc.id);
	while ( j < 4 )
	{
		printf("(%d , %d) ", pc.blocks[j].x, pc.blocks[j].y);
		++j;
	}
		printf("\n\n");
		
}

void swap(point *a, point *b)
{
	point temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



//testing functs down here
//	print_nodes(master_co); //testing funct for column headers
//	print_list_header(&(master_co->list_header));
