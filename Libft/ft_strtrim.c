/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:09 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/21 18:53:20 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    int     start;
    int     end;
    int     i;

    start = 0;
    end = (ft_strlen(s1));
    if (!s1 || !set)
        return(NULL);
    while (ft_strchr(set, s1[start]) && s1[start])
    {
        start++;
    }
    while (end > start && (ft_strchr(set, s1[end])))
    {
        end--;
    }
    str = malloc(end - start + 1);
    i = 0;
    if (!str)
        return (NULL);
    while (start < end)
    {
        str[i++] = s1[start++];
    }
    str[i] = '\0';
    return (str);
}/*

#include <stdio.h>
#include <string.h>

int main()
{
    const char a[] = "ho mangiato la pizza ho";
    const char b[] = "ho";
    //int n = 3;
	//printf("%s", strnstr("abcdef", "cde",3));
	printf("%s", ft_strtrim(a, b)); 
}*/