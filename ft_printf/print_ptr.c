/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:56:52 by yawang            #+#    #+#             */
/*   Updated: 2024/01/04 19:08:36 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr, char specifier)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (print_digit_hexa(ptr, specifier) + 2);
}
