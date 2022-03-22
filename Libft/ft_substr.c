/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:48:37 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/21 11:35:08 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char             *substr;
    unsigned int     i;
    unsigned int     j;

    i = 0;
    j = 0;
    substr = malloc(sizeof(char) * len + 1);
    if  (!substr)
        return (NULL);
    while (i < len)
    {
        while (i < start)
        {
            i++;
        }
        substr[j] = s[i];
        i++;
        j++;
    }
    substr[j] = '\0';
    return (substr);
}/*

#include <stdio.h>
#include <string.h>

int main()
{
    const char a[] = "ciaone";
    //char b[] = "cibo";
    //int n = 3;
	//printf("%s", strnstr("abcdef", "cde",3));
	printf("%s", ft_substr(a, 1, 4)); 
}*/
