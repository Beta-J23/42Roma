/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:15:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/03 15:43:01 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	int 		key;
	t_data		img;
	t_position	pos;
	
	//pos.map_matrix = argv[1];
	//pos.map_matrix = malloc(sizeof(char) * ft_strlen(argv[1]));
	//pos.map_matrix = argv[1];
	if (argc != 2)
	{
		ft_printf("Error, invalid number of args\n");
		return (0);
	}
	if (check_map(argv[1], &pos) == 1)
	{
		ft_printf("Map is invalid!!!\n");
		return(0);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (pos.x * 64), (pos.y * 64), "Daje tutta"); // Title Daje tutta || Reverse Pacman.
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, (pos.x * 64), (pos.y * 64));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);	
	//pos.tux = mlx_xpm_file_to_image(mlx, "xpm/vek.xpm", &x, &y);
	starter(&pos);
	create_map(argv[1], &pos);
	//mlx_put_image_to_window(mlx, mlx_win, pos.tux, pos.x, pos.y);	
	mlx_hook(mlx_win, 2, (1L<<0), deal_key, &pos);
	mlx_loop(mlx);
}