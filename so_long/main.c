/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:15:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 20:10:02 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_position	pos;
	t_fcounter	c;

	if (main_helper(argc, argv[1], &pos, &c) == 0)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (pos.x * 64), (pos.y * 64), "Reverse Pacman");
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	pos.img.img = mlx_new_image(mlx, (pos.x * 64), (pos.y * 64));
	pos.img.addr = mlx_get_data_addr(pos.img.img, &pos.img.bits_per_pixel,
			&pos.img.line_lenght, &pos.img.endian);
	starter(&pos);
	create_map(argv[1], &pos);
	mlx_hook(mlx_win, 17, (1L << 16), x_close, &pos);
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
	if (ber_control(argv, ".ber", 4) == 1)
	{
		ft_printf("File is not .ber\n");
		return (0);
	}
	if (check_map(argv, pos, c) == 2)
	{
		ft_printf("File do not exist!!!\n");
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
