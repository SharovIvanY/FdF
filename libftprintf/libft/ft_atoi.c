/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:07:44 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/10 11:39:59 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_atoilonglong(const char *s, int i, int otr)
{
	unsigned long long	hoba;
	int					result;
	int					step;
	unsigned long long	tuta;

	tuta = 9223372036854775807;
	step = 10;
	hoba = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * step + (s[i] - '0');
		hoba = hoba * step + (s[i] - '0');
		i++;
	}
	if (hoba > tuta && otr == 1)
		return (-1);
	if (hoba > (tuta + 1) && otr == -1)
		return (0);
	return (result * otr);
}

int						ft_atoi(const char *s)
{
	int					result;
	int					i;
	int					otr;

	i = 0;
	otr = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n' ||
			s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == '-')
		otr = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	result = ft_atoilonglong(s, i, otr);
	return (result);
}
