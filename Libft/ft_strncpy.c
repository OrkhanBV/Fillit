/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:56:19 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 20:00:35 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = dst;
	tmp_src = (char*)src;
	while (len > 0)
	{
		if (*tmp_src == '\0')
		{
			*tmp_dst = *tmp_src;
			tmp_dst++;
			len--;
		}
		else
		{
			*tmp_dst = *tmp_src;
			tmp_dst++;
			tmp_src++;
			len--;
		}
	}
	return (dst);
}
