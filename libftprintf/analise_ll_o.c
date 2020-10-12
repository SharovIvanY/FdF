/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_ll_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:54:29 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:56:01 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_power_ll(unsigned long long int nb, int notation)
{
	int						res;

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

static char					*ft_ll_octal_2(unsigned long long int num)
{
	int						k;
	char					*str;
	char					*res;

	k = ft_power_ll(num, 8);
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

int							ft_ll_octal(va_list ap, t_print *new)
{
	char					*str;
	unsigned long long int	num;
	int						res;

	num = va_arg(ap, unsigned long long int);
	str = ft_ll_octal_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
