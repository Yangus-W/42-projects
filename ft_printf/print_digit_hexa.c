/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:23:33 by yawang            #+#    #+#             */
/*   Updated: 2024/01/05 16:17:04 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit_hexa(unsigned long long n, char specifier)
{
	int		count;
	char	*symbols;

	if (specifier == 'x' || specifier == 'p')
		symbols = "0123456789abcdef";
	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 16)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit_hexa(n / 16, specifier);
		return (count + print_digit_hexa(n % 16, specifier));
	}
}
