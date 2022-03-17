/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:02 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 15:56:49 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst, void *src, size_t n)
{
    unsigned char   *dsts;
    unsigned char   *srcs;

    dsts = dst;
    srcs = src;
    
    while (n > 0)
    {
        *dsts++ = *srcs++;
        n--;
    }
    return(dst);
}/*

#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "ciao";
    char b[] = "cibo";
    int n = 3;
	//printf("%s", strnstr("abcdef", "cde",3));
	printf("%s", ft_memcpy(a, b, n)); 
}*/