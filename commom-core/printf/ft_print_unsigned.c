/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	char		res;
	int			count;

	count = 0;
	if (num > 9)
		count += ft_print_unsigned(num / 10);
	res = (num % 10) + '0';
	write(1, &res, 1);
	count += 1;
	return (count);
}
