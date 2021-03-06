/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:12:08 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/15 11:47:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_usage(char **map)
{
	ft_free_map(map);
	ft_putstr("usage: fillit target_file\n");
	return (0);
}

static int	ft_error(char **map)
{
	ft_free_map(map);
	ft_putstr("error\n");
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		*str;
	t_tetris	*tetris;
	char		**map;
	int			len;

	map = NULL;
	if (!(map = ft_allocate_map(map)))
		return (1);
	tetris = NULL;
	if (argc != 2)
		return (ft_usage(map));
	else
	{
		if (((((fd = open(argv[1], O_RDONLY)) == -1) \
		|| ((str = ft_read_file(fd)) == NULL))))
			return (ft_error(map));
		len = ft_strlen(str);
		if (((((tetris = (ft_check_and_letter(str, tetris))) == NULL) \
		|| (ft_create_map(len, map)) != 0)))
			return (ft_error(map));
		ft_solve(tetris, tetris, map);
	}
	ft_display_and_free_map(map, tetris, fd);
	return (0);
}
