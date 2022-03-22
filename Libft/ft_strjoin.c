/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:36:43 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/21 19:20:55 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *newstr;
    int     i;
    int     j;
    
    if (!s1 || !s2)
        return (0);
    i = 0;
    j = 0;
    newstr = (malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
    if (!newstr)
        return (NULL);
    
    while (i < (ft_strlen(s1) + ft_strlen(s2)))
    {
        newstr[i] = s1[i];
        i++;
        while (i >= ft_strlen(s1) && i < (ft_strlen(s1) + ft_strlen(s2)))
        {
            newstr[i] = s2[j];
            i++;
            j++;
        }
    }
    newstr[i] = '\0';
    return (newstr);
}/*

#include <stdio.h>
#include <string.h>

int main()
{
    const char a[] = "troppo";
    const char b[] = "forte";
    //char b[] = "cibo";
    //int n = 3;
	//printf("%s", strnstr("abcdef", "cde",3));
	printf("%s", ft_strjoin(a, b)); 
}*/