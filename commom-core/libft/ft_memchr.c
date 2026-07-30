/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:19:17 by vneves-c          #+#    #+#             */
/*   Updated: 2026/06/18 16:01:29 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	letter;

	i = 0;
	src = (unsigned char *)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == letter)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
