/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:41:47 by chruhin           #+#    #+#             */
/*   Updated: 2023/08/03 09:28:43 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_error_msg(void)
{
	write(2, "\nInvalid input!\n", 16);
	write(2, "\nEnter   ./fractol mandelbrot   or  ./fractol julia\n", 52);
	write(2, "To see different julia sets enter", 33);
	write(2, "  ./fractol julia -0.4  0.6  \n\n", 31);
	exit (EXIT_FAILURE);
}

double	get_decimal(char *s, int i, int j)
{
	double	sum;
	double	dec;

	sum = 0.0;
	dec = 0.0;
	while (*s >= '0' && *s <= '9')
		sum = (sum * 10.0) + (*(s++) - '0');
	if (*(s++) == '.')
	{
		while (*s >= '0' && *s <= '9')
		{
			dec = (dec * 10.0) + (*(s++) - '0');
			i++;
		}
		if (*s && !(*s >= '0' && *s <= '9'))
			handle_error_msg();
	}
	else if (*s && !(*s >= '0' && *s <= '9'))
		handle_error_msg();
	while (j++ < i)
		dec /= 10.0;
	return (sum + dec);
}

double	ft_strtod(char *s)
{
	int		sign;
	double	res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sign = 1;
	res = 0.0;
	if (!*s)
		return (0);
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	res = get_decimal(s, i, j);
	return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	return (1);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
