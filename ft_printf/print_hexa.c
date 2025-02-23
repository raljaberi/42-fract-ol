/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:02:22 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/15 20:03:46 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long long n, char formatter)
{
	int					len;
	unsigned long long	nb;

	len = 0;
	nb = n;
	if (nb > 15)
	{
		len += print_hexa((nb / 16), formatter);
		len += print_hexa((nb % 16), formatter);
	}
	if (nb >= 0 && nb <= 9)
		len += print_char(nb + '0');
	if (nb >= 10 && nb <= 15)
	{
		if (formatter == 'x')
			len += print_char(nb - 10 + 'a');
		else if (formatter == 'X')
			len += print_char(nb - 10 + 'A');
	}
	return (len);
}
