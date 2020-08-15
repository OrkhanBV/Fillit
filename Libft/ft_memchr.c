/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:49:09 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/02 23:56:38 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp_s;

	tmp_s = (unsigned char*)s;
	while (n > 0)
	{
		if (*tmp_s == (unsigned char)c)
			return ((void*)tmp_s);
		tmp_s++;
		n--;
	}
	return (NULL);
}
