/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:56:47 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/05 20:19:01 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	starter(t_position *sprite)
{
	sprite->img_width = 64;
	sprite->img_width = 64;
	sprite->col = 0;
	sprite->counter = 0;
	sprite->floor = mlx_xpm_file_to_image(sprite->mlx,
			"xpm/floor.xpm", &sprite->img_width, &sprite->img_height);
	sprite->wall = mlx_xpm_file_to_image(sprite->mlx,
			"xpm/wall.xpm", &sprite->img_width, &sprite->img_height);
	sprite->player = mlx_xpm_file_to_image(sprite->mlx,
			"xpm/player.xpm", &sprite->img_width, &sprite->img_height);
	sprite->collectibles = mlx_xpm_file_to_image(sprite->mlx,
			"xpm/collectibles.xpm", &sprite->img_width, &sprite->img_height);
	sprite->exit = mlx_xpm_file_to_image(sprite->mlx,
			"xpm/exit.xpm", &sprite->img_width, &sprite->img_height);
}

void	counter_initializer(t_fcounter *c)
{
	c->i = 0;
	c->j = 0;
	c->k = 0;
	c->z = 0;
	c->c = 0;
	c->exit = 0;
	c->i = 0;
}
