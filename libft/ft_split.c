/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:00:40 by absalem           #+#    #+#             */
/*   Updated: 2023/07/27 12:23:55 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*next_word(char const **s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num_words;
	int		i;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (*s && *s == c)
			s++;
		split[i] = next_word(&s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
