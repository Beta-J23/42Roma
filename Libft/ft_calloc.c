/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:47:51 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 17:56:41 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *calloc(size_t count, size_t size)
{
    char    *str;
    
    str = malloc(count * size);
    if (!str)
        return (0);    
    ft_bzero(str, count * size);
    return (str);
}

#include <stdio.h>

int main()
{
    
}