/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:50:55 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 14:42:01 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack	*init_stack(int size)
{
	t_stack *address_stack;

	address_stack = (t_stack*)malloc(sizeof(t_stack));
	address_stack->capacity = size;
	address_stack->top = -1;
	address_stack->array = (t_cell**)malloc(size * sizeof(t_cell*));
	return (address_stack);
}

int		is_full(t_stack *address_stack)
{
	if (address_stack->top == address_stack->capacity - 1)
		return (1);
	return (0);
}

int		is_empty(t_stack *address_stack)
{
	if (address_stack->top == -1)
		return (1);
	return (0);
}

void	push(t_stack *address_stack, t_cell *choice)
{
	if (is_full(address_stack))
		return ;
	address_stack->array[++address_stack->top] = choice;
}

t_cell	*pop(t_stack *address_stack)
{
	if (is_empty(address_stack))
		return (NULL);
	return (address_stack->array[address_stack->top--]);
}
