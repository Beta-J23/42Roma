/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dealer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:51:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/03 19:55:50 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int deal_key(int key, t_position *pos)
{
	//mlx_clear_window(pos->mlx, pos->mlx_win);	
	//mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	ft_printf("%d\n", key);
	if (key == 53)
	{
		ft_printf("Goodbye\n");
		mlx_destroy_window(pos->mlx, pos->mlx_win);
		//free (pos->map_2_matrix);
		//print_matrix(pos);
		exit (0);
	}
	if ((key == 123) || (key == 0)) //sx 'A'
	{
		ft_putchar('L');
		
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 1) == 1)
		{	
			//free(pos->map_2_matrix);
			//pos->map_2_matrix = malloc(sizeof(char *) * (pos->x * pos->y));
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64) - 1] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x -= 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x + 64, pos->player_y);
			//ft_printf("TEST, pos->player_x / 64 - 1 = %c\n", (pos->map_2_matrix[pos->player_y][pos->player_x / 64 - 1]));
			//ft_printf("TEST, pos->player_x / 64 - 1 = %c\n", ((pos->player_x / 64) - 1));
			//map_update(pos, 0, 0, 0);
		}
		/*
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 1) == 1)
		{
			ft_printf("VAR MATRIX IS: %s\n", pos->map_2_matrix[pos->y]);
			ft_printf("TEST \n");
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x -= 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x + 64, pos->player_y);
		}	*/
	}
	else if ((key == 124) || (key == 2)) //dx 'R'
	{
		ft_putchar('R');
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 2) == 2)
		{	
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64) + 1)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][(pos->player_x / 64)] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x += 64, pos->player_y);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x - 64, pos->player_y);
		}
		//player_actions(&pos);
	}
	else if ((key == 126) || (key == 13)) //up 'W'
	{
		ft_putchar('U');
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 3) == 3)
		{
			(pos->map_2_matrix[(pos->player_y / 64) - 1][(pos->player_x / 64)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y -= 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x, pos->player_y + 64);
		}
	}
	else if ((key == 125) || (key == 1)) //down 'S'
	{
		ft_putchar('D');
		if (map_matrix_updater(pos, (pos->player_x / 64), (pos->player_y / 64), 4) == 4)
		{
			(pos->map_2_matrix[(pos->player_y / 64) + 1][(pos->player_x / 64)] = 'P');
			(pos->map_2_matrix[pos->player_y / 64][((pos->player_x / 64))] = '0');
			print_matrix(pos);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y += 64);
			mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->floor, pos->player_x, pos->player_y - 64);
		}
	}
	return (7);
}

int		player_actions(t_position *pos)
{
	pos->player_x /= 64;
	return (0);
}

int		collectible_counter(t_position *pos, int x, int y)
{
	pos->col--;
	ft_printf("COLLECTIBLE COUNTER = %d\n", pos->col);
	return (0);
}

int		exit_door(t_position *pos)
{
	ft_printf("!!!!!!!YOU WIN!!!!!!!!\n");
	exit (0);
}