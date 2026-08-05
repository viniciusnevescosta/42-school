/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:50:14 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/31 21:41:03 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		words_total_size;
	char	*heap;
	size_t	i;
	size_t	j;

	words_total_size = ft_strlen(s1) + ft_strlen(s2);
	heap = malloc(words_total_size + 1);
	if (!heap)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		heap[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		heap[i + j] = s2[j];
		j++;
	}
	heap[i + j] = '\0';
	return (heap);
}
