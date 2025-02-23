/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:44:22 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 15:35:12 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_list(char **argv, int i)
{
	if (i == 1)
	{
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals:\n - mandelbrot\n - burning_ship\n");
		ft_printf("- julia <real_part> <imaginary_part> \n");
		exit(1);
	}
	else if (i == 2)
	{
		ft_printf("Invalid fractal or incorrect number of arguments.\n");
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals:\n- mandelbrot\n- burning_ship\n");
		ft_printf("- julia <real_part> <imaginary_part> \n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
		print_list(argv, 1);
	fractal.name = argv[1];
	if ((!ft_strcmp(fractal.name, "mandelbrot") && argc == 2)
		|| (!ft_strcmp(fractal.name, "julia") && argc == 4)
		|| (!ft_strcmp(fractal.name, "burning_ship") && argc == 2))
	{
		if (!ft_strcmp(fractal.name, "julia"))
		{
			parse_julia(&fractal, argv);
		}
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		print_list(argv, 2);
	return (0);
}
