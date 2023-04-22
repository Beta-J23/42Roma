/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:02 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/05 17:51:38 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*unb;
	unsigned char	unsc;
	int				i;

	unb = b;
	unsc = c;
	i = 0;
	while (i < len)
	{
		*unb++ = unsc;
		i++;
	}
	return (b);
}
