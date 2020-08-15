/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:48:56 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 15:05:35 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fuck_norm_inc(size_t *a, size_t *b, int check)
{
	if (check == 0)
	{
		*a = 0;
		*b = 0;
	}
	else if (check == 1)
	{
		(*a)++;
		(*b)++;
	}
}

static char	**fuck_norm_error(char **result)
{
	ft_str_array_free_all(result);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	size_t	count;
	size_t	i;
	size_t	l;

	l = ft_str_number_of_words(s, c);
	if (!s || (l + 1 <= l) || !(r = (char**)malloc(sizeof(char*) * l + 1)))
		return (NULL);
	r[l] = NULL;
	fuck_norm_inc(&l, &i, 0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			return (r);
		count = 0;
		while (s[i] != c && s[i])
			fuck_norm_inc(&count, &i, 1);
		if (!(r[l] = ft_strnew(count)))
			return (fuck_norm_error(r));
		ft_strncpy(r[l], s + i - count, count);
		l++;
	}
	return (r);
}
