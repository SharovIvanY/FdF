/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_l_ll_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:37 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:48:07 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_ll_uinteger_2(unsigned long long int num)
{
	int						res;
	char					*str;

	res = ft_lupower(num);
	str = ft_strnew(res);
	while (--res >= 0)
	{
		str[res] = (char)(num % 10 + '0');
		num = num / 10;
	}
	return (str);
}

int							ft_ll_uinteger(va_list ap, t_print *new)
{
	unsigned long long int	num;
	char					*str;
	int						res;

	num = va_arg(ap, unsigned long long int);
	str = ft_ll_uinteger_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}

int							ft_lupower(unsigned long int n)
{
	int						power;

	power = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		power++;
		n = n / 10;
	}
	return (power);
}

char						*ft_l_uinteger_2(unsigned long int num)
{
	int						res;
	char					*str;

	res = ft_lupower(num);
	str = ft_strnew(res);
	while (--res >= 0)
	{
		str[res] = (char)(num % 10 + '0');
		num = num / 10;
	}
	return (str);
}

int							ft_l_uinteger(va_list ap, t_print *new)
{
	unsigned long int		num;
	char					*str;
	int						res;

	num = va_arg(ap, unsigned long int);
	str = ft_l_uinteger_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
