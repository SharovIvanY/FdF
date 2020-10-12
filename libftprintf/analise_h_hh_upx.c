/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_h_hh_upx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:38:51 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:40:55 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_hh_upx_2(unsigned char num)
{
	char				*str;
	char				*res;
	int					k;

	k = ft_power_hh(num, 16);
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

int						ft_hh_upx(va_list ap, t_print *new)
{
	char				*str;
	unsigned char		num;
	int					res;

	num = (unsigned char)va_arg(ap, unsigned int);
	str = ft_hh_upx_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}

static char				*ft_h_upx_2(unsigned short int num)
{
	char				*str;
	char				*res;
	int					k;

	k = ft_power_h(num, 16);
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

int						ft_h_upx(va_list ap, t_print *new)
{
	char				*str;
	unsigned short int	num;
	int					res;

	num = (unsigned short int)va_arg(ap, unsigned int);
	str = ft_h_upx_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
