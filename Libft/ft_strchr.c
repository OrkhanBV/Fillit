/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:42:19 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 12:36:46 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char*)str + i);
		i++;
	}
	if (str[i] == '\0' && ch == '\0')
		return ((char*)str + i);
	return (0);
}
