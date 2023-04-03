/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:49:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/03 20:04:51 by alpelliz         ###   ########.fr       */
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
		//ft_printf("VAR MATRIX IS: %s\n", var->map_2_matrix[j]);
		j++;
	}
		ft_printf("line after free: %s\n", line);
	//var->map_2_matrix[var->player_y / 64][var->player_x / 64] = '0';
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
					ft_printf("Error: The wall at the bottom is broken!!!\n");
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
	//free (map);
	if (j != 1) // CHECK 1 PLAYER EXIST
	{
		ft_printf("Error: No Player in the field!\n");
		x = 1;
	}
	pos->x = i - 1; //LINES VALUE
	pos->y = k;		// COLUMNS VALUE
	return (x);
	/// CHECK TO DO : LAST LINE IS ALL 1; IN THE MAP 0 1 C E ARE PRESENT.
	/// DO 1 EXTERNAL FUNCTION FOR ERRORS. (RETURN DIFFERENT NUMBER TO WRITE DIFFERENT ERRORS).
}

int		map_update(t_position *var, int x, int y, int action)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	//var->map_2_matrix = malloc(sizeof(char) * ft_strlen(map));
	//var->map_matrix = map;
	//ft_printf("TEST, pos->player_x / 64 - 1 = %c\n", (var->map_2_matrix[var->player_y][var->player_x / 64 - 1]));
	mlx_clear_window(var->mlx, var->mlx_win);
	while (y <= var->y)
	{
		
		i = 0;		
		while (i <= var->x)
		{
			if (var->map_2_matrix[j][i] == '1')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, i * 64, j * 64);				
			}
			else if (var->map_2_matrix[j][i] == '0')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor, i * 64, j * 64);
			}
			else if (var->map_2_matrix[j][i] == 'P')
			{
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->player, i * 64, j * 64);
				var->player_x = i * 64;
				var->player_y = j * 64;
			}
			else if (var->map_2_matrix[j][i] == 'C')
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->collectibles, i * 64, j * 64);
			else if (var->map_2_matrix[j][i] == 'E')
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->exit, i * 64, j * 64);

			i++;
		}
		j++;
	}
	return (0);
}


int     map_matrix_updater(t_position *pos, int x, int y, int action)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = x;
	j = y;
	
	if (((pos->map_2_matrix[j][i - 1] == '0') || (pos->map_2_matrix[j][i - 1] == 'C') || (pos->map_2_matrix[j][i - 1] == 'E')) && (action == 1)) //MOVING LEFT
	{
		if ((pos->map_2_matrix[j][i - 1]) == 'C')
		{
			collectible_counter(pos, i - 1, j);
			return (1);
		}
		if ((pos->col == 0) && (pos->map_2_matrix[j][i - 1] == 'E'))
		{
			exit_door(pos);
			return (0);
		}
		return (1);
	}
	if (((pos->map_2_matrix[j][i + 1] == '0') || (pos->map_2_matrix[j][i + 1] == 'C') || (pos->map_2_matrix[j][i + 1] == 'E')) && (action == 2)) // MOVING RIGHT
	{
		if ((pos->map_2_matrix[j][i + 1]) == 'C')
		{
			collectible_counter(pos, i, j);
			return (2);
		}
		if ((pos->col == 0) && (pos->map_2_matrix[j][i + 1] == 'E'))
		{
			exit_door(pos);
			return (0);
		}
		return (2);
	}
	if (((pos->map_2_matrix[j - 1][i] == '0')|| (pos->map_2_matrix[j - 1][i] == 'C') || (pos->map_2_matrix[j - 1][i] == 'E')) && (action == 3)) // MOVING UP
	{
		if ((pos->map_2_matrix[j - 1][i]) == 'C')
		{
			collectible_counter(pos, i, j-1);
			return (3);
		}
		if ((pos->col == 0) && (pos->map_2_matrix[j - 1][i] == 'E'))
		{
			exit_door(pos);
			return (0);
		}
		return (3);
	}
	if (((pos->map_2_matrix[j + 1][i] == '0') || (pos->map_2_matrix[j + 1][i] == 'C') || (pos->map_2_matrix[j + 1][i] == 'E')) && (action == 4)) // MOVING DOWN
	{
		if ((pos->map_2_matrix[j + 1][i]) == 'C')
		{
			collectible_counter(pos, i, j+1);
			return (4);
		}
		if ((pos->col == 0) && (pos->map_2_matrix[j + 1][i] == 'E'))
		{
			exit_door(pos);
			return (0);
		}
		return (4);
	}
	return(0);
}
