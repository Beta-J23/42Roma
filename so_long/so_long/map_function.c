/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:49:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/31 20:00:51 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char 	create_map(char *map, t_position *var)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	i = 0;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		i = 0;
		line = malloc(sizeof(char) * ft_strlen(line));
		while (line[i] != '\n')
		{
			if (line[i] == '1')
			{
				/*
				if (line[i + 1] == '0')
				{
					line[i] = reverse(line[i], line[i + 1]);
					line [i + 1] = reverse(line[i + 1], line[i]);
					mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, (i + 1) * 64, j * 64);
				}	
				*/
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, i * 64, j * 64);				
			}
			else if (line[i] == '0')
			{
				//sprites('0', var, i , j); //	draw floor
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor, i * 64, j * 64);
			}
			else if (line[i] == 'P')
				//sprites('P', var, i , j); //	draw Player
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->player, i * 64, j * 64);
				var->player_x = i * 64;
				var->player_y = j * 64;
			}
			else if (line[i] == 'C')
				//sprites('C', var, i , j); //	draw collectibles
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->collectibles, i * 64, j * 64);
			else if (line[i] == 'E')
				//sprites('E', var, i, j); // draw exit
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->exit, i * 64, j * 64);
			i++;
		}
		j++;
		free (line);
	}
	return(0);
}

int check_map(char *map, t_position *pos)
{
	char		*strmap;
	int			fd;
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
	//map = malloc(sizeof(char) * ft_strlen(map));
	fd = open(map, O_RDONLY);
	while (1)
	{
		strmap = get_next_line(fd);
		if (strmap == NULL)
			break;
		//ft_printf("%s", strmap);
		if (k == 0)
		{
			while (strmap[z] != '\n') // CHECK THAT FIRST LINE IS ALL 1.
			{
				if (strmap[z] != '1')
				{
					ft_printf("The wall at the bottom is broken!!!\n");
					x = 1;
				} 
				z++;
			}
		}
		strmap = malloc(sizeof(char) * ft_strlen(strmap));
		i = 0;	
		while (strmap[i] != '\0')
		{
			if (strmap[i] == 'P') //CHECK NUMBER OF PLAYERS
				j++;
			if ((strmap[i] != '0') && (strmap[i] != '1') && (strmap[i] != 'P') && (strmap[i] != 'C') && (strmap[i] != 'E') && (strmap[i] != '\n'))
				x = 1;
			i++;
		}
		if (z != i - 1) //CHECK ALL LINES OF MAP ARE EQUALS
		{
			ft_printf("Lines of map are not equals\n");
			x = 1;
		}
		if ((strmap[0] != '1') || (strmap[(ft_strlen(strmap) - 2)] != '1')) //CHECK 1(walls) at side of maps
		{
			ft_printf("A WALL AT THE SIDE IS BROKEN\n");
			x = 1;
		}
		k++;
		free (strmap);
	}
	if  (k >= z) // CHECK MAP IS RECTANGULAR
	{
		ft_printf("Maps is not rectangular\n");
		x = 1;
	}
	//free (map);
	if (j != 1) // CHECK 1 PLAYER EXIST
	{
		ft_printf("No Player in the field!\n");
		x = 1;
	}
	pos->x = i - 1;
	pos->y = k;
	return (x);
	/// CHECK TO DO : LAST LINE IS ALL 1; IN THE MAP 0 1 C E ARE PRESENT.
	/// DO 1 EXTERNAL FUNCTION FOR ERRORS. (RETURN DIFFERENT NUMBER TO WRITE DIFFERENT ERRORS).
}

int     map_matrix_new(t_position *pos)
{
	create_map(pos->map_matrix, pos);
	return (0);	
}