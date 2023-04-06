/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:12:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 19:28:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *map, t_position *pos, t_fcounter *c)
{
	int			x;

	x = 0;
	counter_initializer(c);
	pos->fd = open(map, O_RDONLY);
	if (pos->fd < 0)
	{
		x = 1;
		return (2);
	}
	x = while_map_checker(pos, c, x);
	if (map_error_handler(x, c) == 1)
		x = 1;
	pos->x = c->i;
	pos->y = c->k;
	if (check_map_helper(map, pos, x, c) == 1)
		x = 1;
	return (x);
}

int	while_map_checker(t_position *pos, t_fcounter *c, int x)
{
	while (1)
	{
		c->strmap = get_next_line(pos->fd);
		if (c->strmap == NULL)
			break ;
		if (c->k == 0)
		{
			while (c->strmap[c->z] != '\n' && c->strmap[c->z] != '\0')
			{
				if (c->strmap[c->z] != '1')
				{
					ft_printf("Error: The wall on top is broken!!!\n");
					x = 1;
				}
				c->z++;
			}
		}
		x = half_while_map(pos, c, x);
		c->k++;
		free (c->strmap);
	}
	return (x);
}

int	half_while_map(t_position *pos, t_fcounter *c, int x)
{
	(void)pos;
	c->i = 0;
	while (c->strmap[c->i] != '\0' && c->strmap[c->i] != '\n')
	{
		if (c->strmap[c->i] == 'P')
			c->j++;
		if ((c->strmap[c->i] != '0') && (c->strmap[c->i] != '1')
			&& (c->strmap[c->i] != 'P') && (c->strmap[c->i] != 'C')
			&& (c->strmap[c->i] != 'E') && (c->strmap[c->i] != '\n'))
			x = 1;
		c->i++;
	}
	if (c->z != c->i)
	{
		ft_printf("Error: Lines of map are not equals\n");
			x = 1;
	}
	if ((c->strmap[0] != '1') || (c->strmap[(ft_strlen(c->strmap) - 2)]
			!= '1'))
	{
		ft_printf("Error: A wall at the side is broken\n");
		x = 1;
	}
	return (x);
}

int	check_map_helper(char *map, t_position *pos, int x, t_fcounter *c)
{
	c->i = 0;
	c->j = 0;
	c->z = 0;
	c->exit = 0;
	pos->fd = open(map, O_RDONLY);
	while (1)
	{
		c->strmap = get_next_line(pos->fd);
		if (c->strmap == NULL)
			break ;
		c->i = 0;
		x = half_while_2(pos, c, x);
		free (c->strmap);
		c->j++;
	}
	if (map_helper_error_handler(x, c) == 1)
		x = 1;
	return (x);
}

int	half_while_2(t_position *pos, t_fcounter *c, int x)
{
	while ((c->strmap[c->i] != '\n' && c->strmap[c->i] != '\0'))
	{
		if (c->strmap[c->i] == '0' || c->strmap[c->i] == 'C')
			c->z++;
		if (c->strmap[c->i] != '0' && c->strmap[c->i] != '1' && c->strmap[c->i]
			!= 'P' && c->strmap[c->i] != 'C' && c->strmap[c->i] != 'E')
		{
			ft_printf ("Error: Unknown element in map!\n");
			x = 1;
		}
		if (c->strmap[c->i] == 'E')
		{
			c->exit++;
		}
		if (c->strmap[c->i] == 'C')
			c->c++;
		x = error_handler_3(pos, c, x);
		c->i++;
	}
	return (x);
}
