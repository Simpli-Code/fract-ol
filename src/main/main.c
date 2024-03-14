/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:42:53 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/03 09:29:19 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	m;

	ft_bzero(&m, sizeof(m));
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0 || \
			ft_strcmp(argv[1], "julia") == 0)
		{
			if (handle_window(&m) == 1)
				handle_error(1, &m);
			else
				init_set(&m, argv[1]);
		}
		else
			handle_error_msg();
	}
	else if (argc == 4)
		check_args(&m, argv[1], argv[2], argv[3]);
	else
		handle_error_msg();
	parse_fractals(&m);
	return (0);
}

int	check_input(t_fractol *m, char *s1, char *s2)
{
	m->x_usr_inpt = ft_strtod(s1);
	m->y_usr_inpt = ft_strtod(s2);
	if (m->x_usr_inpt > 2 || m->x_usr_inpt < -2 || m->x_usr_inpt == 0.0 || \
		m->y_usr_inpt > 2 || m->y_usr_inpt < -2 || m->y_usr_inpt == 0.0)
		return (1);
	else
		return (0);
}

int	check_args(t_fractol *m, char *argv1, char *argv2, char *argv3)
{
	if (ft_strcmp(argv1, "julia") == 1)
		handle_error_msg();
	if (check_input(m, argv2, argv3) == 1)
		handle_error_msg();
	if (handle_window(m) == 1)
		handle_error(1, m);
	else
		init_julia_set(m, "julia_set");
	return (0);
}

int	handle_window(t_fractol *m)
{
	m->ptr = mlx_init();
	if (m->ptr == NULL)
		return (1);
	m->win = mlx_new_window(m->ptr, WIDTH, HIGHT, "Fractol");
	if (m->win == NULL)
		return (1);
	m->image = mlx_new_image(m->ptr, WIDTH, HIGHT);
	if (m->image == NULL)
		return (1);
	m->rgba = (unsigned char *)mlx_get_data_addr \
		(m->image, &m->bpp, &m->size_l, &m->endian);
	if (m->rgba == NULL)
		return (1);
	else
		return (0);
}

int	handle_error(int code, t_fractol *m)
{
	if (!m)
		exit(code);
	if (m->image)
		mlx_destroy_image(m->ptr, m->image);
	if (m->win)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr)
		mlx_destroy_display(m->ptr);
	if (m->ptr)
		free(m->ptr);
	exit(code);
	return (0);
}
