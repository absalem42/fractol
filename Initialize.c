/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:15 by absalem           #+#    #+#             */
/*   Updated: 2023/12/06 19:40:51 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("malloc fails");
	exit(1);
}
void	data_init(t_fractal *fractol)
{
	fractol->outer_value = 4;
	fractol->iteration = 0;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	key_hook(t_fractal *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_press, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, mouse_press, fractol);
	mlx_hook(fractol->win, 17, 1L << 17, close_press, fractol);
	mlx_hook(fractol->win, 6, 1L << 6, julia_track, fractol);
}

void start_fractol(t_fractal *fractol)
{
    fractol->mlx = mlx_init();
    if (!fractol->mlx)
        malloc_error();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (!fractol->win)
	{
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if(!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.addr_pix = mlx_get_data_addr(fractol->img.img,
		&fractol->img.bits_per_pixel, &fractol->img.line_length,
		&fractol->img.endian);
	key_hook(fractol);
	data_init(fractol);
}
