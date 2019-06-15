/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:45:29 by dchen             #+#    #+#             */
/*   Updated: 2019/06/14 16:16:22 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cleanup(column_o *master_co)
{
	column_o	*current;
	t_cell		*current_cell;
	column_o	*next_column;
	t_cell		*next_cell;

	current = master_co->next;
	while (current->colname.id != 'h')
	{
		next_column = current->next;
		current_cell = current->list_header.D;
		while (current_cell->a == 0)
		{
			next_cell = current_cell->D;
			ft_bzero(current_cell, sizeof(t_cell));
			free(current_cell);
			current_cell = next_cell;
		}
		ft_bzero(current, sizeof(column_o));
		free(current);
		current = next_column;
	}
	ft_bzero(&current->list_header, sizeof(t_cell));
	ft_bzero(current, sizeof(column_o));
	free(current);
}

void	free_pieces(piece *arr, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(arr[i].blocks);
		i++;
	}
	free(arr);
}

