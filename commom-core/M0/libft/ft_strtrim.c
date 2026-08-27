/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:20:42 by vneves-c          #+#    #+#             */
/*   Updated: 2026/06/18 15:20:43 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	str_start;
	size_t	str_end;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	str_start = 0;
	str_end = s1_len;
	while (str_start < str_end && ft_strchr(set, s1[str_start]))
		str_start++;
	while (str_end > str_start && ft_strchr(set, s1[str_end - 1]))
		str_end--;
	return (ft_substr(s1, str_start, str_end - str_start));
}
