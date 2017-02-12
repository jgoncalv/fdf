/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:31:56 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/07 19:31:58 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_image(t_mlx *mlx, int keycode)
{
	mlx_clear_set_image(mlx);
	if (keycode == 126)
		mlx->offsety -= mlx->roty;
	if (keycode == 125)
		mlx->offsety += mlx->roty;
	if (keycode == 124)
		mlx->offsetx += mlx->rotx;
	if (keycode == 123)
		mlx->offsetx -= mlx->rotx;
	expose(mlx);
}

static void	zoom_image(t_mlx *mlx, int keycode)
{
	mlx_clear_set_image(mlx);
	if (keycode == 69)
	{
		mlx->rotx += 1;
		mlx->roty += 1;
	}
	if (keycode == 78)
	{
		if (mlx->rotx - 1 > 0 && mlx->roty - 1 > 0)
		{
			mlx->rotx -= 1;
			mlx->roty -= 1;
		}
	}
	expose(mlx);
}

static void	iso_image(t_mlx *mlx, int keycode)
{
	mlx_clear_set_image(mlx);
	if (keycode == 116)
	{
		if (mlx->roty - 1 > 0)
			mlx->roty -= 1;
	}
	if (keycode == 121)
	{
		if (mlx->roty < mlx->rotx)
			mlx->roty += 1;
	}
	expose(mlx);
}

int			keyhook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_clear_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == 126 || keycode == 125
		|| keycode == 124 || keycode == 123)
		move_image(mlx, keycode);
	if (keycode == 69 || keycode == 78)
		zoom_image(mlx, keycode);
	if (keycode == 116 || keycode == 121)
		iso_image(mlx, keycode);
	return (0);
}
