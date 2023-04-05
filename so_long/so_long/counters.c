/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:50:28 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/05 19:55:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	player_actions(t_position *pos)
{
	pos->player_x /= 64;
	return (0);
}*/

int	collectible_counter(t_position *pos, int x, int y)
{
	static int		i;

	pos->col--;
	i++;
	ft_printf("COLLECTIBLE COUNTER = %d\n", i);
	return (0);
}

int	exit_door(t_position *pos, int action, int i, int j)
{
	if (((action == 1) && (pos->map_2_matrix[j][i - 1] == 'E'))
		|| ((action == 2) && (pos->map_2_matrix[j][i + 1] == 'E'))
		|| ((action == 3) && (pos->map_2_matrix[j - 1][i] == 'E'))
		|| ((action == 4) && (pos->map_2_matrix[j + 1][i] == 'E')))
	{
		ft_printf("!!!!!!!!!!!!!!!!YOU WIN!!!!!!!!!!!!!!!!!!!!\n");
		exit (0);
	}
	return (0);
}

void	moves(t_position *pos)
{
	pos->counter++;
	ft_printf("Moves: %d\n", pos->counter);
}
