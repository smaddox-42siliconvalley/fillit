#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	piece *piecearr;

	if (argc != 2)
	{
		//print usage
		return (0);
	}

	fd = open(argv[1], O_RDONLY);
	piecearr = read_file(fd);
	if ( !piecearr )
	{
		ft_putstr("BAD FUCKING PIECE");
		return (0);
	}	
	printf("here");

	int i = 0;
	int j = 0;

	while (i < 27)
	{
		j = 0;
		printf("%c : ", piecearr[i].id);
		while (j < 4)
		{
			printf("(%d,%d) ", piecearr[i].blocks[j].x, piecearr[i].blocks[j].y);
		   	++j;
		}
		printf("\n");
		++i;
	}
	return (0);
}
