/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:44:16 by jbashiri          #+#    #+#             */
/*   Updated: 2019/04/05 13:46:21 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_analise_zd(va_list ap)
{
	int				len;
	char			*str;
	ssize_t			num;

	num = va_arg(ap, ssize_t);
	str = ft_llitoa(num);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int					ft_analise_jd(va_list ap)
{
	int				len;
	char			*str;
	long long int	num;

	num = va_arg(ap, long long int);
	if (num + 1 == -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		return (ft_strlen("-9223372036854775808"));
	}
	str = ft_llitoa(num);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
