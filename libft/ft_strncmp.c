/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:33:42 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:24:47 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ch1;
	unsigned char	*ch2;
	size_t			i;

	i = 0;
	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	while (i < n && (ch1[i] || ch2[i]))
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}
