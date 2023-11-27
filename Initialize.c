/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:15 by absalem           #+#    #+#             */
/*   Updated: 2023/11/27 13:26:13 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
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
		mlx_destroy_window(fractol->mlx,fractol->win);
		free(fractol->mlx);
		malloc_error();
	}
}
