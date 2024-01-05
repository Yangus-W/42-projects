/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:56:11 by yawang            #+#    #+#             */
/*   Updated: 2024/01/05 16:16:51 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		n *= -1;
	}
	if (n >= 10)
		count += print_digit(n / 10);
	count += print_char(n % 10 + '0');
	return (count);
}
