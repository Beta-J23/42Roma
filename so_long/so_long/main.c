/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:15:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/05 20:43:01 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	int			key;
	t_data		img;
	t_position	pos;
	t_fcounter	c;

	if (main_helper(argc, argv[1], &pos, &c) == 0)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (pos.x * 64), (pos.y * 64), "Reverse Pacman");
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, (pos.x * 64), (pos.y * 64));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_lenght, &img.endian);
	starter(&pos);
	mlx_hook(mlx_win, 17, (1L << 16), x_close, &pos);
	create_map(argv[1], &pos);
	mlx_hook(mlx_win, 2, (1L << 0), deal_key, &pos);
	mlx_loop(mlx);
}

int	main_helper(int argnumber, char *argv, t_position *pos, t_fcounter *c)
{
	if (argnumber != 2)
	{
		ft_printf("Error, invalid number of args\n");
		return (0);
	}
	if (check_map(argv, pos, c) == 1)
	{
		ft_printf("Map is invalid!!!\n");
		return (0);
	}
	return (1);
}

int	x_close(void *data)
{
	(void)data;
	ft_printf("Goodbye");
	exit(0);
}
