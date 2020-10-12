/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_help_upl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:22:48 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 14:23:41 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*stack_bl_part_two_while(int power, long double x,
						char *number)
{
	char			*temp;
	char			*temp2;
	long long int	z;

	while (power > 0)
	{
		x *= 10;
		z = (long long int)x;
		x -= z;
		temp = number;
		temp2 = ft_llitoa(z);
		number = ft_strjoin(temp, temp2);
		free(temp2);
		free(temp);
		power--;
	}
	return (number);
}

char				*ft_bl_float_tochka_part_two(long double x, int flag,
						char *number)
{
	char			*str;
	char			*str2;

	str2 = ft_llitoa((long long int)x);
	if (flag == 1)
	{
		str = number;
		number = ft_strjoin(str, str2);
		free(str2);
	}
	else
		number = str2;
	return (number);
}

void				ft_bl_put_longlong(long long int n)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb / 10 > 0)
		ft_bl_put_longlong(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int					ft_bl_infinity_float_l(long double x)
{
	double			pos_inf;
	double			neg_inf;

	pos_inf = 1.0 / 0.0;
	neg_inf = 1.0 / 0.0;
	if (x != x)
	{
		ft_putstr("nan");
		return (3);
	}
	else if (x == pos_inf)
	{
		ft_putstr("inf");
		return (4);
	}
	else if (x == neg_inf)
	{
		ft_putstr("-inf");
		return (4);
	}
	return (0);
}
