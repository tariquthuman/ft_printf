/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:35:32 by kadmoham          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:55 by kadmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_uint(unsigned int n)
{
	int	digit_counter;

	digit_counter = 0;
	if (n > 9)
		digit_counter += printf_uint((n / 10));
	digit_counter += printf_char((n % 10) + 48);
	return (digit_counter);
}
