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
		mlx->offsety -= mlx->roty * 2;
	if (keycode == 125)
		mlx->offsety += mlx->roty * 2;
	if (keycode == 124)
		mlx->offsetx += mlx->rotx * 2;
	if (keycode == 123)
		mlx->offsetx -= mlx->rotx * 2;
	expose(mlx);
}

static void	zoom_image(t_mlx *mlx, int keycode)
{
	mlx_clear_set_image(mlx);
	if (keycode == 69)
		mlx->rotx++;
	if (keycode == 78)
		if (mlx->rotx - 1 > 0 && mlx->roty - 1 > 0)
			mlx->rotx--;
	if (keycode == 88)
		mlx->roty++;
	if (keycode == 92)
		if (mlx->rotx - 1 > 0 && mlx->roty - 1 > 0)
			mlx->roty--;
	expose(mlx);
}

static void	change_z(t_mlx *mlx, int keycode)
{
	mlx_clear_set_image(mlx);
	if (keycode == 116)
		mlx->coefz += mlx->add_coefz;
	if (keycode == 121)
		mlx->coefz -= mlx->add_coefz;
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
	if (keycode == 69 || keycode == 78
		|| keycode == 92 || keycode == 88)
		zoom_image(mlx, keycode);
	if (keycode == 116 || keycode == 121)
		change_z(mlx, keycode);
	return (0);
}
