/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:04:29 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/15 20:03:53 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int	len;

	len = 0;
	len += print_string("0x");
	if (!ptr)
		len += print_char('0');
	else
		len += print_hexa((unsigned long long)ptr, 'x');
	return (len);
}
