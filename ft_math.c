/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:40:49 by dchen             #+#    #+#             */
/*   Updated: 2019/06/18 13:56:52 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int c)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (result <= c)
	{
		++i;
		result = i * i;
	}
	return (i - 1);
}

int		coordinates_to_index(int x, int y, int width)
{
	int i;

	i = x + (y * width);
	return (i + 1);
}

int		index_to_coordinates(int i, int width, int flag)
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
		y = i / width;
		return (y);
	}
	return (0);
}
