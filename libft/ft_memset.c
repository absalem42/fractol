/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:57:11 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:23:34 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (len > 0)
	{
		p[i] = (unsigned char )c;
		i++;
		len--;
	}
	return (b);
}
