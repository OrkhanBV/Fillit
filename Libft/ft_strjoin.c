/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:19:13 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 20:09:16 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;
	char *result;

	if (!s1 && !s2)
		return (ft_strnew(0));
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	if (ft_strlen((char*)s1) + ft_strlen((char*)s2) < ft_strlen((char*)s1) ||
		ft_strlen((char*)s1) + ft_strlen((char*)s2) < ft_strlen((char*)s2))
		return (NULL);
	if (!(result = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
		return (NULL);
	tmp = result;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	while (*s2 != '\0')
		*tmp++ = *s2++;
	*tmp = '\0';
	return (result);
}
