/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:46:28 by dchen             #+#    #+#             */
/*   Updated: 2019/02/27 19:05:52 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (--n && *s1 && *s2 && (s1[i] == s2[i]))
		{
			++s1;
			++s2;
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
