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
	fd = 0;
	lmap = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!parser(&lmap, line, y++))
		{
			ft_putstr_fd("Error.\n", 2);
			close(fd);
			exit(1);
		}
	}
	close(fd);
	if (ret == -1)
	{
		ft_putstr_fd("Error.\n", 2);
		exit(1);
	}
	return (lmap);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fdf(get_map(av[1]));
	else
		ft_putstr_fd("Usage : ./fdf map\n", 2);
	return (0);
}
