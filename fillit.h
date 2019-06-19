/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:29:08 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 17:01:41 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

struct s_column_object;

typedef struct				s_cell
{
	struct s_cell			*u;
	struct s_cell			*d;
	struct s_cell			*l;
	struct s_cell			*r;
	struct s_column_object	*c;
	int						a;
}							t_cell;

typedef struct				s_column_object
{
	t_cell					list_header;
	int						union_type;
	union					u_col_name
	{
		char				id;
		int					row_num;
	}						u_colname;

	struct s_column_object	*next;

	struct s_column_object	*prev;
}							t_column_o;

typedef struct				s_stack
{

	int						top;

	int						capacity;

	t_cell					**array;
}							t_stack;
struct						s_board
{
	int						size;
	char					*str;
	int						num;
	int						fd;
	t_stack					*answers;
};

struct						s_bytes
{
	int						last;
	int						b_read;
	int						i;
};

typedef struct				s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct				s_piece
{
	char					id;
	t_point					*blocks;
}							t_piece;

t_stack						*init_stack(int size);
int							is_full(t_stack *address_stack);
int							is_empty(t_stack *address_stack);
void						push(t_stack *address_stack, t_cell *choice);
t_cell						*pop(t_stack *address_stack);
void						mapstack(t_stack *address_stack, t_piece *arr);
t_column_o					*make_columns_part_one
							(t_piece *arr, int size, int board_size);
void						part_deux(t_column_o *master_co,
							t_column_o *current, int board_size);
void						link_list_header(t_column_o *master_co);
int							ft_sqrt(int c);
int							coordinates_to_index(int x, int y, int width);
int							index_to_coordinates
							(int i, int width, int flag);
void						move_piece(t_piece *pc, int direction);
void						translate(t_point one, t_point *two);
void						reset(t_piece *pc);
t_cell						*generate_rows(void);
void						linke
							(t_column_o *current_co, t_cell *current_cell);
void						cell_linker(t_column_o *master_co,
							t_cell *row, t_piece pc);
void						link_helper(t_column_o *current_co, t_cell
							*current_cell, t_piece pc, int board_size);
t_column_o					*init_toroid
							(t_piece *arr, int num, int board_size);
void						make_rows(t_piece pc, int board_size,
							t_column_o *master_co);
int							valid(t_piece pc, int board_size);
void						print_index(t_piece pc, int size);
void						print_piece(t_piece pc);
void						print_matrix(t_column_o *master_co);
void						print_columns(t_column_o *column);
void						print_choice(t_cell *choice);
void						test_covers(t_column_o *master_co);
int							check_valid_tetris(char *str);
t_piece						get_piece(char *str, char id);
t_piece						*read_file(const int fd, int *num_pieces);
void						cleanup(t_column_o *master_co);
void						free_pieces(t_piece *arr, int num);
void						cover_choice(t_cell *choice);
void						cover_column(t_column_o *column);
void						cover_rows(t_cell *node);

void						uncover_choice(t_cell *choice);
void						uncover_column(t_column_o *column);
void						uncover_row(t_cell *node);
int							solver(t_column_o *master,
							t_stack *address_stack);
void						choice_helper(t_cell *choice, t_piece *arr);
int							validate_choice(t_cell *choice);
void						format_board(struct s_board *board,
							t_column_o *master_co);
void						print_nboard(char *str, int mod);
t_cell						*make_t_cell(void);
t_column_o					*make_column_o(void);
#endif
