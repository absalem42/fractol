/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:08:11 by absalem           #+#    #+#             */
/*   Updated: 2023/08/06 16:39:12 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int	count_num;

	count_num = 0;
	if (n == -2147483648)
	{
		count_num += write(1, "-2147483648", 11);
		return (count_num);
	}
	else if (n < 0)
	{
		count_num += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		count_num += ft_print_num(n / 10);
	}
	count_num += ft_print_char(n % 10 + '0');
	return (count_num);
}

int	ft_print_unsnum(unsigned int n)
{
	int	count_num;

	count_num = 0;
	if (n >= 10)
	{
		count_num += ft_print_num(n / 10);
	}
	count_num += ft_print_char(n % 10 + '0');
	return (count_num);
}
