/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:10:31 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 19:54:18 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s_dst;
	const unsigned char *s_src;

	if (!dst && !src)
		return (NULL);
	s_dst = (unsigned char*)dst;
	s_src = (const unsigned char*)src;
	while (n > 0)
	{
		*s_dst = *s_src;
		s_dst++;
		s_src++;
		n--;
	}
	return (dst);
}
