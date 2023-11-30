/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:06:49 by absalem           #+#    #+#             */
/*   Updated: 2023/11/27 15:48:05 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandel"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	// mlx_loop(mlx);
		fractol.name = av[1];
		if (!ft_strcmp(av[1], "julia"))
		{
			fractol.name = av[1];
			fractol.julia_x = atoi_dbl(av[2]);
			fractol.julia_y = atoi_dbl(av[3]);
		}
		start_fractol(&fractol);
		// fractal_draw(&fractol);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(1);
	}
}