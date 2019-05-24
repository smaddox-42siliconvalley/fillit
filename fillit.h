#ifndef	FILLIT
#define FILLIT
#include "string.h" //for testing

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
	int			placed;
	point 		*blocks;
}				piece;


void	translate(point one, point *two);
void	reset(piece *pc);
piece	*read_file(const int fd);
int		ft_sqrt(int c);
int		index_to_coordinates(int i, int width, int flag);
int		coordinates_to_index(int x, int y, int width);
void	translate(point one, point *two);
void	reset(piece *pc);

#endif
