/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:15:58 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 18:52:52 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *map, t_position *pos)
{
	char		*strmap;
	int			i;
	int			j;
	int			k;
	int			z;
	int			x;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	z = 0;
	pos->fd = open(map, O_RDONLY);
	while (1)
	{
		strmap = get_next_line(pos->fd);
		if (strmap == NULL)
			break ;
		if (k == 0)
		{
			while (strmap[z] != '\n')
			{
				if (strmap[z] != '1')
				{
					ft_printf("Error: The wall on top is broken!!!\n");
					x = 1;
				}
				z++;
			}
		}
		i = 0;
		//if (map_while_helper(pos, strmap, j, z, x) == 1)
		//	x = 1;
		while (strmap[i] != '\0')
		{
			if (strmap[i] == 'P')
				j++;
			if ((strmap[i] != '0') && (strmap[i] != '1') && (strmap[i] != 'P')
				&& (strmap[i] != 'C') && (strmap[i] != 'E')
				&& (strmap[i] != '\n'))
				x = 1;
			i++;
		}
		if (z != i - 1)
		{
			ft_printf("Error: Lines of map are not equals\n");
			x = 1;
		}
		if ((strmap[0] != '1') || (strmap[(ft_strlen(strmap) - 2)] != '1'))
		{
			ft_printf("Error: A WALL AT THE SIDE IS BROKEN\n");
			x = 1;
		}
		k++;
		free (strmap);
	}
	if (map_error_handler(x, k, j, z) == 1)
		x = 1;
	pos->x = i - 1;
	pos->y = k;
	if (check_map_helper(map, pos, x, k) == 1)
		x = 1;
	return (x);
}
/*
int map_while_helper(t_position *pos, char *strmap, int	j, int z, int x)
{
	int		i;

	i = 0;
	while (strmap[i] != '\0')
		{
			if (strmap[i] == 'P')
				j++;
			if ((strmap[i] != '0') && (strmap[i] != '1') && (strmap[i] != 'P')
				&& (strmap[i] != 'C') && (strmap[i] != 'E')
				&& (strmap[i] != '\n'))
			i++;
		}
		if (z != i - 1)
		{
			ft_printf("Error: Lines of map are not equals\n");
			x = 1;
		}
		if ((strmap[0] != '1') || (strmap[(ft_strlen(strmap) - 2)] != '1'))
		{
			ft_printf("Error: A WALL AT THE SIDE IS BROKEN\n");
			x = 1;
		}
		return (x);
}*/

int	map_error_handler(int x, int k, int j, int z)
{
	if (k >= z)
	{
		ft_printf("Error: Maps is not rectangular\n");
		x = 1;
	}
	if (j != 1)
	{
		ft_printf("Error: This is a 1 Player Game!\n");
		x = 1;
	}
	return (x);
}

int	check_map_helper(char *map, t_position *pos, int x, int k)
{
	//int		fd;
	int		i;
	int		j;
	int		z;
	int		c;
	char	*strmap;
	int		exit;

	pos->fd = open(map, O_RDONLY);
	i = 0;
	j = 0;
	z = 0;
	exit = 0;
	while (1)
	{
		strmap = get_next_line(pos->fd);
		if (strmap == NULL)
			break ;
		i = 0;
		while (strmap[i] != '\n')
		{
			if (strmap[i] == '0')
				z++;
			if (strmap[i] != '0' && strmap[i] != '1' && strmap[i]
				!= 'P' && strmap[i] != 'C'
				&& strmap[i] != 'E')
			{
				ft_printf ("Error: Unknown element in map!\n");
				x = 1;
			}
			if (strmap[i] == 'E')
				exit++;
			if (strmap[i] == 'C')
				c++;
			if (j == k - 1)
			{
				if (strmap[i] != '1')
				{
					ft_printf("Error: The wall at the bottom is broken!\n");
					x = 1;
				}	
			}
			i++;
		}
		free (strmap);
		j++;
	}
	if (map_helper_error_handler(x, exit, c, z) == 1)
		x = 1;
	return (x);
}

int	map_helper_error_handler(int x, int exit, int c, int z)
{
	x = 0;
	if (exit != 1)
	{
		ft_printf("Error: There must be 1 Exit!!!\n");
		x = 1;
	}	
	if (c == 0)
	{
		ft_printf("Error: Nothing to collect!\n");
		x = 1;
	}
	if (z == 0)
	{
		ft_printf("Error: There is no floor! I cannot walk!\n");
		x = 1;
	}
	return (x);
}
