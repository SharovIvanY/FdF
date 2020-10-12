/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:01:53 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 14:05:41 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_octal_2(unsigned int num)
{
	int				k;
	char			*str;
	char			*res;

	k = ft_power(num, 8) - 1;
	str = ft_itoa_base(8, 0);
	res = ft_strnew((size_t)k + 1);
	while (k >= 0)
	{
		res[k] = str[num % 8];
		num = num / 8;
		k--;
	}
	free(str);
	return (res);
}

int					ft_octal(va_list ap, t_print *new)
{
	char			*str;
	unsigned int	num;

	num = (unsigned int)va_arg(ap, int);
	str = ft_octal_2(num);
	if (num == 0)
	{
		free(str);
		return (ft_sobachiy_null(new));
	}
	num = (unsigned int)ft_uinteger_print(str, new);
	free(str);
	return (num);
}
