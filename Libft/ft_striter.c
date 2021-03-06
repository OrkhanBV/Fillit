/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:36:37 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/04/13 15:37:26 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	char *tmp;

	if (!s || !f)
		return ;
	tmp = s;
	while (*tmp)
	{
		f(tmp);
		tmp++;
	}
}
