/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:45:13 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 14:18:33 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(1);
}

static void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->win, 2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->win, 4, 1L << 2, mouse_handler, fractal);
	mlx_hook(fractal->win, 17, 0, close_handler, fractal);
	mlx_hook(fractal->win, 6, 1L << 13, julia_path, fractal);
}

void	init_data(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->flag = 1;
}

void	init_pixel_params(t_pixel_params *params, int x, int y,
		t_fractal *fractal)
{
	params->x = x;
	params->y = y;
	params->fractal = fractal;
	params->z.x = 0;
	params->z.y = 0;
	params->c.x = 0;
	params->c.y = 0;
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->win == NULL)
	{
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx,
			WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	init_events(fractal);
	init_data(fractal);
}
