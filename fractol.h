/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:44:48 by raljaber          #+#    #+#             */
/*   Updated: 2024/07/18 14:58:21 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 500
# define HEIGHT 500

# define ESC_KEY 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define R 15
# define L 37
# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define BLACK 0x000000
# define PURPLE 0x800080
# define YELLOW 0xFFFF00

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	t_img	img;
	void	*mlx;
	void	*win;
	int		iterations;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		flag;
}			t_fractal;

typedef struct s_pixel_params
{
	int			x;
	int			y;
	t_fractal	*fractal;
	t_complex	z;
	t_complex	c;
}				t_pixel_params;

int			ft_strcmp(const char *s1, const char *s2);
double		atodbl(char *s);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_path(int x, int y, t_fractal *fractal);
void		render_fractal(t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
void		init_fractal(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
t_complex	abs_complex(t_complex z);
void		init_data(t_fractal *fractal);
void		init_pixel_params(t_pixel_params *params, int x, int y,
				t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		parse_julia(t_fractal *fractal, char **argv);
int			ft_strlen(const char *str);
int			ft_isdigit(int c);

#endif
