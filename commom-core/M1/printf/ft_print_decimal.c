/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	long int	long_n;
	char		res;
	int			count;

	long_n = n;
	count = 0;
	if (long_n < 0)
	{
		count++;
		write(1, "-", 1);
		long_n *= -1;
	}
	if (long_n > 9)
		count += ft_print_decimal(long_n / 10);
	res = (long_n % 10) + '0';
	count += write(1, &res, 1);
	return (count);
}

// int	main(void)
// {
// 	ft_print_decimal(255);
// 	return (0);
// }
