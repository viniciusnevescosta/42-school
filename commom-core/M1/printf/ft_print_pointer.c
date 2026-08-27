/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *n)
{
	int				count;
	unsigned long	num;

	count = 0;
	if (!n)
	{
		count += ft_print_string("(nil)");
		return (count);
	}
	num = (unsigned long) n;
	count += ft_print_string("0x");
	count += ft_print_hexa(num, 'x');
	return (count);
}
