/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:00:02 by dchen             #+#    #+#             */
/*   Updated: 2019/02/26 21:24:08 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	if (src == dst)
		return (dst);
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			dst1[i] = src1[i];
	}
	else
	{
		i = 0;
		while (len > i)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
