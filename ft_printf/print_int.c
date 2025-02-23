/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:01:53 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/15 20:03:49 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int	len;
	int	nb;

	len = 0;
	nb = n;
	if (nb == -2147483648)
	{
		len += print_char('-');
		len += print_char('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += print_char('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		len += print_int(nb / 10);
		len += print_int(nb % 10);
	}
	else
		len += print_char(nb + '0');
	return (len);
}
