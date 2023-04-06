/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:44:26 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 19:15:46 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectibles;
	void	*exit;
	void	*mlx;
	void	*mlx_win; 
	char	*relative_path;
	int		fd;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		counter;
    int		x;
    int		y;
	int		col;
	char	**map_2_matrix;
	int		color;
	t_data	img;
}	t_position;

typedef struct s_fcounter
{
	char	*strmap;
	int		i;
	int		j;
	int		k;
	int		z;
	int 	c;
	int		exit;
}	t_fcounter;

int				ber_control(char *haystack, char *needle, size_t len);
int				main_helper(int argnumber, char *argv, t_position *pos, t_fcounter *c);
int				x_close(void *data);
char 			create_map(char *map, t_position *var);
int				map_while_helper(t_position *pos, char *strmap, int	j, int z, int x);
int				check_map_helper(char *map, t_position *pos, int x, t_fcounter *c);
int				map_error_handler(int x, t_fcounter *c);
int				map_helper_error_handler(int x, t_fcounter *c);
int				check_map(char *map, t_position *pos, t_fcounter *c);
int				while_map_checker(t_position *pos, t_fcounter *c, int x);
int				half_while_map(t_position *pos, t_fcounter *c, int x);
int				half_while_2(t_position *pos, t_fcounter *c, int x);
int				error_handler_3(t_position *pos, t_fcounter *c, int x);
int				deal_key(int key, t_position *pos);
void			move_left(int key, t_position *pos);
void			move_right(int key, t_position *pos);
void			move_up(int key, t_position *pos);
void			move_down(int key, t_position *pos);
void			starter(t_position *sprite);
void			counter_initializer(t_fcounter *c);
char			reverse(char a, char b);
int				map_matrix_updater(t_position *pos, int i, int j, int action);
int				map_2(t_position *pos, int i, int j, int action);
void			create_map_helper(t_position *var, char *line, int i, int j);
int				create_map_helper_split(t_position *var, char *line, int i, int j);
void			map_matrix_creator(t_position *var, char *map);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				collectible_counter(t_position *pos);
int 			print_matrix(t_position *pos);
int				exit_door(t_position *pos, int action, int i , int j);
void			moves(t_position *pos);

#endif