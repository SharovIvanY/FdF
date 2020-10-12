/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_l_ll_upx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:49:02 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:49:48 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_ll_upx_2(unsigned long long int num)
{
	char					*str;
	char					*res;
	int						k;

	k = ft_power_ll(num, 16);
	str = ft_itoa_base(16, 1);
	res = ft_strnew((size_t)k);
	while (--k >= 0)
	{
		res[k] = str[num % 16];
		num = num / 16;
	}
	free(str);
	return (res);
}

int							ft_ll_upx(va_list ap, t_print *new)
{
	char					*str;
	unsigned long long int	num;
	int						res;

	num = va_arg(ap, unsigned long long int);
	str = ft_ll_upx_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}

static char					*ft_l_upx_2(unsigned long int num)
{
	char					*str;
	char					*res;
	int						k;

	k = ft_power_l(num, 16);
	str = ft_itoa_base(16, 1);
	res = ft_strnew((size_t)k);
	while (--k >= 0)
	{
		res[k] = str[num % 16];
		num = num / 16;
	}
	free(str);
	return (res);
}

int							ft_l_upx(va_list ap, t_print *new)
{
	char					*str;
	unsigned long int		num;
	int						res;

	num = va_arg(ap, unsigned long int);
	str = ft_l_upx_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
