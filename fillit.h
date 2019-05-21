#include "libft.h"

struct			board
{
	int			size;
	char		*board;
}

typedef struct POINT
{
	int			x;
	int			y;
}				point;

typedef struct	PIECE
{
	char		piece;
	char		id;
	int			placed;
	point		block_one;
	point		block_two;
	point		block_three;
	point		block_four;
}				piece;



