/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 14:27:33 by saladin       #+#    #+#                 */
/*   Updated: 2021/02/25 16:56:45 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>

void *mlx_init();
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int mlx_loop(void *mlx_ptr);
void *mlx_new_image(void *mlx_ptr, int width, int height);
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int mlx_hook(void *win_ptr, int x_event, int x_mask,
			 int (*funct)(), void *param);
// int close(int keycode, t_data *img);

	typedef struct s_data
{
	void *mlx;
	void *img;
	void *win;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int close(int keycode, t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}
void my_pixel_put(t_data *img, int x, int y, unsigned int colour)
{
	char *dst;
	int offset;
	
	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = colour;
}

int main(void)
{
	int y;
	int x;
	t_data img;

	y = 500;
	x = 500;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, x, y, "title");
	img.img = mlx_new_image(img.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x <= 499)
	{
		my_pixel_put(&img, x, y / 2, 0xFFFFFF);
		x++;
	}
	x = 250;
	y = 0;
	while (y <= 499)
	{
		my_pixel_put(&img, x, y, 0xFFFFFF);
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, close, &img);
	mlx_loop(img.mlx);
}