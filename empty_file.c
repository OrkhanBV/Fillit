/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 17:08:50 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_for_end(char *name_of_file)
{
	int		fd;
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	end;

	fd = open(name_of_file, O_RDONLY);
	if (fd < 0 || read(fd, &buf, 0) < 0)
		return (1);
	while (read(fd, &buf, BUFF_SIZE) > 0)
	{
		i = 0;
		while (buf[i])
			i++;
		if (i > 0 && buf[i - 1] == '\n')
			end = buf[i - 1];
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	close(fd);
	if (i > 0 && end == '\n')
		return (0);
	return (1);
}

int				check_for_empty_file(char *name_of_file)
{
	int fd;

	fd = open(name_of_file, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (1);
	}
	if (!read(fd, NULL, 1))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (check_for_end(name_of_file));
}
