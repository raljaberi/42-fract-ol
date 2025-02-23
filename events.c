/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:44:40 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 14:20:27 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == ESC_KEY)
		close_handler(fractal);
	else if (keysym == LEFT)
		fractal->shift_x += 1.0 * fractal->zoom;
	else if (keysym == RIGHT)
		fractal->shift_x -= 1.0 * fractal->zoom;
	else if (keysym == UP)
		fractal->shift_y -= 1.0 * fractal->zoom;
	else if (keysym == DOWN)
		fractal->shift_y += 1.0 * fractal->zoom;
	else if (keysym == PLUS)
		fractal->iterations += 1;
	else if (keysym == MINUS)
		fractal->iterations -= 1;
	else if (keysym == R)
		init_data(fractal);
	else if (keysym == L)
		fractal->flag = !fractal->flag;
	render_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == MOUSE_UP)
	{
		fractal->zoom *= 0.50;
	}
	else if (button == MOUSE_DOWN)
	{
		fractal->zoom *= 1.20;
	}
	render_fractal(fractal);
	return (0);
}

int	julia_path(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		if (!fractal->flag)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom)
					+ fractal->shift_x;
				fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom)
					+ fractal->shift_y;
				render_fractal(fractal);
			}
		}
	}
	return (0);
}
