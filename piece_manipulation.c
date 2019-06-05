#include "fillit.h"

void	move_piece(piece *pc, int direction)
{
	int i;

	if (direction == 0)
	{
		i = 0;
		while (i < 4)
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

void	translate(point one, point *two)
{
	two->x = two->x + one.x;
	two->y = two->y + one.y;
}

void	reset(piece *pc)
{
	point	origin;
	int		i;

	i = 0;
	origin = pc->blocks[0];
	origin.x = -(origin.x);
	origin.y = -(origin.y);
	while (i < 4)
	{
		translate(origin, ((pc->blocks) + i));
		++i;
	}
}
