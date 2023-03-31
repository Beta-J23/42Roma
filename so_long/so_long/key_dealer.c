/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dealer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:51:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/31 20:00:19 by alpelliz         ###   ########.fr       */
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
		exit (0);
	}
	if (key == 123) //sx
	{
		ft_putchar('L');
        /*
        map_matrix_new(pos);
        mlx_clear_window(pos->mlx, pos->mlx_win);
        */
		mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x -= 64, pos->player_y);
        
		//pos->x -= 64;
	}
	else if (key == 124) //dx
	{
		ft_putchar('R');
		//pos->x += 64;
		mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x += 64, pos->player_y);
	}
	else if (key == 126) //up
	{
		ft_putchar('U');
		pos->y -= 50;
		mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y -= 64);
	}
	else if (key == 125) //down
	{
		ft_putchar('D');
		mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->player, pos->player_x, pos->player_y += 64);
		pos->y += 50;
	}
	//*mlx_xpm_file_to_image(void *mlx_pointer, char *relative_path, int *width, int *height);
	//mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	
		

	//mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	return (7);
}