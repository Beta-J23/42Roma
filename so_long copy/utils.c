/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:27:18 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 18:53:23 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size != 0)
	{	
		while ((src[j] != '\0') && (j < (size - 1)))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
/*
int	print_matrix(t_position *pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < pos->y)
	{
		ft_printf("MATRIX IS: %s\n", pos->map_2_matrix[j]);
		j++;
	}
	return (0);
}*/