/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:27:09 by dchen             #+#    #+#             */
/*   Updated: 2019/02/22 19:19:53 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;
	int		len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char *)s);
		if (!(newstr = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i] != 0)
		{
			newstr[i] = f(s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
