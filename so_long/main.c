/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:15:54 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/31 18:13:04 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int deal_key(int key, t_position *pos)
{
	mlx_clear_window(pos->mlx, pos->mlx_win);	
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

void		starter(t_position *sprite)
{
	sprite->img_width = 64;
	sprite->img_width = 64;
	sprite->floor = mlx_xpm_file_to_image(sprite->mlx, "xpm/floor.xpm", &sprite->img_width, &sprite->img_height);
	sprite->wall = mlx_xpm_file_to_image(sprite->mlx, "xpm/wall.xpm", &sprite->img_width, &sprite->img_height);
	sprite->player = mlx_xpm_file_to_image(sprite->mlx, "xpm/player.xpm", &sprite->img_width, &sprite->img_height);
	sprite->collectibles = mlx_xpm_file_to_image(sprite->mlx, "xpm/collectibles.xpm", &sprite->img_width, &sprite->img_height);
	sprite->exit = mlx_xpm_file_to_image(sprite->mlx, "xpm/exit.xpm", &sprite->img_width, &sprite->img_height);
}

void		sprites(char	c, t_position *sprite, int x, int y)
{
	/*
	sprite->relative_path = "xpm/"
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectibles;
	void	*exit;
	char	*relative_path;
	int		width;
	int		height;
	*/
	sprite->img_width = 64;
	sprite->img_width = 64;
/*
	if (c == '0')
	{
		//sprite->floor = mlx_xpm_file_to_image(sprite->mlx, "xpm/floor.xpm", &sprite->img_width, &sprite->img_height);
		mlx_put_image_to_window(sprite->mlx, sprite->mlx_win, sprite->wall, x, y);
	}
	if (c == '1')
		//sprite->wall = mlx_xpm_file_to_image(sprite->mlx, "xpm/wall.xpm", &sprite->img_width, &sprite->img_height);
	else if (c == 'P')
		//sprite->player = mlx_xpm_file_to_image(sprite->mlx, "xpm/player.xpm", &sprite->img_width, &sprite->img_height);
	else if (c == 'C')
		//sprite->collectibles = mlx_xpm_file_to_image(sprite->mlx, "xpm/collectibles.xpm", &sprite->img_width, &sprite->img_height);
	else if (c == 'E')
		//sprite->exit = mlx_xpm_file_to_image(sprite->mlx, "xpm/exit.xpm", &sprite->img_width, &sprite->img_height);
	*/
}

char 	create_map(char *map, t_position *var)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	i = 0;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		i = 0;
		line = malloc(sizeof(char) * ft_strlen(line));
		while (line[i] != '\n')
		{
			if (line[i] == 'x')
				break;
			else if (line[i] == '1')
			{
				//sprites('1', var, i, j); //	draw_wall
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, i * 64, j * 64);
				
			}
			else if (line[i] == '0')
			{
				//sprites('0', var, i , j); //	draw floor
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor, i * 64, j * 64);
			}
			else if (line[i] == 'P')
				//sprites('P', var, i , j); //	draw Player
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->player, i * 64, j * 64);
			else if (line[i] == 'C')
				//sprites('C', var, i , j); //	draw collectibles
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->collectibles, i * 64, j * 64);
			else if (line[i] == 'E')
				//sprites('E', var, i, j); // draw exit
				mlx_put_image_to_window(var->mlx, var->mlx_win, var->exit, i * 64, j * 64);
			i++;
		}
		j++;
		free (line);
	}
	return(0);
}

int check_map(char *map, t_position *pos)
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
	//map = malloc(sizeof(char) * ft_strlen(map));
	fd = open(map, O_RDONLY);
	while (1)
	{
		strmap = get_next_line(fd);
		if (strmap == NULL)
			break;
		//ft_printf("%s", strmap);
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
	//free (map);
	if (j != 1) // CHECK 1 PLAYER EXIST
	{
		ft_printf("No Player in the field!\n");
		x = 1;
	}
	pos->x = i;
	pos->y = k;
	return (x);
	/// CHECK TO DO : LAST LINE IS ALL 1; IN THE MAP 0 1 C E ARE PRESENT.
	/// DO 1 EXTERNAL FUNCTION FOR ERRORS. (RETURN DIFFERENT NUMBER TO WRITE DIFFERENT ERRORS).
	/// CHECK WHY DOUBLE MAP.
}

int main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	int 		key;
	//void	*tux;
	//int		x = 2;
	//int 	y = 2;
	t_data		img;
	t_position	pos;
	
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
	mlx_win = mlx_new_window(mlx, (pos.x * 64), (pos.y * 64), "Daje tutta");
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	//img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);	
	//pos.tux = mlx_xpm_file_to_image(mlx, "xpm/vek.xpm", &x, &y);
	starter(&pos);
	create_map(argv[1], &pos);
	//mlx_put_image_to_window(mlx, mlx_win, pos.tux, pos.x, pos.y);
	mlx_hook(mlx_win, 2, (1L<<0), deal_key, &pos);
	mlx_loop(mlx);
	
}