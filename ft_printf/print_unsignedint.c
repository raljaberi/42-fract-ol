/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:03:20 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/15 20:04:01 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsignedint(unsigned int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = n;
	if (nb > 9)
	{
		len += print_unsignedint(nb / 10);
		len += print_unsignedint(nb % 10);
	}
	else
		len += print_char(nb + '0');
	return (len);
}
