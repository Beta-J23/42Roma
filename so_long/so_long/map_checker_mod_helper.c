/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_mod_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:34:03 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/05 20:17:54 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error_handler(int x, t_fcounter *c)
{
	if (c->k >= c->z)
	{
		ft_printf("Error: Maps is not rectangular\n");
		x = 1;
	}
	if (c->j != 1)
	{
		ft_printf("Error: This is a 1 Player Game!\n");
		x = 1;
	}
	return (x);
}

int	map_helper_error_handler(int x, t_fcounter *c)
{
	x = 0;
	if (c->exit != 1)
	{
		ft_printf("Error: There must be 1 Exit!!!\n");
		x = 1;
	}	
	if (c->c == 0)
	{
		ft_printf("Error: Nothing to collect!\n");
		x = 1;
	}
	if (c->z == 0)
	{
		ft_printf("Error: There is no floor! I cannot walk!\n");
		x = 1;
	}
	return (x);
}

int	error_handler_3(t_position *pos, t_fcounter *c, int x)
{
	if (c->j == c->k - 1)
	{
		if (c->strmap[c->i] != '1')
		{
			ft_printf("Error: The wall at the bottom is broken!\n");
			x = 1;
		}
		if (c->strmap[ft_strlen(c->strmap)] == '\0')
		{
			c->strmap[ft_strlen(c->strmap + 1)] = '\n';
		}
	}
	return (x);
}
