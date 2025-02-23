/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:44:54 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/15 20:03:31 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char format, int *i)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(args, int));
	else if (format == 's')
		len += print_string(va_arg(args, char *));
	else if (format == 'p')
		len += print_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += print_int(va_arg(args, int));
	else if (format == 'u')
		len += print_unsignedint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += print_char('%');
	else
		(*i)--;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_counter;

	va_start(args, format);
	i = 0;
	char_counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			char_counter += ft_format(args, format[i], &i);
		}
		else
			char_counter += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (char_counter);
}
