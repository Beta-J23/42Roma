/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:24:46 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/14 17:10:39 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strrchr(const char *s, int c)
{
    int i;
    unsigned char cs;

    i = 0;
    cs = c;

    while (*s != '\0')
    {
        s++;
    }
    while (*s != '0')
    {
        if (*s == cs)
            return ((char*) s);
               
        s--;
    }
    if (*s == cs)
        return((char *) s);
    return (0);
}/*

#include <stdio.h>
#include <string.h>

int main()
{
    //printf("%s", strrchr("abcdce", 'c'));
    printf("%s", ft_strrchr("abcdce", '\0')); 
}*/