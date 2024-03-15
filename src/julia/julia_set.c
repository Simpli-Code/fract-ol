/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:15 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/15 08:33:52 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_fractol *m)
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

void	init_julia_set(t_fractol *m, char *s)
{
	m->x_min = -2;
	m->x_max = 2;
	m->y_min = -2;
	m->y_max = 2;
	m->x_real = m->x_usr_inpt;
	m->y_imagin = m->y_usr_inpt;
	m->max_iterate = 50;
	m->colour = 10;
	m->name = s;
}
