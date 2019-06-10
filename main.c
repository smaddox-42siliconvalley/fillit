#include "fillit.h"

int		main(int argc, char **argv)
{
	struct board	board;
	int				num;
	int				fd;
	piece			*piece_arr;
	column_o		*master_co;

	board.answers = init_stack(100);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((piece_arr = read_file(fd, &num)))
		{
			board.size = ft_sqrt(num * 4);
			master_co = init_toroid(piece_arr, num, board.size);
			while (!(solver(master_co, board.answers)))
			{
				//free master_co here
				master_co = init_toroid(piece_arr, num, ++board.size);
			}
		}
		else
			ft_putstr("ERROR\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	format_board(&board);
	print_nboard(board.str, board.size);
	//free board.str
	//free piece_arr
	//free stack
	return (0);
}
