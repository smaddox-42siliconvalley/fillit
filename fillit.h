#ifndef	FILLIT
#define FILLIT
#include "string.h" //for testing
#include <stdlib.h>
#include <stdio.h>

struct			board
{
	int			size;
	char		*board;
};

typedef struct POINT
{
	int			x;
	int			y;
}				point;

/*
typedef struct	PIECE
{
	char		id;
	int			placed;
	point		block_one;
	point		block_two;
	point		block_three;
	point		block_four;
}				piece;

*/

typedef struct 	PIECE
{
	char		id;
//	int			placed;
	point 		*blocks;
}				piece;

struct s_cell;
typedef struct s_cell t_cell;

struct 				column_object;
typedef struct 		column_object column_o;


typedef struct		s_cell
{
	t_cell*			U;
	t_cell*			D;
	t_cell*			L;
	t_cell*			R;
	column_o*		C; //rename for norm later
	int				a; // a = 0 by default 1 indicates the list header
}					t_cell;

typedef struct	column_object
{
	t_cell		list_header;
	int			union_type; // 0 for char 1 for int
	union		col_name
	{
		char	id;
		int		row_num;
	}			colname;
	column_o	*next;
	column_o	*prev;
}				column_o;

void	translate(point one, point *two);
void	reset(piece *pc);
piece	*read_file(const int fd, int *num_pieces);
int		ft_sqrt(int c);
int		index_to_coordinates(int i, int width, int flag);
int		coordinates_to_index(int x, int y, int width);
void	translate(point one, point *two);
void	reset(piece *pc);
column_o	*make_columns(piece *arr, int size, int board_size);
void		print_nodes(column_o *column);
void		print_index(piece pc, int size);
void		link_list_headers(column_o *master_co);
void		print_list_header(t_cell *start);
t_cell		*generate_row(void);
void		print_cells(t_cell *start);
void		cell_linker(column_o *master_co, t_cell *row, piece pc);
void		test_matrix(column_o *master_co);
#endif
