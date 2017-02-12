/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:41:36 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/12 16:41:37 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = 0;
	mlx->xmax = 0;
	mlx->ymax = 0;
	mlx->zmax = 0;
	mlx->zmin = 0;
	mlx->win_w = 1000;
	mlx->win_h = 1000;
	mlx->offsetx = 0;
	mlx->offsety = 0;
	mlx->rotx = 0;
	mlx->roty = 0;
	mlx->bpp = 0;
	mlx->sl = 0;
	mlx->endian = 0;
}
