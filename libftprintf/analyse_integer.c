/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:20 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 14:01:26 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hobaflags(t_print *new)
{
	if (new->flag_otr_i)
	{
		new->flag_space = 0;
		new->flag_plus = 0;
	}
	else if (new->flag_plus)
		new->flag_space = 0;
}

int			ft_integer(va_list ap, t_print *new)
{
	int		num;
	char	*str;

	new->sobaka = va_arg(ap, int);
	if (new->sobaka < 0)
		new->flag_otr_i = 1;
	ft_hobaflags(&*new);
	if (new->sobaka == 0 && new->flag_accuracy && new->accuracy == 0)
		return (ft_iprint_null(new));
	str = ft_itoa(new->sobaka);
	num = ft_integer_print(str, new);
	return (num);
}
