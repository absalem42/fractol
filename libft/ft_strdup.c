/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:19:58 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:24:03 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}
