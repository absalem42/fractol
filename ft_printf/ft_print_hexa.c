/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:06:12 by absalem           #+#    #+#             */
/*   Updated: 2023/10/28 12:47:59 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned int num, const char format)
{
	int	count_num;

	count_num = 0;
	if (num >= 16)
	{
		count_num += ft_put_hexa(num / 16, format);
		count_num += ft_put_hexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			count_num += ft_print_char(num + '0');
		else
		{
			if (format == 'x')
				count_num += ft_print_char(num - 10 + 'a');
			else if (format == 'X')
				count_num += ft_print_char(num - 10 + 'A');
		}
	}
	return (count_num);
}
