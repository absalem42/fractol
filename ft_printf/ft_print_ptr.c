/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:49:55 by absalem           #+#    #+#             */
/*   Updated: 2023/08/07 12:57:52 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
// int main()
// {
//     unsigned long long ptr1 = 0x123456789ABCDEF;
//     unsigned long long ptr2 = 0;
//     unsigned long long ptr3 = 0x7FFFFFFF;

//     ft_print_ptr(&ptr1);
//     write(1, "\n", 1);

//     ft_print_ptr(ptr2);
//     write(1, "\n", 1);

//     ft_print_ptr(ptr3);
//     write(1, "\n", 1);

//     return 0;
// }
