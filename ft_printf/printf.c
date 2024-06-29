/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:54:04 by kadmoham          #+#    #+#             */
/*   Updated: 2024/06/29 15:04:51 by kadmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(const char *format, unsigned int *i, va_list *ap)
{
	unsigned int	return_counter;

	return_counter = 0;
	if (format[*i] == 'c')
		return_counter = return_counter + printf_char(va_arg(*ap, int));
	else if (format[*i] == 's')
		return_counter = return_counter + printf_string(va_arg(*ap, char *));
	else if (format[*i] == 'p')
		return_counter = return_counter + printf_ptr(va_arg(*ap, void *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return_counter = return_counter + printf_nbr(va_arg(*ap, int));
	else if (format[*i] == 'x')
		return_counter = return_counter + printf_hex(va_arg(*ap, int), 1);
	else if (format[*i] == 'X')
		return_counter = return_counter + printf_hex(va_arg(*ap, int), 0);
	else if (format[*i] == 'u')
		return_counter = return_counter + printf_uint(va_arg(*ap, int));
	else if (format[*i] == '%')
	{
		printf_char('%');
		return (1);
	}
	return (return_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	count;
	unsigned int	return_length;

	count = 0;
	return_length = 0;
	va_start(ap, format);
	while (format[count])
	{
		if (format[count] == '%')
		{
			count++;
			return_length = return_length + process_format(format, &count, &ap);
		}
		else
		{
			return_length = return_length + printf_char(format[count]);
		}
		count++;
	}
	va_end(ap);
	return (return_length);
}

/*int	main(void)
{
	ft_printf("Character: %c\nString: %s\nPointer: %p\nDecimal:
		%d\nInteger:%i\nHexadecimal (lowercase): %x\nHexadecimal (uppercase):
		%X\nUnsigned:%u\n", 'A', "Hello, World!", (void *)0x12345678, 123, -456,
		255, 255, 300);
	ft_printf("Percent sign: %%\n");
	return (0);
}*/
