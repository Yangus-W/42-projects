/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:49:05 by yawang            #+#    #+#             */
/*   Updated: 2023/12/19 21:28:50 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	print_char(int c)
{
	return (write(1, &c, 1));
}

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

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_ptr(void *ptr)
{
	write(1, "0x", 2);
	return (print_digit((long)ptr, 16) + 2);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += print_digit((unsigned long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/* TEST */
#include <stdio.h>
int	main(void)
{
	int	count;
	char	*ptr = "hedfgsllo";

	count = ft_printf("%d\n", 111);
	ft_printf("The chars written are %d\n", count);
	count = printf("%d\n", 111);
	printf("The chars written are %d\n", count);
	
	count = ft_printf("%p\n", ptr);
	ft_printf("The chars written are %d\n", count);
	count = printf("%p\n", ptr);
	printf("The chars written are %d\n", count);
	
	count = ft_printf("%p\n", "oisdjf");
	ft_printf("The chars written are %d\n", count);
	count = printf("%p\n", "oisdjf");
	printf("The chars written are %d\n", count);
	
	count = ft_printf("%i\n", 10);
	ft_printf("The chars written are %d\n", count);
	count = printf("%i\n", 10);
	printf("The chars written are %d\n", count);
	
	count = ft_printf("%u\n", -109);
	ft_printf("The chars written are %d\n", count);
	count = printf("%u\n", -109);
	printf("The chars written are %d\n", count);
}
// write returns the number of bytes upon successful completion