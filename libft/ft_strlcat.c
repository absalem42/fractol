/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:41:19 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:24:25 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst == NULL || dstsize == 0)
		return (dstsize + src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	while (src[i - dst_len] && i < dstsize - 1)
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
