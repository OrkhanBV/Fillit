/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:58:26 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 20:11:33 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int ch)
{
	return (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' \
	|| ch == '\v' || ch == '\f');
}

static void	add_digit(char let, long int *digit, int *error)
{
	let -= '0';
	if (!*digit && !let)
		return ;
	else if (((*digit * 10 + (long int)let) > *digit))
		*digit = *digit * 10 + (long int)let;
	else
		*error = 1;
}

static int	error_checker(long int digit, int minus, int error)
{
	if (error && minus == 1)
		return (-1);
	if (error && minus == -1)
		return (0);
	if (digit == ft_maxmin("long", "max") && minus == 1)
		return ((int)digit);
	return ((int)(digit * (long int)minus));
}

int			ft_atoi(const char *str)
{
	int			minus;
	int			plus;
	long int	digit;
	int			error;

	minus = 1;
	plus = 0;
	digit = 0;
	error = 0;
	while (*str)
	{
		if (*str == '-' && minus == 1 && !plus && !digit)
			minus = -1;
		else if (*str == '+' && minus == 1 && !plus && !digit)
			plus = 1;
		else if (ft_isspace(*str) && !digit && minus == 1 && !plus)
			;
		else if (*str >= '0' && *str <= '9')
			add_digit(*str, &digit, &error);
		else
			break ;
		str++;
	}
	return (error_checker(digit, minus, error));
}
