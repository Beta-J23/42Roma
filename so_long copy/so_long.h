/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:44:26 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 19:51:47 by alpelliz         ###   ########.fr       */
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
}	t_position;

//int	main_helper(int argc, char **argv,  t_position pos);
//void	main_helper(t_data img, t_position pos, char *arg);
int x_close(void *data);
char 	create_map(char *map, t_position *var);
int map_while_helper(t_position *pos, char *strmap, int	j, int z, int x);
int	check_map_helper(char *map, t_position *pos, int x, int k);
int	map_error_handler(int x, int k, int j, int z);
int		map_helper_error_handler(int x, int exit, int c, int z);
int		check_map(char *map, t_position *pos);
int		deal_key(int key, t_position *pos);
void	move_left(int key, t_position *pos);
void	move_right(int key, t_position *pos);
void	move_up(int key, t_position *pos);
void	move_down(int key, t_position *pos);
void		starter(t_position *sprite);
char    reverse(char a, char b);
int     map_matrix_updater(t_position *pos, int x, int y, int action);
int		map_2(t_position *pos, int i, int j, int action);
void	create_map_helper(t_position *var, char *line, int i, int j);
void	map_matrix_creator(t_position *var, char *map);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int		collectible_counter(t_position *pos, int x, int y);
int print_matrix(t_position *pos);
int		exit_door(t_position *pos, int action, int i , int j);
void		moves(t_position *pos);

#endif