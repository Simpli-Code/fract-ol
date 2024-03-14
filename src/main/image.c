/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:18 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/02 17:46:51 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_information(t_fractol *m)
{
	mlx_string_put(m->ptr, m->win, 40, 20, 0xFFFFFF,
		"------------ZOOM------------");
	mlx_string_put(m->ptr, m->win, 50, 50, 0xFFFFFF,
		"Scroll UP | Scroll DOWN");
	mlx_string_put(m->ptr, m->win, 330, 20, 0xFFFFFF,
		"-----------RESET------------");
	mlx_string_put(m->ptr, m->win, 390, 50, 0xFFFFFF,
		"Press (0)");
	mlx_string_put(m->ptr, m->win, 600, 20, 0xFFFFFF,
		"-----------CLOSE------------");
	mlx_string_put(m->ptr, m->win, 620, 50, 0xFFFFFF,
		"Press (ESC) | Click (X)");
}

void	render_colour(t_fractol *m, int colour)
{
	m->pixel = (4 * WIDTH * m->y_pixel) + m->x_pixel * 4;
	m->rgba[m->pixel] = (m->iterate * m->colour + 80 + 19) * colour;
	m->rgba[m->pixel + 1] = (m->iterate * m->colour + 842 + 84) * colour;
	m->rgba[m->pixel + 2] = (m->iterate * m->colour + 736 + 45) * colour;
	m->rgba[m->pixel + 3] = 0;
}

void	iterative_loop(t_fractol *m)
{
	while (m->iterate < m->max_iterate)
	{
		m->x_tmp = m->x * m->x - m->y * m->y;
		m->y_tmp = 2 * m->x * m->y;
		m->x = m->x_tmp + m->x_real;
		m->y = m->y_tmp + m->y_imagin;
		if (m->x * m->x + m->y * m->y > 4)
			break ;
		m->iterate++;
	}
}
