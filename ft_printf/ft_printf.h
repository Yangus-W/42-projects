/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:51:04 by yawang            #+#    #+#             */
/*   Updated: 2023/12/24 19:24:57 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, int i);
int	print_ptr(void *ptr);
int	print_digit_upper(long n, int base);
int	print_unsigned_int(unsigned int n, int base);

#endif