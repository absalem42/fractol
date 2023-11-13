/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:02:28 by absalem           #+#    #+#             */
/*   Updated: 2023/10/28 12:47:17 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	count_char;

	count_char = 0;
	if (format == 'c')
		count_char += ft_print_char(va_arg(args, int));
	else if (format == 's')
		count_char += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count_char += ft_print_num(va_arg(args, int));
	else if (format == 'p')
		count_char += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'u')
		count_char = ft_print_unsnum(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count_char += ft_put_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		count_char += ft_print_char('%');
	return (count_char);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count_char;

	i = 0;
	count_char = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count_char += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			count_char += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count_char);
}
