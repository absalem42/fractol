/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:06:49 by absalem           #+#    #+#             */
/*   Updated: 2023/12/12 16:41:27 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if (((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia"))))
			// && !check_input(av[2],av[3]))
	{
		fractol.name = av[1];
		if (!ft_strcmp(av[1], "julia"))
		{
			if (!check_range(av[2], av[3]))
				return (0);
			fractol.name = av[1];
			fractol.julia_x = atoi_dbl(av[2]);
			fractol.julia_y = atoi_dbl(av[3]);
		}
		start_fractol(&fractol);
		fractal_draw(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(1);
	}
}
