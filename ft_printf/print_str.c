/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:54:52 by yawang            #+#    #+#             */
/*   Updated: 2023/12/24 17:29:57 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}