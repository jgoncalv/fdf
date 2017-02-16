/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:25 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/02 15:09:27 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_int(char **tab)
{
	while (*tab)
	{
		if (!ft_isint(*tab))
			return (0);
		tab++;
	}
	return (1);
}

static int	check_x(char **tab, t_map map)
{
	if (map.x != (ft_tablen(tab) - 1))
		return (0);
	return (1);
}

int			parser(t_list **lmap, char *line, int y)
{
	char	**tab;
	t_list	*nmap;
	t_map	map;

	if (!(tab = ft_strsplit(line, ' ')) || (*lmap
		&& !check_x(tab, *(t_map*)(*lmap)->content)) || !check_int(tab))
	{
		ft_tabdel((void**)tab, ft_tablen(tab));
		return (0);
	}
	map.x = ft_tablen(tab) - 1;
	map.y = y;
	map.z = ft_atoi_tab(tab);
	ft_tabdel((void**)tab, ft_tablen(tab));
	if (!(nmap = ft_lstnew(&map, sizeof(t_map))))
		return (0);
	ft_lstadd_end(lmap, nmap);
	if (!*lmap)
	{
		ft_putstr_fd("Error.\n", 2);
		exit(1);
	}
	return (1);
}
