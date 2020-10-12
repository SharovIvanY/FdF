/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_h_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:41:50 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:41:52 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_power_h(unsigned short int nb, int notation)
{
	int					res;

	res = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb = nb / notation;
		res++;
	}
	return (res);
}

static char				*ft_h_octal_2(unsigned short int num)
{
	int					k;
	char				*str;
	char				*res;

	k = ft_power_h(num, 8);
	str = ft_itoa_base(8, 0);
	res = ft_strnew(k);
	while (--k >= 0)
	{
		res[k] = str[num % 8];
		num = num / 8;
	}
	free(str);
	return (res);
}

int						ft_h_octal(va_list ap, t_print *new)
{
	char				*str;
	unsigned short int	num;
	int					res;

	num = (unsigned short int)va_arg(ap, unsigned int);
	str = ft_h_octal_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
