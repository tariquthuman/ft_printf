/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:03:53 by kadmoham          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:55 by kadmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	base_16 = "0123456789abcdef";
	size = size_hex_address(n);
	if (n == 0)
	{
		if (printf_char('0') == -1)
			return (-1);
		return (1);
	}
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (ft_hex_address(n / 16) == -1)
			return (-1);
		if (ft_hex_address(n % 16) == -1)
			return (-1);
	}
	return (size);
}

int	printf_ptr(void *ptr)
{
	int					n;
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		if (printf_string("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (printf_string("0x") == -1)
		return (-1);
	n = ft_hex_address(addr);
	if (n == -1)
		return (-1);
	return (n + 2);
}
