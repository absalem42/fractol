/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:12:12 by absalem           #+#    #+#             */
/*   Updated: 2023/11/13 16:12:14 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Enter \n\t\"mandel\" \n\t\"julia <1> <2>\" \n\t\"burning_ship\"\n"

# define HEIGHT 800
# define WIDTH 800

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
# define R_KEY 44 NEED TO FIX
# define DOWN_KEY 125
# define MENU_KEY 46
# define MOUSE_UP 5
# define MOUSE_DOWN 4