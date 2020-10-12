/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:32 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:42:34 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_atoi_with_err(const char *str, int *err)
{
	long	ret;
	long	max_int;
	int		count;
	int		sign;

	ret = 0;
	count = 0;
	sign = 1;
	*err = 0;
	max_int = (str[count] == '-') ? (INT_MIN) : (INT_MAX);
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	while ((str[count] >= '0') && (str[count] <= '9') && (ret < max_int))
	{
		ret *= 10;
		ret = ret + (str[count++] - '0');
	}
	if (ret > max_int)
		*err = 1;
	return ((int)ret * sign);
}

int			char_to_hex(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}

int			ft_atoi_hex(const char *str)
{
	int		neg;
	int		nb;

	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'\
			|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	neg = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F')
			|| (*str >= 'a' && *str <= 'f'))
	{
		nb *= 16;
		nb += char_to_hex(*str);
		str++;
	}
	return (neg ? -nb : nb);
}
