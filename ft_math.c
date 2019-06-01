#include "fillit.h"

 //* * Square root integer only implementation

int	ft_sqrt(int c)
{
	int i = 1;
	int result = 0;

	while ( result <= c )
	{
		i++;
		result = i * i;
	}

	return (i-1);
}

int	coordinates_to_index(int x, int y, int width)
{
	int i;

	i = x + (y * width);
	return (i+1); //+1 to offset the fact that everything starts at fucking 0
}

 //* * Flag indicates the return value 0 for x and 1 for y

int	index_to_coordinates(int i, int width, int flag)
{
	int x;
	int y;

	if (flag == 0)
	{
		x = i % width;
		if (!x)
			return (width);
		return (x);
	}
	else if (flag == 1)
	{
		y = i/width;
		return (y);
	}
	return (0);
}

void	translate(point one, point *two)
{

	two->x = two->x + one.x;
	two->y = two->y + one.y;
}

void	reset(piece *pc)
{
	point origin;
	int i;

	i = 0;
	origin = pc->blocks[0];
	origin.x = -(origin.x);
	origin.y = -(origin.y);
	while ( i < 4 )
	{
		translate(origin, ((pc->blocks) + i));
	   	++i;	
	}
}
