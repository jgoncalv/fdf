/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:09:02 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/01 20:09:08 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_map
{
	int				x;
	int				y;
	int				*z;
}					t_map;

typedef struct		s_draw
{
	int				color;
	int				zi;
	int				zf;
	int				xi;
	int				yi;
	int				xf;
	int				yf;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				decalx;
	int				decaly;
	int				offsetx;
	int				offsety;
}					t_draw;

typedef struct		s_mlx
{
	t_list			*map;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				xmax;
	int				ymax;
	int				zmax;
	int				zmin;
	int				win_w;
	int				win_h;
	int				offsetx;
	int				offsety;
	int				rotx;
	int				roty;
	int				bpp;
	int				sl;
	int				endian;
	int				coefz;
}					t_mlx;

/*
** Parser
*/
int					parser(t_list **lmap, char *line, int y);

/*
** HOOK
*/
int					keyhook(int keycode, t_mlx *mlx);

/*
**	Draw
*/
void				draw(t_mlx *mlx, t_list *lmap);
void				draw_line(t_mlx *mlx, t_draw draw);
void				pixel_to_image(t_mlx *mlx, int x, int y, int color);
int					get_color(t_draw draw, t_mlx *mlx, int x);
void				fdf(t_list *lmap);

/*
** MLX
*/
void				ft_init_mlx(t_mlx *mlx);
void				init_mlx(t_mlx *mlx, char *name);
void				mlx_image(t_mlx *mlx);
int					expose(t_mlx *mlx);
void				mlx_clear_set_image(t_mlx *mlx);

#endif
