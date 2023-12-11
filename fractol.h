/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:12:12 by absalem           #+#    #+#             */
/*   Updated: 2023/12/11 13:34:55 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Enter \n\t\"mandel\" \n\t\"julia <1> <2>\"\n"

# define HEIGHT 500
# define WIDTH 500

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define PURPLE 0x800080

# define SKY_BLUE 0x87CEEB 
# define LAVENDER 0xE6E6FA
# define CHOCOLATE 0xD2691E
# define LIME_GREEN 0x32CD32
# define TURQUOISE 0x40E0D0
# define TEAL 0x008080
# define MAROON 0x800000

# define ESC_KEY 53
# define PLUS_KEY 69
# define MINUS_KEY 78
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define R_KEY 15 
# define DOWN_KEY 125
# define MENU_KEY 46
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define JULIA_LOCK 37

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr_pix;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_fractal
{
	t_img		img;
	void		*mlx;
	void		*win;
	char		*name;
	double		outer_value;
	int			iteration;
	double		shift_x;
	double		shift_y;
	double		zoom;      
	double		julia_x;
	double		julia_y;
	int 		julia_lock;
	int		visib;
}				t_fractal;

int	ft_strcmp(char *s1, char *s2);
void	putstr_fd(char *s, int fd);
double	atoi_dbl(char *s);

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double	scale(double s, double min2, double max2, double max1);

void    my_pixel_put(int x, int y, t_img *img, int color);
void	data_init(t_fractal *fractol);
void 	start_fractol(t_fractal *fractal);
double	scale(double s, double min2, double max2, double max1);
void	fractal_draw(t_fractal *fractol);
int		key_press(int keycode, t_fractal *fractol);
void	key_hook(t_fractal *fractol);
int	mouse_press(int keycode, int x, int y, t_fractal *fractol);
void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
int close_press(t_fractal *fractol);
int	julia_track(int x, int y, t_fractal *fractal);

#endif