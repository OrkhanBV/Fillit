/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by pjeraldi          #+#    #+#             */
/*   Updated: 2020/08/15 17:11:06 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_last_line(int fd)
{
	char	*tmp;
	int		res;

	if ((res = get_next_line(fd, &tmp) > 0) && *tmp == '\0')
	{
		free(tmp);
		return (1);
	}
	if (res == 0)
		return (0);
	return (-1);
}

t_tetr			*ft_free_tetramins(t_tetr **list, char **four_line)
{
	t_tetr *tmp;

	while (list != NULL && *list != NULL)
	{
		tmp = (*list)->next;
		if ((*list)->tetr != NULL)
			ft_free_str_array((*list)->tetr, 4);
		free(*list);
		*list = tmp;
	}
	if (list != NULL)
		list = NULL;
	if (four_line)
		ft_free_str_array(four_line, 4);
	return (NULL);
}

static void		ft_for_gen(t_tetr *t_new, t_tetr *tetramin, t_stock *stock)
{
	t_new->start = tetramin->start;
	t_new->tetr = stock->four_line;
	t_new->name = stock->alpha;
	t_new->next = NULL;
	tetramin->next = t_new;
}

static t_tetr	*ft_gen(t_tetr *tetramin, t_stock *stock, int fd)
{
	t_tetr		*t_new;

	stock->alpha = 'A';
	stock->new_line = 1;
	while (ft_isalpha(stock->alpha) && stock->new_line == 1)
	{
		if (!(stock->four_line = get_four_line(fd)))
			return (ft_free_tetramins(&tetramin, NULL));
		if ((stock->new_line = ft_last_line(fd)) == -1)
			return (ft_free_tetramins(&tetramin, stock->four_line));
		if (valid_tetra(stock->four_line))
		{
			if (!(t_new = (t_tetr*)malloc(sizeof(t_tetr))))
				return (ft_free_tetramins(&tetramin, stock->four_line));
			ft_for_gen(t_new, tetramin, stock);
			tetramin = tetramin->next;
		}
		else
			return (ft_free_tetramins(&tetramin, stock->four_line));
		stock->alpha++;
	}
	return (tetramin);
}

t_tetr			*get_tetrs(int fd)
{
	t_tetr		*tetramin;
	t_tetr		*result;
	t_stock		*stock;

	if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	if (!(tetramin = (t_tetr*)malloc(sizeof(t_tetr))))
		if (!ft_for_get_tetrs(stock))
			return (NULL);
	tetramin->start = tetramin;
	tetramin->tetr = NULL;
	tetramin->next = NULL;
	if (!ft_gen(tetramin, stock, fd))
		if (!ft_for_get_tetrs(stock))
			return (NULL);
	if (!(ft_isalpha(stock->alpha)) && stock->new_line == 1)
	{
		ft_free_tetramins(&tetramin, NULL);
		if (!ft_for_get_tetrs(stock))
			return (NULL);
	}
	free(stock);
	result = tetramin->start->next;
	free(tetramin->start);
	return (result);
}
