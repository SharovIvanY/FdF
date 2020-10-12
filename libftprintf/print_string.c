/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:44:47 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:18:20 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_string_accuracy(char *str, int accuracy)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strnew((size_t)accuracy);
	while (accuracy - i > 0)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

static char	*ft_other(char *str, int width)
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = ft_strnew((size_t)width);
	ft_memset(new_str, ' ', (size_t)width);
	while ((int)ft_strlen(str) >= ++i)
		new_str[ft_strlen(new_str) - i] = str[ft_strlen(str) - i];
	return (new_str);
}

static char	*ft_check_flag_minus(char *str, t_print *new)
{
	char	*new_str;
	int		i;

	i = -1;
	if (new->flag_minus)
	{
		new_str = ft_strnew((size_t)new->width);
		ft_memset(new_str, ' ', (size_t)new->width);
		while (++i < (int)ft_strlen(str))
			new_str[i] = str[i];
	}
	else if (new->flag_null)
	{
		new_str = ft_strnew((size_t)new->width);
		ft_memset(new_str, '0', (size_t)new->width);
		while ((int)ft_strlen(str) - ++i - 1 >= 0)
			new_str[new->width - 1 - i] = str[ft_strlen(str) - 1 - i];
	}
	else
		new_str = ft_other(str, new->width);
	return (new_str);
}

static int	ft_print_string_2(char *str, t_print *new)
{
	int		num;
	char	*new_str;
	char	*dlc_str;

	if ((!(new->flag_accuracy) || new->accuracy >= (int)ft_strlen(str)) &&
			new->width >= (int)ft_strlen(str) && new->flag_width)
	{
		new_str = ft_check_flag_minus(str, new);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
		free(new_str);
	}
	else
	{
		dlc_str = ft_string_accuracy(str, new->accuracy);
		new_str = ft_check_flag_minus(dlc_str, new);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
		free(new_str);
		free(dlc_str);
	}
	return (num);
}

int			ft_print_string(char *str, t_print *new)
{
	int		num;
	char	*new_str;

	if ((!(new->flag_width) && !(new->flag_accuracy)) ||
		(!(new->flag_width) && new->flag_accuracy &&
		(int)ft_strlen(str) <= new->accuracy) ||
		(!(new->flag_accuracy) && new->flag_width &&
		(int)ft_strlen(str) >= new->width) || ((int)ft_strlen(str) <=
		new->accuracy && (int)ft_strlen(str) >= new->width))
	{
		ft_putstr(str);
		num = ft_strlen(str);
	}
	else if ((!(new->flag_width) || new->width <= (int)ft_strlen(str)) &&
		new->flag_accuracy && (int)ft_strlen(str) > new->accuracy &&
		new->width <= new->accuracy)
	{
		new_str = ft_string_accuracy(str, new->accuracy);
		ft_putstr(new_str);
		num = ft_strlen(new_str);
		free(new_str);
	}
	else
		num = ft_print_string_2(str, new);
	return (num);
}
