/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:33:28 by kadmoham          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:55 by kadmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	printf_hex(unsigned int n, int x_switch)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	base_16 = "0123456789abcdef";
	if (x_switch == 0)
		base_16 = "0123456789ABCDEF";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, x_switch) == -1)
			return (-1);
		if (printf_hex(n % 16, x_switch) == -1)
			return (-1);
	}
	return (size);
}
