/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:49:28 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 15:05:21 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver(t_column_o *master_co, t_stack *address_stack)
{
	t_cell		*choice;
	t_column_o	*current;

	choice = NULL;
	current = NULL;
	current = master_co->next;
	choice = current->list_header.d;
	while (choice->a == 0)
	{
		cover_choice(choice);
		push(address_stack, choice);
		if (master_co->next == master_co || master_co->next->union_type == 1)
			return (1);
		if ((solver(master_co, address_stack)) == 1)
			return (1);
		uncover_choice(address_stack->array[address_stack->top]);
		choice = (pop(address_stack))->d;
	}
	return (0);
}
