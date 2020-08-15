/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:09:34 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_free_str_array(char **array, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int		ft_obrez_tetra_x(char **tetr)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_obrez_tetra_y(char **tetr)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr[i][j] == '#')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

void			ft_obrez_tetra(char **tetr)
{
	int i;
	int j;
	int x;
	int y;

	x = ft_obrez_tetra_x(tetr);
	y = ft_obrez_tetra_y(tetr);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#')
			{
				tetr[i][j] = '.';
				tetr[i - x][j - y] = '#';
			}
			j++;
		}
		i++;
	}
}
