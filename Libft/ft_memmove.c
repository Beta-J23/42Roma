/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:22:34 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 16:45:11 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    void    *ft_memcpy(void *dst, void *src, size_t n)

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

}