/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:12 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/02 17:53:08 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *m)
{
	mlx_clear_window(m->ptr, m->win);
	m->y_pixel = 0;
	while (m->y_pixel < HIGHT)
	{
		m->x_pixel = 0;
		while (m->x_pixel < WIDTH)
		{
			m->iterate = 0;
			mandelbrot_complex(m);
			iterative_loop(m);
			if (m->iterate == m->max_iterate)
				render_colour(m, 0);
			else
				render_colour(m, 1);
			m->x_pixel++;
		}
		m->y_pixel++;
	}
	hooks(m);
}

void	parse_fractals(t_fractol *m)
{
	if (ft_strcmp(m->name, "mandelbrot") == 0)
		mandelbrot(m);
	else if (ft_strcmp(m->name, "julia") == 0)
		julia(m);
	else if (ft_strcmp(m->name, "julia_set") == 0)
		julia_set(m);
	else
		handle_error_msg();
}

void	mandelbrot_complex(t_fractol *m)
{
	m->x = m->x_pixel / (HIGHT / (m->x_max - m->x_min)) + m->x_min;
	m->y = m->y_pixel / (WIDTH / (m->y_max - m->y_min)) + m->y_min;
	m->x_real = m->x;
	m->y_imagin = m->y;
}
