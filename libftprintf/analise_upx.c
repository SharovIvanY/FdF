/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_upx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:57:53 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:58:23 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_upx_2(unsigned int num)
{
	char			*str;
	char			*res;
	int				k;

	k = ft_power(num, 16) - 1;
	str = ft_itoa_base(16, 1);
	res = ft_strnew((size_t)k + 1);
	while (k >= 0)
	{
		res[k] = str[num % 16];
		num = num / 16;
		k--;
	}
	free(str);
	return (res);
}

int					ft_upx(va_list ap, t_print *new)
{
	char			*str;
	unsigned int	num;
	int				x;

	num = (unsigned int)va_arg(ap, int);
	if (num == 0)
		return (ft_sobachiy_null(new));
	str = ft_upx_2(num);
	x = ft_uinteger_print(str, new);
	free(str);
	return (x);
}
