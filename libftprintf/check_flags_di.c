/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_di.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:55:59 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:08:34 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*check_flags_integer_plus_space(char *str, t_print *new)
{
	char	*new_str;
	int		i;

	i = -1;
	if (new->flag_plus)
	{
		new_str = ft_strnew((size_t)ft_strlen(str) + 1);
		new_str[0] = '+';
		while (++i < (int)ft_strlen(str))
			new_str[i + 1] = str[i];
		free(str);
		return (new_str);
	}
	else if (new->flag_space)
	{
		new_str = ft_strnew((size_t)ft_strlen(str) + 1);
		new_str[0] = ' ';
		while (++i < (int)ft_strlen(str))
			new_str[i + 1] = str[i];
		free(str);
		return (new_str);
	}
	return (str);
}

char		*check_flags_integer_width(char *str, t_print *new)
{
	char	*new_str;
	int		i;

	i = -1;
	if (new->flag_minus || new->flag_null)
		new_str = ft_width_for_minus_and_zero(str, new);
	else
	{
		new_str = ft_strnew((size_t)new->width);
		ft_memset(new_str, ' ', (size_t)new->width);
		while ((int)ft_strlen(str) - ++i >= 0)
			new_str[new->width - i] = str[ft_strlen(str) - i];
	}
	free(str);
	return (new_str);
}

char		*ft_integer_accuracy(char *str, t_print *new, int flagi)
{
	int		i;
	char	*new_str;
	char	*dlc_str;

	i = -1;
	dlc_str = check_flags_integer_plus_space(str, new);
	new_str = ft_strnew((size_t)new->accuracy + flagi);
	ft_memset(new_str, '0', (size_t)new->accuracy + flagi);
	if (flagi)
	{
		new_str[0] = dlc_str[0];
		while (ft_strlen(dlc_str) - ++i > 0)
			new_str[ft_strlen(new_str) - i] = dlc_str[ft_strlen(dlc_str) - i];
	}
	else
	{
		while ((int)ft_strlen(dlc_str) - ++i >= 0)
			new_str[new->accuracy - i] = dlc_str[ft_strlen(dlc_str) - i];
	}
	free(dlc_str);
	return (new_str);
}

static int	ft_integer_print_2(char *str, t_print *new, int flagi)
{
	char	*dlc_str;
	char	*new_str;
	int		num;
	int		i;

	i = 0;
	if ((!(new->flag_accuracy) || new->accuracy <= (int)ft_strlen(str)) &&
			new->width >= (int)ft_strlen(str))
	{
		dlc_str = check_flags_integer_plus_space(str, new);
		new_str = check_flags_integer_width(dlc_str, new);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
	}
	else
	{
		FLAG_SPACE;
		dlc_str = ft_integer_accuracy(str, new, flagi - i);
		new_str = check_flags_integer_width(dlc_str, new);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
	}
	free(new_str);
	return (num);
}

int			ft_integer_print(char *str, t_print *new)
{
	int		num;
	char	*new_str;
	int		flagi;

	flagi = (new->flag_space) + (new->flag_plus) + (new->flag_otr_i);
	if ((!(new->flag_width) && !(new->flag_accuracy)) ||
		(new->width < (int)ft_strlen(str) &&
		new->accuracy < (int)ft_strlen(str) - flagi))
	{
		new_str = check_flags_integer_plus_space(str, new);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
	}
	else if (((!(new->flag_width) || new->width < (int)ft_strlen(str)) &&
			new->accuracy > (int)ft_strlen(str) - flagi) ||
			(new->width <= new->accuracy))
	{
		new_str = ft_integer_accuracy(str, new, flagi);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
	}
	else
		return (ft_integer_print_2(str, new, flagi));
	free(new_str);
	return (num);
}
