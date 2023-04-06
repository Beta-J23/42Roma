/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:27:18 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 19:30:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size != 0)
	{	
		while ((src[j] != '\0') && (j < (size - 1)))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}

int	ber_control(char *haystack, char *needle, size_t len)
{
	int		i;
	int		j;

	i = ft_strlen(haystack);
	j = len;
	if (!haystack)
		return (0);
	while (needle[j] == haystack[i] && j > 0)
	{
		j--;
		i--;
	}
	if (j == 0)
		return (0);
	else
		return (1);
}
