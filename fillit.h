#ifndef	FILLIT
#define FILLIT

#include <string.h> //testing
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

struct STACK;
typedef struct STACK stack;

struct column_object;
typedef struct column_object column_o;

struct							board
{
	int							size;
	char						*str;
	int							num;
	int							fd;
	stack						*answers;
};

typedef struct		POINT
{
	int				x;
	int				y;
}					point;

typedef struct		PIECE
{
	char			id;
	point			*blocks;
}					piece;

typedef struct		s_cell
{
	struct s_cell			*U;
	struct s_cell			*D;
	struct s_cell			*L;
	struct s_cell			*R;
	column_o		*C;
	int				a;
}					t_cell;

typedef struct		column_object
{
	t_cell			list_header;
	int				union_type;
	union			col_name
	{
		char		id;
		int			row_num;
	}				colname;
	struct column_object		*next;
	struct column_object		*prev;
}					column_o;

typedef struct STACK
{
	int top;
	int capacity;
	t_cell **array;
}				stack;

stack *init_stack(int size);
int is_full(stack *address_stack);
int is_empty(stack *address_stack);
void push(stack *address_stack, t_cell *choice);
t_cell *pop(stack *address_stack);
void				mapstack(stack *address_stack, piece *arr);
void show_stack(stack *address_stack);

/*
 * *		Column Creator
 */

column_o			*make_columns_part_one(piece *arr, int size, int board_size);
void				part_deux(column_o *master_co, column_o *current, int board_size);
void				link_list_header(column_o *master_co);

/*
 * *		ft_math
 */

int					ft_sqrt(int c);
int					coordinates_to_index(int x, int y, int width);
int					index_to_coordinates(int i, int width, int flag);

/*
 * *		piece_manipulation
 */

void				move_piece(piece *pc, int direction);
void				translate(point one, point *two);
void				reset(piece *pc);


/*
 * *		t_cells
 */


t_cell				*generate_rows(void);
void				linker(column_o *current_co, t_cell *current_cell);
void				cell_linker(column_o *master_co, t_cell *row, piece pc);
void				link_helper(column_o *current_co, t_cell *current_cell, piece pc, int board_size);

/*
 * *		toroid maker
 */

column_o			*init_toroid(piece *arr, int num, int board_size);
void				make_rows(piece pc, int board_size, column_o *master_co);
int					valid(piece pc, int board_size);



/*
 * * 	testing functions
 */


void				print_index(piece pc, int size);
void				print_piece(piece pc);
void				print_matrix(column_o *master_co);
void				print_columns(column_o *column);
void				print_choice(t_cell *choice);
void				test_covers(column_o *master_co);
/*
 * *	read functions
 */

int					check_valid_tetris(char *str, int b_read);
piece				get_piece(char *str, char id);
piece				*read_file(const int fd, int *num_pieces);

/*
 * *	cleanup
 */

void			cleanup(column_o *master_co);
void			free_pieces(piece *arr, int num);

/*
 * *	coverings
 */

void			cover_choice(t_cell *choice);
void			cover_column(column_o *column);
void			cover_rows(t_cell *node);

/*
 * *	uncoverings
 */

void			uncover_choice(t_cell *choice);
void			uncover_column(column_o *column);
void			uncover_row(t_cell *node);

/*
 * *	solver
 */
int				solver(column_o *master, stack *address_stack);
void			choice_helper(t_cell *choice, piece *arr);
int				validate_choice(t_cell *choice);

/*
 * *	Printing Board
 */

//void	fill_board(piece *arr, int num, int board_size, char **board);
//void	print_board(char **board, int board_size, int num);
//char	**create_board(int board_size, int num);
//void	free_board(char **board, int board_size);
void	format_board(struct board *board, column_o *master_co);
void	print_nboard(char *str, int mod);

/*
 * *	allocate shit
 */
t_cell		*make_t_cell(void);
column_o	*make_column_o(void);
#endif

