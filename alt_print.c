/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:46:43 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 17:06:20 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	format_board(struct s_board *board, t_column_o *master_co)
{
	t_cell	*choice;
	char	id;
	int		len;

	len = board->size * board->size;
	board->str = (char*)malloc((len + 1) * sizeof(char));
	board->str[len] = '\0';
	ft_memset(board->str, '.', len);
	while (!(is_empty(board->answers)))
	{
		choice = pop(board->answers);
		id = choice->c->u_colname.id;
		choice = choice->r;
		while (choice->c->union_type == 1)
		{
			board->str[choice->c->u_colname.row_num - 1] = id;
			uncover_choice(choice);
			choice = choice->r;
		}
	}
	print_nboard(board->str, board->size);
	free(board->str);
	free(board->answers->array);
	free(board->answers);
	cleanup(master_co);
}

void	print_nboard(char *str, int mod)
{
	int i;

	i = -1;
	while (*str)
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
