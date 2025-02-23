/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:50:05 by raljaber          #+#    #+#             */
/*   Updated: 2024/01/02 13:21:57 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(char c);
int	print_string(char *str);
int	print_int(int n);
int	print_unsignedint(unsigned int n);
int	print_hexa(unsigned long long n, char formatter);
int	print_pointer(void *ptr);
int	ft_printf(const char *format, ...);

#endif