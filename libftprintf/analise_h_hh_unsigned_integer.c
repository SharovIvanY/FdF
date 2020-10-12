/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analise_h_hh_unsigned_integer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:33:44 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 13:37:50 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_hh_uinteger(va_list ap, t_print *new)
{
	unsigned char		num;
	char				*str;
	int					res;

	num = (unsigned char)va_arg(ap, unsigned int);
	str = ft_uinteger_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}

int						ft_h_uinteger(va_list ap, t_print *new)
{
	unsigned short int	num;
	char				*str;
	int					res;

	num = (unsigned short int)va_arg(ap, unsigned int);
	str = ft_uinteger_2(num);
	res = ft_uinteger_print(str, new);
	free(str);
	return (res);
}
