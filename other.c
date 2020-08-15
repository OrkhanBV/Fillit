/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by pjeraldi          #+#    #+#             */
/*   Updated: 2020/08/15 17:10:51 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map		ft_print_map(t_map *map_list)
{
	int i;
	int j;

	i = 0;
	while (i <= map_list->size)
	{
		j = 0;
		while (j <= map_list->size)
		{
			ft_putchar(map_list->map[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	return (*map_list);
}

t_map		ft_set_dotmap(t_map *map_list)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			(map_list->map)[i][j] = '.';
			j++;
		}
		(map_list->map)[i][j] = '\0';
		i++;
	}
	return (*map_list);
}

void		ft_readformain(int argc, char **argv)
{
	if (argc != 2)
		ft_print_error();
	if (check_for_empty_file(argv[1]))
		ft_print_error();
}
