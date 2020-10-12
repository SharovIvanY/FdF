/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:06:08 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/06 19:19:49 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_otr(int n)
{
	int		otr;

	otr = 0;
	if (n < 0)
		otr = 1;
	return (otr);
}

static int	ft_power(int n)
{
	int		power;

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

char		*ft_itoa(int n)
{
	int		power;
	char	*s;
	int		otr;
	long	nb;

	otr = ft_otr(n);
	nb = n;
	if (otr)
		nb = -nb;
	power = ft_power(nb) + otr;
	s = (char*)malloc(sizeof(char) * (power + 1));
	if (!s)
		return (NULL);
	s[power] = '\0';
	while (power + otr > 0)
	{
		s[power - 1] = (nb % 10) + '0';
		nb = nb / 10;
		power--;
	}
	if (otr)
		s[0] = '-';
	return (s);
}
