/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:02:39 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 14:48:36 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_otr(long int n)
{
	int				otr;

	otr = 0;
	if (n < 0)
		otr = 1;
	return (otr);
}

int					ft_lpower(long int n)
{
	int				power;

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

static char			*ft_litoa_two(long long int nb)
{
	int				i;
	char			*s;

	i = 0;
	s = ft_strnew(20);
	nb += 1;
	nb = -nb;
	s[0] = '-';
	while (19 - i > 0)
	{
		s[19 - i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	s[19] = '8';
	return (s);
}

char				*ft_litoa(long int n)
{
	int				power;
	char			*s;
	int				otr;
	long long int	nb;

	otr = ft_otr(n);
	nb = n;
	if (nb + 1 == -9223372036854775807)
		return (ft_litoa_two(nb));
	if (otr)
		nb = nb * -1;
	power = ft_lpower(nb) + otr;
	s = ft_strnew(power);
	if (!s)
		return (NULL);
	while (power > 0)
	{
		s[power - 1] = (nb % 10) + '0';
		nb = nb / 10;
		power--;
	}
	if (otr)
		s[0] = '-';
	return (s);
}
