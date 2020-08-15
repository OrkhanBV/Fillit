/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:43:58 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 20:00:02 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = dst;
	s2 = (char*)src;
	while (*s1)
	{
		s1++;
	}
	while (*s2)
	{
		if (len <= 0)
		{
			*s1 = '\0';
			return (dst);
		}
		*s1 = *s2;
		s1++;
		s2++;
		len--;
	}
	*s1 = '\0';
	return (dst);
}
