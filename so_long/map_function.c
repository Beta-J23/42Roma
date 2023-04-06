/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:49:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 12:58:39 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_matrix_creator(t_position *var, char *map)
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
		var->map_2_matrix[j] = malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(var->map_2_matrix[j], line, ft_strlen(line));
		while (line[i] != '\n')
			i++;
		free (line);
		j++;
	}
}

int	map_matrix_updater(t_position *pos, int i, int j, int action)
{
	if (((pos->map_2_matrix[j][i - 1] == '0')
		|| (pos->map_2_matrix[j][i - 1] == 'C'))
			&& (action == 1))
	{
		if ((pos->map_2_matrix[j][i - 1]) == 'C')
			collectible_counter(pos);
		return (1);
	}
	if (((pos->map_2_matrix[j][i + 1] == '0')
		|| (pos->map_2_matrix[j][i + 1] == 'C')) && (action == 2))
	{
		if ((pos->map_2_matrix[j][i + 1]) == 'C')
			collectible_counter(pos);
		return (2);
	}
	return (map_2(pos, i, j, action));
}

int	map_2(t_position *pos, int i, int j, int action)
{
	if (((pos->map_2_matrix[j - 1][i] == '0')
		|| (pos->map_2_matrix[j - 1][i] == 'C')) && (action == 3))
	{
		if ((pos->map_2_matrix[j - 1][i]) == 'C')
			collectible_counter(pos);
		return (3);
	}
	if (((pos->map_2_matrix[j + 1][i] == '0')
		|| (pos->map_2_matrix[j + 1][i] == 'C')) && (action == 4))
	{
		if ((pos->map_2_matrix[j + 1][i]) == 'C')
			collectible_counter(pos);
		return (4);
	}
	if (pos->col == 0)
		exit_door(pos, action, i, j);
	return (0);
}
