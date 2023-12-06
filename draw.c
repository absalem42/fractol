/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:48:30 by absalem           #+#    #+#             */
/*   Updated: 2023/12/06 19:22:26 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_pixel_put(int x, int y, t_img *img, int color)
{
    int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr_pix + offset) = color;
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}
void	draw_pixel(int x, int y, t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	i = 0;

	z.x = (scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandel_vs_julia(&z, &c, fractol);
	while (i < fractol->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->outer_value)
		{
			color = scale(i,SKY_BLUE,LAVENDER,fractol->iteration);
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
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}