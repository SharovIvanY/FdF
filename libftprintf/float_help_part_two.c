/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_longfloat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:59:54 by jbashiri          #+#    #+#             */
/*   Updated: 2019/10/12 13:11:57 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*float_flags_part_two(t_print *new, char *number, char ch)
{
	char			*space;
	char			*str;
	int				x;

	if (new->width > (int)ft_strlen(number))
	{
		new->width -= ft_strlen(number);
		if (new->flag_space == 1)
			new->width -= 1;
		space = ft_strnew(new->width);
		x = 0;
		while (x < new->width)
			space[x++] = ch;
		str = number;
		if (new->flag_minus == 0)
			number = ft_strjoin(space, str);
		else
			number = ft_strjoin(str, space);
		free(space);
		free(str);
	}
	return (number);
}

int					ft_analise_float_part_two_len(t_print *new)
{
	int				len;

	len = 6;
	if (new->flag_accuracy != 0)
		len = new->accuracy;
	return (len);
}

void				ft_float_put_part_two(char **number, int null,
						long long num)
{
	char			*str;
	char			*str2;

	while (null-- > 0)
	{
		str = *number;
		*number = ft_strjoin(str, "0");
	}
	str = *number;
	str2 = ft_litoa(num);
	*number = ft_strjoin(str, str2);
	free(str);
	free(str2);
}

void				ft_float_put(long long z, int len, char **number)
{
	long long		num;
	int				null;
	char			*str;

	z /= 10;
	num = z;
	null = len;
	while (z != 0)
	{
		z /= 10;
		null--;
	}
	if (num == 0)
	{
		while (len-- > 0)
		{
			str = *number;
			*number = ft_strjoin(str, "0");
			free(str);
		}
		return ;
	}
	ft_float_put_part_two(&*number, null, num);
}

char				*ft_float_circle(double x, int len, char **number)
{
	long long		z;
	int				null;

	null = len;
	while (null-- >= 0)
		x *= 10;
	z = (long long)x;
	if (z % 10 > 5)
		z += 10 - z % 10;
	else if (z % 10 == 5)
	{
		x *= 10;
		z = (long long)x;
		if (z % 10 > 0)
			z += 10 - z % 10;
		z /= 10;
		if (z % 10 > 5)
			z += 10 - z % 10;
		if (z % 10 == 5)
			if (((z % 100) / 10) % 2 != 0)
				z += 10;
	}
	ft_float_put(z, len, &*number);
	return (*number);
}
