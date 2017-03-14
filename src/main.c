/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:38:36 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/12 16:38:38 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*get_map(char *file)
{
	int		fd;
	int		y;
	char	*line;
	int		ret;
	t_list	*lmap;

	y = 0;
	lmap = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
		if (!parser(&lmap, line, y++))
			ret = -1;
	if ((close(fd) == -1) || (ret == -1))
	{
		ft_putstr_fd("Error.\n", 2);
		exit(1);
	}
	return (lmap);
}

int				main(int ac, char **av)
{
	t_list	*lst;

	if (ac == 2)
	{
		if (!(lst = get_map(av[1])) || !lst->content
			|| ((t_map*)lst->content)->x < 2
			|| lst->next == NULL)
		{
			ft_putstr_fd("Error.\n", 2);
			return (1);
		}
		fdf(lst);
	}
	else
		ft_putstr_fd("Usage : ./fdf map\n", 2);
	return (0);
}
