/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:01:12 by bpichyal          #+#    #+#             */
/*   Updated: 2025/07/11 14:55:07 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char spec, va_list ap)
{
	void	*val;

	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (spec == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 0));
	else if (spec == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 1));
	else if (spec == 'p')
	{
		val = va_arg(ap, void *);
		if (!val)
			return (write(1, "(nil)", 5));
		return (ft_putptr((unsigned long)val));
	}
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		out_len;

	i = 0;
	out_len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			out_len += ft_format(fmt[i], ap);
		}
		else
			out_len += ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (out_len);
}
