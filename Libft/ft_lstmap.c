/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:54:00 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/02 23:24:09 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *new;
	t_list *tmp;
	t_list *previous;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((previous = f(lst)) == NULL)
		return (NULL);
	result = previous;
	tmp = lst->next;
	while (tmp)
	{
		if ((new = f(tmp)) == NULL)
		{
			ft_lst_free_all(result);
			return (NULL);
		}
		previous->next = new;
		previous = previous->next;
		tmp = tmp->next;
	}
	return (result);
}
