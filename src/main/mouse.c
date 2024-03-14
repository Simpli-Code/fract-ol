/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:41 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/02 13:55:41 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_close(t_fractol *m)
{
	handle_error(1, m);
	return (1);
}

void	zoom_out(t_fractol *m)
{
	double	zoom;

	zoom = ZOOM_FACT * (m->x_max - m->x_min);
	if (zoom <= MAX_ZOOM)
	{
		m->x_min -= zoom;
		m->y_min -= zoom;
		m->x_max += zoom;
		m->y_max += zoom;
	}
}

void	zoom_in(t_fractol *m)
{
	double	zoom;

	zoom = ZOOM_FACT * (m->x_max - m->x_min);
	if (zoom >= MIN_ZOOM)
	{
		m->x_min += zoom;
		m->y_min += zoom;
		m->x_max -= zoom;
		m->y_max -= zoom;
	}
}

int	handle_zoom(int keycode, int x, int y, t_fractol *m)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN)
		zoom_in(m);
	if (keycode == MOUSE_UP)
		zoom_out(m);
	mlx_clear_window(m->ptr, m->win);
	if (!ft_strcmp(m->name, "julia"))
		julia(m);
	if (!ft_strcmp(m->name, "mandelbrot"))
		mandelbrot(m);
	if (!ft_strcmp(m->name, "julia_set"))
		julia_set(m);
	mlx_put_image_to_window(m->ptr, m->win, m->image, 0, 0);
	return (0);
}
