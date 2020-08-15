/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:08:18 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			ft_proverka2(t_map *map_list, t_tetr *list, int a, int b)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->tetr[i][j] == '#' && (a + i > map_list->size ||
				b + j > map_list->size))
				return (0);
			if (list->tetr[i][j] == '#' && (map_list->map)[a + i][b + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int			ft_set2(t_map *map_list, t_tetr *list, int a, int b)
{
	int i;
	int j;

	i = 0;
	if ((ft_proverka2(map_list, list, a, b)) == 1)
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (list->tetr[i][j] == '#')
					map_list->map[a + i][b + j] = list->name;
				j++;
			}
			i++;
		}
		return (1);
	}
	else
		return (0);
}

static void			ft_clean_tetra(t_map *map_list, t_tetr *list)
{
	int i;
	int j;

	i = 0;
	while (i <= map_list->size)
	{
		j = 0;
		while (j <= map_list->size)
		{
			if ((map_list->map)[i][j] == list->name)
				(map_list->map)[i][j] = '.';
			j++;
		}
		i++;
	}
}

static int			ft_dead_mashin(t_map *map_list, t_tetr *list, int a, int b)
{
	if (!list)
		return (1);
	a = 0;
	while (a <= (map_list->size))
	{
		b = 0;
		while (b <= map_list->size)
		{
			if ((ft_set2(map_list, list, a, b)) &&
				ft_dead_mashin(map_list, list->next, a, b))
				return (1);
			else
				ft_clean_tetra(map_list, list);
			b++;
		}
		a++;
	}
	return (0);
}

void				ft_dom_truba_shatal(t_map *map_list, t_tetr *list)
{
	map_list->size = 1;
	while (!(ft_dead_mashin(map_list, list, 0, 0)))
		map_list->size = map_list->size + 1;
}
