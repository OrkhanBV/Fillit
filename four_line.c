/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:09:11 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			valid_line(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] != '.' && str[len] != '#')
			return (0);
		len++;
	}
	if (len != 4)
		return (0);
	return (1);
}

static char			**ft_kostilforelse(int current_line, char **lines)
{
	ft_free_str_array(lines, current_line - 1);
	return (NULL);
}

char				**get_four_line(int fd)
{
	char	*tmp;
	char	**lines;
	int		current_line;

	lines = (char**)malloc(sizeof(char*) * 4);
	tmp = NULL;
	current_line = 0;
	while (current_line < 4)
	{
		if ((get_next_line(fd, &tmp)) > 0)
		{
			if (valid_line(tmp))
			{
				lines[current_line] = tmp;
			}
			else
				return (ft_kostilforelse(current_line, lines));
		}
		else
			return (ft_kostilforelse(current_line, lines));
		current_line++;
	}
	ft_obrez_tetra(lines);
	return (lines);
}
