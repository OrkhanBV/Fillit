/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:02:48 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 19:30:35 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			numeric(int c)
{
	int		result;

	if (!c)
		return (1);
	result = 0;
	if (c < 0)
		result++;
	while (c)
	{
		c /= 10;
		result++;
	}
	return (result);
}

static int			check_maxmin(void)
{
	size_t			index;
	int				result;

	index = sizeof(int) * 8 - 1;
	result = 1;
	while (index)
	{
		result *= 2;
		index--;
	}
	return (result * -1);
}

static int			shorter(int *n, char *result)
{
	int				temp;
	int				temp_temp;
	int				correct;
	int				correct2;

	temp = check_maxmin();
	correct = numeric(*n) - 2;
	correct2 = 1;
	if (*n == temp)
	{
		while (correct--)
			correct2 *= 10;
		while (temp)
		{
			temp_temp = temp;
			temp /= 10;
		}
		temp = temp_temp * -1;
		result[1] = (char)(temp + '0');
		temp = *n + (temp * correct2);
		return (temp * -1);
	}
	return (*n * -1);
}

char				*ft_itoa(int n)
{
	char			*result;
	int				index;
	int				hren_indicate;

	index = numeric(n);
	if (!(result = (char *)malloc(numeric(n) + 1)))
		return (NULL);
	hren_indicate = 0;
	result[index] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = shorter(&n, result);
		hren_indicate = 1;
	}
	while (index)
	{
		if (!(hren_indicate && n == 0))
			result[index - 1] = n % 10 + '0';
		n /= 10;
		index--;
	}
	return (result);
}
