/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:33:39 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 17:37:03 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_bl_float_tochka(long double *x, t_print *new,
						char *number)
{
	char			*str;
	int				flag;
	char			*temp;
	char			*number2;

	if (number != NULL)
		number2 = ft_strdup(number);
	else
		number2 = number;
	temp = number2;
	flag = 0;
	if (*x < 0)
		IF_X;
	number2 = ft_bl_float_tochka_part_two(*x, flag, temp);
	if (new->flag_accuracy == 0 || (new->flag_accuracy && new->accuracy > 0)
			|| new->flag_sharp == 1)
	{
		str = number2;
		temp = ".";
		number2 = ft_strjoin(str, temp);
		free(str);
	}
	*x -= (long long int)*x;
	return (number2);
}

int					ft_bl_analise_float_accuracy_null(long double x,
						int value, t_print *new)
{
	long long int	z;
	char			*number;

	number = NULL;
	if (x < 1e-20 || x > 1e+20)
	{
		number = stack(x, value);
		ft_putstr(number);
		z = ft_strlen(number);
		free(number);
		return ((int)z);
	}
	z = (long long int)x % 2;
	if (z == 0)
		z = 0;
	x *= 10;
	if ((long long int)x % 10 >= 5 && z != 0)
		x += 10;
	x /= 10;
	number = ft_bl_float_tochka(&x, new, number);
	value = ft_strlen(number);
	ft_putstr(number);
	free(number);
	return (value);
}

char				*float_bl_flags(char *number, t_print *new, int *value)
{
	char			*str;
	char			ch;

	ch = ' ';
	if (new->flag_null == 1)
		ch = '0';
	if (new->flag_plus == 1)
		if (number[0] != '-')
		{
			str = number;
			number = ft_strjoin("+", str);
			free(str);
		}
	number = float_bl_flags_part_two(new, number, ch);
	if (new->flag_space == 1)
	{
		str = number;
		number = ft_strjoin(" ", str);
		free(str);
	}
	*value = ft_strlen(number);
	return (number);
}

int					ft_bl_analise_float(va_list ap, t_print *new)
{
	int				len;
	long double		x;
	int				value;
	char			*number;
	char			*temp;

	VA_ARG_X;
	x = va_arg(ap, long double);
	if ((value = ft_bl_infinity_float_l(x)) != 0)
		return (value);
	if (new->flag_accuracy == 1 && new->accuracy <= 0)
	{
		value = ft_bl_analise_float_accuracy_null(x, value, new);
		return (value);
	}
	else if (new->flag_accuracy == 1)
		len = new->accuracy;
	number = ft_bl_float_tochka(&x, new, number);
	temp = ft_strdup(number);
	ft_memdel((void**)&number);
	number = ft_bl_float_circle(x, len, &temp);
	number = float_bl_flags(number, new, &value);
	RETURN_VAL;
}
