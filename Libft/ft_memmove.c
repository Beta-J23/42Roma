/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:22:34 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/04 14:14:26 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dsts;
	const char		*srcs;
	unsigned int	n;

	if ((unsigned char *) dst == NULL && (unsigned char *) src == NULL)
		return (NULL);
	n = 0;
	dsts = dst;
	srcs = src;
	if (dsts > srcs)
	{
		while (len-- > 0)
			dsts[len] = srcs[len];
	}
	else
	{
		while (len > 0)
		{	
			dsts[n] = srcs[n];
			len--;
			n++;
		}
	}
	return (dsts);
}
