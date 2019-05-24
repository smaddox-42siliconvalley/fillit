#include "fillit.h"
char	*init_board(int size)
{
	char *board;
	board = (char*)malloc(size * sizeof(char));
	return(board);
}	
