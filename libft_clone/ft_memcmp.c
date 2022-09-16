/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:37 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/04 14:27:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = 0;
	ss2 = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i != n)
	{
		if (ss1[i] == ss2[i])
			i++;
		else
			return (ss1[i] - ss2[i]);
	}
	return (0);
}
