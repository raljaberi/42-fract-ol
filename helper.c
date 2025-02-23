/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:45:08 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 14:59:24 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	power;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s >= '0' && *s <= '9')
		integer_part = (integer_part * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while (*s && *s >= '0' && *s <= '9')
	{
		power /= 10;
		fractional_part = fractional_part + (*s++ - '0') * power;
	}
	return ((integer_part + fractional_part) * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 9 && c <= 13) || c == ' '
		|| c == '-' || c == '+' || c == '.')
	{
		return (1);
	}
	return (0);
}
