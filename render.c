/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:45:40 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 14:15:13 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	setup_fractal(t_pixel_params *params)
{
	params->z.x = map(params->x, -2, +2, WIDTH) * params->fractal->zoom
		+ params->fractal->shift_x;
	params->z.y = map(params->y, +2, -2, HEIGHT) * params->fractal->zoom
		+ params->fractal->shift_y;
	if (!ft_strcmp(params->fractal->name, "julia"))
	{
		params->c.x = params->fractal->julia_x;
		params->c.y = params->fractal->julia_y;
	}
	else
	{
		params->c.x = params->z.x;
		params->c.y = params->z.y;
		params->z.x = 0;
		params->z.y = 0;
	}
}

static void	process_pixel(t_pixel_params *params)
{
	int	i;
	int	color;

	i = 0;
	while (i < params->fractal->iterations)
	{
		if (!ft_strcmp(params->fractal->name, "burning_ship"))
		{
			params->z = abs_complex(params->z);
		}
		params->z = sum_complex(square_complex(params->z), params->c);
		if ((params->z.x * params->z.x) + (params->z.y
				* params->z.y) > params->fractal->escape_value)
		{
			color = map(i, YELLOW, PURPLE, params->fractal->iterations);
			my_pixel_put(params->x, params->y, &params->fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(params->x, params->y, &params->fractal->img, BLACK);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_pixel_params	params;

	init_pixel_params(&params, x, y, fractal);
	setup_fractal(&params);
	process_pixel(&params);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img, 0, 0);
}
