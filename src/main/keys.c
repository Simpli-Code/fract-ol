/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:23 by chruhin           #+#    #+#             */
/*   Updated: 2023/07/31 20:34:13 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_fractol *m)
{
	if (keycode == K_ESC)
	{
		handle_error(1, m);
		return (1);
	}
	else if (keycode == K_0)
	{
		if (ft_strcmp(m->name, "mandelbrot") == 0 || \
			ft_strcmp(m->name, "julia") == 0)
		{
			init_set(m, m->name);
			parse_fractals(m);
		}
		else
		{
			init_julia_set(m, m->name);
			parse_fractals(m);
		}
	}
	return (0);
}

void	hooks(t_fractol *m)
{
	mlx_put_image_to_window(m->ptr, m->win, m->image, 0, 0);
	display_information(m);
	mlx_hook(m->win, 17, 0, mouse_close, m);
	mlx_mouse_hook(m->win, handle_zoom, m);
	mlx_hook(m->win, 2, 1, handle_keypress, m);
	mlx_loop(m->ptr);
}
