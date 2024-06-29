/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:48:20 by kadmoham          #+#    #+#             */
/*   Updated: 2024/06/29 10:43:49 by kadmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	printf_char(int c);
int	printf_string(char *s);
int	printf_ptr(void *ptr);
int	ft_printf(const char *s, ...);
int	printf_nbr(int n);
int	printf_hex(unsigned int n, int x_switch);
int	printf_uint(unsigned int n);

#endif