/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:20:20 by vneves-c          #+#    #+#             */
/*   Updated: 2026/06/18 16:17:06 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*heap;
	size_t			s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	heap = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!heap)
		return (NULL);
	i = 0;
	while (s[i])
	{
		heap[i] = f(i, s[i]);
		i++;
	}
	heap[i] = '\0';
	return (heap);
}
