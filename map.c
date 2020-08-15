/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:10:25 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_free_map(t_map *map, int size_of_map)
{
	while (size_of_map > 0)
	{
		free((map->map)[size_of_map - 1]);
		size_of_map--;
	}
	free(map->map);
	free(map);
}

t_map	*ft_create_map(void)
{
	t_map		*map;
	int			size_of_map;

	size_of_map = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_print_error();
	if (!(map->map = (char**)malloc(sizeof(char*) * 100)))
	{
		free(map);
		ft_print_error();
	}
	while (size_of_map < 100)
	{
		if (!((map->map)[size_of_map] = (char*)malloc(sizeof(char) * (100))))
		{
			ft_free_map(map, size_of_map);
			ft_print_error();
		}
		size_of_map++;
	}
	return (map);
}
