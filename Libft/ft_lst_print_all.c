/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:49:35 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/02 23:10:13 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print_all(t_list *lst)
{
	t_list *tmp;
	size_t size;
	size_t i;

	if (lst == NULL)
		return ;
	tmp = lst;
	while (tmp)
	{
		size = tmp->content_size;
		i = 0;
		while (i < size)
		{
			ft_putchar(((char*)(tmp->content))[i]);
			i++;
		}
		tmp = tmp->next;
		ft_putstr(" - ");
	}
	ft_putchar('\n');
}
