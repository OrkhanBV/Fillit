/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:58:21 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 14:07:05 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	while (str[i])
	{
		if (str[i] == (char)ch)
			result = ((char*)str + i);
		i++;
	}
	if (ch == '\0' && str[i] == '\0')
		result = ((char*)str + i);
	return (result);
}
