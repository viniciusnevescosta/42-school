/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *string)
{
	int	i;

	i = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}
