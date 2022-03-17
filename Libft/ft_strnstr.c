/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:19:29 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 16:12:03 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	
	if (*needle == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] != '\0' && j < len)
		{
			if (needle[j] == haystack[i])
			{
				return ((char *)&haystack[i]);
			}
			j++;	
		}
		i++;
	}
	return (NULL); 
}
/*
#include <xlocale.h>
#include <stdio.h>
#include <string.h>

int main()
{
	//printf("%s", strnstr("abcdef", "bc",3));
	// printf("%s", ft_strnstr("abcdef", "bcd", 3)); 
}*/