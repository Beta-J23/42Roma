/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:44:26 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/30 16:55:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_position
{
	void *mlx; 
	void *mlx_win; 
    int x;
    int y;
    void	*tux;
	int beginX; 
	int beginY; 
	int endX; 
	int endY;
	int color;
}	t_position;

#endif

