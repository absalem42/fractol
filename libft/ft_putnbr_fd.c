/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:08:37 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:23:47 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b *= -1;
	}
	if (b >= 10)
	{
		ft_putnbr_fd (b / 10, fd);
		ft_putnbr_fd (b % 10, fd);
	}
	else
		ft_putchar_fd (b + 48, fd);
}
