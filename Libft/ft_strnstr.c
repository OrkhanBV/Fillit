/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:31:29 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 13:53:19 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fuck_norm_inc(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}

char		*ft_strnstr(const char *stra, const char *strb, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	main;
	char	*result;

	main = 0;
	i = main;
	if (strb[0] == '\0')
		return ((char*)stra);
	while (stra[i] && i < len)
	{
		i = main;
		if (stra[i] == strb[0])
		{
			result = (char*)stra + i;
			j = 0;
			while (stra[i] == strb[j] && stra[i] && strb[j] && i < len)
				fuck_norm_inc(&i, &j);
			if (strb[j] == '\0')
				return (result);
		}
		main++;
	}
	return (0);
}
