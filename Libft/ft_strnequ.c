/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:22:45 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 13:51:11 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (len == 0)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (len <= 0)
			return (1);
		if (s1[i] != s2[i])
			return (0);
		i++;
		len--;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
