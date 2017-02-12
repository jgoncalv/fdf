/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:23:56 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/09 12:58:41 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	if (x < mlx->win_w && y < mlx->win_h && x >= 0 && y >= 0)
	{
		((int*)mlx->data)[x + (y * mlx->win_w)] = color;
	}
}
