#include "fillit.h"

void	format_board(struct board *board)
{
	t_cell *choice;
	char id;
	int len;

	len = board->size * board->size;
	board->str = (char*)malloc((len + 1) * sizeof(char));
	board->str[len] = '\0';
	ft_memset(board->str, '.', len);
	while(!(is_empty(board->answers)))
	{
		choice = pop(board->answers);
		id = choice->C->colname.id;
		choice = choice->R;
		while(choice->C->union_type == 1)
		{
			board->str[choice->C->colname.row_num - 1] = id;
			choice = choice->R;
		}
	}
}

void	print_nboard(char *str, int mod)
{
	int i;

	i = -1;
	while(*str)
	{
		if (++i % mod == 0 && i > 1)
		{
			ft_putchar('\n');
		}
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}
