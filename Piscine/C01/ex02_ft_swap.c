/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_ft_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:28:28 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/05 09:28:28 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;
	int	*a_ptr;
	int	*b_ptr;

	a = 10;
	b = 2;
	a_ptr = &a;
	b_ptr = &b;
	printf("A: %i, B: %i\n", a, b);
	ft_swap(a_ptr, b_ptr);
	printf("A: %i, B: %i", a, b);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
