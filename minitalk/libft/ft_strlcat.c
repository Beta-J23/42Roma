/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:02:33 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/09 14:47:46 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	counter;
	size_t	counter1;
	size_t	cs;

	cs = ft_strlen(src);
	counter1 = 0;
	counter = ft_strlen(dst);
	if (!n || n <= counter)
		return (n + cs);
	while (src[counter1] && (counter + counter1 + 1) < n)
	{
		dst[counter + counter1] = src[counter1];
		counter1++;
	}
	dst[counter + counter1] = 0;
	return (counter + cs);
}
