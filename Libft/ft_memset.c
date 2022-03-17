/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:02 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 18:28:41 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*unb;
	unsigned char	unsc;
	int				i;

	unb = b;
	unsc = c;
	i = 0;
	while (i < len)
	{
		*unb++ = unsc;
		i++;
	}
	return (b);
}

#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "ciao";
    //char b[] = "cibo";
    //int n = 3;
	//printf("%s", strnstr("abcdef", "cde",3));
	printf("%s", ft_memset(a, '$', 3)); 
}
