#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

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
	char	*base_16;
	int		size;

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

int	printf_nbr(int number)
{
	int	digit_counter;

	digit_counter = 0;
	if (number == INT_MIN)
		return (printf_string("-2147483648"));
	else if (number < 0)
	{
		digit_counter += printf_char('-');
		number *= -1;
	}
	if (number > 9)
		digit_counter += printf_nbr(number / 10);
	digit_counter += printf_char((number % 10) + 48);
	return (digit_counter);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

int	printf_string(char *str)
{
	unsigned int	char_counter;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	char_counter = ft_strlen(str);
	return (char_counter);
}

int	printf_uint(unsigned int n)
{
	int	digit_counter;

	digit_counter = 0;
	if (n > 9)
		digit_counter += printf_uint((n / 10));
	digit_counter += printf_char((n % 10) + 48);
	return (digit_counter);
}

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
int	main(void)
{
	ft_printf("Character: %c\nString: %s\nPointer:%p\nDecimal:%d\nInteger:%i\nHexadecimal (lowercase):%x\nHexadecimal (uppercase):%X\nUnsigned:%u\n", 'A', "Hello, World!", (void *)0x12345678, 123, -456, 255, 255, 300);
	ft_printf("Percent sign: %%\n");
	return (0);
}