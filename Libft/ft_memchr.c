/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:53:09 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 15:54:50 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   cs;
    unsigned char   *ssv;

    cs = c;
    ssv = (unsigned char *)s;
    //s = (unsigned char *)s;
    while (n > 0)
    {
        if (*ssv == cs)
        {
            return (ssv);
        }
        ssv++;
        n--;
    }
    return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char s[] = "abcdef";
    int c = '0'; 
    size_t n = 3;
    //printf("%s", memchr("abcdef", 'b',1));
	printf("%s", ft_memchr(s, c, n)); 
}*/