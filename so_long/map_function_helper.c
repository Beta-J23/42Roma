/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:21:26 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 17:08:43 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	create_map(char *map, t_position *var)
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
			break ;
		i = 0;
		create_map_helper(var, line, i, j);
		free (line);
		j++;
	}
	map_matrix_creator(var, map);
	return (0);
}

void	create_map_helper(t_position *var, char *line, int i, int j)
{
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(var->mlx, var->mlx_win,
				var->wall, i * 64, j * 64);
		else if (line[i] == '0')
			mlx_put_image_to_window(var->mlx, var->mlx_win,
				var->floor, i * 64, j * 64);
		else if (line[i] == 'P')
		{
			mlx_put_image_to_window(var->mlx, var->mlx_win,
				var->player, i * 64, j * 64);
			var->player_x = i * 64;
			var->player_y = j * 64;
		}
		i = create_map_helper_split(var, line, i, j);
	}	
}

int	create_map_helper_split(t_position *var, char *line, int i, int j)
{
	if (line[i] == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_win,
			var->collectibles, i * 64, j * 64);
		var->col++;
	}
	else if (line[i] == 'E')
		mlx_put_image_to_window(var->mlx, var->mlx_win,
			var->exit, i * 64, j * 64);
	i++;
	return (i);
}
