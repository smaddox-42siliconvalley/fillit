/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:01 by dchen             #+#    #+#             */
/*   Updated: 2019/02/26 13:47:12 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,\
		const void *restrict src, int c, size_t n)
{
	unsigned int	i;
	char			*dst1;
	char			*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (n > i)
	{
		dst1[i] = src1[i];
		if (src1[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
