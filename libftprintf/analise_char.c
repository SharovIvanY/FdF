/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:46:43 by amace-ty          #+#    #+#             */
/*   Updated: 2019/03/18 15:46:45 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_check_char_flag_minus(char c, char *str_width, t_print *new)
{
	char	*new_str;
	int		i;

	i = 0;
	if (new->flag_minus)
	{
		free(str_width);
		new_str = ft_strnew(new->width);
		ft_memset(new_str, ' ', new->width);
		new_str[i] = c;
		return (new_str);
	}
	else if (new->flag_null)
	{
		free(str_width);
		new_str = ft_strnew(new->width);
		ft_memset(new_str, '0', new->width);
		new_str[new->width - 1] = c;
		return (new_str);
	}
	return (str_width);
}

char		*ft_check(t_print *new, int flag)
{
	char	*str;
	int		len;

	if (new->width == 0)
		len = 0;
	else
		len = new->width - 1;
	str = ft_strnew((size_t)len);
	if (flag == 1)
		ft_memset(str, ' ', len);
	if (flag == 2)
		ft_memset(str, '0', len);
	return (str);
}

static char	*ft_analise_simvol_two(t_print *new, char c)
{
	char	*str;

	if (new->flag_null)
	{
		str = ft_check(new, 2);
		ft_putstr(str);
		write(1, &c, 1);
	}
	else
	{
		str = ft_check(new, 1);
		ft_putstr(str);
		write(1, &c, 1);
	}
	return (str);
}

int			ft_analise_simvol(va_list ap, t_print *new)
{
	int		c;
	char	*str;
	int		x;

	c = va_arg(ap, int);
	if (new->flag_width)
	{
		if (new->flag_minus)
		{
			write(1, &c, 1);
			str = ft_check(new, 1);
			ft_putstr(str);
		}
		else
			str = ft_analise_simvol_two(new, c);
		x = ft_strlen(str) + 1;
		free(str);
		return (x);
	}
	write(1, &c, 1);
	return (1);
}
