#include "fillit.h"

int		main(int argc, char **argv)
{
	struct board	board;
	int				num;
	int				fd;
	int				n;
	piece			*piece_arr;
	column_o		*master_co;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((piece_arr = read_file(fd, &num)))
		{
			board.size = ft_sqrt(num * 4);
			master_co = init_toroid(piece_arr, num, board.size);
			while (!(solver(master_co, piece_arr)))
				master_co = init_toroid(piece_arr, num, ++board.size);
		}
		else
			ft_putstr("ERROR\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	n = -1;
	while (++n < num)
		print_piece(piece_arr[n]);
	return (0);
}
