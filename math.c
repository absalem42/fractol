/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:43:56 by absalem           #+#    #+#             */
/*   Updated: 2023/12/13 11:42:28 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double s, double min2, double max2, double max1)
{
	return ((s - 0) * (max2 - min2) / (max1 - 0) + min2);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_input(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1)
	{
		if (!(is_digit(*str1) || *str1 == '.' || *str1 == '-' || *str1 == '+'))
			return (1);
		if (*str1 == '.' && (*(str1 + 1) == '\0' || !is_digit(*(str1 + 1))))
			return (1);
		str1++;
	}
	while (*str2)
	{
		if (!((*str2 >= '0' && *str2 <= '9') || *str2 == '.'
				|| *str2 == '-' || *str2 == '+'))
			return (1);
		if (*str2 == '.' && (*(str2 + 1) == '\0' || !is_digit(*(str2 + 1))))
			return (1);
		str2++;
	}
	return (0);
}
