/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:40:16 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 13:21:34 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*tmp;
	size_t	index;

	if (!s || !f)
		return ;
	tmp = s;
	index = 0;
	while (*tmp)
	{
		f(index, tmp);
		tmp++;
		index++;
	}
}
