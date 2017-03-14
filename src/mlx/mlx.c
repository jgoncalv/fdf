/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:59:36 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/09 19:59:37 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_mlx *mlx, char *name)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, name);
}

void	mlx_image(t_mlx *mlx)
{
	int bpp;
	int sl;
	int endian;

	bpp = sizeof(int);
	sl = bpp * mlx->win_w;
	endian = 0;
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->data = mlx_get_data_addr(mlx->img, &bpp, &sl, &endian);
}

int		expose(t_mlx *mlx)
{
	draw(mlx, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	menu(mlx);
	return (0);
}

void	mlx_clear_set_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_image(mlx);
}
