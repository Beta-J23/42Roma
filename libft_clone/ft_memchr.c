/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:53:09 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/09 15:36:40 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cs;
	unsigned char	*ssv;

	cs = c;
	ssv = (unsigned char *)s;
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
