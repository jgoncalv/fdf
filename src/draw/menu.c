/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:34:15 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/14 17:34:17 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu(t_mlx *mlx)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	str1 = "        COMMANDS";
	str2 = "STRETCH --  Y : 6/9 / X : +/-";
	str3 = "Z_SCALE --  PAGEUP / PAGEDOWN";
	str4 = "MOVE    --     ARROW_KEYS";
	str5 = "QUIT    --       ESC";
	mlx_string_put(mlx->mlx, mlx->win, 50, 800, 0xFFFFFF, str1);
	mlx_string_put(mlx->mlx, mlx->win, 50, 850, 0xFFFFFF, str2);
	mlx_string_put(mlx->mlx, mlx->win, 50, 875, 0xFFFFFF, str3);
	mlx_string_put(mlx->mlx, mlx->win, 50, 900, 0xFFFFFF, str4);
	mlx_string_put(mlx->mlx, mlx->win, 50, 925, 0xFFFFFF, str5);
}
