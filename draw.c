/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:48:30 by absalem           #+#    #+#             */
/*   Updated: 2023/11/27 18:03:58 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	z.x = 0.0;
	z.y = 0.0;

	c.x = scale(x, -2, +2, WIDTH);
	c.y = scale(y, +2, -2, HEIGHT);
	mandel_vs_julia(&z, &c, fractol);
	while (i < fractol->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->outer_value)
		{
			color = scale(i, BLACK, WHITE, fractol->iteration);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, WHITE);
}

void	fractal_draw(t_fractal *fractol)
{
	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				draw_pixel(x, y, fractol);
				x++;
			}
			y++;
		}
	
}