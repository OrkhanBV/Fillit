/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:22:26 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/25 18:11:21 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../header.h"

static int			lst_del(t_list *del_node, t_list **list, int returned)
{
	t_list *cur;
	t_list *previous;

	previous = NULL;
	cur = *list;
	while (cur)
	{
		if (cur == del_node)
		{
			if (!previous)
				*list = cur->next;
			else
				previous->next = cur->next;
			free(del_node->content);
			ft_memdel((void**)&del_node);
			return (returned);
		}
		previous = cur;
		cur = cur->next;
	}
	return (returned);
}

static t_list		*find_fd(int fd, t_list **list)
{
	t_list *tmp;

	if (!(*list))
	{
		*list = ft_lstnew("", (size_t)fd);
		return (*list);
	}
	tmp = *list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", (size_t)fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static void			*join_with_free(char *s1, char *s2)
{
	char	*tmp;
	char	*result;

	tmp = s1;
	result = ft_strjoin(s1, s2);
	free(tmp);
	return ((void*)result);
}

static int			trun_reminder(char *reminder, char *end_point_of_line,
	t_list **cur_fd, char **line)
{
	char	*result;
	char	*end_point_of_reminder;
	size_t	result_len;

	*line = ft_strnew(end_point_of_line - (char*)((*cur_fd)->content));
	*line = ft_strncpy(*line, (char*)((*cur_fd)->content), end_point_of_line
			- (char*)((*cur_fd)->content));
	end_point_of_reminder = ft_strchr(reminder, '\0');
	result_len = end_point_of_reminder - end_point_of_line - 1;
	result = ft_strnew(result_len);
	result = ft_strncpy(result, end_point_of_line + 1, result_len);
	free(reminder);
	(*cur_fd)->content = result;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*end_point_of_line;
	int				ret;
	t_list			*cur_fd;
	static t_list	*fd_list;

	if (fd < 0 || !line || read(fd, &buf, 0) < 0)
		return (-1);
	cur_fd = find_fd(fd, &fd_list);
	ft_bzero(buf, BUFF_SIZE + 1);
	ret = read(fd, &buf, BUFF_SIZE);
	if (ret == 0 && cur_fd->content == NULL)
		return (lst_del(cur_fd, &fd_list, 0));
	cur_fd->content = join_with_free((char*)(cur_fd->content), buf);
	end_point_of_line = ft_strchr((char*)cur_fd->content, '\n');
	if (ret == 0 && !end_point_of_line)
	{
		if (*((char*)(cur_fd->content)) == '\0')
			return (lst_del(cur_fd, &fd_list, 0));
		*line = ft_strdup((char*)(cur_fd->content));
		return (lst_del(cur_fd, &fd_list, 1));
	}
	if (ret != 0 && !end_point_of_line)
		return (get_next_line(fd, line));
	return (trun_reminder(cur_fd->content, end_point_of_line, &cur_fd, line));
}
