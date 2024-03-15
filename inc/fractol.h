/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:42:56 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/15 08:34:12 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>

# ifdef __APPLE__
#  include "../minilibx-mac/mlx.h"
#  define WIDTH		810
#  define HIGHT		800
#  define ZOOM_FACT	0.08
#  define MIN_ZOOM 	0.001
#  define MAX_ZOOM	15.0
#  define K_ESC		53
#  define K_0		65438
#  define MOUSE_UP	13
#  define MOUSE_DWN	1
# endif
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define WIDTH		810
#  define HIGHT		800
#  define ZOOM_FACT	0.08
#  define MIN_ZOOM 	0.001
#  define MAX_ZOOM	15.0
#  define K_ESC		65307
#  define K_0		65438
#  define MOUSE_UP	4
#  define MOUSE_DWN	5
# endif

typedef struct s_fractol
{
	unsigned char	*rgba;
	char			*name;
	void			*ptr;
	void			*win;
	void			*image;
	int				size_l;
	int				endian;
	int				bpp;

	double			x;
	double			y;
	double			x_tmp;
	double			y_tmp;
	double			y_min;
	double			y_max;
	double			x_min;
	double			x_max;
	double			x_pixel;
	double			y_pixel;
	double			x_real;
	double			y_imagin;
	double			x_usr_inpt;
	double			y_usr_inpt;

	int				pixel;
	int				colour;
	int				iterate;
	int				max_iterate;
}					t_fractol;

void	julia(t_fractol *m);
void	julia_set(t_fractol *m);
void	mandelbrot(t_fractol *m);

void	x_y_coordinate(t_fractol *m);
void	parse_fractals(t_fractol *m);
void	init_set(t_fractol *m, char *s);
void	init_julia_set(t_fractol *m, char *s);

void	hooks(t_fractol *m);
void	iterative_loop(t_fractol *m);
void	mandelbrot_complex(t_fractol *m);
void	display_information(t_fractol *m);
void	render_colour(t_fractol *m, int color);

int		mouse_close(t_fractol *m);
int		handle_window(t_fractol *m);
int		handle_error(int code, t_fractol *m);
int		handle_keypress(int keycode, t_fractol *m);
int		handle_zoom(int keycode, int x, int y, t_fractol *m);
int		check_args(t_fractol *m, char *argv1, char *argv2, char *argv3);
void	handle_error_msg(void);

int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
double	ft_strtod(char *s);

#endif
