/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:07:04 by absalem           #+#    #+#             */
/*   Updated: 2023/08/06 08:23:13 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(const char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
