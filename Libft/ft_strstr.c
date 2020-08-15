/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:03:20 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 15:07:03 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fuck_norme(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}

char		*ft_strstr(const char *stra, const char *strb)
{
	size_t	i;
	size_t	j;
	size_t	main;
	char	*result;

	main = 0;
	i = main;
	if (strb[0] == '\0')
		return ((char*)stra);
	while (stra[i])
	{
		i = main;
		if (stra[i] == strb[0])
		{
			result = (char*)stra + i;
			j = 0;
			while (stra[i] == strb[j] && stra[i] != '\0' && strb[j])
				fuck_norme(&i, &j);
			if (strb[j] == '\0')
				return (result);
		}
		main++;
	}
	return (0);
}
