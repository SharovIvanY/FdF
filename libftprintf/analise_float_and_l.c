/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:33:39 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/14 20:00:27 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_float_tochka(double *x, t_print *new, char **number)
{
	char		*str;
	int			flag;

	flag = 0;
	if (*x < 0)
	{
		*number = "-";
		*x *= -1;
		flag = 1;
	}
	*number = ft_float_tochka_part_two(*x, flag, *number);
	if (new->flag_accuracy == 0 || (new->flag_accuracy && new->accuracy > 0)
			|| new->flag_sharp == 1)
	{
		str = *number;
		*number = ft_strjoin(str, ".");
		free(str);
	}
	*x -= (long long)*x;
	return (*number);
}

char			*stack(long double x, int value)
{
	int			i;
	char		*str;
	int			count;
	char		*temp;

	value = (x < 0 ? -1 : 1);
	x *= value;
	i = long_x(&x);
	str = ft_strnew((size_t)i);
	count = 0;
	while (--i >= (value < 0) ? 1 : 0)
	{
		x *= 10;
		str[count++] = (int)x + '0';
		x -= (int)x;
	}
	if (value == -1)
	{
		temp = str;
		str = ft_strjoin("-", str);
		free(temp);
	}
	return (str);
}

int				ft_analise_float_accuracy_null(double x, int value,
					t_print *new)
{
	long long	z;
	char		*number;

	if (x < 1e-20 || x > 1e+20)
	{
		number = stack(x, value);
		ft_putstr(number);
		z = ft_strlen(number);
		free(number);
		return ((int)z);
	}
	z = (long long)x % 2;
	z = (z == 0 ? 0 : z);
	x *= 10;
	if ((long long)x % 10 >= 5 && z != 0)
		x += 10;
	x /= 10;
	ft_float_tochka(&x, new, &number);
	value = ft_strlen(number);
	if (new->flag_space)
		ft_putchar(' ');
	ft_putstr(number);
	value += (new->flag_space ? 1 : 0);
	free(number);
	return (value);
}

char			*float_flags(char *number, t_print *new, int *value)
{
	char		*str;
	char		ch;

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
	number = float_flags_part_two(new, number, ch);
	if (new->flag_space == 1)
	{
		str = number;
		number = ft_strjoin(" ", str);
		free(str);
	}
	*value = ft_strlen(number);
	return (number);
}

int				ft_analise_float(va_list ap, t_print *new)
{
	int			len;
	double		x;
	int			value;
	char		*number;

	len = ft_analise_float_part_two_len(new);
	number = NULL;
	x = va_arg(ap, double);
	if ((value = ft_infinity_float_l(x)) != 0)
		return (value);
	if (new->flag_accuracy == 1 && new->accuracy <= 0)
	{
		value = ft_analise_float_accuracy_null(x, value, new);
		return (value);
	}
	else if (new->flag_accuracy == 1)
		len = new->accuracy;
	ft_float_tochka(&x, new, &number);
	ft_float_circle(x, len, &number);
	number = float_flags(number, new, &value);
	ft_putstr(number);
	free(number);
	return (value);
}
