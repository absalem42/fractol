/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:21:14 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:23:17 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*source ;

	i = 0;
	source = (unsigned char *)s;
	if (n == 0 && source == NULL)
		return (NULL);
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return ((void *)(source + i));
		i++;
	}
	return (NULL);
}
