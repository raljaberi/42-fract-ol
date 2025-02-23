/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:46:40 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 15:35:32 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_params(const char *param)
{
	int	length;
	int	valid;
	int	i;
	int	dpoint;

	length = ft_strlen(param);
	valid = 1;
	i = 0;
	dpoint = 0;
	while (i < length)
	{
		if (param[i] == '.')
		{
			dpoint++;
			i++;
		}
		if (!ft_isdigit(param[i]) || dpoint > 1)
		{
			valid = 0;
			break ;
		}
		i++;
	}
	return (valid);
}

void	parse_julia(t_fractal *fractal, char **argv)
{
	if (argv[2] == NULL || argv[3] == NULL)
	{
		ft_printf("Please provide both Julia parameters.\n");
		exit (1);
	}
	if (!parse_params(argv[2]) || !parse_params(argv[3]))
	{
		ft_printf("Invalid Julia parameters, ");
		ft_printf("please enter numbers ranging between -2 and 2.\n");
		exit (1);
	}
	fractal->julia_x = atodbl(argv[2]);
	fractal->julia_y = atodbl(argv[3]);
	if (fractal->julia_x < -2 || fractal->julia_x > 2 || fractal->julia_y < -2
		|| fractal->julia_y > 2)
	{
		ft_printf("Julia parameters should be between -2 and 2.\n");
		exit (1);
	}
}
