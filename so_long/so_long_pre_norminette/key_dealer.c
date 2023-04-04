/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dealer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:51:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 13:17:09 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_position *pos)
{
	ft_printf("%d\n", key);
	if (key == 53)
	{
		ft_printf("Goodbye\n");
		mlx_destroy_window(pos->mlx, pos->mlx_win);
		exit (0);
	}
	if ((key == 123) || (key == 0))
	{		
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 1) == 1)
		{
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64) - 1] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x -= 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x + 64, pos->player_y);
			moves(pos);
		}
	}
	else if ((key == 124) || (key == 2))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 2) == 2)
		{	
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64) + 1)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64)] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x += 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x - 64, pos->player_y);
			moves(pos);
		}
	}
	else if ((key == 126) || (key == 13))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 3) == 3)
		{
			(pos->map_2_matrix[(pos->player_y / 64) - 1][(pos->player_x / 64)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y -= 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x, pos->player_y + 64);
			moves(pos);
		}
	}
	else if ((key == 125) || (key == 1))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 4) == 4)
		{
			(pos->map_2_matrix[(pos->player_y / 64) + 1][(pos->player_x / 64)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y += 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x, pos->player_y - 64);
			moves(pos);
		}
	}
	return (7);
}

int	player_actions(t_position *pos)
{
	pos->player_x /= 64;
	return (0);
}

int	collectible_counter(t_position *pos, int x, int y)
{
	int		i;

	pos->col--;
	i++;
	ft_printf("COLLECTIBLE COUNTER = %d\n", i);
	return (0);
}

int	exit_door(t_position *pos, int action, int i, int j)
{
	if (((action == 1) && (pos->map_2_matrix[j][i - 1] == 'E')) || ((action == 2) && (pos->map_2_matrix[j][i + 1] == 'E')) ||
	((action == 3) && (pos->map_2_matrix[j - 1][i] == 'E')) || ((action == 4) && (pos->map_2_matrix[j + 1][i] == 'E')))
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
