/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:48:49 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/07 19:48:50 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_x(t_mlx *mlx, t_draw draw)
{
	int cumul;
	int	i;
	int x;
	int y;

	i = 1;
	x = draw.xi;
	y = draw.yi;
	cumul = draw.dx / 2;
	while (i <= draw.dx)
	{
		x += draw.xinc;
		if ((cumul += draw.dy) >= draw.dx)
		{
			cumul -= draw.dx;
			y += draw.yinc;
		}
		draw.color = get_color(draw, mlx, x);
		pixel_to_image(mlx, x, y, draw.color);
		i++;
	}
}

static void	ft_draw_line_y(t_mlx *mlx, t_draw draw)
{
	int cumul;
	int	i;
	int x;
	int y;

	i = 1;
	x = draw.xi;
	y = draw.yi;
	cumul = draw.dy / 2;
	while (i <= draw.dy)
	{
		y += draw.yinc;
		if ((cumul += draw.dx) >= draw.dy)
		{
			cumul -= draw.dy;
			x += draw.xinc;
		}
		draw.color = get_color(draw, mlx, x);
		pixel_to_image(mlx, x, y, draw.color);
		i++;
	}
}

void		draw_line(t_mlx *mlx, t_draw draw)
{
	draw.dx = draw.xf - draw.xi;
	draw.dy = draw.yf - draw.yi;
	draw.xinc = draw.dx > 0 ? 1 : -1;
	draw.yinc = draw.dy > 0 ? 1 : -1;
	draw.dx = abs(draw.dx);
	draw.dy = abs(draw.dy);
	draw.color = get_color(draw, mlx, draw.xi);
	pixel_to_image(mlx, draw.xi, draw.yi, draw.color);
	if (draw.dx > draw.dy)
		ft_draw_line_x(mlx, draw);
	else
		ft_draw_line_y(mlx, draw);
}
