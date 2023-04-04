/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:49:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 14:25:12 by alpelliz         ###   ########.fr       */
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
		while (line[i] != '\n')
		{
			if (line[i] == '1')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, i * 64, j * 64);				
			}
			else if (line[i] == '0')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor, i * 64, j * 64);
			}
			else if (line[i] == 'P')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->player, i * 64, j * 64);
				var->player_x = i * 64;
				var->player_y = j * 64;
			}
			else if (line[i] == 'C')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->collectibles, i * 64, j * 64);
				var->col++;
			}
			else if (line[i] == 'E')
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->exit, i * 64, j * 64);

			i++;
		}
		free (line);
		j++;
	}
	fd = open(map, O_RDONLY);
	i = 0;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		i = 0;
		var->map_2_matrix[j] = malloc(sizeof(char) * ft_strlen(line));
		//ft_printf("line = %s\n", line);
		ft_strlcpy(var->map_2_matrix[j], line, ft_strlen(line));	
		while (line[i] != '\n')
			i++;
		free (line);
		j++;
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
	int			c;
	int			exit;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	z = 0;

	fd = open(map, O_RDONLY);
	
	while (1)
	{
		strmap = get_next_line(fd);
		if (strmap == NULL)
			break;
		if (k == 0)
		{
			while (strmap[z] != '\n') // CHECK THAT FIRST LINE IS ALL 1.
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
			ft_printf("Error: Lines of map are not equals\n");
			x = 1;
		}
		if ((strmap[0] != '1') || (strmap[(ft_strlen(strmap) - 2)] != '1')) //CHECK 1(walls) at side of maps
		{
			ft_printf("Error: A WALL AT THE SIDE IS BROKEN\n");
			x = 1;
		}
		k++;
		free (strmap);
	}
	if  (k >= z) // CHECK MAP IS RECTANGULAR
	{
		ft_printf("Error: Maps is not rectangular\n");
		x = 1;
	}
	if (j != 1) // CHECK 1 PLAYER EXIST
	{
		ft_printf("Error: No Player in the field!\n");
		x = 1;
	}
	pos->x = i - 1; //LINES VALUE
	pos->y = k;		// COLUMNS VALUE

	fd = open(map, O_RDONLY);
	i = 0;
	j = 0;
	z = 0;
	while (1)
	{
		strmap = get_next_line(fd);
		if (strmap == NULL)
			break;
		i = 0;
		while (strmap[i] != '\n')
		{
			if (strmap[i] == '0')
				z++;
			if (strmap[i] != '0' && strmap[i] != '1' && strmap[i] != 'P' && strmap[i] != 'C' &&
			strmap[i] != 'E')
			{
				ft_printf ("Error: in map only Floor, Walls, Player, Collectibles and Exit are admitted!\n");
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
					ft_printf("Error: The wall at the bottom is broken!\n"); //CHECK WALLS AT BOTTOM
					x = 1;
				}	
			}
			i++;
		}
		free (strmap);
		j++;
	}
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
		ft_printf("Error: There is no floor! I cannot walk!\n"); // CHECK FLOOR IS PRESENT
		x = 1;
	}
	return (x);
	/// CHECK TO DO : LAST LINE IS ALL 1; IN THE MAP 0 1 C E ARE PRESENT.
	/// DO 1 EXTERNAL FUNCTION FOR ERRORS. (RETURN DIFFERENT NUMBER TO WRITE DIFFERENT ERRORS).
}

int     map_matrix_updater(t_position *pos, int x, int y, int action)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = x;
	j = y;
	
	if (((pos->map_2_matrix[j][i - 1] == '0') || (pos->map_2_matrix[j][i - 1] == 'C')) && (action == 1)) //MOVING LEFT
	{
		if ((pos->map_2_matrix[j][i - 1]) == 'C')
		{
			collectible_counter(pos, i - 1, j);
			return (1);
		}
		return (1);
	}
	if (((pos->map_2_matrix[j][i + 1] == '0') || (pos->map_2_matrix[j][i + 1] == 'C')) && (action == 2)) // MOVING RIGHT
	{
		if ((pos->map_2_matrix[j][i + 1]) == 'C')
		{
			collectible_counter(pos, i, j);
			return (2);
		}
		return (2);
	}
	if (((pos->map_2_matrix[j - 1][i] == '0')|| (pos->map_2_matrix[j - 1][i] == 'C')) && (action == 3)) // MOVING UP
	{
		if ((pos->map_2_matrix[j - 1][i]) == 'C')
		{
			collectible_counter(pos, i, j-1);
			return (3);
		}
		return (3);
	}
	if (((pos->map_2_matrix[j + 1][i] == '0') || (pos->map_2_matrix[j + 1][i] == 'C')) && (action == 4)) // MOVING DOWN
	{
		if ((pos->map_2_matrix[j + 1][i]) == 'C')
		{
			collectible_counter(pos, i, j+1);
			return (4);
		}
		return (4);
	}
	if (pos->col == 0)
	{
		exit_door(pos, action, i , j);
		return(0);
	}
	return(0);
}
