/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:02:33 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/14 17:08:14 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char * dst, const char * src, size_t dstsize)
{
    unsigned int    i;
    unsigned int    j;
    
    i = 0;
    j = 0;
    if ((int)dstsize <= ft_strlen(dst))
        return (dstsize + ft_strlen(src));
    while (dst[i] != '\0')
    {   
        i++;        
    }
    while (src[j] != '\0' && j + i < dstsize)
    {
        
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
    return(i + j);
    
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char dst[] = "ciao";
    char src[] = "grande";
    size_t dstsize = 6;
    //printf("%lu", strlcat("ciao", "grande", 4));
    //printf("%lu", ft_strlcat("ciao", "grande", 4));
    printf("lunghezza:\t%lu\ndst:\t\t%s\n", strlcat(dst, src, dstsize), dst);
    printf("lunghezza:\t%lu\ndst:\t\t%s\n", ft_strlcat(dst, src, dstsize), dst);
}*/