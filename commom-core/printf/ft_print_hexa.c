/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long n, char c)
{
	char		*base_convertion;
	int			count;

	count = 0;
	if (c == 'x')
		base_convertion = "0123456789abcdef";
	else
		base_convertion = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hexa(n / 16, c);
	count += write(1, &base_convertion[n % 16], 1);
	return (count);
}
