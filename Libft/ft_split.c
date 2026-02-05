/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:06:12 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/09 14:57:51 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how_many(char const *s, char c)
{
	int	x;
	int	sep;

	x = 0;
	sep = 1;
	while (s[x] == c)
		x++;
	while (s[x])
	{
		if (s[x] == c && s[x + 1] != c && s[x + 1])
			sep++;
		x++;
	}
	return (sep);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		y;

	if (!s)
		return (NULL);
	y = 0;
	i = 0;
	arr = malloc(sizeof(char *) * (how_many(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			y = 0;
			while (*s && *s != c && ++y)
				++s;
			arr[i++] = ft_substr(s - y, 0, y);
		}
		else
			++s;
	}
	arr[i] = 0;
	return (arr);
}
