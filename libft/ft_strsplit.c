/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:12:13 by dchen             #+#    #+#             */
/*   Updated: 2019/03/04 23:25:55 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i + 1] == c)
			words++;
		if (str[i] != c && str[i + 1] == '\0')
			words++;
		i++;
	}
	return (words);
}

static int		word_len(char *str, int i, char c)
{
	int		len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int				i;
	char			**arr;
	unsigned int	j;
	unsigned int	words;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = word_count((char *)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	j = 0;
	while (words--)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		arr[j] = ft_strsub((const char *)s, i, word_len((char *)s, i, c));
		if (arr[j] == NULL)
			return (NULL);
		i = i + word_len((char *)s, i, c);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
