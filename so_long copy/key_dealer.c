/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dealer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:51:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 19:51:41 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_position *pos)
{
	if (key == 53)
	{
		ft_printf("Goodbye\n");
		mlx_destroy_window(pos->mlx, pos->mlx_win);
		exit (0);
	}
	move_left(key, pos);
	move_right(key, pos);
	move_up(key, pos);
	move_down(key, pos);
	return (7);
}

void	move_left(int key, t_position *pos)
{
	if ((key == 123) || (key == 0))
	{		
		if (map_matrix_updater(pos, (pos->player_x / 64),
				(pos->player_y / 64), 1) == 1)
		{
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64)
					- 1] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))]
					= '0');
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player,
				pos->player_x -= 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor,
				pos->player_x + 64, pos->player_y);
			moves(pos);
		}
	}
}

void	move_right(int key, t_position *pos)
{
	if ((key == 124) || (key == 2))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64),
				(pos->player_y / 64), 2) == 2)
		{	
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64)
						+ 1)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64)]
					= '0');
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player,
				pos->player_x += 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor,
				pos->player_x - 64, pos->player_y);
			moves(pos);
		}
	}
}

void	move_up(int key, t_position *pos)
{
	if ((key == 126) || (key == 13))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64)
				, 3) == 3)
		{
			(pos->map_2_matrix[(pos->player_y / 64) - 1][(pos->player_x / 64)]
					= 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))]
					= '0');
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player,
				pos->player_x, pos->player_y -= 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor,
				pos->player_x, pos->player_y + 64);
			moves(pos);
		}
	}
}

void	move_down(int key, t_position *pos)
{
	if ((key == 125) || (key == 1))
	{
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64)
				, 4) == 4)
		{
			(pos->map_2_matrix[(pos->player_y / 64) + 1][(pos->player_x / 64)]
					= 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))]
					= '0');
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player,
				pos->player_x, pos->player_y += 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor,
				pos->player_x, pos->player_y - 64);
			moves(pos);
		}
	}
}
