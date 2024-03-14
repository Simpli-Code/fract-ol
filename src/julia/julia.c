/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:47:52 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/02 17:19:07 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *m)
{
	mlx_clear_window(m->ptr, m->win);
	m->y_pixel = 0;
	while (m->y_pixel < HIGHT)
	{
		m->x_pixel = 0;
		while (m->x_pixel < WIDTH)
		{
			m->iterate = 0;
			x_y_coordinate(m);
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

void	init_set(t_fractol *m, char *s)
{
	m->x_min = -2;
	m->x_max = 2;
	m->y_min = -2;
	m->y_max = 2;
	m->x_real = 0.285;
	m->y_imagin = 0.01;
	m->max_iterate = 50;
	m->colour = 10;
	m->name = s;
}

void	x_y_coordinate(t_fractol *m)
{
	m->x = ((m->x_pixel / (double)WIDTH) * (m->x_max - m->x_min)) + m->x_min;
	m->y = ((m->y_pixel / (double)HIGHT) * (m->y_max - m->y_min)) + m->y_min;
}
