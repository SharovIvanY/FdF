/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:48:49 by jbashiri          #+#    #+#             */
/*   Updated: 2019/04/05 13:48:54 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_analise_z_two(t_print *new)
{
	char		*temp;

	temp = ft_strnew(new->width);
	if (new->flag_minus)
	{
		ft_memset(temp, ' ', new->width);
		temp[0] = 'Z';
	}
	else if (new->flag_null)
	{
		ft_memset(temp, '0', new->width);
		temp[new->width - 1] = 'Z';
	}
	else
	{
		ft_memset(temp, ' ', new->width);
		temp[new->width - 1] = 'Z';
	}
	return (temp);
}

int				ft_analise_z(t_print *new)
{
	int			num;
	char		*temp;

	if (new->flag_width)
		temp = ft_analise_z_two(new);
	else
	{
		temp = ft_strnew(1);
		temp[0] = 'Z';
	}
	ft_putstr(temp);
	num = ft_strlen(temp);
	free(temp);
	return (num);
}

int				ft_power(unsigned long nb, int notation)
{
	int			res;

	res = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb = nb / notation;
		res++;
	}
	return (res);
}

char			*ft_itoa_base(int notation, int up_or_down)
{
	char		*str;
	int			i;

	i = -1;
	str = ft_strnew((size_t)notation);
	str[notation] = '\0';
	while (++i < 10 && i < notation)
		str[i] = (char)(i + '0');
	i--;
	if (up_or_down && i < notation)
	{
		while (++i < notation)
			str[i] = (char)(i - 10 + 'A');
	}
	else
	{
		while (++i < notation)
			str[i] = (char)(i - 10 + 'a');
	}
	return (str);
}

int				ft_analise_n(va_list ap, int res)
{
	int			*k;

	k = va_arg(ap, int*);
	*k = res;
	return (0);
}
