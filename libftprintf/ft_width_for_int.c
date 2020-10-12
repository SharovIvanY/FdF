/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_for_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:12:05 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:13:57 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_for_mz_2(char *str, char *new_str, t_print *new,
		char *hoba)
{
	int		i;

	free(hoba);
	i = -1;
	if (new->flag_accuracy && new->accuracy < (int)ft_strlen(str))
		ft_memset(new_str, ' ', (size_t)new->width);
	else
		ft_memset(new_str, '0', (size_t)new->width);
	if (new->flag_otr_i || new->flag_plus || new->flag_space)
	{
		new_str[0] = str[0];
		while (ft_strlen(str) - ++i > 0)
			new_str[new->width - i] = str[ft_strlen(str) - i];
	}
	else
	{
		while ((int)ft_strlen(str) - ++i >= 0)
			new_str[new->width - i] = str[ft_strlen(str) - i];
	}
	return (new_str);
}

char		*ft_width_for_minus_and_zero(char *str, t_print *new)
{
	char	*new_str;
	int		i;
	char	*hoba;

	INT_I;
	new_str = ft_strnew((size_t)new->width);
	if (new->flag_minus)
	{
		ft_memset(new_str, ' ', (size_t)new->width);
		while (++i < (int)ft_strlen(str))
			new_str[i] = str[i];
	}
	else
	{
		if (new->flag_accuracy && new->accuracy > (int)ft_strlen(hoba))
		{
			ft_memset(new_str, ' ', (size_t)new->width);
			while ((int)ft_strlen(str) - ++i >= 0)
				new_str[new->width - i] = str[ft_strlen(str) - i];
		}
		else
			return (ft_width_for_mz_2(str, new_str, new, hoba));
	}
	free(hoba);
	return (new_str);
}
