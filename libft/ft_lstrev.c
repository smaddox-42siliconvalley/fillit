/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:06:03 by dchen             #+#    #+#             */
/*   Updated: 2019/06/17 22:24:27 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_lstrev(t_list **alst)
{
	t_list		*cur;
	t_list		*prev;
	t_list		*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}
