#include "fillit.h"


int main(int argc, char **argv)
{
	int			board_size;
	int			num;
	int			fd;
	piece		*piece_arr;
	column_o	*master_co;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if((piece_arr = read_file(fd, &num)))
		{
			board_size = ft_sqrt(num * 4);
			master_co = init_toroid(piece_arr, num, board_size);
		}
		else
			ft_putstr("ERROR\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return(0);
}

		
