/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:57:49 by dchen             #+#    #+#             */
/*   Updated: 2019/02/28 12:23:14 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(int n)
{
	int size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		size = get_size(n) + 1;
	else
		size = get_size(n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[size--] = '\0';
	if (n == 0)
		str[size] = n % 10 + '0';
	while (n >= 1)
	{
		str[size--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
