/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/08/04 12:22:05 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int			count_of_sharp(char **fl)
{
	int i;
	int j;
	int n_of_sharp;

	n_of_sharp = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fl[i][j] == '#')
				n_of_sharp++;
			j++;
		}
		i++;
	}
	return (n_of_sharp);
}

static int			prevalid(char **fl, int i, int j)
{
	int res;

	fl[i][j] = '.';
	res = 0;
	if (j != 3 && fl[i][j + 1] == '#')
		res = prevalid(fl, i, j + 1);
	if (j && fl[i][j - 1] == '#')
		res = res + prevalid(fl, i, j - 1);
	if (i && fl[i - 1][j] == '#')
		res = res + prevalid(fl, i - 1, j);
	if (i != 3 && fl[i + 1][j] == '#')
		res = res + prevalid(fl, i + 1, j);
	fl[i][j] = '#';
	return (res + 1);
}

int					valid_tetra(char **fl)
{
	int i;
	int j;

	if (count_of_sharp(fl) != 4)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fl[i][j] == '#')
			{
				if (prevalid(fl, i, j) == 4 || prevalid(fl, i, j) == 7)
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
