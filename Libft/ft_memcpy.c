/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:02 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/05 12:37:53 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dsts;
	const unsigned char	*srcs;

	if (!dst && !src)
		return (0);
	dsts = dst;
	srcs = src;
	while (n > 0)
	{
		*dsts++ = *srcs++;
		n--;
	}
	return (dst);
}
