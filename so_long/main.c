/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:45:28 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/29 19:34:29 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	int beginX; 
	int beginY; 
	int endX; 
	int endY;
	int color;
}	t_position;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double pixelX = beginX;
	double pixelY = beginY;
	double deltaX = endX - beginX; 
	double deltaY = endY - beginY; 
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return(0);
}

int deal_key(int key, t_position *pos)
{
	//printf("%d\n", key);
	draw_line(pos->mlx, pos->mlx_win, pos->beginX, pos->beginY, pos->endX, pos->endY, 0x000000);
	if (key == 123) //sx
	{	
		pos->beginX -= 10;
		pos->endX -= 10;
		ft_putchar('L');
	}
	else if (key == 124) //dx
	{
		pos->beginX += 10;
		pos->endX += 10;
		ft_putchar('R');
	}
	else if (key == 126) //up
	{
		pos->beginY -= 10;
		pos->endY -= 10;
		//pos->beginX = pos->endX - 1;
		ft_putchar('U');
	}
	else if (key == 125) //down
	{
		pos->beginY += 10;
		pos->endY += 10;
		ft_putchar('D');
	}
	draw_line(pos->mlx, pos->mlx_win, pos->beginX, pos->beginY, pos->endX, pos->endY, pos->color);
	//sleep(1);
	return (7);
}
/*
//DRAWLINE ALTERNATIVE
int draw_line(t_position pos)
{
	int 	key;
	double pixelX = pos.beginX;
	double pixelY = pos.beginY;
	double deltaX = pos.endX - pos.beginX; 
	double deltaY = pos.endY - pos.beginY; 
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	mlx_key_hook(pos.mlx_win, deal_key, &key);
	while (pixels)
	{
		mlx_pixel_put(pos.mlx, pos.mlx_win, pixelX, pixelY, pos.color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return(0);
}
*/

//drawing lines
int main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	key;
	int		move = 8;
	t_data	img;
	t_position	pos;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Daje tutta");
	pos.mlx = mlx;
	pos.mlx_win = mlx_win;
	pos.beginX = 360;
	pos.beginY = 360;
	pos.endX = 560;
	pos.endY = 560;
	pos.color = 0xFFFFFF;
	img.img = mlx_new_image(mlx, 1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);	
	draw_line(mlx, mlx_win, 360, 360, 560, 360, 0xFFFFFF);
	//my_mlx_pixel_put(&img, 200, 200, 0x00FF0000);
	//mlx_key_hook(mlx_win, deal_key, &key);
	//mlx_loop_hook(mlx, draw_line, &pos);
	//mlx_hook(mlx_win, 2, 1L<<0, deal_key, &key);
	mlx_hook(mlx_win, 2, (1L<<0), deal_key, &pos);
	//mlx_loop_hook(mlx, render_next_frame, YourStruct); ///example by guide
	//move = deal_key(mlx_hook(mlx_win, 2, 1L<<0, deal_key, &key));
	//move = deal_key(mlx_key_hook(mlx_win, deal_key, &key));
	printf("%d\n", key);
	
	mlx_loop(mlx);
}
//IMAGE DISPLAYED ON WINDOW
/*
int	main(void)
{
	void	*mlx;
    void	*mlx_win;
	void	*tux
	int		x = 743;
	int		y = 900;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	tux = mlx_xpm_file_to_image(mlx, "tux.xpm", &x, &y);
	//my_mlx_pixel_put(&img, 200, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, tux, 0, 0);
	mlx_loop(mlx);
}
*/