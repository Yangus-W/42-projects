/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:51:04 by yawang            #+#    #+#             */
/*   Updated: 2024/01/04 19:37:40 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n);
int	print_digit_hexa(unsigned long long n, char specifier);
int	print_ptr(unsigned long long ptr, char specifier);
int	print_unsigned_int(unsigned long n);
int	ft_printf(const char *format, ...);

#endif
