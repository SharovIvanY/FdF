/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:27:44 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:04:34 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_analise_pointer_2(unsigned long num)
{
	char			*str;
	char			*res;
	int				k;

	if (num == 0)
	{
		str = "0x0";
		res = ft_strdup(str);
		return (res);
	}
	k = ft_power(num, 16);
	str = ft_itoa_base(16, 0);
	res = ft_strnew((size_t)k + 2);
	res[0] = '0';
	res[1] = 'x';
	while (num && k > 0)
	{
		res[k + 1] = str[num % 16];
		num = num / 16;
		k--;
	}
	free(str);
	return (res);
}

int					ft_analise_pointer(va_list ap, t_print *new)
{
	unsigned long	num;
	char			*str;
	int				res;

	num = va_arg(ap, unsigned long);
	if (num == 0 && new->accuracy == 0 && new->flag_accuracy)
	{
		ft_putstr("0x");
		return (2);
	}
	str = ft_analise_pointer_2(num);
	res = ft_print_pointer(str, new);
	return (res);
}
