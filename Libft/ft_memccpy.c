/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:59:48 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/02 23:32:29 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
	int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	sym;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	sym = (unsigned char)c;
	while (n > 0)
	{
		*d = *s;
		if (*s == sym)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (NULL);
}
