/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:15 by absalem           #+#    #+#             */
/*   Updated: 2023/11/27 15:43:00 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("malloc fails");
	exit(1);
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
