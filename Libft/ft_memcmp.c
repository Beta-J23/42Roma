/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:37 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 14:47:35 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
    unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = 0;
	ss2 = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	
	i = 0;
	while (i < n && (ss1[i] == ss2[i]))
	{    
			i++;
	}
	if (ss1[i] != ss2[i])
	{
		return (ss1[i] - ss2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	//printf("%d", memcmp("dfcdef", "abcdef",3));
	printf("%d", ft_memcmp("abc", "abc",4)); 
}
*/