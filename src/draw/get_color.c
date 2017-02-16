/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:07:56 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/09 18:07:57 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static int	colorize(double z, int zmax)
{
	int color;
	int red;
	int green;
	int blue;

	color = 0xFFFFFF;
	zmax = zmax == 0 ? 1 : zmax;
 	red = 255 - (((color / 256 / 256) * z)) / zmax;
	green = (((color / 256 % 256) * z)) / zmax;
	blue = (((color % 256) * z)) / zmax;
	color = red * 256 * 256 + green * 256 + blue;
	return (color);
}*/

int		get_color(t_draw draw, t_mlx *mlx, int x)
{
/*	int	color;
	double	z;
	int	add;

	*/
	(void)draw;
	(void)mlx;
	(void)x;
	/*
	add = (mlx->zmin < 0 ? abs(mlx->zmin) : mlx->zmin);
	if (mlx->zmin < 0)
	{
		add = abs(mlx->zmin);
		draw.zi += add;
		draw.zf += add;
	}
	else
	{
		add = mlx->zmin;
		draw.zi -= add;
		draw.zf -= add;
	}
	if (draw.zi > draw.zf)
	{
		if (draw.xi > draw.xf)
		{
			x = x - draw.xf;
			z = (draw.zi - draw.zf) * x / (draw.xi - draw.xf) + draw.zf;
		}
		else
		{
			x = draw.xf - x;
			z = (draw.zi - draw.zf) * x / (draw.xf - draw.xi) + draw.zf;
		}
		color = colorize(z + 1, mlx->zmax + add + 1);
	}
	else if (draw.zi < draw.zf)
	{
		if (draw.xi > draw.xf)
		{
			x = draw.xi - x;
			z = (draw.zf - draw.zi) * x / (draw.xi - draw.xf) + draw.zi;
		}
		else
		{
			x = x - draw.xi;
			z = (draw.zf - draw.zi) * x / (draw.xf - draw.xi) + draw.zi;
		}
		color = colorize(z + 1, mlx->zmax + 1);
	}
	else
		color = colorize(draw.zi + 1, mlx->zmax + 1);*/
	return (0xFFFFFF);
}
