/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:37:53 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/03 13:03:32 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cs;

	cs = c;
	while (*s != '\0')
	{
		if (*s == cs)
			return ((char *) s);
		s++;
	}
	if (*s == cs)
		return ((char *) s);
	return (0);
}
