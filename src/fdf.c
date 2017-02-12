/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:43:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/05 21:43:56 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_coord_max(t_mlx *mlx)
{
	t_list	*cp_lmap;
	t_map	*cp_map;
	int		i;

	cp_lmap = mlx->map;
	while (cp_lmap)
	{
		i = 0;
		cp_map = (t_map*)cp_lmap->content;
		if (cp_map->x > mlx->xmax)
			mlx->xmax = cp_map->x;
		if (cp_map->y > mlx->ymax)
			mlx->ymax = cp_map->y;
		while (i++ < cp_map->x)
		{
			if (cp_map->z[i] > mlx->zmax)
				mlx->zmax = cp_map->z[i];
			if (cp_map->z[i] < mlx->zmin)
				mlx->zmin = cp_map->z[i];
		}
		cp_lmap = cp_lmap->next;
	}
}

void		fdf(t_list *lmap)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx);
	mlx.map = lmap;
	get_coord_max(&mlx);
	mlx.rotx = mlx.win_w / (mlx.ymax + mlx.xmax);
	mlx.roty = mlx.rotx / mlx.ymax;
	mlx.offsetx = mlx.ymax * (mlx.win_w / (mlx.ymax + mlx.xmax - 1));
	mlx.offsety = 0;
	init_mlx(&mlx, "fdf");
	mlx_image(&mlx);
	expose(&mlx);
	mlx_key_hook(mlx.win, keyhook, &mlx);
	mlx_loop(mlx.mlx);
}
