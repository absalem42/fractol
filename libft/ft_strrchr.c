/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:41:50 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:24:55 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*end;
	char	found;

	end = (char *)s;
	found = (char )c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (end[i] == found)
		{
			return (end + i);
		}
		i--;
	}
	if (end[i] == found)
		return (end);
	return (NULL);
}
