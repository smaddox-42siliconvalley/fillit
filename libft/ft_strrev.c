/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:35:49 by dchen             #+#    #+#             */
/*   Updated: 2019/02/26 19:37:13 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	tmp;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		tmp = str[i];
		str[i] = str[length - 1];
		str[length - 1] = tmp;
		length--;
		i++;
	}
	return (str);
}
