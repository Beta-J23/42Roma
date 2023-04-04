/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:44:26 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/03 19:42:42 by alpelliz         ###   ########.fr       */
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
	//Inizio struct e sprites
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectibles;
	void	*exit;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	char	*map_matrix;
	
	//Fine Sprites
	void	*mlx; 
	void	*mlx_win; 
    int		x;
    int		y;
	int		col;
	char	**map_2_matrix;
    void	*tux;
	int		beginX; 
	int		beginY; 
	int		endX; 
	int		endY;
	int		color;
}	t_position;

char 	create_map(char *map, t_position *var);
int check_map(char *map, t_position *pos);
int deal_key(int key, t_position *pos);
void		starter(t_position *sprite);
char    reverse(char a, char b);
int     map_matrix_updater(t_position *pos, int x, int y, int action);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int		collectible_counter(t_position *pos, int x, int y);
int		map_update(t_position *var, int x, int y, int action);
int print_matrix(t_position *pos);
int		exit_door(t_position *pos);




#endif
