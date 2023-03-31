/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:15:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/31 14:33:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int deal_key(int key, t_position *pos)
{
	mlx_clear_window(pos->mlx, pos->mlx_win);	
	//mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	printf("%d\n", key);
	if (key == 53)
	{
		ft_printf("Goodbye\n");
		exit (0);
	}
	if (key == 123) //sx
	{
		ft_putchar('L');
		pos->x -= 50;
	}
	else if (key == 124) //dx
	{
		ft_putchar('R');
		pos->x += 50;
	}
	else if (key == 126) //up
	{
		ft_putchar('U');
		pos->y -= 50;
	}
	else if (key == 125) //down
	{
		ft_putchar('D');
		pos->y += 50;
	}//*mlx_xpm_file_to_image(void *mlx_pointer, char *relative_path, int *width, int *height);
	//mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->tux, pos->x, pos->y);
	return (7);
}

int check_map(char *map)
{
	char		*strmap;
	int			fd;
	int			i;
	int			j;
	int			k;
	int			z;
	int			x;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	z = 0;
	map = malloc(sizeof(char) * ft_strlen(map));
	fd = open("map/map.ber", O_RDONLY);
	while (1)
	{
		strmap = get_next_line(fd);
		if (strmap == NULL)
			break;
		ft_printf("%s", strmap);
		if (k == 0)
		{
			while (strmap[z] != '\n') // CHECK THAT FIRST LINE IS ALL 1.
			{
				if (strmap[z] != '1')
				{
					ft_printf("The wall at the bottom is broken!!!\n");
					x = 1;
				} 
				z++;
			}
		}
		strmap = malloc(sizeof(char) * ft_strlen(strmap));
		i = 0;	
		while (strmap[i] != '\0')
		{
			if (strmap[i] == 'P') //CHECK NUMBER OF PLAYERS
				j++;
			if ((strmap[i] != '0') && (strmap[i] != '1') && (strmap[i] != 'P') && (strmap[i] != 'C') && (strmap[i] != 'E') && (strmap[i] != '\n'))
				x = 1;
			i++;
		}
		if (z != i - 1) //CHECK ALL LINES OF MAP ARE EQUALS
		{
			ft_printf("Lines of map are not equals\n");
			x = 1;
		}
		if ((strmap[0] != '1') || (strmap[(ft_strlen(strmap) - 2)] != '1')) //CHECK 1(walls) at side of maps
		{
			ft_printf("A WALL AT THE SIDE IS BROKEN\n");
			x = 1;
		}
		k++;
		free (strmap);
	}
	if  (k >= z) // CHECK MAP IS RECTANGULAR
	{
		ft_printf("Maps is not rectangular\n");
		x = 1;
	}
	free (map);
	if (j != 1) // CHECK 1 PLAYER EXIST
	{
		ft_printf("No Player in the field!\n");
		x = 1;
	}
	return (x);
	/// CHECK TO DO : LAST LINE IS ALL 1; IN THE MAP 0 1 C E ARE PRESENT
	/// DO 1 EXTERNAL FUNCTION FOR ERRORS. (RETURN DIFFERENT NUMBER TO WRITE DIFFERENT ERRORS)
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int 	key;
	//void	*tux;
	int		x = 2;
	int 	y = 2;
	t_data	img;
	t_position	pos;
	
	if (argc != 2)
	{
		ft_printf("Error, ivalid number of args\n");
		return (0);
	}
	if (check_map(argv[1]) == 1)
	{
		ft_printf("Map is invalid\n");
		return(0);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Daje tutta");
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);	
	pos.tux = mlx_xpm_file_to_image(mlx, "xpm/vek.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, pos.tux, pos.x, pos.y);
	mlx_hook(mlx_win, 2, (1L<<0), deal_key, &pos);
	mlx_loop(mlx);
	
}