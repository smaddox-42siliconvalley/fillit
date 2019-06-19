/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:44:04 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 15:09:40 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cell		*make_t_cell(void)
{
	t_cell *new;

	new = NULL;
	new = (t_cell*)malloc(sizeof(t_cell));
	new->r = NULL;
	new->l = NULL;
	new->u = NULL;
	new->d = NULL;
	new->c = NULL;
	new->a = 0;
	return (new);
}

t_column_o	*make_column_o(void)
{
	t_column_o *new;

	new = NULL;
	new = (t_column_o*)malloc(sizeof(t_column_o));
	new->list_header.u = NULL;
	new->list_header.d = NULL;
	new->list_header.r = NULL;
	new->list_header.l = NULL;
	new->list_header.c = NULL;
	new->union_type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
