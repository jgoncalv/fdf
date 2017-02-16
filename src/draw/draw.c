/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:10:22 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/07 20:10:24 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw(t_mlx *mlx, t_draw *draw, t_list *lmap, int x)
{
	t_map	*map;

	map = ((t_map*)lmap->content);
	draw->zi = map->z[x];
	draw->zf = (x + 1 < map->x ? map->z[x + 1] : draw->zi);
	draw->xi = draw->offsetx;
	draw->yi = draw->offsety - (mlx->coefz * map->z[x]);
	draw->xf = (x + 1 < map->x ? draw->offsetx + mlx->rotx : draw->xi);
	draw->yf = (x + 1 < map->x ? draw->offsety
		+ mlx->roty - (mlx->coefz * map->z[x + 1]) : draw->yi);
	draw_line(mlx, *draw);
	if (lmap->next)
	{
		draw->xf = draw->offsetx - mlx->rotx;
		draw->yf = draw->offsety + mlx->roty -
		(mlx->coefz * ((t_map*)lmap->next->content)->z[x]);
		draw->zf = ((t_map*)lmap->next->content)->z[x];
		draw_line(mlx, *draw);
	}
}

void		draw(t_mlx *mlx, t_list *lmap)
{
	int		x;
	t_draw	draw;
	t_map	*map;

	draw.decalx = mlx->offsetx;
	draw.decaly = mlx->offsety;
	while (lmap)
	{
		x = 0;
		map = ((t_map*)lmap->content);
		draw.offsetx = draw.decalx;
		draw.offsety = draw.decaly;
		while (x < map->x)
		{
			ft_draw(mlx, &draw, lmap, x);
			draw.offsetx += mlx->rotx;
			draw.offsety += mlx->roty;
			x++;
		}
		lmap = lmap->next;
		draw.decalx -= mlx->rotx;
		draw.decaly += mlx->roty;
	}
}
