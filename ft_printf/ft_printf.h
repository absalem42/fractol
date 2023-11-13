/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:00:02 by absalem           #+#    #+#             */
/*   Updated: 2023/08/07 12:57:14 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_put_ptr(unsigned long num);
int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_print_char(int c);
int		ft_print_str(const char *str);
int		ft_print_num(int n);
int		ft_ptr_len(unsigned long num);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_unsnum(unsigned int n);
int		ft_put_hexa(unsigned int num, const char format);

#endif