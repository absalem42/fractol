/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:22:28 by absalem           #+#    #+#             */
/*   Updated: 2023/12/05 18:27:25 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_press(t_fractal *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img);
    mlx_destroy_window(fractol->mlx, fractol->win);
    free(fractol->mlx);
    exit(0);
}

int key_press(int keycode, t_fractal *fractol)
{
	if (keycode == ESC_KEY)
		close_press(fractol);
	else if (keycode == LEFT_KEY)
		fractol->shift_x += 0.5;
	else if (keycode == RIGHT_KEY)
		fractol->shift_x -= 0.5;
	else if (keycode == UP_KEY)
		fractol->shift_y -= 0.5;
	else if (keycode == DOWN_KEY)
		fractol->shift_y += 0.5;
	else if (keycode == PLUS_KEY)
		fractol->iteration += 5;
	else if (keycode == MINUS_KEY)
		fractol->iteration -= 5;
    
    fractal_draw(fractol);
    
    return 0;
}