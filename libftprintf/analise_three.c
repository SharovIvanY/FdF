/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:19:39 by jbashiri          #+#    #+#             */
/*   Updated: 2019/04/05 14:19:40 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_analise_two(va_list ap, t_print *new, char c)
{
	if (c == 'i' || c == 'd')
	{
		if (new->size[0] == 'h')
		{
			if (new->size[1] == 'h')
				return (ft_hh_integer(ap, new));
			else
				return (ft_h_integer(ap, new));
		}
		else if (new->size[0] == 'l')
		{
			if (new->size[1] == 'l')
				return (ft_ll_integer(ap, new));
			else
				return (ft_l_integer(ap, new));
		}
		else if (new->size[0] == 'j')
			ft_analise_jd(ap);
		else if (new->size[0] == 'z')
			ft_analise_zd(ap);
		else
			return (ft_integer(ap, new));
	}
	return (-100);
}
