/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:09:49 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_kulyek_udovolstviya(t_map *map, t_tetr *tetr)
{
	ft_set_dotmap(map);
	ft_dom_truba_shatal(map, tetr);
	ft_print_map(map);
}

int				main(int argc, char **argv)
{
	t_tetr		*tetr;
	t_map		*map;
	int			fd;

	map = ft_create_map();
	ft_readformain(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if ((tetr = get_tetrs(fd)) == NULL)
	{
		ft_free_map(map, 100);
		ft_print_error();
	}
	ft_kulyek_udovolstviya(map, tetr);
	ft_free_tetramins(&tetr, NULL);
	ft_free_map(map, 100);
	return (0);
}
