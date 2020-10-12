/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_l_ll_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:51:47 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:51:57 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_ll_x_2(unsigned long long int num)
{
	char					*str;
	char					*res;
	int						k;

	k = ft_power_ll(num, 16);
	str = ft_itoa_base(16, 0);
	res = ft_strnew((size_t)k);
	while (--k >= 0)
	{
		res[k] = str[num % 16];
		num = num / 16;
	}
	free(str);
	return (res);
}

int							ft_ll_x(va_list ap, t_print *new)
{
	char					*str;
	char					*temp;
	unsigned long long int	num;
	int						num2;

	num = va_arg(ap, unsigned long long int);
	str = ft_ll_x_2(num);
	temp = str;
	str = check_flag_sharp(temp, new);
	free(temp);
	num2 = ft_uinteger_print(str, new);
	free(str);
	return (num2);
}

static char					*ft_l_x_2(unsigned long int num)
{
	char					*str;
	char					*res;
	int						k;

	k = ft_power_l(num, 16);
	str = ft_itoa_base(16, 0);
	res = ft_strnew((size_t)k);
	while (--k >= 0)
	{
		res[k] = str[num % 16];
		num = num / 16;
	}
	free(str);
	return (res);
}

int							ft_l_x(va_list ap, t_print *new)
{
	char					*str;
	unsigned long int		num;
	int						res;

	num = va_arg(ap, unsigned long int);
	str = ft_l_x_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
